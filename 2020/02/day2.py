def get_content(line):
    splits = line.split()
    more_splits = splits[0].split('-')
    _min, _max = int(more_splits[0]), int(more_splits[1])
    letter = splits[1].rstrip(':')
    pwd = splits[2]
    return letter, _min, _max, pwd

def is_pwd_correct(letter, _min, _max, pwd):
    return _min <= pwd.count(letter) <= _max

def is_pwd_correct2(letter, _min, _max, pwd):
    letters = pwd[_min-1] + pwd[_max-1]
    return letters.count(letter) == 1

with open("day2.txt", mode = "r") as my_file:
    lines = my_file.readlines()
    counter = 0
    for line in lines:
        letter, _min, _max, pwd = get_content(line)
        if is_pwd_correct2(letter, _min, _max, pwd):
            counter += 1
    
    print(counter)
