#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include "generic_input.h"

#include<unordered_map>
#include<sstream>
#include <vector>

std::unordered_map<std::string,int> brute_force(std::vector<generic_input<std::string>> documents);


#endif