/*
Author: Jan Polzer
File:   Heap.h
Date:   3/12/2018
*/

#ifndef HEAP_H
#define HEAP_H

#include "Node.h"
#include <iostream>
#include <queue>

class Heap {

private:
	Node *m_root;

	// @pre:    5 - Heap
	// @post:   inserting node in root
	// @return: Node pointer of element to be inserted
	virtual void inserthelper(int key, Node *root);

	// @pre:    5 - Heap
	// @post:   Printed keys in level traversal
	// @return: None
	virtual void Levelorderhelper(Node *root);

	// @pre:    5 - Heap
	// @post:   Serching in root
	// @return: Node pointer of element to be found
	virtual Node *findMinhelper(Node *root);

	// @pre:    5 - Heap
	// @post:   Searching in root
	// @return: Node pointer of element to be found
	virtual Node *findminhelper(Node *root);

	// @pre:    5 - Heap
	// @post:   Found node from the Heap
	// @return: True if found, false otherwise
	virtual Node *findhelper(int key, Node *root);

	// @pre:    5 - Heap
	// @post:   deleted node from the Heap
	// @return: True if deleted, false otherwise
	virtual bool deletehelper(int key, Node *root);

public:
	Heap();
	~Heap();

	// @pre:    No three
	// @Post:   Unsorted full tree
	// @Return: Node
	virtual void build();

	// @pre:    5 - Heap
	// @Post:   New node inserted into the Heap:    as root if empty,
	//                                              as first node if key is smaller then root key
	//                                              as third node if key is larger then root key
	//                                              as second otherwise
	// @Return: True if success, false otherwise
	virtual bool insert(int key);

	// // @pre:    5 - Heap
	// // @post:   deleted passed key
	// // @return: True if deleted, false otherwise
	// bool delete(int key);

	// @pre:    5 - Heap
	// @post:   deleted min key
	// @return: True if deleted, false otherwise
	virtual bool deletemin();

	// @pre:    5 - Heap
	// @post:   deleted max key
	// @return: True if deleted, false otherwise
	virtual bool deletemax();

	// @pre:    5 - Heap
	// @post:   Found the smallest element in the 5 - Heap
	// @return: A pointer to teh smallest node, nullptr if not found.
	virtual Node *findmin();

	// @pre:    5 - Heap
	// @post:   Found the largest element in the 5 - Heap
	// @return: A pointer to the largest node, nullptr if not found.
	virtual Node *findmax();

	// // @pre:    5 - Heap
	// // @post:   Found the node with key in the Heap
	// // @return: True if node was in Heap, false if not found.
	// Node *find(int key);

	// @pre:    5 - Heap
	// @post:   Printed out all the elements of the Heap using levelorder traversal.
	// @return: None
	virtual void levelorder();

};

#endif
