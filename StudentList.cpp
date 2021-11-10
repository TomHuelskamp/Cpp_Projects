//This project creates a database of students based on the user's input and lets them add, remove, and print the students and their information
//Thomas Huelskamp
//November 10,2021

#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;
//Creates a struct for student
struct Student{
  char fname[10];
  char lname[10];
  int id;
  float gpa;
};
//declares functions
void add(vector<Student*> &va);
void print(vector<Student*> &vp);
void del(vector<Student*> &vd);
using namespace std;
int main(){
  //creates vector of student pointers
  vector<Student*> vect;
  char input[10];
  bool notfalse=true;

  while(notfalse){//while loop never ends unless the user chooses to 'QUIT'

    cout<<"Enter: ";//Takes the user's command
    cin.get(input,10);
    cin.get();


    if(strcmp(input, "ADD")==0){//ADD
      add(vect);
    }else if(strcmp(input, "PRINT")==0){//PRINT
      print(vect);
    }else if(strcmp(input, "DELETE")==0){//DELETE
      del(vect);
    }else if(strcmp(input, "QUIT")==0){//QUIT
      break;
    }
  }
  return 0;
}

void add(vector<Student*> &va){
  //Creates a new student and asks the user for all the necessary information
  Student* a = new Student();
  cout<<"First Name: ";
  cin.get(a->fname, 10);
  cin.get();
  cout<<"Last Name: ";
  cin.get(a->lname, 10);
  cin.get();
  cout<<"Student ID: ";
  cin>>a->id;
  cout<<"Grade Point Average: ";
  cin>>a->gpa;
  cin.ignore(100,'\n');

  va.push_back(a);
}
void print(vector<Student*> &vp){
  for(int i=0; i<vp.size();i++){//goes through the vector of students and tells the user their information
    float roundedgpa;
    roundedgpa=round(vp[i]->gpa*100)/100;//rounds the gpa
    cout<<vp[i]->fname<<" "<<vp[i]->lname<<", "<<vp[i]->id<<", "<<roundedgpa<<endl; 
  }
}
void del(vector<Student*> &vd){
  //Asks the user for the student's id to delete the student
  int idinput;
  cout<<"What ID number would you like to delete?: ";
  cin>>idinput;
  cin.ignore(100,'\n');
  for(int i=0; i<vd.size();i++){//goes through the students looking for the id, and deletes the student with the same id as the user entered
    if(vd[i]->id==idinput){
      vd.erase(vd.begin()+i);
    }
  }
}
