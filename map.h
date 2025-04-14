#ifndef MAP_H
#define MAP_H

#include "generic_input.h"
#include <string>
#include <vector>
#include <mutex>

extern std::vector<std::pair<std::string, int>> intermediate;
extern std::mutex emit_mutex;

void map(const generic_input<std::string>& document);

#endif
