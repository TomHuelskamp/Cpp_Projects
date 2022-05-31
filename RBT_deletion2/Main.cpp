//This program sorts numbers read in from a file or entered in console in a red black tree
//Thomas Huelskamp
//May 19, 2022
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
  bool nill;
};
void add(node* &root, int num, node* &p, node* &r);//adds numbers into an unbalanced tree
void print(node* root, int space);//prints tree
void rotateLeft(node* n, node* &rt);//left rotation
void rotateRight(node* n, node* &rt);//right rotation
void insertMaintenance(node* n, node* &rt);//balances the tree after insert
void remove(node* root, node* &r, int num);
void search(node* root, int num);
void deleteMaintenance(node* x, node* &rt);
int main(){
  bool forever=true;
  //node* root=NULL;//creating the tree's root
  node* root=new node();
  root->rb=false;
  root->nill=true;
  while(forever==true){
    cout<<"do you want to 'add' from console, 'read' from file,  'delete', or 'search'?: ";//read or add
    char input[20];
    cin.get(input,20);
    cin.get();
    if (strcmp(input,"read")==0){//read from a file 
      string numberString;
      int num=0;
      int num1=-1;
      ifstream file1;
      file1.open("file2.txt");//using file1.txt file
      while(file1){
	file1>>numberString;
	num=stoi(numberString);
	if(num==num1){//reading stops if it finds two consecutive numbers in the file
	  break;
	}
	num1=num;
	add(root,num,root,root);//add
	print(root,0);//print after each number is added
      }
      file1.close();
    }else if(strcmp(input,"quit")==0){//quit
      break;
    }else if(strcmp(input,"delete")==0){//delete
      int num;
      cout<<"delete: ";
      cin>>num;
      cin.get();
      remove(root,root,num);
      print(root,0);
    }else if(strcmp(input,"print")==0){//print
      print(root,0);
    }else if(strcmp(input,"search")==0){//search
      int num;
      cout<<"search for: ";
      cin>>num;
      cin.get();
      search(root,num);
    }else{//otherwise, assumes the user wants to add from  console
      int num;
      cout<<"add: ";
      cin>>num;
      cin.get();
      add(root,num,root,root);//add
      print(root,0);//print the new, updated tree
    }
  }
  return 0;
}
void rotateLeft(node* n, node* &rt){//used for left rotations
  cout<<"rotate left"<<endl;
  node* c=n;
  node* l=n->left;
  node* r=n->right;
  node* p=n->parent;
  bool rootParentFix = false;//for when the node used to 'pivot' is parent
  if(n==rt){
    rootParentFix=true;
  }
  if(n->right->nill!=true){//ROTATE A, for when a chain of 3 consecutive numbers is being turned into a parent and two children
    node* rl=r->left;
    cout<<"rotate A"<<endl;
    n=r;
    n->parent=c->parent;
    n->left=c;
    n->left->parent=n;
    //n->left->right->nill=true;
    n->left->right=new node();
    n->left->right->nill=true;
    n->left->right->rb=false;
    n->left->right->parent=n->left;
    //n->left->right=NULL;
    node* nl=n->left;
    while(nl->right->nill!=true){
    nl=nl->right;
    }
    nl->right=rl;
    if(nl->right!=NULL){
      nl->right->parent=nl;
    }
    if(rootParentFix){
      rt=n;
      //rt->parent->nill=true;
      rt->parent=NULL;
    }else{
      n->parent->right=n;
      while(n->parent!=NULL){
	n=n->parent;
      }
      rt=n;
      rt->parent=NULL;
    }
  }else{//ROTATE B, turning an unlinear chain of 3 consecutive numbers into an organized chain from greatest to least
    cout<<"rotate B"<<endl;
    //n->left->nill=true;
    n->left=new node();
    n->left->parent=n;
    n->left->nill=true;
    n->left->rb=false;
    //
    l->parent=p;
    l->right=n;
    n->parent=l;
    p->right=l;
    while(p->parent!=NULL){
      p=p->parent;
    }
    rt=p;
  }
}
void rotateRight(node* n, node* &rt){//used for right rotations, this is all identical to rotateLeft, besides that all the sides are reversed
  cout<<"rotate right"<<endl;
  node* c=n;
  node* l=n->left;
  node* r=n->right;
  node* p=n->parent;
  bool rootParentFix=false;
  if(n==rt){
    rootParentFix=true;
  }
  if(n->left->nill!=true){//ROTATE A
    node* lr=l->right;
    cout<<"rotate A"<<endl;
    n=l;
    n->parent=c->parent;
    n->right=c;
    n->right->parent=n;
    //n->right->left->nill=true;
    n->right->left=new node();
    n->right->left->nill=true;
    n->right->left->rb=false;
    n->right->left->parent=n->right;
    //
    node* nr=n->right;
    while(nr->left->nill!=true){
      nr=nr->left;
    }
    nr->left=lr;
    if(nr->left->nill!=true){
      nr->left->parent=nr;
    }
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
    // n->right->nill=true;
    n->right=new node();
    n->right->parent=n;
    n->right->nill=true;
    n->right->rb=false;
    //
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
void add(node* &root, int num, node* &p, node* &rt){//adding numbers into the tree
  if(root==NULL || root->nill==true){//if the node is null, and the program is at the end of a leaf, add the input number
    if(p==root){//if the input is the first number being added, parent is NULL and is black
      root=new node();
      
      // root->left=fill;
      //oot->left->parent=root;
      root->left=new node();
      root->left->nill=true;
      root->left->rb=false;
      root->left->parent=root;
      //root->right=fill;
      //root->right->parent=root;
      root->right=new node();
      root->right->nill=true;
      root->right->rb=false;
      root->right->parent=root;
      
      root->rb=false;
      root->key=num;
      root->parent=NULL;
      root->nill=false;
      cout<<"root key: "<<root->key<<endl;
      return;
    }else if(root->nill==true){//if the input isn't the first number, and has parents, and is red
      root=new node();
      root->key=num;
      root->parent=p;

      root->left=new node();
      root->left->nill=true;
      root->left->rb=false;
      root->left->parent=root;
      root->right=new node();
      root->right->nill=true;
      root->right->rb=false;
      root->right->parent=root;
      /** if(p->key>root->key){
	root->lr=true;
      }else{
	root->lr=false;
	}**/
      root->rb=true;
      root->nill=false;
      cout<<"root key: "<<root->key<<endl;
    }
    insertMaintenance(root,rt);//calling maintenence to balance the tree
  }else if(num<root->key){//recursively navigating the tree to get to a leaf
    add(root->left,num,root,rt);
  }else{//recursively navigating the tree to get to a leaf
    add(root->right,num,root,rt);
  }
}

void print(node* root, int space){//prints the tree using spaces to represent different levels and lines to represent different sides
  if(!root||root->nill==true){//root is empty
    return;
  }
  space +=3;
  print(root->right, space);//calls the right child of root
  cout<<endl;
  for(int i=3; i<space; i++){//adds the right number of spaces
    cout<<" ";
  }
  cout<<root->key;//prints
  if(root->rb){
    cout<<"r";
  }else{
    cout<<"b";
  }
  if(root->parent!=NULL){
    //cout<<"-p:"<<root->parent->key;
  }
  cout<<"\n";
  print(root->left,space);//calls the left child of root
}
void insertMaintenance(node* n,node* &rt){
  print(rt,0);
  cout<<"tree maintenance"<<endl;
  //I learned the cases and format from Programiz
  while(n->parent->rb==true){//continues to go through the tree if parent is red
    if(n->parent==n->parent->parent->right){//Parent is on the right
      node* u=n->parent->parent->left;
      if(u!=NULL&&u->rb==true){//uncle is red
	if(u->rb==true){
	  u->rb=false;
	  n->parent->rb=false;
	  n->parent->parent->rb=true;
	  n=n->parent->parent;
	}
      }else if(u==NULL || u->rb==false){//uncle is black
	if(n==n->parent->left){
	  n=n->parent;
	  rotateLeft(n,rt);
	}
	n->parent->rb=false;                             
	n->parent->parent->rb=true;
	rotateLeft(n->parent->parent,rt);                                    
      }
    }else{//parent is on the left
       node* u=n->parent->parent->right;
       if(u!=NULL&&u->rb==true){//uncle is red
	 if(u->rb==true){
	   u->rb=false;
	   n->parent->rb=false;
	   n->parent->parent->rb=true;
	   n=n->parent->parent;
	 }
       }else if(u==NULL || u->rb==false){//uncle is black
	 if(n==n->parent->right){
	   n=n->parent;
	   rotateRight(n,rt);
	 }
	 n->parent->rb=false;
	 n->parent->parent->rb=true;
	 rotateRight(n->parent->parent,rt);
       }
      }
    if(n==rt){//stop if the tree has been balanced through root
      break;
    }
    node* c=n;
    while(c->parent!=NULL){
    c=c->parent;
    }
    rt=c;
  }
  rt->rb=false;//set root to black
}
void remove(node* root, node* &r, int num){
  bool originalrb;
  if(root==NULL||root->nill==true ||root->key==num){//match
    if(root==NULL||root->nill==true){
      cout<<"number not foud in the tree"<<endl;
    }else{//programiz
      //node* y=root;
      node* x;
      node* p;
      node* y;
      y=root;
      cout<<"removing "<<num<<endl;
      //1.
      originalrb=y->rb;
      //2.
      if(root->left->nill==true){
	cout<<"2."<<endl;
	x=root->right;
	if(root->parent==NULL){
	  r=x;
	}else if(root==root->parent->left){
	  root->parent->left=x;
	}else{
	  root->parent->right=x;
	}
	//node* rootp=root->parent;
	if(x!=NULL){
	  x->parent=root->parent;///// PROBLEM
	  cout<<"parentIF"<<endl;
	}
      }
      //3.
      else if(root->right->nill==true){
	cout<<"3."<<endl;
	//p=root->parent
	x=root->left;
	if(root->parent==NULL){
	  r=x;
	}else if(root==root->parent->right){
	  root->parent->right=x;
	}else{
	  root->parent->left=x;
	}
	x->parent=root->parent;
	//transplant root, root->left
	/**if(root->parent==NULL){
	  r=x;
	}else if(root==root->parent->left){
	  root->parent->left=x;
	}else{
	  root->parent->right=x;
	}
	x->parent=root->parent;
	**/	
	//root=x;
	//root->parent=p;
	//p->left/right
	//parent of root
      }
      //4.
      else{
	cout<<"4."<<endl;
	node* y=root->right;
	while(y->left->nill!=true){
	  y=y->left;
	}
	cout<<"y:"<<y->key<<endl;
	originalrb=y->rb;
	x=y->right;
	cout<<"x"<<endl;
	if(y->parent==root){
	  cout<<"if"<<endl;
	  x->parent=y;///
	}else{
	  cout<<"else"<<endl;
	  if(y->parent==NULL){
	    r=x;
	  }else if(y==y->parent->left){
	    y->parent->left=x;
	  }else{
	    y->parent->right=x;
	  }
	  if(x!=NULL){
	    x->parent=y->parent;
	  }
	  //transplant y, y->right
	  y->right=root->right;
	  y->right->parent=y;
	}
	//transplant(y, root)
	node* clone=root;
	if(root->parent==NULL){
	  r=y;
	}else if(root==root->parent->left){
	  root->parent->left=y;
	}else{
	  root->parent->right=y;
	}	
	y->parent=root->parent;
	y->left=clone->left;
	y->left->parent=y;
	y->rb=clone->rb;	
      }
      delete root;
      
      if(originalrb==false){
	deleteMaintenance(x,r);
      }
    }
  }else if(num<root->key){
    remove(root->left,r,num);
  }else{
    remove(root->right,r,num);
  }
}
void search(node* root, int num){
  if(root==NULL||root->nill==true){
    cout<<"the number you are searching for cannot be found"<<endl;
  }else if(root->key==num){
    cout<<num<<" is in the tree"<<endl;
  }else if(num<root->key){
    search(root->left,num);
  }else{
    search(root->right,num);
  }
}
void deleteMaintenance(node* x, node* &rt){
  print(rt,0);
  cout<<endl<<"Delete Maintenance"<<endl;
  //if(x==NULL){
    //cout<<"x is NULL"<<endl;
    //}
  node* w;
  while(x->rb==false&&x!=rt){
   
    print(rt,0);
    cout<<"x: "<<x->key<<endl;

    if(x==x->parent->left){
      cout<<"left"<<endl;
      node* w=x->parent->right;
      if(w->rb==true){
	//case1
	w->rb=false;
	x->parent->rb=true;
	cout<<"0004"<<endl;

	//rotateRight(x->parent,rt);
	
	rotateLeft(x->parent,rt);
	//left rotate x->parent
	w=x->parent->right;
      }
      if(w->right->rb==false&&w->left->rb==false){
	//case2
	w->rb=true;
	x=x->parent;
      }else{
	if(w->right->rb==false){
	  //case3
	  w->left->rb=false;
	  w->rb=true;
	  //right rotate w
	  cout<<"0005"<<endl;
	  //rotateRight(w,rt);
	  rotateLeft(w,rt);
	  w=x->parent->right;
	}
	//case4
	w->rb=x->parent->rb;
	x->parent->rb=false;
	w->right->rb=false;
	//left rotate x parent
	cout<<"0006"<<endl;
	//rotateRight(x->parent,rt);
	rotateLeft(x->parent, rt);// original;
	//rt=x;
	x=rt;
	//////RT=X
      }
    }
    else{
      cout<<"right"<<endl;
      //VICE VERSA
      node* w=x->parent->left;
      if(w->rb==true){
	//case 1
	w->rb=false;
	x->parent->rb=true;
	cout<<"0007"<<endl;
	//rotateLeft(x->parent,rt);
	rotateRight(x->parent,rt);
	//original
	w=x->parent->left;
      }
      if(w->left->rb==false&&w->right->rb==false){
	//case 2
	w->rb=true;
	x=x->parent;
      }else{
	if(w->left->rb==false){
	//case 3
	  w->right->rb=false;
	  w->rb=true;
	  cout<<"0008"<<endl;
	  rotateLeft(w,rt);
	  w=x->parent->left;
	}
	//case 4
	w->rb=x->parent->rb;
	x->parent->rb=false;
	w->left->rb=false;
	cout<<"0009"<<endl;
	//rotateLeft(x->parent, rt);
	rotateRight(x->parent,rt); //original;
	x=rt;
	//rt=x;
	//////x=rt
      }
    }
    node* c=x;
    while(c->parent!=NULL){
      c=c->parent;
    }
    
    x->rb=false;
  }
  
}
