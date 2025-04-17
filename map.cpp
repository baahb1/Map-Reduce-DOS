#include "map.h"


std::unordered_map<std::string, std::vector<int>> intermediate;
std::mutex emit_mutex;

void map(const generic_input<std::string>& document) {
    std::unordered_map<std::string, std::vector<int>> local_pairs;
    std::stringstream ss(document.get_value());
    std::string word;

    while (ss >> word) {
        local_pairs[word].emplace_back(1);
    }

    std::lock_guard<std::mutex> lock(emit_mutex);
    for (const auto& [key, value] : local_pairs)
    {
        intermediate[key].insert(intermediate[key].end(), local_pairs[key].begin(), local_pairs[key].end());
    }
    
    
}
