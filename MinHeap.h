/*
 Author: Jan Polzer
 File:   minHeap.h
 Date:   3/12/2018
 */

#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "Heap.h"
#include <iostream>
#include <queue>
#include <math.h>

class MinHeap{ // TODO ////////////////////////////////////////////////}: public Heap {

public:
    MinHeap();
    ~MinHeap();

    // @pre:    None
    // @Post:   Heap
    // @Return: None
    void buildheap();

    // @pre:    5 - minHeap
    // @Post:   Inserted a new element
    // @Return: None
    void insert(int key);

    // // @pre:    5 - minHeap
    // // @post:   deleted passed key
    // // @return: True if deleted, false otherwise
    // bool delete(int key);

    // @pre:    5 - minHeap
    // @post:   deleted min key
    // @return: None
    void deletemin();

    // @pre:    5 - minHeap
    // @post:   deleted max key
    // @return: None
    void deletemax();

    // @pre:    5 - minHeap
    // @post:   Found the smallest element in the 5 - minHeap
    // @return: A pointer to teh smallest element, nullptr if not found.
    int findmin();

    // @pre:    5 - minHeap
    // @post:   Found the largest element in the 5 - minHeap
    // @return: A pointer to the largest element, nullptr if not found.
    int findmax();

    // // @pre:    5 - minHeap
    // // @post:   Found the element with key in the minHeap
    // // @return: True if element was in minHeap, false if not found.
    // element *find(int key);

    // @pre:    5 - minHeap
    // @post:   Printed out all the elements of the min heap by level  using levelorder traversal.
    // @return: None
    void levelorder();

    // @pre:    5 - minHeap
    // @post:   element.
    // @return: True if element is a leaf, false otherwise
    bool isLeaf(int index);
    void swap(int index1, int index2);
    void heapify(int index);
    int childOf(int index, int atPosition);
    int minChild(int parent);
    int parentOf(int index);
    
private:
    int m_array[500];
    int m_size;
    static const int M_K = 5; // for K-ary heap (5-heap)
    
    
    // @pre:    5 - minHeap
    // @post:   Found the largest index of element in the 5 - minHeap
    // @return: The index of the largest element
    int findmaxindex();
    
    //
    //    // @pre:    5 - minHeap
    //    // @post:   Printed keys in level traversal
    //    // @return: None
    //    void levelorderhelper(element *root);
    //
    //    // @pre:    5 - minHeap
    //    // @post:   Serching in root
    //    // @return: element pointer of element to be found
    //    element *findminhelper(element *root);
    //
    //    // @pre:    5 - maxHeap
    //    // @post:   Searching in root
    //    // @return: element pointer of element to be found
    //    element *findmaxhelper(element *root);
    //
    //    // @pre:    5 - minHeap
    //    // @post:   Found element from the minHeap
    //    // @return: True if found, false otherwise
    //    element *findhelper(int key, element *root);
    //
    //    // @pre:    5 - minHeap
    //    // @post:   deleted element from the minHeap
    //    // @return: True if deleted, false otherwise
    //    bool deletehelper(int key, element *root);
};

#endif
