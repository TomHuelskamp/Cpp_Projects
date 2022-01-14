#include "Student.h"
Student::Student(){

}
Student::~Student(){

}
void Student::setStudentName(char* newName){
  name = new char[50];
  strcpy(name, newName);
}
char* Student::getStudentName(){
  return name;
}
void Student::setStudentID(int newID){
  ID = newID;
}
int Student::getStudentID(){
  return ID;
}
