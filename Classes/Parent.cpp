//parent.cpp
#include <iostream>
#include <cstring>
#include "Parent.h"
using namespace std;

Parent::Parent(){
  //description = new char[80];
}
Parent::Parent(char* newdescription,int newId){
  description=new char[80];
  strcpy(description, newdescription);//how what the user enters in put int description
  id=newId;
}
char* Parent::getDescription(){
  return description;
}
int Parent::getId(){
  return id;
}
