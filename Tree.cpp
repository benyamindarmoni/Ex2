//Benyamin Darmoni , Danielle Zand
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
Tree::~Tree(){
    if(Troot!=NULL){
        HelpMemory(Troot);
    }
    std::cout << "Tree deleted!" << std::endl;
}
void Tree:: HelpMemory(Node* a){
     if(a==NULL)
        return;

   
    HelpMemory(a->left);
    HelpMemory(a->right);
     delete a;
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
    void Tree:: HelpDelete(Node** root, int d) 
    { 
        int found=0;
        Node* h=*root;
        Node* t=*root;
        if(d==(*root)->value){
            found=1;
        if((*root)->right!=NULL&&(*root)->left==NULL){
          
             *root=(*root)->right;
             delete(h);
             h=NULL;
        }
        if((*root)->left!=NULL&&(*root)->right==NULL){
             *root=(*root)->left;
             delete(h);
              h=NULL;
        }
   
        
       
        }
         if(d==(*root)->value&&(*root)->left==NULL&&(*root)->right==NULL){
        
           
           *root=NULL; 
           found=1;
          h=NULL;
        }
       
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
            found=1;
            if(h->left==NULL&&h->right==NULL){ //no kids
                
                if(t->right!=NULL&&t->right->value==h->value)
                t->right=NULL;
                else
                t->left=NULL;
                delete(h);
            }
            else if(h->left==NULL){   //only right kid
               if(t->right!=NULL&&t->right->value==h->value){
                  t->right=h->right;
              
                  
                   delete(h);
                
                h=NULL;
                break;
               }
                 if(t->left!=NULL&&h->value==t->left->value){
                     t->left=h->right;
                   delete(h);
                h=NULL; 
                  break;
                 }
            }
            else if(h->right==NULL){  //only left kid
               if(t->right!=NULL&&t->right->value==h->value){
                  t->right=h->left;
                   delete(h);
                h=NULL;
                  break;
               }
                 if(t->left!=NULL&&t->left->value==h->value){
                     t->left=h->left;
                   delete(h);    
                   h=NULL; 
                     break;
                 }
            }
            else{      //2 kids
       
              Node* father=h;
             t=Max(h->left,&father);
              h->value=t->value;
            if(father==h){
                h->left=t->left;
                delete t;
                 
            }
            else{
                if(t->left!=NULL){
                    father->right=t->left;
                }
                else{
                    father->right=NULL;
                    
                }
                delete t;
            } 
            break;
            }
        }
  
        
        }
        if(found==0)throw std::invalid_argument( "number not found!" ); 

    }
    
    Node* Tree:: Max(Node* root,Node** f){
if(root==NULL)
    return NULL;

    while(root->right != NULL)
    {
        *f=root;
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
        print2DUtil(Troot, 0);
    }
    void Tree:: print2DUtil(Node *root, int space)  
{  
    // Base case  
    if (root == NULL)  
        return;  
  
    // Increase distance between levels  
    space += 10;  
  
    // Process right child first  
    print2DUtil(root->right, space);  
  
    // Print current node after space  
    // count  
    cout<<endl;  
    for (int i = 10; i < space; i++)  
        cout<<" ";  
    cout<<root->value<<"\n";  
  
    // Process left child  
    print2DUtil(root->left, space);  
} 
