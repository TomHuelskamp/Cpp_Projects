//Room.h
#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

class Room{
 public:
  Room();
  Room(char*, char*);
  char* getName();
  char* getDescription();
  void setExit(const char* direction, Room* destination);
  void setItem(char*);
  map<const char*, Room*>* getExits();
 private:
  char* name;
  char* description;
  map<const char*, Room*>Map; 
};
