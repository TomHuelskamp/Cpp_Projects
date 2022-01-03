//This is a text-based adventure game
//Thomas Huelskamp
//
#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
  cout<<"Welcome to Airport Adventure! To complete the game collect all the Covid variants in the airport and bring them to the exit. To go move, type the direction in all capitals. To pick up an item, type the item name, enter items before movements. Good luck!"<<endl;

  //char entranceDescription[] ="You are in the Entrance.";
  //char* entranceDescriptionPtr = new char[100];
  //strcpy(entranceDescriptionPtr, entranceDescription);
  //Room *entrance = new Room(entranceDescriptionPtr);

  Room* entrance= new Room((char*)"entrance",(char*)"You are in the Entrance.");
  Room* tsa= new Room((char*)"tsa",(char*)"You are at the TSA.");
  Room* lounge= new Room((char*)"lounge",(char*)"You are in the Lounge.");
  Room* foodcourt= new Room((char*)"foodcourt",(char*)"You are in the Food Court.");
  Room* exit= new Room((char*)"exit",(char*)"You are at the Exit.");
  Room* t1= new Room((char*)"t1",(char*)"You are in Terminal 1");
  Room* t2= new Room((char*)"t2",(char*)"You are in Terminal 2");
  Room* t3= new Room((char*)"t3",(char*)"You are in Terminal 3");
  Room* t4= new Room((char*)"t4",(char*)"You are in Terminal 4");
  Room* t5= new Room((char*)"t5",(char*)"You are in Terminal 5");
  Room* t6= new Room((char*)"t6",(char*)"You are in Terminal 6");
  Room* t7= new Room((char*)"t7",(char*)"You are in Terminal 7");
  Room* t8= new Room((char*)"t8",(char*)"You are in Terminal 8");
  Room* t9= new Room((char*)"t9",(char*)"You are in Terminal 9");
  Room* t10= new Room((char*)"t10",(char*)"You are in Terminal 10");

  entrance->setExit("EAST",tsa);
  tsa->setExit("EAST",lounge);
  lounge->setExit("NORTH",t3);
  lounge->setExit("EAST",foodcourt);
  lounge->setExit("SOUTH",t8);
  foodcourt->setExit("NORTH",t4);
  foodcourt->setExit("EAST",exit);
  foodcourt->setExit("SOUTH",t9);
  foodcourt->setExit("WEST",lounge);
  exit->setExit("WEST",foodcourt);
  t1->setExit("EAST",t2);
  t2->setExit("EAST",t3);
  t2->setExit("WEST",t1);
  t3->setExit("EAST",t4);
  t3->setExit("SOUTH",lounge);
  t3->setExit("WEST",t2);
  t4->setExit("EAST",t5);
  t4->setExit("SOUTH",foodcourt);
  t4->setExit("WEST",t3);
  t5->setExit("WEST",t4);
  t6->setExit("EAST",t7);
  t7->setExit("EAST",t8);
  t7->setExit("WEST",t6);
  t8->setExit("NORTH",lounge);
  t8->setExit("EAST",t9);
  t8->setExit("WEST",t7);
  t9->setExit("NORTH",foodcourt);
  t9->setExit("EAST",t10);
  t9->setExit("WEST",t8);
  t10->setExit("WEST",t9);
  
  Room* currentroom = entrance;
  bool notfalse=true;
  
  while (notfalse){
    cout<<currentroom->getDescription()<<endl;
    cout<<"exits: ";

    for(map<const char*, Room*>::iterator it = currentroom->getExits()->begin(); it!= currentroom->getExits()->end(); it++){
      cout<<it->first<<" ";
    }
    cout<<endl;

    cout<<"move: ";
    char move[50];
    cin.get(move, 50);
    cin.get();

    for(map<const char*, Room*>::iterator it = currentroom->getExits()->begin(); \
	it!= currentroom->getExits()->end(); it++){
      if(strcmp(move, it->first)==0){
	cout<<"moving... "<<endl;
	currentroom = it->second;
	break;
      }
    }
  }
  
  //create map of rooms and exits
  //- create rooms and descriptions, set exits and connecting rooms
  //add items to rooms
  //cout current room
  //cout items
  //cout exits
  //cin items
  //cin exits
  //repeat...

  return 0;
}
