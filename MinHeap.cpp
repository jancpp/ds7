/*
Author: Jan Polzer
File:   minHeap.cpp
Date:   3/12/2018
*/

#include "minHeap.h"

minHeap::minHeap(): m_root(nullptr) {}
minHeap::~minHeap() {
    while (m_root != nullptr) {
        deletemin();
    }
}

bool minHeap::insert(int key) {
    bool inserted = false;
    inserthelper(key, m_root);
    return inserted;
}

void minHeap::inserthelper(int key, Node *root) {
    Node *newLeaf = new Node();
    newLeaf->setTag(1);
    newLeaf->setKey(key);
//    Node *temp = root;

    // No nodes in minHeap
    // @return minHeap with one leaf node
    if (root == nullptr) {
        m_root = newLeaf;
    }
    // One leaf node in minHeap
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
//        newInterior->setminSecond(newInterior->second()->key());
//        newInterior->first()->setParent(newInterior);
//        newInterior->second()->setParent(newInterior);
//        newInterior->setParent(root);
//    }
//    // 2 nodes in minHeap
//    else if ((temp->first()->tag() == 1) &&
//    (temp->first()  != nullptr) &&
//    (temp->second() != nullptr) &&
//    (temp->third()  == nullptr)) {
//        // new leaf is largest of all 3 leaves
//        if (temp->minSecond() <= newLeaf->key()) {
//            temp->setThird(newLeaf);
//            temp->setminThird(temp->third()->key());
//        }
//        // new leaf is 2nd largest of all 3 leaves
//        else if (temp->first()->key() <= newLeaf->key()) {
//            temp->setThird(temp->second());
//            temp->setSecond(newLeaf);
//            temp->setminSecond(temp->second()->key());
//            temp->setminThird(temp->third()->key());
//        }
//        // new leaf is smallest of all 3 leaves
//        else {
//            temp->setThird(temp->second());
//            temp->setSecond(temp->first());
//            temp->setFirst(newLeaf);
//            temp->setminSecond(temp->second()->key());
//            temp->setminThird(temp->third()->key());
//        }
//        temp->first()->setParent(temp);
//        temp->second()->setParent(temp);
//        temp->third()->setParent(temp);
//    }
//    // 3 leaf nodes in minHeap
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
//            newInterior->setminSecond(newInterior->second()->key());
//            temp->setThird(nullptr);
//            temp->setminThird(-1);
//        }
//        // new leaf is 2nd largest of all 4 leaves
//        else if (temp->minSecond() <= newLeaf->key()) {
//            newInterior->setFirst(newLeaf);
//            newInterior->setSecond(temp->third());
//            newInterior->setminSecond(newInterior->second()->key());
//            temp->setThird(nullptr);
//            temp->setminThird(-1);
//        }
//        // new leaf is 2nd smallest of all 4 leaves
//        else if (temp->minSecond() <= newLeaf->key()) {
//            newInterior->setFirst(temp->second());
//            newInterior->setSecond(temp->third());
//            newInterior->setminSecond(newInterior->second()->key());
//            temp->setSecond(newInterior);
//            temp->setminSecond(newLeaf->key());
//            temp->setThird(nullptr);
//            temp->setminThird(-1);
//        }
//        // new leaf is smallest of all 4 leaves
//        else if (temp->first()->key() < newLeaf->key()) {
//            newInterior->setFirst(temp->second());
//            newInterior->setSecond(temp->third());
//            newInterior->setminSecond(newInterior->second()->key());
//            temp->setSecond(temp->first());
//            temp->setFirst(newLeaf);
//            temp->setminSecond(temp->second()->key());
//            temp->setThird(nullptr);
//            temp->setminThird(-1);
//        }
//        if (temp->parent() == temp) {
//            // Make parent to temp (internal) and newInterior nodes
//            Node *parentInternal = new Node();
//            parentInternal->setTag(0);
//            parentInternal->setFirst(temp);
//            parentInternal->setSecond(newInterior);
//            parentInternal->setminSecond(newInterior->first()->key());
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
//        // 3 interior nodes in the minHeap
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

bool minHeap::delete(int key) {
    bool deleted = false;
    deleted = deletehelper(key, m_root);
    return deleted;
}

bool minHeap::deletemin() {
    if (m_root == nullptr) {
        return false;
    } else {
        int key = findmin()->key();
        return deletehelper(key, m_root);
    }
}

bool minHeap::deletemax() {
    if (m_root == nullptr) {
        return false;
    } else {
        int key = findMax()->key();
        return deletehelper(key, m_root);
    }
}

bool minHeap::deletehelper(int key, Node *root) {
    bool deleted = false;

    if (root == nullptr) {
        deleted = false;
    }
    // minHeap has one node
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

Node *minHeap::findmin() {
    if (m_root == nullptr) {
        return m_root;
    } else {
        return findminhelper(m_root);
    }
}

Node *minHeap::findminhelper(Node *root) {
    if (root->tag() == 1) {
        return root;
    }
//    else if (root->first() == nullptr) {
        return root;
//    } else {
//        return findminhelper(root->first());
//    }
}

Node *minHeap::findmax() {
    if (m_root == nullptr) {
        return m_root;
    } else {
        return findminhelper(m_root);
    }
}

Node *minHeap::findminhelper(Node *root) {
    if (root->tag() == 1) {
        return root;
    }
//    else if ((root->third() == nullptr) && (root->tag() == 1)) {
//        return root;
//    }
//    else if (root->third() != nullptr) {
//        return findminhelper(root->third());
//    }
//    else if (root->second() != nullptr) {
//        return findminhelper(root->second());
//    }
//    else if (root->first() != nullptr) {
//        return findminhelper(root->first());
//    }
    return root;
}

// Node *minHeap::find(int key) {
//     return findhelper(key, m_root);
// }

// Node *minHeap::findhelper(int key, Node *root) {
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

void minHeap::levelorder() {
    if (m_root == nullptr) {
        std::cout << "minHeap is empty.\n";
    } else {
        levelorderhelper(m_root);
    }
}

void minHeap::levelorderhelper(Node *root) {
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
