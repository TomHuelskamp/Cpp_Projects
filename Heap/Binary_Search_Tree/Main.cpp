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
int main(){
  node* root=new node();
  root->left=NULL;
  root->right=NULL;
  root->data=0;

  bool loop=true;
  while(loop){
    cout<<"Enter by 'console' or 'file'?: ";
    char input[20];
    cin.get(input,20);
    cin.get();
    
    if(strcmp(input,"console")==0){
      cout<<"Enter a number: ";
      int num;
      cin>>num;
      cin.get();
      add(root, num);
      cout<<root->data;
    }

    else if(strcmp(input,"file")==0){
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
    else{

    }
  }
  return 0;
}
void add(node* &root, int num){
  if(!root){//add
    root = new node();
    root->data=num;
    root->left=NULL;
    root->right=NULL;
  }else if(num<=root->data){//less
    add(root->left, num);
  }else{//more
    add(root->right,num);
  }
}

