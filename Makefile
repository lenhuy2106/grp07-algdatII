
all:
	$(CXX) -pthread -std=c++11 -Wall -Wextra main.cpp -o main

test:
	 ./main || exit 1
