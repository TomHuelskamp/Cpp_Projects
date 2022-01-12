//Node.h
#include <iostream>
using namespace std;

class Node{
 public:
  Node();
  ~Node();
  void setNext(Node*);
  Node* getNext();
  void setValue(int);
  int getValue();
 private:
    int value;
    Node* next;
};
