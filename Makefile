
all:
	$(CXX) -pthread -std=c++11 -Wall -Wextra TextSearch.cpp -o TextSearch

test:
	 ./TextSearch || exit 1
