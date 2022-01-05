//Room.h for Zuul
//Thomas Huelskamp
//January 5, 2022
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
struct Item;

class Room{
 public:
  Room();
  Room(char*, char*);//room takes in the name of the room and the room's description
  char* getName();//function used to get the name of the room
  char* getDescription();//function used to get the description of the room
  void setExit(const char* direction, Room* destination);//function used to set exits with direction and destination
  map<const char*, Room*>* getExits();//function returns the map of exits
  void setItem(Item* newItem);//function used to add items to rooms' vectors
  void takeItem(Item* newItem);//function used to remove items to rooms' vectors
  vector<Item*>* getItem();//function returns the vector of item pointers which stores all the items present in a room
 private:
  char* name;//name of room
  char* description;//description of room
  map<const char*, Room*>Map;//map of room exits storing directions and destinations
  vector<Item*>Vect;//vector of the items in rooms
};
