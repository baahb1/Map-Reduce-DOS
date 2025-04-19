#include "reduce.h"
//example reduce program for the word count example
std::unordered_map<std::string, int> word_count;
std::unordered_map<std::string, int> get_word_count(){return word_count;}

void reduce(const std::unordered_map<std::string, std::vector<int>>& intermediate_set) {
    std::unordered_map<std::string, int> result;
    for (const auto& [key, values] : intermediate_set) {
        int sum = 0;
        for (int v : values) sum += v;
        word_count[key] = sum;
    }
}