# Read puzzle file into a list of strings
def read_puzzle_input():
    with open("input.txt", "r") as file:
        return file.readlines()


# Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
# Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
# Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
# Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
# Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green
# Sum of Correct Game Ids: 1 + 2 + 5 = 8


# Write a test for the function given above comment
def test_product_calibration_values():
    example_lines = [
        "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green",
        "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue",
        "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red",
        "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red",
        "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green",
    ]
    print([parse_line(line) for line in example_lines])
    print(
        [
            find_max_cubes_per_game(game_sets)
            for _, game_sets in [parse_line(line) for line in example_lines]
        ]
    )
    assert (
        sum(
            product_max_cubes(games)
            for game_id, games in [parse_line(line.strip()) for line in example_lines]
        )
    ) == 2286


# Determine which games would have been possible if the bag had been loaded with only 12 red cubes, 13 green cubes, and 14 blue cubes.

# Find the number of cubes of each color in the bag
# "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green",
# "1" : {"blue": 9, "red": 5, "green": 4}


def parse_line(line):
    # Find the index of the first colon
    colon_index = line.index(":")

    # Get the game id
    game_id = line[:colon_index]

    # Get the cubes
    cubes = line[colon_index + 2 :]

    # Split the cubes into the three games
    games = cubes.split("; ")

    # Split each game into the colors
    games = [game.split(", ") for game in games]

    # Split each color into the number of cubes
    games = [[color.split(" ") for color in game] for game in games]

    # Convert the number of cubes to integers
    games = [{color[1]: int(color[0]) for color in game} for game in games]

    return game_id.split(" ")[1], games


def find_max_cubes_per_game(game_sets):
    # Find the maximum number of cubes of each color for any number of games
    # find_max_cubes_per_game(
    #     [
    #         {"red": 2, "blue": 13, "green": 1},
    #         {"green": 1, "blue": 12},
    #         {"red": 1, "blue": 5, "green": 1},
    #         {"blue": 3, "red": 3},
    #     ]
    # )
    # {"red": 1, "blue": 3, "green": 1}
    max_cubes = {}
    for game in game_sets:
        for color in game:
            if color not in max_cubes:
                max_cubes[color] = game[color]
            else:
                max_cubes[color] = max(max_cubes[color], game[color])
    return max_cubes


def product_max_cubes(game_sets):
    # Sum all the max cubes per game set

    # Find the maximum number of cubes of each color for any number of games
    max_cubes = find_max_cubes_per_game(game_sets)
    print(f"max_cubes : {max_cubes}")

    # product the number of cubes of each color
    return max_cubes["red"] * max_cubes["green"] * max_cubes["blue"]


if __name__ == "__main__":
    # Read puzzle input
    lines = read_puzzle_input()

    # Calculate the sum of calibration values
    # print([parse_line(line.strip()) for line in lines])

    # # print(sum_filter_possible_games([parse_line(line.strip()) for line in lines]))
    # print(
    #     find_max_cubes_per_game(
    #         [
    #             {"red": 2, "blue": 13, "green": 1},
    #             {"green": 1, "blue": 12},
    #             {"red": 1, "blue": 5, "green": 1},
    #             {"blue": 3, "red": 3},
    #         ]
    #     )
    # )

    print(
        sum(
            product_max_cubes(games)
            for game_id, games in [parse_line(line.strip()) for line in lines]
        )
    )
