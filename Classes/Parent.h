//this is the parent.h file for Classes
#ifndef PARENT_H
#define PARENT_H

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
class Parent{//functions will act as constructor with 'id' (year) and 'decription'(title) 
 public:
  Parent();
  Parent(char*, int);
  virtual char* getDescription();
  virtual int getId();
  virtual int getType();
 private:
  char* description;
  int id;
};
#endif
