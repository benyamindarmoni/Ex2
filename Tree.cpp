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
   Node* h=root;
    while(h->right->value!=a&&h->left->value!=a){
        if(a>h->value)h=h->right;
        else
        h=h->left;
    }
    int ans=h->value;
  //  delete(h);
    return ans;
}
    int Tree:: parent(int a)
    {
        if(this.contains(a)&&Troot->data!=a){
            return HelpParent(Troot,a);
        }
       else{
           throw std::invalid_argument( "number doesnt exist!" );
       } 
       return 0;
    }
    int Tree:: left(int a)
    {
         if(!this.contains(a)) throw std::invalid_argument( "number doesnt exist!" );
       else{
           Node* h=Troot;
           while(a!=h->value){
               if(a>h->value)h=h->right;
               else
               h=h->left;
           }
           int ans= h->left->value;
        //   delete(h);
           return ans;
          
       }
        return 0;
    }
    int Tree:: right(int a)
    {
        if(!this.contains(a)) throw std::invalid_argument( "number doesnt exist!" );
       else{
           Node* h=Troot;
           while(a!=h->value){
               if(a>h->value)h=h->right;
               else
               h=h->left;
           }
           int ans= h->right->value;
         //  delete(h);
           return ans;
       }
        return 0;
    }
    Node * Tree:: insert (int a)
    {
         if(this.contains(a))

        {
            throw std::invalid_argument( "already exist!" );
        }
        else
        {
            Node n= new Node(a);

            HelpInsert(Troot,n);
        }
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
          else
            {
                HelpInsert(main->right,NewNode);

            }    

        }

    }
    
    int Tree:: root()
    {
         return Troot->data;
    }
    void Tree:: remove (int a){
        if(contains(a)){
            size1--;
        HelpDelete(  Troot, a); 
        }
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
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
             Node *temp = root->left; 
            delete(root); 
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
