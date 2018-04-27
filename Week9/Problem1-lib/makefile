CXX:=g++

maze: maze.a main.o OptRouter.cpp
	$(CXX) $^ -std=c++11 -o $@ 

%.o: %.cpp
	$(CXX) -c $< -std=c++11 -g

.PHONY: clean
clean:
	rm *.o maze
