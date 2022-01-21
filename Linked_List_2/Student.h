//Student H
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student{
 public:
  Student(char* newFname, char* newLname, int newID, float newGPA);
  ~Student();
  char* getFname();
  char* getLname();
  int getID();
  float getGPA();
 private:
  char* Fname;
  char* Lname;
  int ID;
  float GPA;
};


#endif
