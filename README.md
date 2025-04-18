# Map-Reduce-DOS

This program is written as the final projet of Tennessee Techological University's Distributed Operating Systems class taught by Mike Rogers.
Authors: Hunter Sawyer, Sankalpa Timilsina 

This programs is a small single system reconstruction of a map reduce project shown in the paper titled "MapReduce: Simplified Data Processing
on Large Clusters". 
Dean, J., & Ghemawat, S. (2008). MapReduce: simplified data processing on large clusters. Communications of the ACM, 51(1), 107-113.

The program uses the word count example in the paper as the map and reduce combination for implimentation.

# File Description
The program consists of 6 files containing code:

Driver.cpp

  -The main file responsible for managing thread spin up (The equivilant of working across clusters for or single system example), intermediate to reduce mappings, map assignments, speed measurements, a brute force solution for comparison, and initiazation of the sample document classes.
  
Generic_input.h
A generic class allowing key: value mapping, so that this program can be more easily adapted to different data types for differeing map - reduce goals

Map.cpp and Map.h

  The class responsible for creating the intermediates is stored in these two files. The one written by us is the specific example from the paper, but so long as the conventions set out by the Driver are followed, this should be easily replacable.
Reduce.cpp and Reduce.h

  The class responsible for re-merging the data. It once again follows the example conventions from the map reduce paper, but as long as conventions are followed, can be swapped out.

and 3 other files
.gitignore
  -ignores .exe and .out
  
Makefile
  -contains compilation instructions
  
README.md
  -This file
