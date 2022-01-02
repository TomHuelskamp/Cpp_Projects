//Room.h
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Room{
 public:
  Room();
  Room(char*, char*);
  char* getName();
  char* getDescription();
  void setExit(const char* direction, Room* destination);
  //char* getExits();
 private:
  char* name;
  char* description;
  //map exits;
};
