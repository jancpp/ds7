/*
Author: Jan Polzer
File:   Heap.cpp
Date:   3/12/2018
*/

#include "Heap.h"

Heap::Heap(): m_root(nullptr) {}
Heap::~Heap() {
    while (m_root != nullptr) {
        DeleteMin();
    }
}

bool Heap::insert(int key) {
    bool inserted = false;
    inserthelper(key, m_root);
    return inserted;
}

void Heap::inserthelper(int key, Node *root) {
    Node *newLeaf = new Node();
    newLeaf->setTag(1);
    newLeaf->setKey(key);
//    Node *temp = root;

    // No nodes in Heap
    // @return Heap with one leaf node
    if (root == nullptr) {
        m_root = newLeaf;
    }
    // One leaf node in Heap
    // Make internal node, with an old leaf and new leaf
//    else if (temp->tag() == 1) {
//        Node *newInterior = new Node();
//        newInterior->setTag(0);
//        root = newInterior;
//        // new leaf is larger of 2 leaves
//        if (temp->key() < newLeaf->key()) {
//            newInterior->setFirst(temp);
//            newInterior->setSecond(newLeaf);
//        } else {
//            newInterior->setSecond(temp);
//            newInterior->setFirst(newInterior);
//        }
//        newInterior->setMinSecond(newInterior->second()->key());
//        newInterior->first()->setParent(newInterior);
//        newInterior->second()->setParent(newInterior);
//        newInterior->setParent(root);
//    }
//    // 2 nodes in Heap
//    else if ((temp->first()->tag() == 1) &&
//    (temp->first()  != nullptr) &&
//    (temp->second() != nullptr) &&
//    (temp->third()  == nullptr)) {
//        // new leaf is largest of all 3 leaves
//        if (temp->minSecond() <= newLeaf->key()) {
//            temp->setThird(newLeaf);
//            temp->setMinThird(temp->third()->key());
//        }
//        // new leaf is 2nd largest of all 3 leaves
//        else if (temp->first()->key() <= newLeaf->key()) {
//            temp->setThird(temp->second());
//            temp->setSecond(newLeaf);
//            temp->setMinSecond(temp->second()->key());
//            temp->setMinThird(temp->third()->key());
//        }
//        // new leaf is smallest of all 3 leaves
//        else {
//            temp->setThird(temp->second());
//            temp->setSecond(temp->first());
//            temp->setFirst(newLeaf);
//            temp->setMinSecond(temp->second()->key());
//            temp->setMinThird(temp->third()->key());
//        }
//        temp->first()->setParent(temp);
//        temp->second()->setParent(temp);
//        temp->third()->setParent(temp);
//    }
//    // 3 leaf nodes in Heap
//    else if ((temp->first()->tag() == 1) &&
//    (temp->first()  != nullptr) &&
//    (temp->second() != nullptr) &&
//    (temp->third()  != nullptr)) {
//        Node *newInterior = new Node();
//        newInterior->setTag(0);
//        // new leaf is largest of all 4 leaves
//        if (temp->minThird() <= newLeaf->key()) {
//            newInterior->setFirst(temp->third());
//            newInterior->setSecond(newLeaf);
//            newInterior->setMinSecond(newInterior->second()->key());
//            temp->setThird(nullptr);
//            temp->setMinThird(-1);
//        }
//        // new leaf is 2nd largest of all 4 leaves
//        else if (temp->minSecond() <= newLeaf->key()) {
//            newInterior->setFirst(newLeaf);
//            newInterior->setSecond(temp->third());
//            newInterior->setMinSecond(newInterior->second()->key());
//            temp->setThird(nullptr);
//            temp->setMinThird(-1);
//        }
//        // new leaf is 2nd smallest of all 4 leaves
//        else if (temp->minSecond() <= newLeaf->key()) {
//            newInterior->setFirst(temp->second());
//            newInterior->setSecond(temp->third());
//            newInterior->setMinSecond(newInterior->second()->key());
//            temp->setSecond(newInterior);
//            temp->setMinSecond(newLeaf->key());
//            temp->setThird(nullptr);
//            temp->setMinThird(-1);
//        }
//        // new leaf is smallest of all 4 leaves
//        else if (temp->first()->key() < newLeaf->key()) {
//            newInterior->setFirst(temp->second());
//            newInterior->setSecond(temp->third());
//            newInterior->setMinSecond(newInterior->second()->key());
//            temp->setSecond(temp->first());
//            temp->setFirst(newLeaf);
//            temp->setMinSecond(temp->second()->key());
//            temp->setThird(nullptr);
//            temp->setMinThird(-1);
//        }
//        if (temp->parent() == temp) {
//            // Make parent to temp (internal) and newInterior nodes
//            Node *parentInternal = new Node();
//            parentInternal->setTag(0);
//            parentInternal->setFirst(temp);
//            parentInternal->setSecond(newInterior);
//            parentInternal->setMinSecond(newInterior->first()->key());
//            temp->setParent(parentInternal);
//            root = parentInternal;
//            parentInternal->setParent(root);
//            newInterior->setParent(parentInternal);
//            temp->setParent(parentInternal);
//        } else if ((temp->parent()->first() != nullptr) ||
//        (temp->parent()->second() != nullptr) ||
//        (temp->parent()->third() == nullptr)) {
//            temp->parent()->setThird(newInterior);
//        }
//    } else {
//        // 3 interior nodes in the Heap
//        if (key < temp->minSecond()) {
//            inserthelper(key, temp->first());
//            root->setFirst(temp);
//        } else if (key > temp->minThird() && temp->minThird() != -1) {
//            inserthelper(key, temp->third());
//            root->setThird(temp);
//        } else {
//            inserthelper(key, temp->second());
//            root->setSecond(temp);
//        }
//    }
//    return root;
}

