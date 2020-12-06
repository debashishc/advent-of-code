#part 1
# with open("day6.txt", mode="r") as my_file:
#     lines = my_file.read()
#     group_ans = lines.split("\n\n")
#     cleaned_ans = [line.replace("\n", "") for line in group_ans]
#     grp_ans_set = map(set, cleaned_ans)
#     grp_ans_len = map(len, grp_ans_set)
#     result = sum(grp_ans_len)

# small_grp = cleaned_ans[:5]
# print(list(map(set, small_grp)))

# print(result)
# part 2
with open("day6.txt", mode="r") as my_file:
    lines = my_file.read()
    group_ans = lines.split("\n\n")
    cleaned_ans = [ line.split("\n") for line in group_ans]
    grp_ans_set = [set.intersection(*map(set,single_ans)) for single_ans in cleaned_ans]
    grp_ans_len = map(len, grp_ans_set)
    result = sum(grp_ans_len)

small_grp = grp_ans_set[:5]
print(result)
