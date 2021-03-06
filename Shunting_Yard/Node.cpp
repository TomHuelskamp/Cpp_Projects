//This is the cpp file for the class Node, comments in the header Node.h
//Thomas Huelskamp
//March 3, 2022
#include "Node.h"
using namespace std;
Node::Node(char newValue, Node* newLeft, Node* newRight){
  value=newValue;
  nextLeft=newLeft;
  nextRight=newRight;
}
Node::~Node(){
  nextLeft=NULL;
  nextRight=NULL;
}
char Node::getValue(){
  return value;
}
Node* Node::getLeft(){
  return nextLeft;
}
Node* Node::getRight(){
  return nextRight;
}
