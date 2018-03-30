CC:=g++

mst: mst.o main.o graph.o
	$(CC) $^ -o $@ 

%.o: %.cpp
	$(CC) -c $< -std=c++11 -g

.PHONY: test
test: mst
	./mst > mst.dot && dot -Kfdp -n -Tpng -o mst.png mst.dot && open mst.png


