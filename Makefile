
all:
	$(CXX) -pthread -std=c++11 *.cpp *.h -o TextSearch

test:
	 ./TextSearch || exit 1
