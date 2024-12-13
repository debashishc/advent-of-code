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

bool isValidSequence(const std::vector<int>& seq, bool increasing) {
    for (size_t i = 1; i < seq.size(); i++) {
        int diff = seq[i] - seq[i-1];
        if (increasing) {
            if (diff <= 0 || diff > 3) return false;
        } else {
            if (diff >= 0 || diff < -3) return false;
        }
    }
    return true;
}

bool isSequenceSafe(const std::vector<int>& seq) {
    if (seq.size() < 2) return true;
    
    // Try both increasing and decreasing
    return isValidSequence(seq, true) || isValidSequence(seq, false);
}


int64_t Day02::solvePart2(const utils::VariableColumnData& input) {
    auto rows = input.columns;
    int safeReports = 0;

    for (const auto& line : rows) {
        // First check if already safe
        if (isSequenceSafe(line)) {
            safeReports++;
            continue;
        }

        // Try removing each number
        for (size_t skip = 0; skip < line.size(); skip++) {
            std::vector<int> modified;
            modified.reserve(line.size() - 1);
            
            // Create sequence without the skipped number
            for (size_t i = 0; i < line.size(); i++) {
                if (i != skip) {
                    modified.push_back(line[i]);
                }
            }

            if (isSequenceSafe(modified)) {
                safeReports++;
                break;
            }
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