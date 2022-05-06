#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
struct node{
  int key;
  node* parent;
  node* left;
  node* right;
  bool lr;//left right
  bool rb;//red black
};
void add(node* &root, int num, node* &p);
void print(node* root, int space);
node* rotateLeft(node* n);
node* rotateRight(node* n);
void insertMaintenance(node* &n);
int main(){
  bool forever=true;
  node* root=NULL;
  while(forever==true){
    int num;
    cout<<"add: ";
    cin>>num;
    cin.get();
    add(root, num, root);
    print(root,0);
  }
  return 0;
}
node*rotateLeft(node* n){//& ?
  node* r=n->right;
  node* l=n->left;
  r->left=n;
  n->right=l;
  n->parent=r;
  if(l!=NULL){
    l->parent=n;
  }
  return(r);
}
node*rotateRight(node* n){
  node* r=n->right;
  node* l=r->right;
  r->right=n;
  n->left=l;
  n->parent=r;
  if(l!=NULL){
    l->parent=n;
  }
  return(r);
}
void add(node* &root, int num, node* &p){
  if(!root){
    if(p==root){
      root=new node();
      //root->parent=NULL
      root->left=NULL;
      root->right=NULL;
      //root->lr=NULL
      root->rb=false;
      root->key=num;
      return;
      //root has been planted as black
    }else if(!root){
      root=new node();
      root->key=num;
      root->parent=p;
      root->left=NULL;
      root->right=NULL;
      if(p->key>root->key){
	root->lr=true;
      }else{
	root->lr=false;
      }
      root->rb=true;
    }
  }else if(num<root->key){
    add(root->left,num,root);
  }else{
    add(root->right,num,root);
  }
}

void print(node* root, int space){
  if(!root){
    return;
  }
  space +=3;
  print(root->right, space);
  cout<<endl;
  for(int i=3; i<space; i++){
    cout<<" ";
  }
  cout<<root->key;
  if(root->rb){
    cout<<"r";
  }else{
    cout<<"b";
  }
  cout<<"\n";
  print(root->left,space);
}
void insertMaintenance(node* &n){
  node* p=n->parent;
  node* gp=p->parent;
  while(p->rb!=FALSE){//1. 
    if(p->lr==TRUE){//2.
      //
      if(gp->right->rb==true){//Case1 a.
	gp->right->rb=false;
	gp->left->rb=false;
	gp->rb=true;
	n=gp;//Case1 b.
      }
      //
      else if(n==p->right){//Case2 c.
	n=p;
	rotateLeft(n);//Case2 d.
      }
    }
  }
}
