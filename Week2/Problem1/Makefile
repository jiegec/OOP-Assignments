CC:=g++

problem1: polynomial.o posynomial.o main.o timer.o
	$(CC) $^ -o $@ 

%.o: %.cpp
	$(CC) -c $< -std=c++11 


