#include "reduce.h"

std::unordered_map<std::string, int> word_count;
/*std::unordered_map<std::string, int> reduce(const std::unordered_map<std::string, std::vector<int>>& grouped) {
    std::unordered_map<std::string, int> result;
    for (const auto& [key, values] : grouped) {
        int sum = 0;
        for (int v : values) sum += v;
        result[key] = sum;
    }
    
    return result;
}
*/

std::unordered_map<std::string, int> get_word_count(){return word_count;}

void reduce(const std::unordered_map<std::string, std::vector<int>>& intermediate_set) {
    std::unordered_map<std::string, int> result;
    for (const auto& [key, values] : intermediate_set) {
        int sum = 0;
        for (int v : values) sum += v;
        word_count[key] = sum;
    }
}