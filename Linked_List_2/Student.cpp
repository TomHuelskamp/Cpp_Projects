//Student CPP
#include "Student.h"
Student::Student(char* newFname, char* newLname, int newID, float newGPA){
  Fname=new char[50];
  strcpy(Fname, newFname);
  Lname=new char[50];
  strcpy(Lname, newLname);
  ID=newID;
  GPA=newGPA;
}
Student::~Student(){
}
char* Student::getFname(){
  return Fname;
}
char* Student::getLname(){
  return Lname;
}
int Student::getID(){
  return ID;
}
float Student::getGPA(){
  return GPA;
}
