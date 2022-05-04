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
node* rotate(node* &p, bool side);
int main(){
  node* root = NULL;
  add(root, 5, root);
  return 0;
}
void add(node* &root, int num, node* &p){
  node* g=p->parent;
  node* u;
  if(p<g){//u is right
    u=g->right;
  }else{//u is left
    u=g->left;
  }
  
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
  }else if(num<root->key){
    add(root->left,num,root);
  }else{
    add(root->right,num,root);
  }
}


