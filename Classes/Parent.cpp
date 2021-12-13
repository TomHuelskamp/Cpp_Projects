//this is the parent.cpp file for Classes
#include <iostream>
#include <cstring>
#include "Parent.h"
using namespace std;

Parent::Parent(){
}
Parent::Parent(char* newdescription,int newId){//converts the users inputs into usable values
  description=new char[80];
  strcpy(description, newdescription);
  id=newId;
}
char* Parent::getDescription(){//returns the title
  return description;
}
int Parent::getId(){//returns the year
  return id;
}
int Parent::getType(){
    return 4;
}
