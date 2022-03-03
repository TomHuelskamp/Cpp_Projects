//This program takes in an expression in infix notation and translates it into postfix notation using the shunting yard algorith, then it creates a binary expression tree and traverses the tree finding infix, prefix, and postfix translations of the expression
//Thomas Huelskamp
//March 2, 2022
#include <iostream>
#include <cstring>
#include "Node.h"//the class Node is used for each part of the tree, it contains the char value and left and right pointers to other parts of the tree
using namespace std;
struct node{//node is used to add and remove operators and operands from the operator stack and output queue
  char value;
  node* next;
};
struct node2{//node2 is used to add and remove tree nodes from the tree stack
  Node* value2;
  node2* next2;
};
void push(node* &,char);//push is used to add operators to the operator stack
void pop(node* &);//pop is used to remove operators from the operator stack
char peek(node*);//peek is used to check the top operator of the operator stack
void enqueue(node* &, char);//enqueue is used to add to the output queue
void dequeue(node* &);//dequeue is used to remove from the output queue
char test(node*);//test returns the top charachter from the output queue
void printOutput(node*, node2* &);//print outpur prints the output queue
void push2(node2* &, Node*);//push2 is used to push tree nodes to the tree stack
void pop2(node2* &);//pop2 is used to pop tree nodes from the tree stack
Node* peek2(node2*);//peek2 is used to view the top tree node from the tree stack
void printInfix(Node*);//print infix prints the infix expression from the expression tree
void printPrefix(Node*);//print prefix prints the prefix expression from the expression tree
void printPostfix(Node*);//print postfix prints the postfix expression from the expression tree

int main(){
  node* stackHead = new node();//create a head for the stack linked list
  stackHead->value='\0';
  node* queueHead = new node();//create a head for the queue linked list
  queueHead->value='\0';
  char expression[50];
  cout<<"Enter an expression in infix notation: ";//takes in the user's expression
  cin.get(expression, 50);
  cin.get();
  int stacklength=0;//stack length is used when adding and removing from the operator stack

  for(int i=0; i<strlen(expression);i++){//for loop goes through the user's input expression
    char o2 = expression[i];//character o2 is the operator  which is about to be added to the stack
    int o2p=0;//o2p is the prescedence of the operand
    char o2a='n';//o2a is the left or right association of the operand
    //sets the operator's prescedence and association
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
      enqueue(queueHead, o2);//pushes the number to oputput  queue
    }
    else if(o2>='('&&o2<='+'||o2=='-'||o2=='/'||o2=='^'){//operand or parenthases
      if(o2=='+'||o2=='-'||o2=='*'||o2=='/'||o2=='^'){//operand
	char o1 = peek(stackHead);//character o1 is the operator at the top of the operator stack
	int o1p=0;
	//sets the operator's prescedence and association
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
	while((stacklength!=0 && o1p>o2p)||(stacklength!=0&&o1p==o2p&&o2a=='l')){//while the operator at the top of the stack has greater prescedence, or the two are the same, and the new operator has a left associativity, add the top of the stack to the output queue
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
      }else if(o2=='('){//left parentheses added to operator stack
	push(stackHead, o2);
	stacklength++;
      }else if(o2==')'){//right parentheses
	while(peek(stackHead)!='('){//everything between the right and left parentheses is added to the oputput queue and removed from the operator stack
	  enqueue(queueHead, peek(stackHead));
	  pop(stackHead);
	  stacklength--;
	}
	pop(stackHead);//discard left parentheses
	stacklength--;
    }
    else if(o2==' '){//space, the program works wether or not the user has spaces between characters
    }
    else{//invalid
      cout<<endl<<"invalid expression, try again"<<endl;
      break;
    }
  }
  }
  while(stacklength>0){//goes through the operator stack, adding all the operators to the output queue
    enqueue(queueHead, peek(stackHead));
    pop(stackHead);
    stacklength--;
  }
  cout<<"Shunting-Yard postfix expression: ";
  node2* stackHead2 = new node2;//head for the tree stack
  stackHead2->value2=NULL;
  printOutput(queueHead, stackHead2);//prints output and creates expression tree
  cout<<endl<<"Binary expression tree infix expression:";
  printInfix(peek2(stackHead2));//prints infix
  cout<<endl<<"Binary expression tree prefix expression:";
  printPrefix(peek2(stackHead2));//prints prefix
  cout<<endl<<"Binary expression tree postfix espression:";
  printPostfix(peek2(stackHead2));//prints postfix
 return 0;
}

