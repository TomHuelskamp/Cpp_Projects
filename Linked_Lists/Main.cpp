//Main
//Thomas Huelskamp
//January 12, 2022
#include <iostream>
#include "Node.h"
#include "Student.h"
using namespace std;
void  add(int newInput);
void  search();
void destroy();
void  print(Node* next);

Node* head = NULL;

int main(){
  cout<<"testing 1 2, testing 1 2"<<endl;  
  bool forever = true;
  while(true){
    int input;
    cout<<"add: ";
    cin>>input;
    //add(input);
    //print(head);
  } 
  return 0;
}
void add(int newInput){
  Node* current = head;
  if(current==NULL){//
    head = new Node();
    //head -> setValue(newInput);
  }else{
    while(current->getNext() != NULL ){
      current = current->getNext();
    }
    current->setNext(new Node());
    //current->getNext()->setValue(newInput);
  }
}
void search(){
}
void destroy(){
}
void  print(Node* next){
  if(next==head){
    cout<<"list: ";
  }
  if(next != NULL){
    //cout<<next->getValue()<< " ";
    //print(next->getNext());
  }
  if(next==NULL){
    cout<<endl;
  }
}
