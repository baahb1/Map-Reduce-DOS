#include "bruteforce.h"


std::unordered_map<std::string,int> brute_force(std::vector<generic_input<std::string>> documents){
    std::unordered_map<std::string,int> brute_force_word_count;
    std::string word;
    for (const auto& docs : documents)
    {
        std::stringstream ss(docs.get_value());
        while (ss >> word)
        {
            
            brute_force_word_count[word] +=1;
        }
    }
    return brute_force_word_count;
}