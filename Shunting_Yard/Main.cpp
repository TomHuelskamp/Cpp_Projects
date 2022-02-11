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
  node* stackHead = new node();
  stackHead->value=NULL;
  node* queueHead;
  bool loop=true;
  while(loop){
    char choice[50];
    cout<<"push, pop, peek, enqueue, or dequeue: ";
    cin.get(choice, 50);
    cin.get();
    char *input=new char[1];
    if(strcmp(choice,"push")==0){
      cout<<"enter push char: ";
      cin>>input;
      cin.get();
      push(stackHead,input);
    }else if(strcmp(choice,"pop")==0){
      pop(stackHead);
    }else if(strcmp(choice,"peek")==0){
      peek(stackHead);
    }
  }
  return 0;
}
//need to add null for first new node
//need to prevent the user from deleting/modifying empty stack
void push(node* &stackHead, char* input){
  node* stackTemp = new node();
  stackTemp->value = input;
  stackTemp->next = stackHead;
  stackHead = stackTemp;
}
void pop(node* &stackHead){
  if(stackHead->value==NULL){
    cout<<"cannot pop, stack is already empty"<<endl;
  }else{
    node* stackTemp = new node();
    stackTemp=stackHead->next;
    delete stackHead;
    stackHead=stackTemp;
  }
  }
void peek(node* stackHead){
  if(stackHead->value==NULL){
    cout<<"cannot peek, stack is empty"<<endl;
  }else{
  cout<<stackHead->value<<endl;
  }
}
