#include <iostream>
using namespace std;
class Node{
 public:
  Node(char newValue, Node* newLeft, Node* newRight);
  ~Node();
  char getValue();
  Node* getLeft();
  Node* getRight();
 private:
  char value;
  Node* nextLeft;
  Node* nextRight;
};
