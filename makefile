
Lab07: main.o MinHeap.o MaxHeap.o Node.o
	g++ -g -std=c++11 -Wall main.o MinHeap.o MaxHeap.o Node.o -o Lab07

main.o:  MinHeap.h MaxHeap.h  Node.h main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

MinHeap.o: MinHeap.h MinHeap.cpp Node.cpp Node.h
	g++ -g -std=c++11 -Wall -c MinHeap.cpp

MaxHeap.o: MaxHeap.h MaxHeap.cpp Node.cpp Node.h
	g++ -g -std=c++11 -Wall -c MaxHeap.cpp

Node.o: Node.cpp Node.h
	g++ -g -std=c++11 -Wall -c Node.cpp

clean:
	rm *.o Lab05
