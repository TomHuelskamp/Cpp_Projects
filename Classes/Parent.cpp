//parent.cpp
#include <iostream>
#include <cstring>
#include "Parent.h"

using namespace std;
Parent::Parent(){
  description = new char[80];
  id = 0;
}
Parent::Parent(char* newdescription){
  description = new char[80];
  strcpy(description, newdescription);//how the char* is put into an accessible char*
  id=0;
}
