#include "day01.hpp"
// #include "fileReader.hpp"
#include <iostream>
#include <unordered_map>

int64_t Day01::solvePart1(const utils::TwoColumnData& input) {
    // TODO: implement part 1
    auto left_list = input.left_column;
    auto right_list = input.right_column;

    std::sort(left_list.begin(), left_list.end());
    std::sort(right_list.begin(), right_list.end());

    int64_t total_distance = 0;
    for (size_t i = 0; i < left_list.size(); ++i) {
        total_distance += std::abs(left_list[i] - right_list[i]);
    }

    return total_distance;
}

int64_t Day01::solvePart2(const utils::TwoColumnData& input) {
    // TODO: implement part 2
    auto left_list = input.left_column;
    std::unordered_map<int, int> counter;

    int64_t similarity_score = 0;

    for (auto& num : input.right_column) {
        counter[num]++;
    }

    for (auto& num : left_list) {
        similarity_score += num * counter[num];
    }

    return similarity_score;
}

int main() {
    try {
        auto input = utils::FileReader::readTwoColumnInts("input.txt");
        
        // Verify input has equal number of elements in both columns
        if (input.left_column.size() != input.right_column.size()) {
            throw std::runtime_error("Input columns have different sizes");
        }
        
        // Print descriptive headers
        std::cout << "\n=== Day 1 Solutions ===\n";
        
        // Print debugging information
        std::cout << "Input size: " << input.left_column.size() << " pairs\n";
        
        // Print solutions with descriptive labels
        auto part1_result = Day01::solvePart1(input);
        std::cout << "\nPart 1 Solution: " << part1_result << std::endl;
        
        auto part2_result = Day01::solvePart2(input);
        std::cout << "Part 2 Solution: " << part2_result << std::endl;
        
        std::cout << "\n===================\n";
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}