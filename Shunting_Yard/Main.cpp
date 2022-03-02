#include <iostream>
#include <cstring>
#include "Node.h"
using namespace std;
struct node{
  char value;
  node* next;
};
struct node2{
  Node* value2;
  node2* next2;
};
void push(node* &,char);
void pop(node* &);
char peek(node*);
void enqueue(node* &, char);
void dequeue(node* &);
char test(node*);
void printOutput(node*, node2* &);
void push2(node2* &, Node*);
void pop2(node2* &);
Node* peek2(node2*);
void printInfix(Node*);
void printPrefix(Node*);
void printPostfix(Node*);


int main(){
  node* stackHead = new node();
  stackHead->value='\0';
  node* queueHead = new node();
  queueHead->value='\0';
  bool loop=true;
  char expression[50];
  cout<<"Enter an expression in infix notation: ";
  cin.get(expression, 50);
  cin.get();
  int stacklength=0;

  for(int i=0; i<strlen(expression);i++){
    char o2 = expression[i];
    int o2p=0;
    char o2a='n';
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
      if(o2=='+'||o2=='-'||o2=='*'||o2=='/'||o2=='^'){//
	char o1 = peek(stackHead);
	int o1p=0;
	if(o1=='+'){
	  o1p=2;
	}else if(o1=='-'){
	  o1p=2;
	}else if(o1=='*'){
	  o1p=3;
	}else if(o1=='/'){
	  o1p=3;
	}else if(o1=='^'){
	  o1p=4;
	}
	while((stacklength!=0 && o1p>o2p)||(stacklength!=0&&o1p==o2p&&o2a=='l')){
	  enqueue(queueHead, peek(stackHead));
	  pop(stackHead);
	  stacklength--;
	  char o1 = peek(stackHead);
	  if(o1=='+'){
	    o1p=2;
	  }else if(o1=='-'){
	    o1p=2;
	  }else if(o1=='*'){
	    o1p=3;
	  }else if(o1=='/'){
	    o1p=3;
	  }else if(o1=='^'){
	    o1p=4;
	  }
	}
	push(stackHead, o2);
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
    }
    else if(o2==' '){//space
    }
    else{//invalid
      cout<<endl<<"invalid expression, try again"<<endl;
      break;
    }
  }
  }

  while(stacklength>0){
    enqueue(queueHead, peek(stackHead));
    pop(stackHead);
    stacklength--;
  }
  
  cout<<"Shunting-Yard postfix expression: ";
  node2* stackHead2 = new node2;
  stackHead2->value2=NULL;
  printOutput(queueHead, stackHead2);
  cout<<endl<<"Binary expression tree infix expression:";
  printInfix(peek2(stackHead2));
  cout<<endl<<"Binary expression tree prefix expression:";
  printPrefix(peek2(stackHead2));
  cout<<endl<<"Binary expression tree postfix espression:";
  printPostfix(peek2(stackHead2));
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

void printOutput(node* queueHead, node2* &stackHead2){
  cout<<queueHead->value<<' ';
  if(queueHead->value>='1'&&queueHead->value<='9'){//char is an oprerand, create new node and push to stack
    Node* opernd = new Node(queueHead->value, NULL, NULL);
    push2(stackHead2, opernd);
  }else if((queueHead->value>='('&&queueHead->value<='+')||queueHead->value=='-'||queueHead->value=='/'){//char is an operator, pop t1 t2 and push to stack
    Node* oper = new Node(queueHead->value, peek2(stackHead2), peek2(stackHead2->next2));
    pop2(stackHead2);
    pop2(stackHead2);
    push2(stackHead2, oper);
  }
  if(queueHead->next->value!='\0'){
    printOutput(queueHead->next, stackHead2);
  }
}
void push2(node2* &stackHead2, Node* inputNode){
  node2* stackTemp2 = new node2;
  stackTemp2->value2 = inputNode;
  stackTemp2->next2 = stackHead2;
  stackHead2 = stackTemp2;
}
void pop2(node2* &stackHead2){
  //if(stackHead2->value2==NULL){
  //cout<<"test a error";
  //}else{
  node2* stackTemp2 = new node2();
  stackTemp2=stackHead2->next2;
  delete stackHead2;
  stackHead2=stackTemp2;
  //}
}
Node* peek2(node2* stackHead2){
  return stackHead2->value2;
}
void printInfix(Node* tree){
  if(tree!=NULL){
    if(tree->getValue()=='+'
       ||tree->getValue()=='-'
       ||tree->getValue()=='*'
       ||tree->getValue()=='/'
       ||tree->getValue()=='^'){
      cout<<"(";
    }
    if(tree->getRight()!=NULL){
      printInfix(tree->getRight());
    }
    cout<<' '<<tree->getValue();
    if(tree->getLeft()!=NULL){
      printInfix(tree->getLeft());
    }
    if(tree->getValue()=='+'||
       tree->getValue()=='-'||
       tree->getValue()=='*'||
       tree->getValue()=='/'||
       tree->getValue()=='^'){
      cout<<')';
    }
     
  }
}
void printPrefix(Node* tree){
  if(tree!=NULL){
    if(tree->getRight()!=NULL){
      printPrefix(tree->getRight());
    }
    if(tree->getLeft()!=NULL){
      printPrefix(tree->getLeft());
    }
    cout<<' '<<tree->getValue();
  }
}
void printPostfix(Node* tree){
  if(tree!=NULL){
    cout<<' '<<tree->getValue();
    if(tree->getRight()!=NULL){
      printPostfix(tree->getRight());
    }
    if(tree->getLeft()!=NULL){
      printPostfix(tree->getLeft());
    }
  }
}
