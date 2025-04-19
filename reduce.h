#ifndef REDUCE_H
#define REDUCE_H

#include <string>
#include <unordered_map>
#include <vector>

extern std::unordered_map<std::string, int> word_count;
std::unordered_map<std::string, int> get_word_count();
void reduce(const std::unordered_map<std::string, std::vector<int>>& grouped);

#endif
