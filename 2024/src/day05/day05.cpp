#include "day05.hpp"
#include "fileReader.hpp"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
// #include <iostream>
#include <sstream>

void parseInput(const std::vector<std::string>& input,
                std::unordered_map<int, std::unordered_set<int>>& rules,
                std::vector<std::vector<int>>& updates) {
    
    bool isRules = true;

    for (const auto& line : input) {
        if (line.empty()) {
            isRules = false;
            continue;
        }

        if (isRules) {
            std::istringstream iss(line);
            int before, after;
            char delimiter;
            iss >> before >> delimiter >> after;
            rules[before].insert(after);
        } else {
            std::vector<int> update;
            std::istringstream iss(line);
            int page;
            while (iss >> page) {
                if (iss.peek() == ',') iss.ignore();
                update.push_back(page);
            }
            updates.push_back(update);
        }
    }
};


int64_t Day05::solvePart1(const std::vector<std::string>& input) {
    // TODO: Implement solution for part 1
    int64_t countMiddlePages = 0;

    std::unordered_map<int, std::unordered_set<int>> rules;
    std::vector<std::vector<int>> updates;



    return countMiddlePages;
}

int64_t Day05::solvePart2(const std::vector<std::string>& input) {
    // TODO: Implement solution for part 2
    return 0;
}

int main() {
    try {
        auto input = utils::FileReader::readLines("input.txt");
        
        std::cout << "Part 1: " << Day05::solvePart1(input) << std::endl;
        std::cout << "Part 2: " << Day05::solvePart2(input) << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}