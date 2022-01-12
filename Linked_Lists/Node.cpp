//Node.cpp
#include "Node.h"
Node::Node(){//constructor
  value=0;
  next=NULL;
}
Node::~Node(){//destructor
  delete &value;
  next=NULL;
}
void Node::setNext(Node* newNext){
  next=newNext;
}
Node*  Node::getNext(){
  return next;
}
void Node::setValue(int newValue){
  value=newValue;
}
int Node::getValue(){
  return value;
}
