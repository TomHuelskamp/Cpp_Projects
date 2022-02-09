#include <iostream>
#include <cstring>
using namespace std;
struct node{
  char* value;
  node* next;
};
void push(node* &,char*);
void pop(node* &);
void peek(node*);
int main(){
  node* stackh;
  node* queueh;
  cout<<"test A"<<endl;
  bool loop=true;
  while(loop){
    int choice;
    char *input=new char[1];
    cin>>choice;
    if(choice==1){
      cout<<"testC"<<endl;
      cin>>input;
      cout<<"testB"<<endl;
      push(stackh,input);
    }else if(choice==2){
      pop(stackh);
    }else if(choice==3){
      peek(stackh);
    }
  }
  return 0;
}
//need to add null for first new node
//need to prevent the user from deleting/modifying empty stack
void push(node* &stackh, char* input){
  node* stackt = new node();
  stackt->value = input;
  stackt->next = stackh;
  stackh = stackt;
}
void pop(node* &stackh){
  node* stackt = new node();
  stackt=stackh->next;
  delete stackh;
  stackh=stackt;
}
void peek(node* stackh){
  cout<<stackh->value<<endl;
}
