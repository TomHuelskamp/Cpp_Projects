#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>
using namespace std;
class Student{
 public:
  Student();
  ~Student();
  void setStudentfName(char*);
  char* getStudentfName();
  void setStudentlName(char*);
  char* getStudentlName();
  void setStudentID(int);
  int getStudentID();
  void setStudentGPA(float);
  float getStudentGPA();
 private:
  char* fname;
  char* lname;
  int ID;
  float GPA;
};

#endif
