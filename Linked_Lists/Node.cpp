//Node.cpp
#include "Node.h"
Node::Node(){//constructor
  st=NULL;
  next=NULL;
}
Node::~Node(){//destructor
  delete &st;
  next=NULL;
}
void Node::setNext(Node* newNext){
  next=newNext;
}
Node*  Node::getNext(){
  return next;
}
void Node::setStudent(Student* newStudent){
  st=newStudent;
}
Student*  Node::getStudent(){
  return st;
}
