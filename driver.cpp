#include "generic_input.h"
#include <iostream>
#include <sstream>
#include <thread>
#include <vector>
using namespace std;


vector<generic_input<int>> map_vector = {};
int mv_lock = 0;




//map function will split 
template <typename T>
void map(generic_input<T> document, int (*f)(generic_input<T>)){
    int val_count = f(document);
    
    for (auto i = 0; i < map_vector.size(); i++)
    {
        if (map_vector[i].get_key() == document.get_key())
        {
            while (mv_lock != 0)
            {
            }
            mv_lock = 1;
            map_vector[i].set_value(map_vector[i].get_value() + val_count);
            cout<<val_count;
            mv_lock = 0;
        }
    }   
}

int word_count_function(generic_input<string> document){
    if (document.get_value().size() == 0)
    {
        return 0;
    }

    string temp = "";
    int count = 1;

    stringstream string_input(document.get_value());

    while (getline(string_input,temp,' '))
    {
        count +=1;
    }
    
    return count;
}

int main(int argc, char const *argv[])
{

    // example where the map function is applied to a document class, as in the example in the paper. document can be replaced with a process with the generic class, possibly using windows handles

    generic_input<string> document("document.txt","hello\n this is my document\n this is more document, words words. hello the quick yellow fox hops the fence. This is a document");
    generic_input<string>* inputs;

    vector<generic_input<string>> documents;
    inputs = new generic_input<string>[10];
    for (int i = 0; i < 10; i++)
    {
        documents.push_back(document);
    }

    
    
    
    generic_input<int> ICG = generic_input<int>(documents[0].get_key(),0);
    map_vector.push_back(ICG);

    for (int i = 0; i < 10; i++)
    {
        map(documents[i],word_count_function);
    }



    std::cout << map_vector[0].get_key() << " | " << map_vector[0].get_value();

    return 0;
}