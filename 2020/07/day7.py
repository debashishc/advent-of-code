# striped olive bags contain 4 dim tomato bags.
# dotted yellow bags contain 4 mirrored aqua bags, 4 faded indigo bags, 2 faded green bags.
# pale bronze bags contain 3 plaid teal bags, 2 posh aqua bags, 2 dotted lime bags.
# striped blue bags contain 4 dark tomato bags, 2 dim aqua bags, 1 dull olive bag.
# dull salmon bags contain 1 light yellow bag.
# muted tan bags contain 2 dim purple bags, 2 shiny coral bags, 2 drab bronze bags.
# bright gold bags contain 5 shiny lavender bags, 4 dark maroon bags.
# vibrant lavender bags contain 3 vibrant lime bags, 1 dark tomato bag, 2 dim fuchsia bags, 4 clear black bags.
# bright tomato bags contain 4 clear blue bags, 2 wavy beige bags, 5 faded lime bags.
# drab plum bags contain 4 bright olive bags, 1 posh lavender bag, 3 pale white bags, 2 dim green bags.
# muted gold bags contain 3 posh magenta bags.
# mirrored coral bags contain 3 dotted beige bags, 1 light magenta bag, 4 wavy turquoise bags.
# mirrored purple bags contain 1 mirrored plum bag, 4 faded black bags, 3 bright violet bags, 1 vibrant yellow bag.
# mirrored lavender bags contain 4 shiny violet bags, 4 dark violet bags, 3 drab gray bags, 3 plaid salmon bags.
# muted teal bags contain 1 plaid turquoise bag, 5 light tomato bags.
# plaid turquoise bags contain 2 posh aqua bags, 3 wavy plum bags, 3 dotted salmon bags.
# pale coral bags contain 4 wavy lavender bags, 5 striped gray bags, 2 dotted turquoise bags, 4 striped violet bags.
# pale lavender bags contain 4 vibrant lime bags, 1 dim plum bag, 1 posh salmon bag.

def first_split(line_list):
    """lets make a dict of dicts"""
    bag_dict = dict()
    for line in line_list:
        split1 = line.split("contain")
        main_bag = split1[0].rstrip("s ")

        container_dict = dict()
        for bag_count in split1[1]:


with open("day7.txt", mode="r") as my_file:
    data = my_file.readlines()

