#include <iostream>
#include <cstring>
using namespace std;
struct node{
  char value;
  node* next;
};
void push(node* &,char);
void pop(node* &);
char peek(node*);
void enqueue(node* &, char);
void dequeue(node* &);
char test(node*);
void printOutput(node*);
int main(){
  node* stackHead = new node();
  stackHead->value='\0';
  node* queueHead = new node();
  queueHead->value='\0';
  bool loop=true;
  char expression[50];
  cin.get(expression, 50);
  cin.get();
  int stacklength=0;

  for(int i=0; i<strlen(expression);i++){
    char o2 = expression[i];
    int o2p;
    char o2a;
    if(o2=='+'){
      o2p=2;
      o2a='l';
    }else if(o2=='-'){
      o2p=2;
      o2a='l';
    }else if(o2=='*'){
      o2p=3;
      o2a='l';
    }else if(o2=='/'){
      o2p=3;
      o2a='l';
    }else if(o2=='^'){
      o2p=4;
      o2a='r';
    }
    if(o2>='1'&&o2<='9'){//number
      enqueue(queueHead, o2);//pushing number to the output queue
    }
    
    else if(o2>='('&&o2<='+'||o2=='-'||o2=='/'||o2=='^'){//operator
      if((o2=='+'||o2=='-')&& (peek(stackHead)=='*'||peek(stackHead)=='/')){//lower precedence head (multiply or divide)
	while(stacklength>0){
	  enqueue(queueHead, peek(stackHead));
	  pop(stackHead);
	  stacklength--;
	}
	push(stackHead,o2);
	stacklength++;
      }else if(o2=='('){//left parentheses
	push(stackHead, o2);
	stacklength++;
      }else if(o2==')'){//right parentheses
	while(peek(stackHead)!='('){
	  enqueue(queueHead, peek(stackHead));
	  pop(stackHead);
	  stacklength--;
	}
	//left parentheses found and discarded:
	pop(stackHead);
	stacklength--;
      }else{//higher precedence head
	push(stackHead, o2);//pushing operator to the operator stack
	stacklength++;
      }
    }
    else if(o2==' '){//space
    }
    else{//invalid
      cout<<endl<<"invalid expression, try again"<<endl;
      break;
    }
  }
  while(stacklength>0){
    enqueue(queueHead, peek(stackHead));
    pop(stackHead);
    stacklength--;
  }
  printOutput(queueHead);
  return 0;
}

void push(node* &stackHead, char input){
  node* stackTemp = new node();
  stackTemp->value = input;
  stackTemp->next = stackHead;
  stackHead = stackTemp;
}
void pop(node* &stackHead){
  if(stackHead->value=='\0'){
    cout<<"cannot pop, stack is already empty"<<endl;
  }else{
    node* stackTemp = new node();
    stackTemp=stackHead->next;
    delete stackHead;
    stackHead=stackTemp;
  }
}
char peek(node* stackHead){
  return stackHead->value;
}
void enqueue(node* &queueHead, char input){
  if(queueHead->value=='\0'){//if the queue is empty (there is only a null node)
    node* queueTemp = new node();
    queueTemp->value='\0';
    queueHead->value=input;
    queueHead->next=queueTemp;
  }else{
    node* queueTemp = new node();
    queueTemp = queueHead;
    while(queueTemp->next->next!='\0'){
      queueTemp=queueTemp->next;
    }
    //the new node is right before the tail
    node* queueTemp2 = new node();
    node* queueTail = new node();
    queueTail->value='\0';
    queueTemp2->value=input;
    queueTemp->next=queueTemp2;
    queueTemp2->next=queueTail;
  }
}
void dequeue(node* &queueHead){
  if(queueHead->value=='\0'){
    cout<<"cannot dequeue, queue is empty"<<endl;
  }else{
    node* queueTemp = new node();
    queueTemp=queueHead->next;
    delete queueHead;
    queueHead=queueTemp;
  }
}
char test(node* queueHead){
  return queueHead->value;
}
void printOutput(node* queueHead){
  cout<<queueHead->value;
  if(queueHead->next->value!='\0'){
    printOutput(queueHead->next);
  }
}
