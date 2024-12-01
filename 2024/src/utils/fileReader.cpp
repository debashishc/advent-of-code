#include "fileReader.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace utils {
    std::string FileReader::readFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + filename);
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    std::vector<std::string> FileReader::readLines(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + filename);
        }

        std::vector<std::string> lines;
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        return lines;
    }

    std::vector<int> FileReader::readLinesAsInts(const std::string& filename) {
        std::vector<std::string> lines = readLines(filename);
        std::vector<int> numbers;
        numbers.reserve(lines.size());

        for (const auto& line : lines) {
            numbers.push_back(std::stoi(line));
        }
        return numbers;
    }

    TwoColumnData FileReader::readTwoColumnInts(const std::string& filename) {
        TwoColumnData data;
        std::vector<std::string> lines = readLines(filename);

        for (const auto& line : lines) {
            std::istringstream iss(line);
            int left, right;

            if (iss >> left >> right) {
                data.left_column.push_back(left);
                data.right_column.push_back(right);
            }
        }

        return data;
    }
}