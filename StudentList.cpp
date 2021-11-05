//This project lets the user enter, view, and delete stored information about different students
//Thomas Huelskamp
//October 26, 2021

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


struct Student {
  char fname[10];
  char lname[10];
  int id;
  float gpa;
};

void function();
void Add(vector<Student*> &v);
void Print(vector<Student*> &v);
void Delete(vector<Student*> &v);

int main(){

  //Student* Bob;
  //cin>>Bob.fname;
  //cin>>Bob.lname;
  //Bob.id=123;
  //Bob.gpa=123;
  
  vector<Student*> vect;

  
  
  char command[10];
  
  char fnameInput[10];
  char lnameInput[10];
  int idInput;
  float gpaInput;
  
  cout<<"Enter 'Add', 'Print', or 'Delete' to the student list: ";
  
  cin.get(command, 10);
  cin.ignore(100, '\n');
  
  if(command[0]=='A'){//Add
    Add(vect);
  }else if(command[0]=='P'){//Print
    Print(vect);
  }else if(command[0]=='D'){//Delete
    Delete(vect);
  }
  cout<<"Enter 'Add', 'Print', or 'Delete' to the student list: ";
  
  cin.get(command, 10);
  cin.ignore(100, '\n');
  
  if(command[0]=='A'){//Add
    Add(vect);
  }else if(command[0]=='P'){//Print
    Print(vect);
  }else if(command[0]=='D'){//Delete
    Delete(vect);
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
  cout<<"h&ello"<<endl;
}

void Add(vector<Student*> &v){
  cout<<"adding..."<<endl;
  Student* Bob = new Student();
  cin>>Bob->fname;
  cin>>Bob->lname;
  Bob->id=123;
  Bob->gpa=123;
}  
void Delete(vector<Student*> &v){
  cout<<"adding..."<<endl;
  cout<<Bob->fname;
}
void Print(vector<Student*> &v){
  cout<<"adding..."<<endl;
}
