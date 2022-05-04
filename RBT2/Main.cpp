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
    node* u=g->right;
  }else{//u is left
    node* u=g->left;
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
    //new node had been added as red
    if(p->rb==false){
      return;
    }
    if((g=p->parent)==NULL){
      goto icase4;
    }
    if(u==NULL||u->rb==false){
      goto icase56;
    }
    p->rb=false;
    u->rb=false;
    g->rb=true;
    //current = g
    //while loop
    
  icase4:
    p->rb=false;
    return;
  icase56:
    //rotate(P);
    //current=parent;
    //p=g->child
  icase6:
    //rotate(t,g,);
    //p->color=black;
    //g->color=red;
    //return;
    return;
  }else if(num<root->key){
    add(root->left,num,root);
  }else{
    add(root->right,num,root);
  }
}
node* rotate(node* &p,bool side){
  node* g=p->parent;
  node* s;
  if(p<g){//s is right
    node* s=g->right;
  }else{//s is left
    node* s=g->left;
  }
  node* c;
  //assert
  if(side==true){
    c=p->left;
    p->right=c;
    s->left=p;
    p->parent=s;
    s->parent=g;
  }else{
    c=p->right;
    p->left=c;
    s->right=p;
    p->parent=s;
    s->parent=g;
  }
  //if(g!=NULL){
    
  //}else{

  //}
  return s;
}

