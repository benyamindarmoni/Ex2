
#pragma once

#include <iostream>


namespace ariel{
  struct Node{
    
	int value;
	Node *left;
	Node *right;
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
    Tree& insert (int);
    int root();
    void remove (int);
    bool contains(int);
    void print();
    
    };
    
    
}
    
