#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <math.h>
using namespace std;
struct node{
  int data;
  node* left;//less
  node* right;//greater
  node* parent;
};
void add(node* &root, int num, node* &p);
void print(node* &root, int space);
bool search(node* root, int num);
void remove(node* &root, int num);
void remove2(node* &root, int num);
int main(){
  node* root=new node();
  root=NULL;
  bool loop=true;
  while(loop){
    char input1[20];
    cout<<"'add', 'print', 'search', 'remove', or 'quit'?: ";
    cin.get(input1,20);
    cin.get();
    if(strcmp(input1,"add")==0){
      cout<<"Add by 'console' or 'file'?: ";
      char input2[20];
      cin.get(input2,20);
      cin.get();
      if(strcmp(input2,"console")==0){
	cout<<"Enter a number: ";
	int num;
	cin>>num;
	cin.get();
	add(root, num, root);
      }
      else if(strcmp(input2,"file")==0){
	cout<<"available files: ";
	cout<<"'file1'"<<endl;
	cout<<"enter a file name: ";
	char fileName[100];
	cin.get(fileName, 100);
	cin.get();
	if(strcmp(fileName,"file1")==0){
	  string numberString;
	  int num;
	  ifstream file1;
	  file1.open("file1.txt");
	  while(file1){
	    file1>>numberString;
	    num=stoi(numberString);
	    add(root,num,root);
	  }
	  file1.close();
	}
      }
    }else if(strcmp(input1,"print")==0){
      print(root, 0);
    }else if(strcmp(input1,"search")==0){
      int num;
      cout<<"enter a number to be searched for: ";
      cin>>num;
      cin.get();
      if(search(root,num)){
	cout<<num<<" is in the tree"<<endl;
      }else{
	cout<<num<<" is not in the tree"<<endl;
      }
    }else if(strcmp(input1,"remove")==0){
      int num;
      cout<<"enter a number to be removed: ";
      cin>>num;
      cin.get();
      if(search(root,num)){
	remove(root, num);
      }else{
	cout<<num<<" cannot be removed because it wasn't found in the tree"<<endl;
      }
    }else if(strcmp(input1,"quit")==0){
      break;
    }else{
      cout<<"invalid input, try again.";
    }
    cout<<endl;
  }
  return 0;
}
void add(node* &root, int num, node* &p){
  if(!root){//add
    root = new node();
    root->data=num;
    root->left=NULL;
    root->right=NULL;
    root->parent=p;
  }else if(num<=root->data){//less
    add(root->left, num,root);
  }else{
    add(root->right,num,root);
  }
}
void print(node* &root, int space){
  if(!root){
    return;
  }
  space += 3;
  print(root->right, space);
  cout<<endl;
  for(int i=3; i<space;i++){
    cout<<" ";
  }
  cout<<root->data<<"\n";
  print(root->left, space);
}
bool search(node* root, int num){
  int i=0;
  while(i==0){
    if(!root){
      return false;
    }else if(root->data==num){
      return true;
    }else if(num<root->data){
      root=root->left;
    }else{
      root=root->right;
    }
  }
  return false;
}
void remove(node* &root, int num){
  int i=0;
  while(i==0){
    if(root->data==num){
      i=1;
    }else if(root->data>num){
      root=root->left;
    }else{
      root=root->right;
    }
  }
  if(!(root->left)&&!(root->right)){
    root=root->parent;
    root->left=NULL;
    root->right=NULL;
  }else if(!(root->right)){//only a left
    if(root<root->parent){//root was less
      root=root->parent;
      root->left=root->left->left;
    }else{//root was greater
      root=root->parent;
      root->right=root->right->left;
    }
  }else if(!(root->left)){//only a right child
    if(root<root->parent){
      root=root->parent;
      root->left=root->left->right;
    }else{
      root=root->parent;
      root->right=root->right->right;
    }
  }else{
    remove2(root,num);
  }
  while(!(root->parent)){
    root=root->parent;
  }
}
void remove2(node* &root, int num){
}
