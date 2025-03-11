#ifndef GENERIC_INPUT_H
#define GENERIC_INPUT_H

#include <string>

template <class T> 
class generic_input
{
private:
    std::string key;
    T value;
public:
    generic_input(){};

    generic_input(std::string key, T value);
    ~generic_input();
    

    std::string get_key(){
        return key;
    }
    T get_value(){
        return value;
    }

    void set_key(std::string key){
        this->key = key;
    }
    void set_value(T value){
        this->value = value;
    }
};


template <class T>
generic_input<T>::generic_input(std::string key, T value)
{
    this->key = key;
    this->value = value;
}

template <class T>
generic_input<T>::~generic_input()
{
}

#endif
