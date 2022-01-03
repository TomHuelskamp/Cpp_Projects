//Item.h
#include<cstring>
#include<iostream>
using namespace std;
class Items{
 public:
  Items();
  Items(char*);
  char* getName();
 private:
  char* itemName;
};
