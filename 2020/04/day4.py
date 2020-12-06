import re

def is_passport_valid(list_props:list):
    # flag = True
    pattern = re.compile(r"cid*")
    if any(pattern.match(prop) for prop in list_props):
        # list_props.remove("cid")
        return len(list_props) == 8
    else:
        return len(list_props) == 7

with open("day4.txt", mode="r") as my_file:
    lines = my_file.read()
    passport_info = lines.split("\n\n")

counter = 0

import re
for passp in passport_info:
    pass_infos = re.split(r"[\s\n]", passp)
    pass_hash = {sub.split(":")[0]: sub.split(":")[1] for sub in passport_info}
    valid = is_passport_valid(pass_infos)
    counter += valid
    # print(pass_infos, valid)

print(counter)
