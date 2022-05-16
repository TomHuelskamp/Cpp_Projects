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
void insertMaintenance(node* &n, node* &rt);
int main(){
  bool forever=true;
  node* root=NULL;
  while(forever==true){
    int num;
    cout<<"add: ";
      cin>>num;
      cin.get();
      add(root, num, root, root);
      print(root,0);
  }
  return 0;
}
void rotateLeft(node* n, node* &rt){
  cout<<"rotateL"<<endl;
}
void rotateRight(node* n, node* &rt){//fix parents
  cout<<"rotateR"<<endl;
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
  cout<<"\n";
  print(root->left,space);
}
void insertMaintenance(node* &n,node* &rt){
  cout<<"insertM"<<endl;
  //case 1, root = black
  //case 2, if parent is black then done
  //case 3, parent and uncle are red: change parent and uncle to black. change grandparent to red, recursive;y call on grandparent
  //case 4, uncle is black, parent is left and node is right, or parent is right and node is left,, rotate through parent, mind children,, call case 5 on parent
  //case 5, uncle is black, parent and child are on the same side
  //rotate through gp, switch parent and gp colors
  node* p=n->parent;
  node* gp=p->parent;
  node* u;
  if(n==p->right){
    u=p->left;
  }else{
    u=p->right;
  }
  while(p->rb==true){//case 2
    cout<<"case2"<<endl;
    if(p->rb==true&&u!=NULL&&u->rb==true){//case 3
      cout<<"case3"<<endl;
      //parent and uncle are red
      p->rb=false;
      u->rb=false;
      gp->rb=true;
      insertMaintenance(gp,rt);
    }else if(u==NULL||u->rb==false){//case 4
      if(p==gp->left&&n==p->right){
	cout<<"case4"<<endl;
	//rotate through p (fix children)
	//case 5 on parent
      }else if(p==gp->right&&n==p->left){
	cout<<"case4"<<endl;
      }
    }else if(u==NULL||u->rb==false){
      if(p==gp->left&&n==p->left){//case 5
	cout<<"case5"<<endl;
	//rotate through gp
	//switch parent and gp colors
      }else if(p==gp->right&&n==p->right){//case 5
	cout<<"case5"<<endl;
      }
    }
  }
  rt->rb=false;
}                                                
      
