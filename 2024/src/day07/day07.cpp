#include "day07.hpp"
#include "fileReader.hpp"
#include <iostream>
#include <sstream>

// evaluate an expression with given operators
int64_t evaluateExpression(const std::vector<int64_t>& numbers, 
                           const std::vector<char>& operators) {
    int64_t result = numbers[0];
    
    return result;
}

// generate all possible operator combinations to check target
bool canMakeTarget(int64_t target, const std::vector<int64_t>& numbers) {

    
    return false;
}

int64_t Day07::solvePart1(const std::vector<std::string>& input) {
    int64_t totalCalibrationResult = 0;

    for (const auto& line : input) {
        if (line.empty()) continue;
        
        // split on colon
        size_t colonPos = line.find(':');
        if (colonPos == std::string::npos) continue;
        
        // parse target number
        int64_t target;
        target = std::stoll(line.substr(0, colonPos));
        
        // parse numbers after colon
        std::vector<int64_t> numbers;
        std::istringstream iss(line.substr(colonPos + 1));
        std::string numStr;
        while (iss >> numStr) {
            numbers.push_back(std::stoll(numStr));
        }
        
        if (numbers.size() < 2) continue;
        
        // check if we can make the target
        if (canMakeTarget(target, numbers)) {
            totalCalibrationResult += target;
        }
    }

    return totalCalibrationResult;
}


int64_t Day07::solvePart2(const std::vector<std::string>& input) {
    // TODO: Implement solution for part 2
    return 0;
}

int main() {
    try {
        auto input = utils::FileReader::readLines("input.txt");
        
        std::cout << "Part 1: " << Day07::solvePart1(input) << std::endl;
        std::cout << "Part 2: " << Day07::solvePart2(input) << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}