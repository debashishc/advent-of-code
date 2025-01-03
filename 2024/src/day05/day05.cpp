#include "day05.hpp"
#include "fileReader.hpp"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
// #include <iostream>
#include <sstream>

// parse rules and updates
// first section is page ordering rules, one per line
// second section specifies the page number of each update
void parseInput(const std::vector<std::string>& input,
                std::unordered_map<int, std::unordered_set<int>>& rules,
                std::vector<std::vector<int>>& updates) {
    
    bool isRules = true;

    for (const auto& line : input) {
        if (line.empty()) {
            isRules = false;
            continue;
        }
        if (isRules) { // rules separated like before | after
            std::istringstream iss(line);
            int before, after;
            char delimiter;
            iss >> before >> delimiter >> after;
            rules[before].insert(after);
        } else { // update pages are comma separated
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
}

// check if a single update is in the correct order
bool isValidOrder(const std::vector<int>& update,
                    const std::unordered_map<int, std::unordered_set<int>>& rules) {
    
    std::unordered_map<int, int> positions;
    for (size_t i = 0; i < update.size(); ++i) {
        positions[update[i]] = i;
    }

    for (const auto& [before, afterSet]: rules) {
        if (positions.count(before)) {
            int beforePos = positions[before];
            for (int after : afterSet) {
                if (positions.count(after)) {
                    int afterPos = positions[after];
                    if (beforePos >= afterPos) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}


int64_t Day05::solvePart1(const std::vector<std::string>& input) {
    // TODO: Implement solution for part 1
    int64_t sumMiddlePages = 0;

    std::unordered_map<int, std::unordered_set<int>> rules;
    std::vector<std::vector<int>> updates;

    parseInput(input, rules, updates);

    for (const auto& update: updates) {
        if (isValidOrder(update, rules)) {
            sumMiddlePages += update[update.size() / 2];
        }
    }
    return sumMiddlePages;
}

std::vector<int> _topologicalSort(const std::vector<int>& update,
                                        const std::unordered_map<int, std::unordered_set<int>>& rules) {
    std::vector<int> sortedPages;
    std::unordered_map<int, int> inDegree;
    std::unordered_map<int, std::vector<int>> graph;
    for (int page : update) {
        inDegree[page] = 0;
    }
    for (const auto& [before, afterSet] : rules) {
        if (inDegree.count(before)) {
            for (int after : afterSet) {
                if (inDegree.count(after)) {
                    graph[before].push_back(after);
                    inDegree[after]++;
                }
            }
        }
    }

    std::queue<int> q;
    for (const auto& [page, degree] : inDegree) {
        if (degree == 0) {
            q.push(page);
        }
    }

    while (!q.empty()) {
        int current = q.front();
        sortedPages.push_back(current);
        q.pop();
    
        for (int neighbour : graph[current]) {
            if (--inDegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }

    }

    return sortedPages;
}

int64_t Day05::solvePart2(const std::vector<std::string>& input) {
    // TODO: Implement solution for part 2
    int64_t sumMiddlePages = 0;
    std::unordered_map<int, std::unordered_set<int>> rules;
    std::vector<std::vector<int>> updates;

    // std::vector<std::vector<int>> reorderedUpdates;

    parseInput(input, rules, updates);

    for (const auto& update : updates) {
        // add reordered updates
        if (!isValidOrder(update, rules)) {
            auto reorderedUpdate = _topologicalSort(update, rules);
            sumMiddlePages += reorderedUpdate[reorderedUpdate.size() / 2];
        }
    }

    return sumMiddlePages;

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