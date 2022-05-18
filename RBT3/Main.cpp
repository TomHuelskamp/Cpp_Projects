#include <vector>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <math.h>
using namespace std;
struct node{
  int key;
  node* parent;
  node* left;
  node* right;
  bool lr;//left right
  bool rb;//red black
};
void add(node* &root, int num, node* &p, node* &r);
void print(node* root, int space);
void rotateLeft(node* n, node* &rt);
void rotateRight(node* n, node* &rt);
void insertMaintenance(node* n, node* &rt);
int main(){
  bool forever=true;
  node* root=NULL;
  while(forever==true){
    //cout<<"add a number by 'console' or 'file'?: ";
    //char input[20];
    //cin.get(input,20);
    //cin.get();
    //if(strcmp(input,"console")==0){
    int num;
    cout<<"add: ";
      cin>>num;
      cin.get();
      add(root, num, root, root);
      print(root,0);
      /**}else{
      string numberString;
      int num;
      ifstream file1;
      file1.open("file1.txt");
      while(file1){
	file1>>numberString;
	num=stoi(numberString);
	add(root,num,root,root);
	print(root,0);
      }
      file1.close();
      }**/
  }
  return 0;
}
void rotateLeft(node* n, node* &rt){
  cout<<"rotate left"<<endl;
  node* c=n;
  node* l=n->left;
  node* r=n->right;
  node* p=n->parent;
  bool rootParentFix = false;
  if(n==rt){
    rootParentFix=true;
  }
  if(n->right!=NULL){//ROTATE A
    cout<<"rotate A"<<endl;
    n=r;
    n->parent=c->parent;
    n->left=c;
    n->left->parent=n;
    n->left->right=NULL;
    if(rootParentFix){
      rt=n;
      rt->parent=NULL;
    }else{
      n->parent->right=n;
      while(n->parent!=NULL){
	n=n->parent;
      }
      rt=n;//
      rt->parent=NULL;
    }
    //print(rt,0);
  }else{//ROTATE B
    cout<<"rotate B"<<endl;
    n->left=NULL;
    l->parent=p;//l->parent->___=l
    l->right=n;
    n->parent=l;
    p->right=l;
    while(p->parent!=NULL){
      p=p->parent;
    }
    rt=p;
    //rt->parent=p->parent;//probably need the same parent fix as left rotate A
    //rt->parent->right=rt;//
    //print(rt,0);
  }
}
void rotateRight(node* n, node* &rt){//fix parents
  cout<<"rotate right"<<endl;
  node* c=n;
  node* l=n->left;
  node* r=n->right;
  node* p=n->parent;
  bool rootParentFix=false;
  if(n==rt){
    rootParentFix=true;
  }
  if(n->left!=NULL){//ROTATE A
    cout<<"rotate A"<<endl;
    n=l;
    n->parent=c->parent;
    n->right=c;
    n->right->parent=n;
    n->right->left=NULL;
    if(rootParentFix){
      rt=n;
      rt->parent=NULL;
    }else{
      n->parent->left=n;
      while(n->parent!=NULL){
	n=n->parent;
      }
      rt=n;//
      rt->parent=NULL;
    }
    //print(rt,0);
  }else{//ROTATE B
    cout<<"rotate B"<<endl;
    n->right=NULL;
    r->parent=p;
    r->left=n;
    n->parent=r;
    p->left=r;
    while(p->parent!=NULL){
      p=p->parent;
    }
    rt=p;
    //rt->parent=NULL;
    //rt->parent->left=rt;
    //print(rt,0);
  }
}
void add(node* &root, int num, node* &p, node* &rt){
  if(!root){
    if(p==root){
      root=new node();
      root->left=NULL;
      root->right=NULL;
      root->rb=false;
      root->key=num;
      root->parent=NULL;
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
    insertMaintenance(root,rt);
  }else if(num<root->key){
    add(root->left,num,root,rt);
  }else{
    add(root->right,num,root,rt);
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
  if(root->parent!=NULL){
  cout<<"-p:"<<root->parent->key;
  }
  cout<<"\n";
  print(root->left,space);
}
void insertMaintenance(node* n,node* &rt){
  print(rt,0);
  cout<<"tree maintenance"<<endl;
  int counter=0;
  while(n->parent->rb==true){//1.
    cout<<"-"<<endl;
    cout<<"n: "<<n->key;
    counter++;
    if(counter>10){
      break;
    }
    cout<<"number 1"<<endl;
    if(n->parent==n->parent->parent->right){//2.
      node* u=n->parent->parent->left;
      cout<<"number2"<<endl;
      if(u!=NULL&&u->rb==true){
	if(u->rb==true){//Case1 a.
	  u->rb=false;
	  n->parent->rb=false;
	  n->parent->parent->rb=true;
	  n=n->parent->parent;//Case1 b.
	}
      }else if(u==NULL || u->rb==false){//added if part of else
	cout<<"number3"<<endl;
	if(n==n->parent->left){//Case2 c.
	  n=n->parent;
	  rotateLeft(n,rt);//Case2 d.
	  //rotateRight(n,rt);
	}
	//Should do this
	cout<<"should do this"<<endl;
	n->parent->rb=false;//Case3 e.                             
	n->parent->parent->rb=true;
	rotateLeft(n->parent->parent,rt);//Case3 f.                                    
      }
    }else{//3
       node* u=n->parent->parent->right;
       if(u!=NULL&&u->rb==true){//3. a.
	 if(u->rb==true){
	   u->rb=false;
	   n->parent->rb=false;
	   n->parent->parent->rb=true;
	   n=n->parent->parent;//3. b.
	 }
       }else if(u==NULL || u->rb==false){
	 if(n==n->parent->right){//3. c.
	   n=n->parent;
	   //rotateLeft(n,rt); or
	   rotateRight(n,rt);
	 }
	 n->parent->rb=false;//3. d.
	 n->parent->parent->rb=true;//3. e.
	 rotateRight(n->parent->parent,rt);
	 //rotateRight(n->parent,rt);
       }
      }
    if(n==rt){
      break;
    }
    node* c=n;
    while(c->parent!=NULL){
      c=c->parent;
    }
    rt=c;
    //rt->rb=false;
  }
  rt->rb=false;//4.
}
