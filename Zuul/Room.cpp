//Room.cpp
#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"

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
}
//char* Room::setExits(){
//}
//char* Room::getExits(){
//}
