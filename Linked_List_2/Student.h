//Student H
#ifndef STUDENT_H
#define STUDENT_H
#include <cstring>
#include <iostream>
using namespace std;

class Student{
 public:
  Student(char* newFname, char* newLname, int newID, float newGPA);//student constructor with first name, last name, ID, and GPA
  ~Student();//student destructor
  char* getFname();//returns first name
  char* getLname();//returns last name
  int getID();//returns ID
  float getGPA();//returns gpa
 private:
  char* Fname;
  char* Lname;
  int ID;
  float GPA;
};


#endif
