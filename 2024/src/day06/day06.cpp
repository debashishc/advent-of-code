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
    int rows = input.size();
    int cols = input[0].size();
    std::pair<int, int> guardPos;
    std::vector<std::pair<int, int>> directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // Up, Right, Down, Left
    int startDir = 0;
    
    // Locate guard's starting position and direction
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (input[r][c] == '^') {
                guardPos = {r, c};
                startDir = 0; // Up
            } else if (input[r][c] == '>') {
                guardPos = {r, c};
                startDir = 1; // Right
            } else if (input[r][c] == 'v') {
                guardPos = {r, c};
                startDir = 2; // Down
            } else if (input[r][c] == '<') {
                guardPos = {r, c};
                startDir = 3; // Left
            }
        }
    }

    auto causesLoop = [&](std::pair<int, int> newObstacle) -> bool {
        struct StateHash {
            std::size_t operator()(const std::pair<std::pair<int, int>, int>& state) const {
                return std::hash<int>()(state.first.first) ^ 
                       std::hash<int>()(state.first.second) ^ 
                       std::hash<int>()(state.second);
            }
        };

        using State = std::pair<std::pair<int, int>, int>;
        std::unordered_set<State, StateHash> visited;
        
        State current = {{guardPos.first, guardPos.second}, startDir};
        visited.insert(current);
        
        // Use a smaller maximum step count - just enough to find a reasonable loop
        const size_t maxSteps = static_cast<size_t>(rows + cols) * 4;
        size_t steps = 0;
        
        while (steps < maxSteps) {  // Changed from while(true)
            auto [pos, dir] = current;
            int nextRow = pos.first + directions[dir].first;
            int nextCol = pos.second + directions[dir].second;
            
            // Check bounds
            if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols) {
                return false;
            }
            
            // Check obstacles
            if (input[nextRow][nextCol] == '#' || std::make_pair(nextRow, nextCol) == newObstacle) {
                // Turn right
                int newDir = (dir + 1) % 4;
                current = {pos, newDir};
            } else {
                // Move forward
                State newState = {{nextRow, nextCol}, dir};
                
                if (visited.count(newState)) {
                    // We found a loop before hitting max steps
                    return true;
                }
                visited.insert(newState);
                current = newState;
            }
            
            ++steps;
        }
        
        return false;  // We hit max steps without finding a loop
    };

    int validObstructionCount = 0;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            std::pair<int, int> candidateObstacle = {r, c};
            if (candidateObstacle == guardPos || input[r][c] == '#') {
                continue;
            }
            if (causesLoop(candidateObstacle)) {
                ++validObstructionCount;
            }
        }
    }
    
    return validObstructionCount;
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