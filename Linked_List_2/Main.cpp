//Main
#include <iostream>
#include "Student.h"
#include "Node.h"
#include <cstring>
#include <iomanip>
using namespace std;
void add(Node* &head);
void add2(Node* &head, Node* &current, Student* student);
void print(Node* head);
void remove(Node* &head);
void average(Node* head, float quantity, float total);
int main(){
  Node* head = NULL;
  bool quitIfFalse = true;
  char input[50];
  while(quitIfFalse){
    cout<<endl<<"enter: ";
    //char input[50];
    cin.get(input, 50);
    cin.get();
    //cin>>input;
    if(strcmp(input,"QUIT")==0){
      cout<<"exiting...";
      quitIfFalse=false;
    }else if(strcmp(input,"ADD")==0){
      add(head);
    }else if(strcmp(input, "PRINT")==0){
      print(head);
    }else if(strcmp(input,"DELETE")==0){
      remove(head);
    }else if(strcmp(input, "AVERAGE")==0){
      average(head, 0, 0);
    }
    //cin.clear();
    cin.ignore(INT_MAX, '\n');
    strcpy(input, "HELLO");
    //cout<<"bebop";
  }
  return 0;
}
void add(Node* &head){
  cout<<"enter First Name: ";
  char Fname[50];
  char* Fname2=new char[50];
  cin.get(Fname, 50);
  cin.get();
  strcpy(Fname2, Fname);
  cout<<"enter Last Name: ";
  char Lname[50];
  char* Lname2=new char[50];
  cin.get(Lname, 50);
  cin.get();
  strcpy(Lname2, Lname);
  cout<<"enter Student ID: ";
  int ID;
  cin>>ID;
  cout<<"enter GPA: ";
  float GPA;
  cin>>GPA;
  Student* student = new Student(Fname2, Lname2, ID, GPA);
  add2(head, head, student);
}
void add2(Node* &head, Node* &current,  Student* student){
  if(head==NULL){//adding the very first student
    cout<<"test a";
    head = new Node(student);
  }
  else if(student->getID()<=head->getStudent()->getID()){//if student is the smallest in the array
    cout<<"test b";
    head = new Node(student);
    head->setNext(current);
  }else if(current->getNext()==NULL){
    cout<<"test c";
    current->setNext(new Node(student));
  }
  else{//student isn't smaller then head
    //Node* current2 = current->getNext();
    if(student->getID()<=current->getNext()->getStudent()->getID()){
      cout<<"test d";
      Node* temp = new Node(student);
      //current->setNext(temp); 
      temp->setNext(current->getNext());
      current->setNext(temp);
    }
    else{
      Node* current2 = current->getNext();
      add2(head, current2, student);
    }
  }

  //cout<<student->getFname();
}
void print(Node* head){
  cout<<head->getStudent()->getFname()<<" "<<head->getStudent()->getLname()<<", "<<head->getStudent()->getID()<<", "<<setprecision(2)<<head->getStudent()->getGPA()<<endl;
  if(head->getNext()!=NULL){
    print(head->getNext());
  }
  cin.get();
}
void remove(Node* &head){
}
void average(Node* head, float quantity, float total){
  if(head->getNext()!=NULL){
    average(head->getNext(),(quantity+1),(total+head->getStudent()->getGPA()));
      }else{
    cout<<setprecision(2)<<total/quantity<<endl;
  }
  cin.get();
}
