# Read puzzle file into a list of strings
def read_puzzle_input():
    with open("puzzle", "r") as file:
        return file.readlines()


def sum_calibration_values(lines):
    # Function to extract the calibration value from a line
    def extract_value(line):
        first_digit = next(char for char in line if char.isdigit())
        last_digit = next(char for char in reversed(line) if char.isdigit())
        return int(first_digit + last_digit)

    # Summing the calibration values of each line
    return sum(extract_value(line) for line in lines)


# Write a test for the function
def test_sum_calibration_values():
    example_lines = ["1abc2", "pqr3stu8vwx", "a1b2c3d4e5f", "treb7uchet"]
    assert sum_calibration_values(example_lines) == 142


if __name__ == "__main__":
    # Read puzzle input
    lines = read_puzzle_input()

    # Calculate the sum of calibration values
    print(sum_calibration_values(lines))
