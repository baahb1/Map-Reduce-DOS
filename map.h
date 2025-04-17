#ifndef MAP_H
#define MAP_H

#include "generic_input.h"
#include <string>
#include <vector>
#include <mutex>
#include <sstream>
#include<unordered_map>

extern std::unordered_map<std::string, std::vector<int>> intermediate;
extern std::mutex emit_mutex;

void map(const generic_input<std::string>& document);

#endif
