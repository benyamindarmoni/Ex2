//Benyamon Darmoni , Danielle Zand
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
	    Node* insert (int);
	    int root();
	    void remove (int);
	    bool contains(int);
	    void print();
	    
	    };
	    
	    
	}

