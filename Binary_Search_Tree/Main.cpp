//This program stores integers between 1 and 1000 in a binary search tree
//Thomas Huelskamp
//April 24, 2022
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
  while(loop){//Prompts the user for the different funcitons: add, print, search, remove, and quit
    char input1[20];
    cout<<"'add', 'print', 'search', 'remove', or 'quit'?: ";
    cin.get(input1,20);
    cin.get();
    if(strcmp(input1,"add")==0){//add
      cout<<"Add by 'console' or 'file'?: ";
      char input2[20];
      cin.get(input2,20);
      cin.get();
      if(strcmp(input2,"console")==0){//add by console
	cout<<"Enter a number: ";
	int num;
	cin>>num;
	cin.get();
	add(root, num, root);
      }
      else if(strcmp(input2,"file")==0){//add by file
	cout<<"available files: ";//file prompt
	cout<<"'file1'"<<endl;
	cout<<"enter a file name: ";
	char fileName[100];
	cin.get(fileName, 100);
	cin.get();
	if(strcmp(fileName,"file1")==0){//file reading 
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
	  remove(root,num);
	}
      }
    }else if(strcmp(input1,"print")==0){//print
      print(root, 0);
    }else if(strcmp(input1,"search")==0){//search
      int num;
      cout<<"enter a number to be searched for: ";
      cin>>num;
      cin.get();
      if(search(root,num)){
	cout<<num<<" is in the tree"<<endl;
      }else{
	cout<<num<<" is not in the tree"<<endl;
      }
    }else if(strcmp(input1,"remove")==0){//remove
      int num;
      cout<<"enter a number to be removed: ";
      cin>>num;
      cin.get();
      if(search(root,num)){//checking the number is present with search
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
void add(node* &root, int num, node* &p){//add function
  if(!root){//creating new node
    root = new node();
    root->data=num;
    root->left=NULL;
    root->right=NULL;
    root->parent=p;
  }else if(num<=root->data){//less,left
    add(root->left, num,root);
  }else{//more,right
    add(root->right,num,root);
  }
}
void print(node* &root, int space){//printing the binary search tree
  if(!root){//empty tree
    return;
  }
  //code learned from GeeksForGeeks
  space += 3;
  print(root->right, space);//call right
  cout<<endl;
  for(int i=3; i<space;i++){//print spaces
    cout<<" ";
  }
  cout<<root->data<<"\n";//print number
  print(root->left, space);//call left
}
bool search(node* root, int num){//search
  int i=0;
  while(i==0){//continous loop
    if(!root){//not found
      return false;
    }else if(root->data==num){//found
      return true;
    }else if(num<root->data){//traversal
      root=root->left;
    }else{
      root=root->right;
    }
  }
  return false;
}
void remove(node* &root, int num){//remove
  node* counter = root;
  bool loop=true;//contionus loop used to navigate array
  int LR=0;//keeps track if counter is a left or right child
  int rn=0;//keeps track of the number which needs to be removed in remove2
  while(loop){
    if(counter->data==num){//target number found
      if(!(counter->left)&&!(counter->right)){//no children
	counter=counter->parent;
	if(LR==1){
	  counter->left=NULL;
	}else{
	  counter->right=NULL;
	}
	loop=false;
      }else if(!(counter->left)||!(counter->right)){//one child
	node* n;
	if(!(counter->right)){//assigns child to replace parent
	  n=counter->left;
	}else{
	  n=counter->right;
	}
	counter=counter->parent;
	if(LR==1){
	  counter->left=n;
	}else{
	  counter->right=n;
	}
	loop=false;
      }else{//two children
	node* n = counter;//used to find the replacement node
	n=counter->left;
	while(n->right!=NULL){//closest smaller value
	  n=n->right;
	}
	int store = counter->data;
	counter->data=n->data;//replaces removed node
	rn=n->data;
	loop=false;
      }
    }else if(counter->data>num){//traversing
      counter=counter->left;
      LR=1;
    }else{
      counter=counter->right;
      LR=2;
    }
  }
  remove2(root,rn);//removes the old redundant number
}
 
void remove2(node* &root, int num){
  if(num==0){//nothing happens if a 2 node parent wasn't removed
  }else{
    node* counter = root;
    bool loop=true;
    int LR=0;
    while(loop){//continous loop to climb the tree                          
      if(counter->data==num&&!(counter->left)&&!(counter->right)){//removes number by reassigning parents             
        counter=counter->parent;
        if(LR==1){
          counter->left=NULL;
        }else{
          counter->right=NULL;
        }
        loop=false;							       
      }else if(num>counter->data){//traversing
	counter=counter->right;
	LR=2;
      }else{
	counter=counter->left;
	LR=1;
      }
    }
  }
}
