def get_seat_id(row: int, col:int) -> int:
    return (row*8)+col

def recurse(_chars, _list):
    list_len = len(_list)
    if not _chars:
        return _list[0]
    elif _chars[0] in ("F", "L"): # lower-half
        return recurse(_chars[1:], _list[0:list_len//2])
    else:
        return recurse(_chars[1:], _list[list_len//2:])

def get_row_col(boarding_pass):
    bp_row_chars = boarding_pass[:7]
    bp_col_chars = boarding_pass[7:]

    row = recurse(bp_row_chars, list(range(128)))
    col = recurse(bp_col_chars, list(range(8)))

    return row, col

if __name__ == "__main__":
    with open("day5.txt", mode="r") as my_file:
        data = my_file.readlines()

    result = 0

    # Part 1
    # for row, col in map(get_row_col, data):
    #     seat_id = get_seat_id(row, col)
    #     if seat_id > result:
    #     # if (seat_id := get_seat_id(row, col)) > result:
    #         result = seat_id
    
    seat_ids = set()
    for row, col in map(get_row_col, data):
        seat_id = get_seat_id(row, col)
        seat_ids.add(seat_id)

    empty_seat_ids = set(range(max(seat_ids))) - seat_ids
    print(empty_seat_ids)

    for seat in empty_seat_ids:
        if (seat-1 in seat_ids) and (seat+1 in seat_ids):
            print(seat)

    

# ROWS = list(range(128))
# CHARS = "FBFBBFFR"

# print(recurse(CHARS, ROWS))

