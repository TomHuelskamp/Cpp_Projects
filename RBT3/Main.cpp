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
    /**
    cout<<"do you want to 'add' from console or 'read' from file?: ";
    char input[20];
    cin.get(input,20);
    cin.get();
    if (strcmp(input,"read")==0){
      string numberString;
      int num=0;
      int num1=1;
      ifstream file1;
      file1.open("file1.txt");
      while(file1){
	file1>>numberString;
	num=stoi(numberString);
	if(num==num1){
	  break;
	}
	num1=num;
	add(root,num,root,root);
	print(root,0);
      }
      file1.close();
      }**/
    //else{
      int num;
      cout<<"add: ";
      cin>>num;
      cin.get();
      add(root,num,root,root);
      print(root,0);
      // }
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
    node* rl=r->left;//
    cout<<"rotate A"<<endl;
    n=r;
    n->parent=c->parent;
    n->left=c;
    n->left->parent=n;
    n->left->right=NULL;
    //
    node* nl=n->left;
    while(nl->right!=NULL){
    nl=nl->right;
    }
    nl->right=rl;
    if(nl->right!=NULL){
      nl->right->parent=nl;
    }
    //
    if(rootParentFix){
      rt=n;
      rt->parent=NULL;
    }else{
      n->parent->right=n;
      while(n->parent!=NULL){
	n=n->parent;
      }
      rt=n;
      rt->parent=NULL;
    }
  }else{//ROTATE B
    cout<<"rotate B"<<endl;
    n->left=NULL;
    l->parent=p;
    l->right=n;
    n->parent=l;
    p->right=l;
    while(p->parent!=NULL){
      p=p->parent;
    }
    rt=p;
    //rt->parent=p->parent;//probably need the same parent fix as left rotate A
    //rt->parent->right=rt;
  }
}
void rotateRight(node* n, node* &rt){
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
    node* lr=l->right;
    cout<<"rotate A"<<endl;
    n=l;
    n->parent=c->parent;
    n->right=c;
    n->right->parent=n;
    n->right->left=NULL;
    //
    node* nr=n->right;
    while(nr->left!=NULL){
      nr=nr->left;
    }
    nr->left=lr;
    if(nr->left!=NULL){
      nr->left->parent=nr;
    }
    //
    if(rootParentFix){
      rt=n;
      rt->parent=NULL;
    }else{
      n->parent->left=n;
      while(n->parent!=NULL){
	n=n->parent;
      }
      rt=n;
      rt->parent=NULL;
    }
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
  if(root->parent!=NULL){/////////
    cout<<"-p:"<<root->parent->key;
  }////////
  cout<<"\n";
  print(root->left,space);
}
void insertMaintenance(node* n,node* &rt){
  cout<<"tree maintenance"<<endl;
  int counter=0;
  while(n->parent->rb==true){//1.
    //if(counter>0){
      cout<<"-n: "<<n->key<<endl;
      print(rt,0);
      //}
    if(n->parent==n->parent->parent->right){//2.
      node* u=n->parent->parent->left;
      if(u!=NULL&&u->rb==true){
	if(u->rb==true){//Case1 a.
	  u->rb=false;
	  n->parent->rb=false;
	  n->parent->parent->rb=true;
	  n=n->parent->parent;//Case1 b.
	}
      }else if(u==NULL || u->rb==false){//added if part of else
	if(n==n->parent->left){//Case2 c.
	  n=n->parent;
	  //rotateRight(n,rt);
	  rotateLeft(n,rt);//Case2 d.
	}
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
	   rotateRight(n,rt);
	   //rotateLeft(n,rt);
	 }
	 n->parent->rb=false;//3. d.
	 n->parent->parent->rb=true;//3. e.
	 rotateRight(n->parent->parent,rt);
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
  }
  rt->rb=false;//4.
}
