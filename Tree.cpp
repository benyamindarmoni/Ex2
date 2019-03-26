//Benyamon Darmoni , Danielle Zand
#include "Tree.hpp"

using namespace std;
using namespace ariel;
Tree::Tree()
{
    Troot=NULL;
}
Tree::Tree(Node n)
{
    Troot=&n;
}
Node:: Node (int a)
{
    value=a;
    right=left=NULL;
}
  int Tree:: size()
 {
   
    return HelpSize(Troot);
    
}
int Tree:: HelpSize(Node* n){
  
    if (n == NULL)  
        return 0;  
    else
        return( HelpSize(n->left) + 1 +  HelpSize(n->right));  

}
int Tree::HelpParent(Node* root,int a)
{
    
  Node *h=root;
    Node *f=root;
   
    while(h!=NULL){
        if(a>h->value){
            f=h;
            h=h->right;
        }
        else if(a<h->value){
           f=h;
             h=h->left;
        }
        else{
            return f->value;
        }
       
    }
    
  //  delete(h);
  throw std::invalid_argument( "didnt found the number" ); 
    return 0;
}
    int Tree:: parent(int a)
    {
        if(Troot==NULL){
         throw std::invalid_argument( "tree is empty" ); 
           return 0;
        } 
    if(Troot->value==a){
       throw std::invalid_argument( "the number is the root!" );
        return 0;
    }
            return HelpParent(Troot,a);
       
      
    }
    int Tree:: left(int a)
    {
        
           Node* h=Troot;
           while(h!=NULL){
               if(a>h->value)h=h->right;
               else if(a<h->value) h=h->left;
              else{
                  if(h->left!=NULL)
                  return h->left->value;
                  else
                  throw std:: invalid_argument( "left node is null!" );
                  
              }
           }
          
           
          
      throw std::invalid_argument( "number doesnt exist!" );
        return 0;
    }
    int Tree:: right(int a)
    {
        Node* h=Troot;
           while(h!=NULL){
               if(a>h->value)h=h->right;
               else if(a<h->value) h=h->left;
              else{
                  if(h->right!=NULL)
                  return h->right->value;
                  else
                  throw std:: invalid_argument( "right node is null!" );
                  
              }
           }
          
           
          
      throw std:: invalid_argument( "number doesnt exist!" );
        return 0;
    }
    Node* Tree:: insert (int a)
    {
        
            Node* n=new Node(a);

            HelpInsert(&Troot,&n);
            return Troot;
        
    }
    void Tree::HelpInsert(Node** main,Node** NewNode)
    {
        if(*main==NULL) 
         {
         *main=new Node((**NewNode).value);
         
         delete(*NewNode);
         }
        else
        {
          if((*main)->value>(*NewNode)->value)
            {
              HelpInsert(&((*main)->left),NewNode);
            }
          else if((*main)->value<(*NewNode)->value)
            {
                HelpInsert(&((*main)->right),NewNode);

            }
            else{
                throw std::invalid_argument( "number already exist!" );
                int a=0;
            }

        }

    }
    
    int Tree:: root()
    {
        if(Troot!=NULL)
         return Troot->value;
           throw std::invalid_argument( "The root is null!" ); 
    }
    void Tree:: remove (int a){
       
        if(Troot!=NULL) 
        HelpDelete(&Troot, a); 
        else
        throw std::invalid_argument( "number not found!" ); 
        
    }
    void Tree:: HelpDelete(Node** root, int value) 
    {   
        
 
	c=Search(root,value);
	if(root==NULL)
		return ;
	else if(value< root->value)
	{
		root->left= Delete(root->left,value);
	}
	else if(value> root->value)
	{
		root->right= Delete(root->right,value);
	}
	
	// Node deletion
	else
	{
		//case 1: Leaf Node
		if(root->left==NULL&&root->right==NULL)
		{
			delete root;
			root=NULL;
		return;
		}
		//case 2: one child
		else if(root->left==NULL)
		{
			 Node* temp=root;
			root=root->right;
			delete temp;
			return;
		}
		else if(root->right==NULL)
		{
			 Node* temp=root;
			root=root->left;
			delete temp;
			return;
		}
		//case 3: 2 child
		else
		{
			 Node*temp=findMin(root->right);
			root->value=temp->value;
			root->right=Delete(root->right,temp->value);
		}
	}
	return;

}


Node* Tree:: Max(Node* root,Node* f){
if(root==NULL)
    return NULL;

    while(root->right != NULL)
    {
        f=root;
        root = root->right;
    }
    return root;
}
    bool Tree:: contains(int a){
          if(Troot==NULL)return false;
               return HelpContains(Troot,a);

    }
     bool  Tree:: HelpContains(Node * root,int a)
   {
       Node * help=root;
       while(help!=NULL){
          if(a>help->value)help=help->right;
           else if(a<help->value)help=help->left;
           else
           return true; 
       }
          return false; 
       
   }
    void Tree:: print(){
       
    }
