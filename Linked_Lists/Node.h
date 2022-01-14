//Node.h
#include <iostream>
#include "Student.h"
using namespace std;

class Node{
 public:
  Node();
  ~Node();
  void setNext(Node*);
  Node* getNext();
  void setStudent(Student*);
  Student*  getStudent();
 private:
    Student* st;
    Node* next;
};
