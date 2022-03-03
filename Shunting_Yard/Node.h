//This is the header file of the class Node, used as a node for the binary expression tree.
//Thomas Huelskamp
//March 3, 2022
#include <iostream>
using namespace std;
class Node{
 public:
  Node(char newValue, Node* newLeft, Node* newRight);//Node constructor reads in the Node's value and left and right children
  ~Node();
  char getValue();//returns the Node's value
  Node* getLeft();//returns the left child
  Node* getRight();//returns the right child
 private:
  char value;
  Node* nextLeft;
  Node* nextRight;
};
