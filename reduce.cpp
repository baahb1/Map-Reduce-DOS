#include "reduce.h"

std::unordered_map<std::string, int> reduce(const std::unordered_map<std::string, std::vector<int>>& grouped) {
    std::unordered_map<std::string, int> result;
    for (const auto& [key, values] : grouped) {
        int sum = 0;
        for (int v : values) sum += v;
        result[key] = sum;
    }
    return result;
}
