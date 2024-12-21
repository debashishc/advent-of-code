#include "day04.hpp"
#include "fileReader.hpp"
#include <iostream>

int64_t Day04::solvePart1(const std::vector<std::string>& input) {
    // TODO: Implement solution for part 1
    const std::string word = "XMAS";
    int64_t count = 0;
    
    const int wordLength = word.length();
    const int rows = input.size();
    const int cols = input[0].size();
    
    // possible directions to search for the word
    const std::vector<std::pair<int, int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1,0},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };

    
    
    return count;
}

int64_t Day04::solvePart2(const std::vector<std::string>& input) {
    // TODO: Implement solution for part 2
    return 0;
}

int main() {
    try {
        auto input = utils::FileReader::readLines("input.txt");
        
        std::cout << "Part 1: " << Day04::solvePart1(input) << std::endl;
        std::cout << "Part 2: " << Day04::solvePart2(input) << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}