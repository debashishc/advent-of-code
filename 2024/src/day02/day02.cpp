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
            continue;
        } 
        
        bool becomesSafe = false;

        // Check if removing one level makes it safe
        for (size_t j = 0; j < line.size(); j++) {
            bool isSafeWithRemoval = true;
            bool isIncreasingWithRemoval = false;

            // Determine the direction after removal
            if (line.size() >= 3) {
                if (j == 0) {
                    isIncreasingWithRemoval = line[2] > line[1];
                } else if (j == line.size() - 1) {
                    isIncreasingWithRemoval = line[line.size() - 1] > line[line.size() - 2];
                } else {
                    isIncreasingWithRemoval = line[j + 1] > line[j - 1];
                }
            } 

            for (size_t i = 0; i < line.size(); i++) {
                if (i == j) continue; // Skip the removed level

                int prev;
                if (i == j + 1) {
                    prev = (i - 2 >= 0) ? line[i - 2] : 0;
                } else {
                    prev = line[i - 1];
                }
                int curr = line[i];
                int diff = curr - prev;


                bool validDiff = abs(diff) >= 1 && abs(diff) <= 3;

                bool correctDirection = (isIncreasingWithRemoval && diff > 0) || (!isIncreasingWithRemoval && diff < 0);

                if (!validDiff || !correctDirection) {
                    isSafeWithRemoval = false;
                    break;
                }
            }

            if (isSafeWithRemoval) {
                becomesSafe = true;
                break;
            }
        }

        if (becomesSafe) {
            safeReports++;
        }
        
    }

    return safeReports;
}

int main() {
    try {
        auto input = utils::FileReader::readVariableColumnInts("input.txt");
        
        std::cout << "Part 1: " << Day02::solvePart1(input) << std::endl;
        std::cout << "Part 2: " << Day02::solvePart2(input) << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}