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
node* rotateLeft(node* &n);
node* rotateRight(node* &n);
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
    root->rb=false;
    print(root,0);
  }
  return 0;
}
node*rotateLeft(node* &n){//& 
  cout<<"rotate left"<<endl;
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
node*rotateRight(node* &n){
  cout<<"rotate right"<<endl;
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
  /**
     node* empty=new node();
     empty->parent=root;
    
   **/
  if(!root){
    if(p==root){
      root=new node();
      //root->parent=NULL
      root->left=NULL;
      root->right=NULL;
      //root->lr=NULL
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
    insertMaintenance(root);
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
  cout<<"hello!"<<endl;
  while(n->parent->rb==true){//1. 
    cout<<"1."<<endl;
    if(n->parent==n->parent->parent->right){//2.
      //
      node* u=n->parent->parent->left;
      if(u!=NULL){//my addition
	if(u->rb==true){//Case1 a.
	  cout<<"case1"<<endl;
	  u->rb=false;
	  n->parent->rb=false;
	  n->parent->parent->rb=true;
	  n=n->parent->parent;//Case1 b.
	}
      }
      //
      else if(u==NULL || u->rb==false){//added if part of else
	if(n==n->parent->left){//Case2 c.
	  cout<<"case2"<<endl;
	  n=n->parent;
	  rotateLeft(n);//Case2 d.
	}
	//                                                            
	cout<<"case3"<<endl;
	n->parent->rb=false;//Case3 e.                             
	n->parent->parent->rb=true;
	rotateLeft(n->parent->parent);//Case3 f.                                      
      //
      }
    }
     else{//3.
       cout<<"else"<<endl;
       node* u=n->parent->parent->right;//I think the problem is NULL nodes
       if(u!=NULL&&u->rb==true){//3. a.
	 cout<<"3.a."<<endl;
	 u->rb=false;
	  n->parent->rb=false;
	  n->parent->parent->rb=true;
	  n=n->parent->parent;//3. b.
	}
       else{
	 cout<<"3.c."<<endl;
	 if(n==n->parent->right){//3. c.
	   n=n->parent;
	   rotateLeft(n);
	 }
	 n->parent->rb=false;//3. d.
	 cout<<"before"<<endl;
	 n->parent->parent->rb=true;//3. e.
	 cout<<"after"<<endl;
	 rotateRight(n->parent->parent);
	}
      }
    //if(n->parent==NULL){
    //break;
    //}
    //problem with gp when there is no gp
  }
  cout<<"end"<<endl;
  //4. set root black
}
