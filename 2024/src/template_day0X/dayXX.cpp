#include "dayXX.hpp"
#include "fileReader.hpp"
#include <iostream>

int64_t DayXX::solvePart1(const std::vector<std::string>& input) {
    // TODO: Implement solution for part 1
    return 0;
}

int64_t DayXX::solvePart2(const std::vector<std::string>& input) {
    // TODO: Implement solution for part 2
    return 0;
}

int main() {
    try {
        auto input = utils::FileReader::readLines("input.txt");
        
        std::cout << "Part 1: " << DayXX::solvePart1(input) << std::endl;
        std::cout << "Part 2: " << DayXX::solvePart2(input) << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}