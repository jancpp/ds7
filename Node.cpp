/*
Author: Jan Polzer
File:   Node.cpp
Date:   3/12/2018
*/

#include "Node.h"

Node::Node() : m_key(-1), m_first(nullptr), m_second(nullptr), m_third (nullptr), m_fourth (nullptr), m_fifth (nullptr), m_parent (nullptr) {
}

Node::Node(const int &key,
        Node *first, Node *second, Node *third, Node *fourth, Node *fifth, Node *parent ) {
        setKey(key);
        setFirst (first);
        setSecond (second);
        setThird (third);
        setFourth (fourth);
        setFifth (fifth);
        setParent (parent);
    }

    int Node::key() const {
        return m_key;
    }

    void Node::setKey (const int &key) {
        m_key = key;
    }

    void Node::setFirst (Node *node) {
        m_first  = node;
    }

    void Node::setSecond (Node *node) {
        m_second  = node;
    }

    void Node::setThird (Node *node) {
        m_third  = node;
    }

    void Node::setFourth (Node *node) {
        m_fourth  = node;
    }

    void Node::setFifth (Node *node) {
        m_fifth  = node;
    }

    void Node::setParent (Node *node) {
        m_parent  = node;
    }

    Node *Node::first () const {
        return m_first ;
    }

    Node *Node::second () const {
        return m_second ;
    }

    Node *Node::third () const {
        return m_third ;
    }

    Node *Node::fourth () const {
        return m_fourth ;
    }

    Node *Node::fifth () const {
        return m_fifth ;
    }

    Node *Node::parent () const {
        return m_parent ;
    }
