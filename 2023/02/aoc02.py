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
def test_sum_calibration_values():
    example_lines = [
        "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green",
        "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue",
        "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red",
        "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red",
        "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green",
    ]
    print([parse_line(line) for line in example_lines])
    assert sum_filter_possible_games([parse_line(line) for line in example_lines]) == 8


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


# def sum_per_cube(game):
#     """
#     >>> sum_per_cube(('Game 1', [{'blue': 3, 'red': 4}, {'red': 1, 'green': 2, 'blue': 6}, {'green': 2}]))
#     "1" : {"blue": 9, "red": 5, "green": 4}
#     """
#     game_id, games = game

#     # Sum the number of cubes of each color
#     sum_per_color = {}
#     for game in games:
#         for color in game:
#             if color not in sum_per_color:
#                 sum_per_color[color] = game[color]
#             else:
#                 sum_per_color[color] += game[color]

#     return game_id.split(" ")[1], sum_per_color


MAX_CUBES = {"red": 12, "green": 13, "blue": 14}


# Write a function that determines if a game is possible
def is_possible(game):
    """
    Check if the number of cubes of each color is less than or equal to the maximum number of cubes
    >>> is_possible(('Game 1', {'blue': 9, 'red': 5, 'green': 4}))
    True
    >>> is_possible(('Game 2', {'blue': 15, 'green': 7, 'red': 5}))
    False
    """
    game_id, list_of_games = game
    for game in list_of_games:
        for color in game:
            if game[color] > MAX_CUBES[color]:
                return False
    return True


def sum_filter_possible_games(games):
    # return index of games that are possible
    print([int(game[0]) for game in games if is_possible(game)])
    return sum(
        int(game[0]) for game in games if is_possible(game)
    )  # sum of game ids that are possible


if __name__ == "__main__":
    # Read puzzle input
    lines = read_puzzle_input()

    # Calculate the sum of calibration values
    # print([parse_line(line.strip()) for line in lines])

    print(sum_filter_possible_games([parse_line(line.strip()) for line in lines]))
