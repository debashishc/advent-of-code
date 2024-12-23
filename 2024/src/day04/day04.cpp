#include "day04.hpp"
#include "fileReader.hpp"
#include <iostream>

int64_t Day04::solvePart1(const std::vector<std::string>& input) {
    // TODO: Implement solution for part 1
    const std::string word = "XMAS";
    int64_t count = 0;
    
    const int wordLength = word.length();
    const size_t rows = input.size();
    const size_t cols = input[0].size();
    
    // possible directions to search for the word
    const std::vector<std::pair<int, int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1,0},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };

    auto isValid = [&](int r, int c, int dr, int dc) {
        for (int i = 0; i < wordLength; ++i) {
            int nr = r + dr * i;
            int nc = c + dc * i;
            if (nr < 0 || nc < 0 || 
                nr >= rows || nc >= cols ||
                input[nr][nc] != word[i]) {
                    return false;
                }
        }
        return true;
    };

    for (size_t r = 0; r < rows; ++r) {
        for (size_t c = 0; c < cols; ++c) {
            for (const auto& [dr, dc] : directions) {
                if (isValid(r, c, dr, dc)) {
                    ++count;
                }
            }
        }
    }
    
    return count;
}

int64_t Day04::solvePart2(const std::vector<std::string>& input) {
    int64_t count = 0;
    int rows = input.size();
    int cols = input[0].size();

    auto isMas = [](char a, char b, char c) -> bool {
        return (a == 'M' && b == 'A' && c == 'S') ||
        (a == 'S' && b == 'A' && c == 'M');
    };

    for (int r = 1; r < rows - 1; ++r) {
        for (int c = 1; c < cols - 1; ++c) {
            if (input[r][c] == 'A') {
                if (isMas(input[r - 1][c - 1], input[r][c], input[r + 1][c + 1]) &&
                isMas(input[r - 1][c + 1], input[r][c], input[r + 1][c - 1])) {
                    count++;
                }
            }
        }
    }

    return count;
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