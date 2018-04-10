CXX:=g++

mst: mst.o main.o graph.o
	$(CXX) $^ -o $@ 

%.o: %.cpp
	$(CXX) -c $< -std=c++11 -g

.PHONY: test
test: mst
	./mst gen

