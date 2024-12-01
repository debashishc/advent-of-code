#pragma once
#include <string>
#include <vector>

namespace utils {
    class FileReader {
    public:
        static std::string readFile(const std::string& filename);
        static std::vector<std::string> readLines(const std::string& filename);
        static std::vector<int> readLinesAsInts(const std::string& filename);
    };
}