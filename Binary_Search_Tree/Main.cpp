#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <math.h>
using namespace std;
struct node{
  int data;
  node* parent;
  node* left;//less
  node* right;//greater
};
void add(node* &root, int num);
void print(node* &root, int space);
bool search(node* root, int num);
int main(){
  node* root=new node();
  //root->left=NULL;
  //root->right=NULL;
  //root->data=0;
  root=NULL;
  bool loop=true;
  while(loop){
    char input1[20];
    //cout<<root->data;
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
	add(root, num);
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
	    add(root,num);
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
    }else if(strcmp(input1,"quit")==0){
      break;
    }else{
      cout<<"invalid input, try again.";
    }
    cout<<endl;
  }
  return 0;
}
void add(node* &root, int num){
  if(!root){//add
    root = new node();
    root->data=num;
    root->left=NULL;
    root->right=NULL;
    //}else if(root->data==0){
    //root->data=num;
  }else if(num<=root->data){//less
    add(root->left, num);
  }else{//more
    add(root->right,num);
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
