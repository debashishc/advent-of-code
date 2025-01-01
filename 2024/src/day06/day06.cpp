#include "day06.hpp"
#include "fileReader.hpp"
#include <iostream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <functional>
// #include <iostream>
#include <sstream>

struct PairHash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

int64_t Day06::solvePart1(const std::vector<std::string>& input) {
    // TODO: Implement solution for part 1
        int rows = input.size();
    int cols = input[0].size();
    std::pair<int, int> guardPos;
    std::vector<std::pair<int, int>> directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // Up, Right, Down, Left
    int currentDir = 0; // Start facing up (index 0 in directions)

    // Locate guard's starting position and direction
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (input[r][c] == '^') {
                guardPos = {r, c};
                currentDir = 0; // Up
            } else if (input[r][c] == '>') {
                guardPos = {r, c};
                currentDir = 1; // Right
            } else if (input[r][c] == 'v') {
                guardPos = {r, c};
                currentDir = 2; // Down
            } else if (input[r][c] == '<') {
                guardPos = {r, c};
                currentDir = 3; // Left
            }
        }
    }

    // Track visited positions
    std::unordered_set<std::pair<int, int>, PairHash> visited;
    visited.insert(guardPos);

    // Simulate the guard's movement
    while (true) {
        int nextRow = guardPos.first + directions[currentDir].first;
        int nextCol = guardPos.second + directions[currentDir].second;

        // Check if out of bounds
        if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols) {
            break;
        }

        // Check if there is an obstacle
        if (input[nextRow][nextCol] == '#') {
            currentDir = (currentDir + 1) % 4; // Turn right
        } else {
            // Move forward
            guardPos = {nextRow, nextCol};
            visited.insert(guardPos);
        }
    }

    return visited.size();
}

int64_t Day06::solvePart2(const std::vector<std::string>& input) {
    // TODO: Implement solution for part 2
    return 0;
}

int main() {
    try {
        auto input = utils::FileReader::readLines("input.txt");
        
        std::cout << "Part 1: " << Day06::solvePart1(input) << std::endl;
        std::cout << "Part 2: " << Day06::solvePart2(input) << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}