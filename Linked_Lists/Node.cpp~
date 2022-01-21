//Node.cpp
#include "Node.h"
Node::Node(){
  st=NULL;
  next=NULL;
}
Node::~Node(){
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
