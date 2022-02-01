//This program lets the user add, print, delete, and average the GPAs of students in a database
//Thomas Huelskamp
//January 30, 2021
#include <iostream>
#include "Student.h"
#include "Node.h"
#include <cstring>
#include <iomanip>
using namespace std;
void add(Node* &head);
void add2(Node* &head, Node* &current, Student* student);
void print(Node* head);
void remove(Node* &head, Node* &current, int input);
void average(Node* head, float quantity, float total);
int main(){
  Node* head = NULL;
  bool quitIfFalse = true;
  char input[50];
  cout<<"Welcome to Student Database. Enter ADD, PRINT, AVERAGE, DELETE, or QUIT."<<endl;
  while(quitIfFalse){//Loop keeps prompting the user to change the linked list
    cout<<endl<<"enter: ";
    cin.get(input, 50);
    cin.get();
    if(strcmp(input,"QUIT")==0){//ends program
      cout<<"exiting...";
      break;
    }else if(strcmp(input,"ADD")==0){//runs add
      add(head);
      cin.get();
    }else if(strcmp(input, "PRINT")==0){//runs print
      if(head!=NULL){
	print(head);
      }else{
	cout<<"student list is empty"<<endl;
      }
    }else if(strcmp(input,"DELETE")==0){//runs delete
      if(head!=NULL){
      cout<<"enter ID: ";
      int input2;
      cin>>input2;
      remove(head,head, input2);
      cin.get();
      }else{
	cout<<"student list is empty"<<endl;
      }
    }else if(strcmp(input, "AVERAGE")==0){//runs average
      if(head!=NULL){
      average(head, 0, 0);
      }else{
	cout<<"student list is empty"<<endl;
      }
    }else{//handles invalid inputs
      cout<<"invalid input";
      break;
    }
  }
  return 0;
}
void add(Node* &head){//the first of the add classes, takes in the student information
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
  Student* student = new Student(Fname2, Lname2, ID, GPA);//creates student with given information
  add2(head, head, student);
}
void add2(Node* &head, Node* &current,  Student* student){//the second add class, adds the new student into the linked list
  if(head==NULL){//if there are no nodes in the linked list
    head = new Node(student);
  }
  else if(student->getID()<head->getStudent()->getID()){//if the student being added has the smallest ID number in the linked list
    Node* temp = current;
    head  = new Node(student);
    head->setNext(temp);
  } else if(current->getNext()==NULL){//if the student being added has the highest ID number
    current->setNext(new Node(student));
    }
  else{
    if(student->getID()<=current->getNext()->getStudent()->getID()){//if the student being added has a smaller ID number than one of the nodes (using counter to go through the list)
      Node* temp = new Node(student); 
      temp->setNext(current->getNext());
      current->setNext(temp);
    }
    else{//recalls class with the next node in the linked list
      Node* current2 = current->getNext();
      add2(head, current2, student);
    }
  }

}
void print(Node* head){//prints the students in the linked list
  cout<<head->getStudent()->getFname()<<" "<<head->getStudent()->getLname()<<", "<<head->getStudent()->getID()<<", ";//prints the current students information
  if(head->getStudent()->getGPA()<1){//if the student has a gpa where it would be printed to 3 decimal places (less than one), print to two decimal places
    cout<<setprecision(2)<<head->getStudent()->getGPA()<<endl;
  }else{//print a gpa of one whole number and two following decimals
    cout<<setprecision(3)<<head->getStudent()->getGPA()<<endl;
  }
  if(head->getNext()!=NULL){//recalls the class with the next node in the linked list
    print(head->getNext());
  }
}

void remove(Node* &head, Node* &current, int input){//removes a node from the linked list with a given ID
  Node* temp=current->getNext();
  if(head->getStudent()->getID()==input){//if the ID is head, removes head
    current->~Node();
    current=temp;
  }else if(temp->getStudent()->getID()==input){//if the ID isn't head, but matches the student after current, removes node
    Node* temp2 = temp->getNext();
    temp->~Node();
    current->setNext(temp2);
  }else{//otherwise runs class checking the next node in the linked list
    remove(head, temp, input);
  }
  
}
void average(Node* head, float quantity, float total){//finds the average of the students' GPAs
  if(head->getNext()!=NULL){
    average(head->getNext(),(quantity+1),(total+head->getStudent()->getGPA()));//if the current(named head) student isn't the last in the linked list, add its GPA to the total and increase the counter of students, then recall average with the new totals 
  }else{//if the end of the linked list had been reached, add the data from the last student and  display the average
    quantity++;
    total=total+head->getStudent()->getGPA();
    if((total/quantity)<1){//adjust the decimal places for averages below 1
      cout<<setprecision(2)<<total/quantity<<endl;
    }else{//2 decimals for averages above 1
      cout<<setprecision(3)<<total/quantity<<endl;
    }
  }
}
