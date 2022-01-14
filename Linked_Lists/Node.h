//Node.h, this is the first part of a linked-lists project
//Thomas Huelskamp
//January 14, 2022
#include <iostream>
#include "Student.h"
using namespace std;

class Node{
 public:
  Node();//Node Constructor
  ~Node();//Node Destructor
  void setNext(Node*);//create a new Node
  Node* getNext();//return node
  void setStudent(Student*);//create a new Student
  Student*  getStudent();//return student
 private:
    Student* st;
    Node* next;
};
