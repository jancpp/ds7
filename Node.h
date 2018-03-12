/*
Author: Jan Polzer
File:   Node.h
Date:   3/12/2018
*/

#ifndef NODE_H
#define NODE_H

class Node
{
private:
	int m_key;
	Node *m_first ;
	Node *m_second ;
	Node *m_third ;
	Node *m_fourth ;
	Node *m_fifth ;
	Node *m_parent ;

public:
	// @pre:    None
	// @post:   Initialized Node class
	// @return  None
	Node();


	// @pre:    None
	// @post:   Initialized Node class
	// @return  None
	Node(const int &key, Node *first , Node *second , Node *third , Node *fourth , Node *fifth , Node *parent );

	// @pre:    Node
	// @post:   None
	// @return  m_key
	int key() const;

	// @pre:    Node
	// @post:   Set key (-1 if no key set)
	// @return  None
	void setKey(const int &key);

	// @pre:    Node
	// @post:   None
	// @return  m_first
	Node *first () const;

	// @pre:    Node
	// @post:   None
	// @return  m_second
	Node *second () const;

	// @pre:    Node
	// @post:   None
	// @return  m_third
	Node *third () const;

	// @pre:    Node
	// @post:   None
	// @return  m_fourth
	Node *fourth () const;

	// @pre:    Node
	// @post:   None
	// @return  m_fifth

	Node *fifth () const;

	// @pre:    Node
	// @post:   None
	// @return  m_parent
	Node *parent () const;

	// @pre:    Node
	// @post:   Set first child
	// @return  None
	void setFirst (Node *first );

	// @pre:    Node
	// @post:   Set second child
	// @return  None
	void setSecond(Node *second );

	// @pre:    Node
	// @post:   Set third child
	// @return  None
	void setThird (Node *third );

	// @pre:    Node
	// @post:   Set fourth child
	// @return  None
	void setFourth (Node *fourth );

	// @pre:    Node
	// @post:   Set fifth child
	// @return  None
	void setFifth (Node *fifth );

	// @pre:    Node
	// @post:   Set parent pointer
	// @return  None
	void setParent (Node *parent );

};

#endif
