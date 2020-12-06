import re

def is_passport_valid(dict_props:dict):
    # flag = True
    if "cid" in dict_props:
        if len(dict_props) == 8:
            # print(1)
            return check_valid(dict_props)
        return False
    elif len(dict_props) == 7:
        # print(2)
        return check_valid(dict_props)
    else:
        return False

def check_byr(byr):
    return bool(re.compile(r"^(19[2-9][0-9]|200[0-2])").match(byr))

def check_iyr(iyr):
    return bool(re.compile(r"^(201[0-9]|2020)").match(iyr))

def check_eyr(eyr):
    return bool(re.compile(r"^(202[0-9]|2030)").match(eyr))

def check_hgt(hgt):
    return (bool(re.compile(r"^(1[5-8][0-9]|19[0-3])cm").match(hgt))) or (bool(re.compile(r"^(59|6[0-9]|7[0-6])in").match(hgt)))  


def check_ecl(ecl):
    return ecl in ("amb", "blu", "brn", "gry", "grn", "hzl", "oth")

def check_hcl(hcl):
    return bool(re.compile(r"^#([0-9]{6}|[a-f]{6})$").match(hcl))

def check_pid(pid):
    return bool(re.compile(r"^(?=0+[1-9])0\d{8}|[0-9]{9}$").match(pid)) 

# byr (Birth Year) - four digits; at least 1920 and at most 2002.
# iyr (Issue Year) - four digits; at least 2010 and at most 2020.
# eyr (Expiration Year) - four digits; at least 2020 and at most 2030.
# hgt (Height) - a number followed by either cm or in:
# If cm, the number must be at least 150 and at most 193.
# If in, the number must be at least 59 and at most 76.
# hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.
# ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
# pid (Passport ID) - a nine-digit number, including leading zeroes.
# cid (Country ID) - ignored, missing or not.

def check_valid(pass_dict):
    return bool(re.compile(r"^(19[2-9][0-9]|200[0-2])").match(pass_dict['byr'])) \
            and bool(re.compile(r"^(201[0-9]|2020)").match(pass_dict['iyr'])) \
            and bool(re.compile(r"^(202[0-9]|2030)").match(pass_dict['eyr'])) \
            and (bool(re.compile(r"^(1[5-8][0-9]|19[0-3])cm").match(pass_dict['hgt'])) or (bool(re.compile(r"^(59|6[0-9]|7[0-6])in").match(pass_dict['hgt']))))  \
            and pass_dict["ecl"] in ("amb", "blu", "brn", "gry", "grn", "hzl", "oth") \
            and bool(re.compile(r"^#([0-9a-f]{6})$").match(pass_dict["hcl"])) \
            and bool(re.compile(r"^(?=0+[1-9])0\d{8}$|^[0-9]{9}$").match(pass_dict["pid"])) 
            

with open("day4.txt", mode="r") as my_file:
    lines = my_file.read()
    passport_info = lines.split("\n\n")


counter = 0

for passp in passport_info[:5]:
    print(passp)
    pass_infos = re.split(r"[\s\n]", passp)
    print(pass_infos)
    pass_hash = {sub.split(":")[0]: sub.split(":")[1] for sub in pass_infos}
    valid = is_passport_valid(pass_hash)
    print(pass_hash, valid)
    counter += valid

print(counter)
