def test():
    example_input = """
    467..114..
    ...*......
    ..35..633.
    ......#...
    617*......
    .....+.58.
    ..592.....
    ......755.
    ...$.*....
    .664.598..
    """
    example_txt = read_puzzle_input("example.txt")
    print(example_txt)
    print(get_symbols_from_lines(example_txt))
    pass
    # assert sum_part_symbols(example_input) == 4361


def read_puzzle_input(txt_file):
    with open(txt_file, "r") as file:
        return file.read().split("\n")


import itertools

# Store coordinates of symbols in a set
# For each line

coords = list(itertools.product((-1, 0, 1), repeat=2))


def get_symbols_from_lines(lines):
    symbols = {
        (x, y)
        for x, line in enumerate(lines)
        for y, character in enumerate(line)
        if character != "." and not character.isdigit()
    }
    return symbols


def sum_part_symbols(lines):
    symbols = get_symbols_from_lines(lines)
    total = 0
    for i, line in enumerate(lines):
        import re

        for match in re.finditer(r"\d+", line):
            num = int(match.group())
            boundaries = {
                (i + di, j + dj)
                for di, dj in coords
                for j in range(match.start(), match.end())
            }
            if symbols & boundaries:
                total += num
    return total


def sum_part_symbols2(lines):
    symbols = get_symbols_from_lines(lines)
    # dict = defaultdict(list)
    for i, line in enumerate(lines):
        import re

        for match in re.finditer(r"\d+", line):
            num = int(match.group())
            boundaries = {
                (i + di, j + dj)
                for di, dj in coords
                for j in range(match.start(), match.end())
            }
            if symbols & boundaries:
                total += num
    return total
