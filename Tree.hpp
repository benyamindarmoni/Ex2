//Benyamin Darmoni , Danielle Zand
#pragma once

#include <iostream>


namespace ariel{
   
  class Node{
    public:
	int value;
	Node *left;
	Node *right;
                 
    Node(int);         //constractors
	
};

class Tree {
  
  Node* Troot;

  public:
  Tree(Node);          //constractors
  Tree();
  ~Tree();
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
   Node* Max(Node*,Node**);
   void HelpDelete( Node** , int );
    bool HelpContains(Node*,int);
    int  HelpSize(Node*);
    void print2DUtil(Node* , int ); 
    void HelpMemory(Node* );
     };
    
    
}
