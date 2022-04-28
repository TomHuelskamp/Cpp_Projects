#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;
struct node{
  int value;
  node* parent;
  node* left;
  node* right;
  bool lr;//true=left, false=right
  bool color;//true=left, false=right
};
void addByConsole(node* &root);
void addByFile();
void add(int num, node* &root, node* &p, bool plr);
void print(node* root, int space);
void sort();

int main(){
  node* root= new node();
  root=NULL;
  bool forever=true;
  while(forever){
    addByConsole(root);
    //sort(root);
    print(root, 0);
  }
  return 0;
}
void addByConsole(node* &root){
  int num;
  cout<<"enter a number to add: ";
  cin>>num;
  cin.get();
  add(num, root, root, true);//lr could become an issue?
}
void addByFile(){
}
void add(int num, node* &root, node* &p, bool plr){
if(!root){
    root=new node();
    root->value=num;
    root->left=NULL;
    root->right=NULL;
    root->parent=p;
    if(root==p){
      root->color=true;
      //root->lr=NULL;
    }else{
       root->color=false;
      if(plr){
        root->lr=true;
      }else{
        root->lr=false;
      }
    }
  }else if(num<=root->value){
    add(num, root->left, root, true);
  }else{
    add(num, root->right, root, false);
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
  cout<<root->value<<"\n";
  print(root->left,space);
}
void sort(){
}
