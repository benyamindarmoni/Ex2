//Benyamon Darmoni , Danielle Zand
#include "Tree.hpp"
using namespace std;
using namespace ariel;
  int size1=0;
Tree::Tree()
{
    Troot=NULL;
}
Tree::Tree(Node n)
{
    Troot=&n;
}
//Node::Node()
//{
//    value=0;
//    right=left=NULL;
 //   size1++;
//}
Node:: Node (int a)
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
         size1--;
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
                size1--;
                int a=0;
            }

        }

    }
    
    int Tree:: root()
    {
         return Troot->value;
    }
    void Tree:: remove (int a){
       
        if(Troot!=NULL) 
        HelpDelete(Troot, a); 
    }
    void Tree:: HelpDelete(Node* root, int d) 
    {
        Node* h=root;
        Node* t=root;
        while(h!=NULL){
            if(d>h->value)
            {
                t=h;
                h=h->right;
        }
        else if(d<h->value){
             t=h;
                h=h->left;
        }
        else{
            if(h->left==NULL&&h->right==NULL){
                delete(h);
                size1--;
                h=NULL;
            }
            else if(h->left==NULL){
               if(t->right->value==h->value){
                  t->right=h->right;
                   delete(h);
                size1--;
                h=NULL;
               }
                 else{
                     t->left=h->right;
                   delete(h);
                size1--;
                h=NULL; 
                 }
            }
            else if(h->right==NULL){
               if(t->right->value==h->value){
                  t->right=h->left;
                   delete(h);
                size1--;
                h=NULL;
               }
                 else{
                     t->left=h->left;
                   delete(h);
                size1--;
                h=NULL; 
                 }
            }
            else{//2 kids
             t=Max(h->left);
              h->value=t->value;
              size1--;
             if(t->left!=NULL){
             t->value=t->left->value;
              delete(t->left);
             }
             else
             delete(t);
            }
        }
  
        }}

Node* Tree:: Max(Node* root){

    if(root==NULL)
    return NULL;

    while(root->right != NULL)
    {
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
  
