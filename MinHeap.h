/*
 Author: Jan Polzer
 File:   minHeap.h
 Date:   3/12/2018
 */

#ifndef min_HEAP_H
#define min_HEAP_H

#include "Heap.h"
#include <iostream>
#include <queue>

class MinHeap: public Heap {
    
private:
    int m_array[250];
    
//    // @pre:    5 - minHeap
//    // @post:   inserting node in root
//    // @return: Node pointer of element to be inserted
//    void inserthelper(int key, Node *root);
//
//    // @pre:    5 - minHeap
//    // @post:   Printed keys in level traversal
//    // @return: None
//    void levelorderhelper(Node *root);
//
//    // @pre:    5 - minHeap
//    // @post:   Serching in root
//    // @return: Node pointer of element to be found
//    Node *findminhelper(Node *root);
//
//    // @pre:    5 - maxHeap
//    // @post:   Searching in root
//    // @return: Node pointer of element to be found
//    Node *findmaxhelper(Node *root);
//
//    // @pre:    5 - minHeap
//    // @post:   Found node from the minHeap
//    // @return: True if found, false otherwise
//    Node *findhelper(int key, Node *root);
//
//    // @pre:    5 - minHeap
//    // @post:   deleted node from the minHeap
//    // @return: True if deleted, false otherwise
//    bool deletehelper(int key, Node *root);
    
public:
    MinHeap();
    ~MinHeap();
    
    // @pre:    No three
    // @Post:   Unsorted full tree
    // @Return: Node
    void buildheap(int data[], int size);
    
    // @pre:    5 - minHeap
    // @Post:   New node inserted into the minHeap:    as root if empty,
    //                                              as first node if key is smaller then root key
    //                                              as third node if key is larger then root key
    //                                              as second otherwise
    // @Return: True if success, false otherwise
    bool insert(int key);
    
    // // @pre:    5 - minHeap
    // // @post:   deleted passed key
    // // @return: True if deleted, false otherwise
    // bool delete(int key);
    
    // @pre:    5 - minHeap
    // @post:   deleted min key
    // @return: True if deleted, false otherwise
    bool deletemin();
    
    // @pre:    5 - minHeap
    // @post:   deleted max key
    // @return: True if deleted, false otherwise
    bool deletemax();
    
    // @pre:    5 - minHeap
    // @post:   Found the smallest element in the 5 - minHeap
    // @return: A pointer to teh smallest node, nullptr if not found.
    int findmin();
    
    // @pre:    5 - minHeap
    // @post:   Found the largest element in the 5 - minHeap
    // @return: A pointer to the largest node, nullptr if not found.
    int findmax();
    
    // // @pre:    5 - minHeap
    // // @post:   Found the node with key in the minHeap
    // // @return: True if node was in minHeap, false if not found.
    // Node *find(int key);
    
    // @pre:    5 - minHeap
    // @post:   Printed out all the elements of the minHeap using levelorder traversal.
    // @return: None
    void levelorder();

    
};

#endif