void push(node* &stackHead, char input){//adds a value to the "top" of the stack, and renames the new addition as head
  node* stackTemp = new node();
  stackTemp->value = input;
  stackTemp->next = stackHead;
  stackHead = stackTemp;
}
void pop(node* &stackHead){//removes a value from the "top" of the stack, making head the second-last addition to the stack
  if(stackHead->value=='\0'){
    cout<<"cannot pop, stack is already empty"<<endl;
  }else{
    node* stackTemp = new node();
    stackTemp=stackHead->next;
    delete stackHead;
    stackHead=stackTemp;
  }
}
char peek(node* stackHead){//returns the "top" of the stack, head
  return stackHead->value;
}
void enqueue(node* &queueHead, char input){//adds to the queue, where head is the opposite of the null node
  if(queueHead->value=='\0'){//if the queue is empty, head is the only node and points to null
    node* queueTemp = new node();
    queueTemp->value='\0';
    queueHead->value=input;
    queueHead->next=queueTemp;
  }else{
    node* queueTemp = new node();
    queueTemp = queueHead;
    while(queueTemp->next->next!='\0'){//goes through the queue, assigning queue temp to the second last position, so that the next node can be input, and the tail will be null
      queueTemp=queueTemp->next;
    }
    node* queueTemp2 = new node();
    node* queueTail = new node();
    queueTail->value='\0';
    queueTemp2->value=input;
    queueTemp->next=queueTemp2;
    queueTemp2->next=queueTail;
  }
}
void dequeue(node* &queueHead){//removes the head of queue
  if(queueHead->value=='\0'){
    cout<<"cannot dequeue, queue is empty"<<endl;
  }else{
    node* queueTemp = new node();
    queueTemp=queueHead->next;
    delete queueHead;
    queueHead=queueTemp;
  }
}
char test(node* queueHead){//returns the value of queue head
  return queueHead->value;
}

void printOutput(node* queueHead, node2* &stackHead2){//function prints the values in the output queue and creates the binary expression tree, using recurssion to go through the queue
  cout<<queueHead->value<<' ';
  if(queueHead->value>='1'&&queueHead->value<='9'){//char is an oprerand, create new tree node and pushes to the tree stack
    Node* opernd = new Node(queueHead->value, NULL, NULL);
    push2(stackHead2, opernd);
  }else if((queueHead->value>='('&&queueHead->value<='+')||queueHead->value=='-'||queueHead->value=='/'){//char is an operator, pops the top two tree nodes from the tree stack and creates a new tree node with them as left and right children than pushes to the tree stack
    Node* oper = new Node(queueHead->value, peek2(stackHead2), peek2(stackHead2->next2));
    pop2(stackHead2);
    pop2(stackHead2);
    push2(stackHead2, oper);
  }
  if(queueHead->next->value!='\0'){//recalls the printoutput function to go through the queue
    printOutput(queueHead->next, stackHead2);
  }
}
void push2(node2* &stackHead2, Node* inputNode){//adds to the top of the tree stack
  node2* stackTemp2 = new node2;
  stackTemp2->value2 = inputNode;
  stackTemp2->next2 = stackHead2;
  stackHead2 = stackTemp2;
}
void pop2(node2* &stackHead2){//removes from the top of the tree stack
  node2* stackTemp2 = new node2();
  stackTemp2=stackHead2->next2;
  delete stackHead2;
  stackHead2=stackTemp2;
}
Node* peek2(node2* stackHead2){//views the top tree node from the tree stack
  return stackHead2->value2;
}
void printInfix(Node* tree){//traverses the expression tree recalling the function for right node, printing the parent, and recalling for left node (right and left are switched from their official names in all the recursive functions)
  if(tree!=NULL){
    if(tree->getValue()=='+'
       ||tree->getValue()=='-'
       ||tree->getValue()=='*'
       ||tree->getValue()=='/'
       ||tree->getValue()=='^'){//adds left parentheses
      cout<<"(";
    }
    if(tree->getRight()!=NULL){
      printInfix(tree->getRight());
    }
    cout<<' '<<tree->getValue();//prints out the tree node's value
    if(tree->getLeft()!=NULL){
      printInfix(tree->getLeft());
    }
    if(tree->getValue()=='+'||
       tree->getValue()=='-'||
       tree->getValue()=='*'||
       tree->getValue()=='/'||
       tree->getValue()=='^'){//adds right parentheses
      cout<<')';
    }
     
  }
}
void printPrefix(Node* tree){//prints the prefix expression from the tree using recursion, similar to infix, only recalling right and left before printing the value
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
void printPostfix(Node* tree){//prints the postfix expression from the tree using recursion, similar to the infix, only recalling right and left after printing the value
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
