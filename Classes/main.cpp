//main.cpp
#include <iostream>
#include <cstring>
#include <vector>
#include "Parent.h"

using namespace std;
int SIZE = 2;
int main(){
  Parent* list[SIZE];
  vector<Parent*> vect;
  char* firstDescription = new char[80];
  strcpy(firstDescription, "First");
  list[0]=new Parent(firstDescription);
  char* secondDescription = new char[80];
  strcpy(secondDescription, "Second");
  list[1]=new Parent(secondDescription);
  printArrayDescriptions(list, SIZE);
  vect.push_back(list[0]);
  vect.push_back(list[1]);
  //print vector 
  return 0;
}
