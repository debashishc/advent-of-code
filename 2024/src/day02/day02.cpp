#include "day02.hpp"
// #include "fileReader.hpp"
#include <iostream>
#include <string>
#include <sstream>

int64_t Day02::solvePart1(const utils::VariableColumnData& input) {
    // TODO: Implement solution for part 1
    auto rows = input.columns;
    int safeReports = 0;

    for (const auto& line : rows) {
        bool isSafe = true;
        bool isIncreasing = false;

        if (line.size() >= 2) {
            isIncreasing = line[1] > line[0];
        }

        for (size_t i = 1; i < line.size(); i++) {
            int diff = line[i] - line[i-1];
            bool validDiff = abs(diff) >= 1 && abs(diff) <= 3;

            bool correctDirection = (isIncreasing && diff > 0) || (!isIncreasing && diff < 0);
            
            if (!validDiff || !correctDirection) {
                isSafe = false;
                break;
            }
        }

        if (isSafe) {
            safeReports++;
        }

    }

    return safeReports;
}

int64_t Day02::solvePart2(const utils::VariableColumnData& input) {
    // TODO: Implement solution for part 2
    return 0;
}

int main() {
    try {
        auto input = utils::FileReader::readVariableColumnInts("input.txt");
        
        std::cout << "Part 1: " << Day02::solvePart1(input) << std::endl;
        // std::cout << "Part 2: " << Day02::solvePart2(input) << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}