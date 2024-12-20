#include "day03.hpp"
#include "fileReader.hpp"
#include <iostream>
#include <regex>
#include <string>

int64_t Day03::solvePart1(const std::vector<std::string>& input) {
    const std::regex mulRegex(R"(mul\((\d{1,3}),(\d{1,3})\))");
    int64_t sum = 0;

    for (const auto& line: input) {
        std::smatch match;
        std::string remaining = line;

        while (std::regex_search(remaining, match, mulRegex)) {
            int x = std::stoi(match[1].str());
            int y = std::stoi(match[2].str());
            sum += x * y;
            remaining = match.suffix().str();
        }
    }

    return sum;
}

int64_t Day03::solvePart2(const std::vector<std::string>& input) {
    const std::regex instructionRegex(R"((\bdo\(\))|(\bdon't\(\))|(mul\((\d{1,3}),(\d{1,3})\)))");

    int64_t sum = 0;
    bool isEnabled = true; // Instructions start enabled.

    for (const auto& line : input) {
        std::smatch match;
        std::string remaining = line;

        while (std::regex_search(remaining, match, instructionRegex)) {
            if (match[1].matched) { // `do()` matches
                isEnabled = true;
            } else if (match[2].matched) { // `don't()` matches
                isEnabled = false;
            } else if (isEnabled && match[3].matched) { // `mul(X,Y)` matches and is enabled
                int x = std::stoi(match[4].str());
                int y = std::stoi(match[5].str());
                sum += x * y;
            }
            remaining = match.suffix().str(); // Continue parsing the rest of the string.
        }
    }

    return sum;
}

int main() {
    try {
        auto input = utils::FileReader::readLines("input.txt");
        
        std::cout << "Part 1: " << Day03::solvePart1(input) << std::endl;
        std::cout << "Part 2: " << Day03::solvePart2(input) << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}