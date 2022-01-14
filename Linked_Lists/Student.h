#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>
using namespace std;
class Student{
 public:
  Student();
  ~Student();
  void setStudentName(char*);
  char* getStudentName();
  void setStudentID(int);
  int getStudentID();
 private:
  char* name;
  int ID;
};

#endif
