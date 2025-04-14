CXX = g++
CXXFLAGS = -std=c++17 -pthread

all: driver

driver: driver.cpp map.cpp reduce.cpp
	$(CXX) $(CXXFLAGS) driver.cpp map.cpp reduce.cpp -o driver.out

run: driver
	./driver.out

clean:
	rm -f driver.out
