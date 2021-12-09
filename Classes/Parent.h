//parent.h
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Parent{
 public:
  Parent();
  Parent(char*, int);
  char* getDescription();
  int getId();
 private:
  char* description;
  int id;
};
