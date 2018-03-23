
Lab07: main.o MinHeap.o MaxHeap.o
	g++ -g -std=c++11 -Wall main.o MinHeap.o MaxHeap.o -o Lab07

main.o:  MinHeap.h MaxHeap.h main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

MinHeap.o: MinHeap.h MinHeap.cpp
	g++ -g -std=c++11 -Wall -c MinHeap.cpp

MaxHeap.o: MaxHeap.h MaxHeap.cpp
	g++ -g -std=c++11 -Wall -c MaxHeap.cpp

clean:
	rm *.o Lab07
