#pragma once
#include <string>
#include <vector>

namespace utils {

    struct TwoColumnData{
        std::vector<int> left_column;
        std::vector<int> right_column;
    };

    struct VariableColumnData{
        std::vector<std::vector<int>> columns;
    };
    
    class FileReader {
    public:
        static std::string readFile(const std::string& filename);
        static std::vector<std::string> readLines(const std::string& filename);
        static std::vector<int> readLinesAsInts(const std::string& filename);
        static TwoColumnData readTwoColumnInts(const std::string& filename);
        static VariableColumnData readVariableColumnInts(const std::string& filename);
    };
}