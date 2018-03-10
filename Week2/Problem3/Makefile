CC:=g++

problem3: main.o timer.o sorter.o
	$(CC) $^ -o $@ -g

%.o: %.cpp
	$(CC) -c $< -std=c++11 -g


