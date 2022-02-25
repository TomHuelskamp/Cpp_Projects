#include <iostream>
#include <cstring>
using namespace std;
struct node{
  char* value;
  node* next;
};
void push(node* &,char*);
void pop(node* &);
char* peek(node*);
void enqueue(node* &, char*);
void dequeue(node* &);
char* test(node*);
int main(){
  node* stackHead = new node();
  stackHead->value=NULL;
  node* queueHead = new node();
  queueHead->value=NULL;
  bool loop=true;
  char expression[50];
  cin.get(expression, 50);
  cin.get();
  cout<<strlen(expression);
  for(int i=0; i<strlen(expression);i++){
    if(expression[i]>='1'&&expression[i]<=9){//number
      cout<<"number";
    }else if(expression[i]>='('&&expression[i]<='+'){//operator
      cout<<"operator";
    }
    else if(expression[i]==' '){//space
      cout<<"space";
    }
    else{//invalid
      cout<<"invalid";
    }
    cout<<" ";
  }
  /**while(loop){
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
    }

    else if(strcmp(choice,"pop")==0){
      pop(stackHead);
    }

    else if(strcmp(choice,"peek")==0){
      cout<<*(peek(stackHead))<<endl;
    }

    else if(strcmp(choice,"enqueue")==0){
      cout<<"enter enqueue char: ";
      cin>>input;
      cin.get();
      enqueue(queueHead, input);
    }
    
    else if(strcmp(choice,"dequeue")==0){
      dequeue(queueHead);
    }
    
    else if(strcmp(choice,"test")==0){
      cout<<*(test(queueHead))<<endl;
      }
  }**/
  return 0;
}
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
char* peek(node* stackHead){
  //if(stackHead->value==NULL){
  //cout<<"cannot peek, stack is empty"<<endl;
  //return
      //}else{
  //cout<<stackHead->value<<endl;
  //}
  return stackHead->value;
}
void enqueue(node* &queueHead, char* input){
  //node* queuqueTemp = new node();
  if(queueHead->value==NULL){//if the queue is empty (there is only a null node)
    // cout<<"first"<<endl;
    node* queueTemp = new node();
    queueTemp->value=NULL;
    queueHead->value=input;
    queueHead->next=queueTemp;
  }else{
    // cout<<"not first"<<endl;
    node* queueTemp = new node();
    queueTemp = queueHead;
    while(queueTemp->next->next!=NULL){
      queueTemp=queueTemp->next;
    }
    node* queueTemp2 = new node();
    node* queueTail = new node();
    queueTail->value=NULL;
    queueTemp2->value=input;
    queueTemp->next=queueTemp2;
    queueTemp2->next=queueTail;
  }
}
void dequeue(node* &queueHead){
  if(queueHead->value==NULL){
    cout<<"cannot dequeue, queue is empty"<<endl;
  }else{
    node* queueTemp = new node();
    queueTemp=queueHead->next;
    delete queueHead;
    queueHead=queueTemp;
  }
}
char* test(node* queueHead){
  return queueHead->value;
}