def is_tree(cell):
    return cell == '#'

def move3r1d(x,y):
    return (x+3, y+1)

def move1r1d(x,y):
    return (x+1, y+1) 
    
def move5r1d(x,y):
    return (x+5, y+1)
    
def move7r1d(x,y):
    return (x+7, y+1)

def move1r2d(x,y):
    return (x+1, y+2)

def list_moves():
    return [move1r1d, move1r2d, move3r1d, move5r1d, move7r1d]


with open("day3.txt", mode="r") as my_file:
    data = list(map(str.strip, my_file.readlines()))
    print(data[:3])


def main(func):
    counter = 0
    x, y = 0, 0

    y_len, x_len = (len(data), len(data[0]))

    print(y_len, x_len)

    while (y < y_len - 1):
        
        x, y = func(x, y)
        x = x % x_len # wrap around as the pattern gets repeated
        counter += is_tree(data[y][x])

    return counter

result = 1
for func in list_moves():
    print(main(func))
    result *= main(func)

print(result)
