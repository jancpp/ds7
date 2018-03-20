/*
Author: Jan Polzer
File:   MaxHeap.h
Date:   3/12/2018
*/

#ifndef MAX_HEAP
#define MAX_HEAP


#include "Node.h"
#include "Heap.h"
#include <iostream>

class MaxHeap: public Heap {

private:
	Node *m_root;
//    
//    // @pre:    5 - maxHeap
//    // @post:   Unsorted tree
//    // @return: None
//    void buildheap();
//    
//    // @pre:    5 - maxHeap
//    // @post:   Inserting node in root
//    // @return: Node pointer of element to be inserted
//    void inserthelper(int key, Node *root);
//
//    // @pre:    5 - maxHeap
//    // @post:   Printed keys in level traversal
//    // @return: None
//    void levelorderhelper(Node *root);
//
//    // @pre:    5 - maxHeap
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
//    // @post:   Found node from the maxHeap
//    // @return: True if found, false otherwise
//    Node *findhelper(int key, Node *root);
//
//    // @pre:    5 - maxHeap
//    // @post:   deleted node from the maxHeap
//    // @return: True if deleted, false otherwise
//    bool deletehelper(int key, Node *root);

public:
	MaxHeap();
	~MaxHeap();

    // @pre:    5 - maxHeap
    // @post:   Unsorted tree
    // @return: None
    void buildheap();
    
	// @pre:    Binary search maxHeap
	// @Post:   New node inserted into the maxHeap:    as root if empty,
	//                                              as first node if key is smaller then root key
	//                                              as third node if key is larger then root key
    //                                              as second otherwise
	// @Return: True if success, false otherwise
	bool insert(int key);

	// @pre:    5 - maxHeap
	// @post:   deleted min key
	// @return: True if deleted, false otherwise
	bool deletemin();

	// @pre:    5 - maxHeap
	// @post:   deleted max key
	// @return: True if deleted, false otherwise
	bool deletemax();

	// @pre:    5 - maxHeap
	// @post:   Found the smallest element in the 5 - maxHeap
	// @return: A pointer to teh smallest node, nullptr if not found.
	Node *findmin();

	// @pre:    5 - maxHeap
	// @post:   Found the largest element in the 5 - maxHeap
	// @return: A pointer to the largest node, nullptr if not found.
	Node *findmax();

	// @pre:    5 - maxHeap
	// @post:   Found the node with key in the maxHeap
	// @return: True if node was in maxHeap, false if not found.
	Node *find(int key);

	// @pre:    5 - maxHeap
	// @post:   Printed out all the elements of the maxHeap using levelorder traversal.
	// @return: None
	void levelorder();

};

#endif
