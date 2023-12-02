# Read puzzle file into a list of strings
def read_puzzle_input():
    with open("input.txt", "r") as file:
        return file.readlines()


# Dictionary of letters and their number it represents between 0 and 9
# e.g. "eight" => 8
spelled_out_digits = {
    "zero": "0",
    "one": "1",
    "two": "2",
    "three": "3",
    "four": "4",
    "five": "5",
    "six": "6",
    "seven": "7",
    "eight": "8",
    "nine": "9",
}


def process_line(line):
    # Find the indices of the first letter of each spelled out number
    indices = find_spelled_out_numbers(line)

    # Find the indices of all the digits
    digits = find_digits(line)

    # Concatenate the indices of the spelled out numbers and digits
    indices += digits

    # Sort the indices by their index
    indices.sort(key=lambda x: x[1])

    # Create a new line with digits and spelled out numbers according to their indices
    new_line = ""
    for index in indices:
        # If the index is a spelled out number
        if index[0] in spelled_out_digits.keys():
            # Replace the spelled out number with its digit
            new_line += spelled_out_digits[index[0]]
        # If the index is a digit
        else:
            # Add the digit to the new line
            new_line += index[0]
    return new_line


def sum_calibration_values(lines):
    new_lines = [process_line(line) for line in lines]
    print([extract_value(line) for line in new_lines])

    # Summing the calibration values of each line
    return sum(extract_value(line) for line in new_lines)


def extract_value(line):
    first_digit = next(char for char in line if char.isdigit())
    last_digit = next(char for char in reversed(line) if char.isdigit())
    return int(first_digit + last_digit)


# Write a function that finds the spelled out numbers in a line and returns the word and indices of the first letter
def find_spelled_out_numbers(line):
    # Find the indices of the first letter of each spelled out number
    word_indices = []
    for word in spelled_out_digits:
        index = line.find(word)
        if index != -1:
            # find all the indices of the word substring in the line using regex
            import re

            indices = [m.start() for m in re.finditer(word, line)]
            word_indices += [(word, index) for index in indices]
    return word_indices


# Write a funtion that finds indices of all the digits in a line
# return a list of tuples of the digit and its index
def find_digits(line):
    indices = []
    for index, char in enumerate(line):
        if char.isdigit():
            indices.append((char, index))
    return indices


def test_sum_calibration_values():
    example_lines = [
        "two1nine",
        "eightwothree",
        "abcone2threexyz",
        "xtwone3four",
        "4nineeightseven2",
        "zoneight23 4",
        "7pqrstsixteen",
        "45122",
        "sevenonezknqnkfqbzffjvfivetwo94two",
        "mp7one6eightvhfnmfive6",
    ]
    print(find_spelled_out_numbers("mp7one6eightvhfnmfive6"))
    print(find_digits("mp7one6eightvhfnmfive6"))
    print([process_line(line) for line in example_lines])
    assert sum_calibration_values(example_lines) == 471


if __name__ == "__main__":
    # Read puzzle input
    lines = read_puzzle_input()

    # Calculate the sum of calibration values
    print(sum_calibration_values(lines))
