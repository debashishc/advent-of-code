
with open("day1.txt", mode="r") as my_file:
    my_list = list(map(int, my_file.readlines()))

for num in my_list:
    if (2020 - num) in my_list[1:]:    
        print(num * (2020 - num))
        break


for num in my_list:
    for num1 in my_list[1:]:
        if (2020 - (num+num1)) in my_list[2:]: 
            print(num * num1 * (2020 - (num+num1)))
            break

    