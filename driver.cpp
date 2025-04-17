#include "generic_input.h"
#include "map.h"
#include "reduce.h"
#include "bruteforce.h"

#include <iostream>
#include <thread>
#include <unordered_map>
#include <chrono>
#include <cmath>

int main() {
    int num_nodes = 15;
    generic_input<std::string> base_doc("doc.txt",
        "hello this is a document this is another document hello world hello ");

    

    std::string temp_string = "";
    for (int i = 0; i < 10000; i++) {
        temp_string += "word ";
        temp_string += "hello ";
        temp_string += "third ";
        temp_string += "document ";
        temp_string += "class ";
        temp_string += "strings ";
    }

    generic_input<std::string> secondary_doc("doc.txt",temp_string);
    std::vector<generic_input<std::string>> documents;
    /*
    for (int i = 0; i < 50000; ++i) {
        documents.push_back(base_doc);
    }
    */

    for (int i = 0; i < 90; ++i) {
        documents.push_back(secondary_doc);
    }
    

    auto start_MR = std::chrono::high_resolution_clock::now();
    std::vector<std::thread> threads;
    for (const auto& doc : documents) {
        threads.emplace_back(map, doc);
    }

    for (auto& t : threads) {
        t.join();
    }threads.clear();
    
    std::unordered_map<std::string, std::vector<int>> sub_group;
    int intermediate_size = 0;
    for (auto i : intermediate) {
        intermediate_size += i.second.size();
    }
    
    float num_per_node = intermediate_size / num_nodes;
    int int_per_node = ::floor(num_per_node);
    int counter = 0;
    if (int_per_node < 1) {
        int_per_node = 1;
    }
    std::vector<int> temp;
    for (const auto& [key, value] : intermediate) {
        
        counter += value.size();
        if (counter >= int_per_node){
            int over = counter - value.size();
            std::vector<int> temp = value;
            sub_group[key].resize(over + 1);
            copy(temp.begin(), temp.begin() + over + 1, sub_group[key].begin());
            threads.emplace_back(reduce,sub_group);
            counter = value.size() - over;
            sub_group.clear();
            copy(temp.begin() + over, temp.end(), std::back_inserter(sub_group[key]));
            
        }
        else{
        sub_group[key] = value;
        }
    }
    if (counter > 0) {
        threads.emplace_back(reduce,sub_group);
    }

    for (auto& t : threads) {
        t.join();
    }
    threads.clear();
    
    auto stop_MR = std::chrono::high_resolution_clock::now();

    auto MR_time = std::chrono::duration_cast<std::chrono::microseconds>(stop_MR - start_MR);

    /*for (const auto& [word, count] : get_word_count()) {
        //std::cout << word << ": " << count << std::endl;
    }
    */
    for (const auto& [word, count] : word_count) {
        std::cout << word << ": " << count << std::endl;
    }
    

    
    auto start_BF = std::chrono::high_resolution_clock::now();
    auto brute_force_word_count = brute_force(documents);
    auto stop_BF = std::chrono::high_resolution_clock::now();

    auto BF_time = std::chrono::duration_cast<std::chrono::microseconds>(stop_BF - start_BF);

    std::cout<<"BF TIME : " << BF_time.count() <<std::endl;
    std::cout<<"MR TIME : " << MR_time.count() <<std::endl;
    

    return 0;
}
