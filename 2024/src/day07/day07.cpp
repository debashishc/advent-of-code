#include "day07.hpp"
#include "fileReader.hpp"
#include <iostream>
#include <sstream>

// evaluate an expression with operators: '+', '*'
int64_t evaluateExpression(const std::vector<int64_t>& numbers, 
                           const std::vector<char>& operators) {
    int64_t result = numbers[0];
    
    for (size_t i = 0; i < operators.size(); i++) {
        if (operators[i] == '+') {
            result += numbers[i + 1];
        } else { // '*'
            result *= numbers[i + 1];
        }
    }
    
    return result;
}

int64_t concatenate(int64_t a, int64_t b) {
    std::string s1 = std::to_string(a);
    std::string s2 = std::to_string(b);
    return std::stoll(s1+s2);
}

// evaluate an expression with operators: '+', '*', '|'
int64_t evaluate(const std::vector<int64_t>& numbers, 
                           const std::vector<char>& operators) {
    std::vector<int64_t> vals = {numbers[0]}; 
    
    for (size_t i = 0; i < operators.size(); i++) {
        int64_t current = numbers[i+1];
        char op = operators[i];

        if (op == '+') {
            vals.back() += current;
        } else if (op == '*') {
            vals.back() += current;
        } else if (op == '|') {
            std::string num_string = std::to_string(current);
            vals.back() = vals.back() * std::pow(10, num_string.length()) + current;
        }
    }
    
    return vals.back();
}

// evaluate an expression with operators: '+', '*', '|'
int64_t evaluateExpression2(const std::vector<int64_t>& numbers, 
                           const std::vector<char>& operators) {
    int64_t result = numbers[0];
    
    for (size_t i = 0; i < operators.size(); i++) {
        if (operators[i] == '+') {
            result += numbers[i + 1];
        } else if (operators[i] == '*') { // '*'
            result *= numbers[i + 1];
        } else if (operators[i + 1] == '|') {
            result = concatenate(result, numbers[i + 1]);
        }
    }
    
    return result;
}


// generate all possible operator combinations to check target
bool canMakeTarget(int64_t target, const std::vector<int64_t>& numbers) {
    size_t numOperators = numbers.size() - 1;
    std::vector<char> operators(numOperators, '+');
    
    // all possible combinations of + and *
    for (size_t mask = 0; mask < (1ULL << numOperators); mask++) {
        // create operator combination based on bits in mask
        for (size_t i = 0; i < numOperators; i++) {
            operators[i] = (mask & (1ULL << i)) ? '*' : '+';
        }
        
        int64_t result = evaluateExpression(numbers, operators);
        if (result == target) {
            return true;
        }
    }
    
    return false;
}


bool canMakeTarget2(int64_t target, const std::vector<int64_t>& numbers) {
    //TODO: Need to add concatenate operator
    size_t numOperators = numbers.size() - 1;
    std::vector<char> operators(numOperators, '+');
    
    // all possible combinations of + and *
    for (size_t mask = 0; mask < (1ULL << numOperators); mask++) {
        // create operator combination based on bits in mask
        for (size_t i = 0; i < numOperators; i++) {
            operators[i] = (mask & (1ULL << i)) ? '*' : '+';
        }
        
        int64_t result = evaluateExpression(numbers, operators);
        if (result == target) {
            return true;
        }
    }
    
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
        if (canMakeTarget2(target, numbers)) {
            totalCalibrationResult += target;
        }
    }

    return totalCalibrationResult;
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