CC:=g++

problem4: main.o timer.o unionfind.o
	$(CC) $^ -o $@ -g

%.o: %.cpp
	$(CC) -c $< -std=c++11 -g


