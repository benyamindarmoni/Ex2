//Benyamon Darmoni , Danielle Zand
#include "Tree.hpp"
using namespace ariel;
 static int size1=0;
Tree::Tree()
{
    Troot=NULL;
}
Tree::Tree(Node n)
{
    Troot=&n;
}
Node::Node()
{
    value=0;
    right=left=NULL;
    size1++;
}
Node::Node(int a)
{
    size1++;
    value=a;
    right=left=NULL;
}
  int Tree:: size()
 {
    return size1;
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
    if(root->value==a){
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
                  return h->left->value;
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
                  return h->right->value;
              }
           }
          
           
          
       throw std::invalid_argument( "number doesnt exist!" );
        return 0;
    }
    Node * Tree:: insert (int a)
    {
        
            Node n= new Node(a);

            HelpInsert(Troot,n);
        
    }
     void Tree::HelpInsert(Node* main,Node NewNode)
    {
        if(main==NULL) 
         {
         main=&NewNode;
         }
        else
        {
          if(main->value>NewNode->value)
            {
              HelpInsert(main->left,NewNode);
            }
          else if(main->value<NewNode->value)
            {
                HelpInsert(main->right,NewNode);

            }
            else{
                throw std::invalid_argument( "number already exist!" );
                return;
            }

        }

    }
    
    int Tree:: root()
    {
         return Troot->data;
    }
    void Tree:: remove (int a){
        
        HelpDelete(  Troot, a); 
        
    }
     Node* Tree:: HelpDelete( Node* root, int key) 
    { 
    if (root == NULL) return root; 
 
    if (key < root->key) 
        root->left = HelpDelete(root->left, key); 
  
    else if (key > root->key) 
        root->right = HelpDelete(root->right, key); 
    else
    { 
        if (root->left == NULL) 
    { 
             Node *temp = root->right; 
            delete(root); 
            size1--;
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
             Node *temp = root->left; 
            delete(root); 
                        size1--;

            return temp; 
        } 
         Node* temp = minValueNode(root->right); 
        root->key = temp->key; 
        root->right = HelpDelete(root->right, temp->key); 
    } 
    return root; 
}
Node*  Tree:: minValueNode( Node* node) 
  { 
     Node* current = node; 
  
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
}
    bool Tree:: contains(int a){
               return HelpContains(troot,a);

    }
     bool  Tree:: HelpContains(Node * root,int a)
   {
       if(root==null)return false;
       else{
           if(a>root->value)HelpContains(root->right,a);
           else if(a<root->value)HelpContains(root->left,a);
           else
           return true;
       }
   }
    void Tree:: print(){
       
    }
