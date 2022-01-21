//Main
//Thomas Huelskamp
//January 12, 2022
#include <iostream>
#include "Node.h"
#include "Student.h"
#include <cstring>

using namespace std;

int main(){
  char fnameInput[]="john";
  char lnameInput[]="doe";
  Student* studentInput = new Student();
  studentInput->setStudentfName(fnameInput);
  studentInput->setStudentlName(lnameInput);
  studentInput->setStudentID(12345);
  studentInput->setStudentGPA(4.0);

  
  Node* head=NULL;
  Node* current=head;
  Node* next=head;

  //add
  if (current==NULL){
    head=new Node();
    head->setStudent(studentInput);
  }
  else{
    while(current->getNext() != NULL){
      current = current->getNext();
    }
    current->setNext(new Node());
    current->getNext()->setStudent(studentInput);
  }


  cout<<"running...";
  return 0;
}

