//Room.cpp
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
char* Room::getName(){
  return name;
}
char* Room::getDescription(){
  return description;
}
void Room::setExit(const char* direction, Room* destination){
  Map.insert(make_pair(direction, destination));
}
map<const char*, Room*>* Room::getExits(){
  return &Map;
}
