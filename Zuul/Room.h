//Room.h
#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;
struct Item;
class Room{
 public:
  //struct Item;
  Room();
  Room(char*, char*);
  char* getName();
  char* getDescription();
  void setExit(const char* direction, Room* destination);
  map<const char*, Room*>* getExits();
  void setItem(Item* newItem);
  void takeItem(Item* newItem);
  vector<Item*>* getItem();
 private:
  char* name;
  char* description;
  map<const char*, Room*>Map;
  vector<Item*>Vect;
};
