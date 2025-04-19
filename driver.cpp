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
    //num nodes acts to limit the maximum number of threads and is used to balance based in intermediate files
    int num_nodes = 15;

    //this is our generic doc object creation. the dox.txt title is pretty much irrelivent, but if we wanted to impliment it over a file system that is how it would be done.
    generic_input<std::string> base_doc("doc.txt",
        "hello this is a document this is another document hello world hello ");

    //fills our base doc up with a really long set of words.
    std::string temp_string = "";
    for (int i = 0; i < 10000; i++) {
        temp_string += "word ";
        temp_string += "hello ";
        temp_string += "third ";
        temp_string += "document ";
        temp_string += "class ";
        temp_string += "strings ";
    }

    //this is the doc object we used for the newer sets of testing. we have two because there was a bit of mixed document testing.
    generic_input<std::string> secondary_doc("doc.txt",temp_string);
    std::vector<generic_input<std::string>> documents;
    for (int i = 0; i < 90; ++i) {
        documents.push_back(secondary_doc);
    }
    
    //this is the start of the timer for the Map Reduce Starting.
    auto start_MR = std::chrono::high_resolution_clock::now();

    //This creates a vector of threads (our analog to clusters) and starts assigning the map function to our "documents"
    std::vector<std::thread> threads;
    for (const auto& doc : documents) {
        threads.emplace_back(map, doc);
    }

    //Wait for all of our threads to finish
    for (auto& t : threads) {
        t.join();
    }threads.clear();
    
    //this is how we manage our intermediaries into logically coherent sub groups
    std::unordered_map<std::string, std::vector<int>> sub_group;
    int intermediate_size = 0;
    for (auto i : intermediate) {
        intermediate_size += i.second.size();
    }
    
    // this is how we balance our load between the different workers
    float num_per_node = intermediate_size / num_nodes;
    int int_per_node = ::floor(num_per_node);
    int counter = 0;
    if (int_per_node < 1) {
        int_per_node = 1;
    }
    std::vector<int> temp;
    for (const auto& [key, value] : intermediate) {
        
        counter += value.size();
        //we create sub groups of the maximum size that will fit across the sub groups evenly
        if (counter >= int_per_node){
            int over = counter - value.size();
            std::vector<int> temp = value;
            sub_group[key].resize(over + 1);
            copy(temp.begin(), temp.begin() + over + 1, sub_group[key].begin());
            //creates our next set of threads
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

    //waits for threads to finish and joins back to master.
    for (auto& t : threads) {
        t.join();
    }
    threads.clear();
    //finishes the timer for map reduce
    auto stop_MR = std::chrono::high_resolution_clock::now();
    auto MR_time = std::chrono::duration_cast<std::chrono::microseconds>(stop_MR - start_MR);

    //This prints out the total word count at the end. This is just for us to verify that map and reduce are being assigned correctly without missing any content
    for (const auto& [word, count] : word_count) {
        std::cout << word << ": " << count << std::endl;
    }
    

    //This times the brute force solution
    auto start_BF = std::chrono::high_resolution_clock::now();
    auto brute_force_word_count = brute_force(documents);
    auto stop_BF = std::chrono::high_resolution_clock::now();
    auto BF_time = std::chrono::duration_cast<std::chrono::microseconds>(stop_BF - start_BF);

    //This compares our BF vs MR time. Very neat to play around with different document sizes, num nodes, etc.
    std::cout<<"BF TIME : " << BF_time.count() <<std::endl;
    std::cout<<"MR TIME : " << MR_time.count() <<std::endl;
    

    return 0;
}
