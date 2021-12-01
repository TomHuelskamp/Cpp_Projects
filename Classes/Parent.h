//parent.h
#include <iostream>
#include <cstring>

using namespace std;

class Parent{
public:
  Parent();
  Parent(char*);
  char* getDescription();
  int getID();
private:
  char* desctiption;
  int id;
}
