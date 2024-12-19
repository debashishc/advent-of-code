#include "day01.hpp"
#include "fileReader.hpp"
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

int64_t Day03::solvePart1(const std::vector<std::string>& input) {
    // TODO: Implement solution for part 1
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
    // TODO: Implement solution for part 2
    return 0;
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