bool Heap::delete(int key) {
    bool deleted = false;
    deleted = Deletehelper(key, m_root);
    return deleted;
}

bool Heap::deletemin() {
    if (m_root == nullptr) {
        return false;
    } else {
        int key = findMin()->key();
        return Deletehelper(key, m_root);
    }
}

bool Heap::deletemax() {
    if (m_root == nullptr) {
        return false;
    } else {
        int key = findMax()->key();
        return Deletehelper(key, m_root);
    }
}

bool Heap::deletehelper(int key, Node *root) {
    bool deleted = false;

    if (root == nullptr) {
        deleted = false;
    }
    // Heap has one node
    else if (root->tag() == 1) {
        delete root;
//        root = nullptr;
        deleted = true;
    }
//    else {
//        //Parent of node to delete
//        Node *parent = find(key)->parent();
//
//        if (parent->first() != nullptr)
//        if (key == parent->first()->key()) { delete parent->first(); }
//        if (parent->second() != nullptr)
//        if (key == parent->second()->key()) { delete parent->second(); }
//        if (parent->third() != nullptr)
//        if (key == parent->third()->key()) { delete parent->third(); }
//    }
    return deleted;
}

Node *Heap::findmin() {
    if (m_root == nullptr) {
        return m_root;
    } else {
        return findMinhelper(m_root);
    }
}

Node *Heap::findminhelper(Node *root) {
    if (root->tag() == 1) {
        return root;
    }
//    else if (root->first() == nullptr) {
        return root;
//    } else {
//        return findMinhelper(root->first());
//    }
}

Node *Heap::findmax() {
    if (m_root == nullptr) {
        return m_root;
    } else {
        return findmaxhelper(m_root);
    }
}

Node *Heap::findmaxhelper(Node *root) {
    if (root->tag() == 1) {
        return root;
    }
//    else if ((root->third() == nullptr) && (root->tag() == 1)) {
//        return root;
//    }
//    else if (root->third() != nullptr) {
//        return findMaxhelper(root->third());
//    }
//    else if (root->second() != nullptr) {
//        return findMaxhelper(root->second());
//    }
//    else if (root->first() != nullptr) {
//        return findMaxhelper(root->first());
//    }
    return root;
}

// Node *Heap::find(int key) {
//     return findhelper(key, m_root);
// }

// Node *Heap::findhelper(int key, Node *root) {
//     if (root->tag() == 1) {
//         return root;
//     }
//    else {
//        Node *temp = root;
//        if (key < temp->minSecond()) {
//            findhelper(key, temp->first());
//        } else if (temp->minThird() != -1 && key >= temp->minThird()) {
//            findhelper(key, temp->third());
//        } else {
//            findhelper(key, temp->second());
//        }
//    }
    return root;
}

void Heap::levelorder() {
    if (m_root == nullptr) {
        std::cout << "Heap is empty.\n";
    } else {
        levelorderhelper(m_root);
    }
}

void Heap::levelorderhelper(Node *root) {
    if (root != nullptr) {
        std::queue<Node*> queue;
        // Enqueue all nodes from level 0 to last level
        queue.push(root);
        while (!queue.empty()) {
            Node *temp = queue.front();
            // Print all leaves
            if (temp->tag() == 1) {
                std::cout << " " << temp->key();
            }
            queue.pop();

            if (temp->first()  != nullptr) { queue.push(temp->first()); }
            if (temp->second() != nullptr) { queue.push(temp->second()); }
            if (temp->third()  != nullptr) { queue.push(temp->third()); }
        }
    }
}
