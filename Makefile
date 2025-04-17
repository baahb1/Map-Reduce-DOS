CXX = g++
CXXFLAGS = -std=c++17 -pthread

all: driver

driver: driver.cpp map.cpp reduce.cpp bruteforce.cpp
	$(CXX) $(CXXFLAGS) driver.cpp map.cpp reduce.cpp bruteforce.cpp -o driver.out

run: driver
	./driver.out

clean:
	rm -f driver.out
