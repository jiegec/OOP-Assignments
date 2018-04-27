CXX:=g++

main: main.o
	$(CXX) $^ -o $@ 

%.o: %.cpp
	$(CXX) -c $< -std=c++11 -g

