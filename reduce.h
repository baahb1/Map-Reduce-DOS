#ifndef REDUCE_H
#define REDUCE_H

#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<std::string, int> reduce(const std::unordered_map<std::string, std::vector<int>>& grouped);

#endif
