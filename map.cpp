#include "map.h"
#include <sstream>

std::vector<std::pair<std::string, int>> intermediate;
std::mutex emit_mutex;

void map(const generic_input<std::string>& document) {
    std::vector<std::pair<std::string, int>> local_pairs;
    std::stringstream ss(document.get_value());
    std::string word;

    while (ss >> word) {
        local_pairs.emplace_back(word, 1);
    }

    std::lock_guard<std::mutex> lock(emit_mutex);
    intermediate.insert(intermediate.end(), local_pairs.begin(), local_pairs.end());
}
