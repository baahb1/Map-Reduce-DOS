#include "generic_input.h"
#include "map.h"
#include "reduce.h"

#include <iostream>
#include <thread>
#include <unordered_map>

int main() {
    generic_input<std::string> base_doc("doc.txt",
        "hello this is a document this is another document hello world hello");

    std::vector<generic_input<std::string>> documents;
    for (int i = 0; i < 5; ++i) {
        documents.push_back(base_doc);
    }

    std::vector<std::thread> threads;
    for (const auto& doc : documents) {
        threads.emplace_back(map, doc);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::unordered_map<std::string, std::vector<int>> grouped;
    for (const auto& [key, value] : intermediate) {
        grouped[key].push_back(value);
    }

    auto final_result = reduce(grouped);

    for (const auto& [word, count] : final_result) {
        std::cout << word << ": " << count << std::endl;
    }

    return 0;
}
