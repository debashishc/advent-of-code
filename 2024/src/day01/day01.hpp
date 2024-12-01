#pragma once
#include <string>
#include <vector>
#include "fileReader.hpp"  // Include this to get TwoColumnData definition

class Day01 {
public:
    static int64_t solvePart1(const utils::TwoColumnData& input);
    static int64_t solvePart2(const utils::TwoColumnData& input);
};
