//Room.cpp for Zuul
#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include <map>
using namespace std;

Room::Room(){
}

Room::Room(char* newName, char* newDescription){//converts to usable char*
  name=new char[500];
  strcpy(name, newName);
  description=new char [500];
  strcpy(description, newDescription);
}

char* Room::getName(){//returns the name of the room
  return name;
}

char* Room::getDescription(){//returns the description of the room
  return description;
}

void Room::setExit(const char* direction, Room* destination){//adds an exit for the room into the map of exits
  Map.insert(make_pair(direction, destination));
}

map<const char*, Room*>* Room::getExits(){//returns the map of exits for the room
  return &Map;
}

void Room::setItem(Item* newItem){//adds an item for the room into the vector which stores the room's items
  Vect.push_back(newItem);
}

void Room::takeItem(Item* newItem){//removes an item from the room's vector of items
  Vect.erase(find(Vect.begin(),Vect.end(),newItem));
}

vector<Item*>* Room::getItem(){//returns the vector of items in the room
  return &Vect;
}
