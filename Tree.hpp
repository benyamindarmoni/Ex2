//Benyamon Darmoni , Danielle Zand
#pragma once

#include <iostream>


namespace ariel{
   
  class Node{
    public:
	int value;
	Node *left;
	Node *right;
   // Node();          //constractors
    Node(int);
	
};

class Tree {
  
  Node* Troot;

  public:
  Tree(Node);
  Tree();
  
    
    public:          //functions
    int size();
    int parent(int);
    int left(int);
    int right(int);
    Node* insert (int);
    int root();
    void remove (int);
    bool contains(int);
    void print();
    void HelpInsert(Node**,Node**);
    int HelpParent(Node * ,int );
   Node* Max(Node*);
    void HelpDelete( Node* , int );
    bool HelpContains(Node*,int);
    
    };
    
    
}
