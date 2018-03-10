CC:=g++

problem2: main.o review_assigner.o
	$(CC) $^ -o $@ 

%.o: %.cpp
	$(CC) -c $< -std=c++11 -g


