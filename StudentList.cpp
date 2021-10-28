//This project lets the user enter, view, and delete stored information about different students
//Thomas Huelskamp
//October 26, 2021

#include <iostream>
#include <cstring>
using namespace std;

void function();
void Add();
void Print();
void Delete();

struct Student {
  char fname[10];
  char lname[10];
  int id;
  float gpa;
};


int main(){
  char command[10];
  
  char fnameInput[10];
  char lnameInput[10];
  int idInput;
  float gpaInput;

  cin.get(command, 10);
  cin.ignore(100, '\n');
  
  if(command[0]=='A'){//Add
    Add();
  }else if(command[0]=='P'){//Print
    Print();
  }else if(command[0]=='D'){//Delete
    Delete();
  }

  /*cout<<"Enter the first name: ";
  cin.get(fnameInput, 10);
  cin.ignore(100, '\n');

  cout<<"Enter the last name: ";
  cin.get(lnameInput, 10);
  cin.ignore(100, '\n');

  cout<<"Enter the student ID: ";
  cin>> idInput;

  cout<<"Enter the GPA: ";
  cin>> gpaInput;
  
  function();

  cout<<fnameInput<<endl;
  cout<<lnameInput<<endl;
  */
  return 0;

}

void function(){
  cout<<"hello"<<endl;
}

void Add(){
  cout<<"adding..."<<endl;
}
void Print(){
  cout<<"printing..."<<endl;
}
void Delete(){
  cout<<"deleting..."<<endl;
}
