//This is a text-based adventure game, full description on line 18
//Thomas Huelskamp
//January 5, 2022

#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

struct Item{//struct for item, the only object that is a member of item is the name, this is used to display items and take input information about items  
  char itemname[10];
};

int main(){
  cout<<"Welcome to Airport Adventure! To complete the game collect all the Covid variants in the airport and bring them to the exit. Good luck!"<<endl<<" - type in single word responses"<<endl<<" - type in all caps"<<endl<<" - to skip a prompt type 'NONE'"<<endl;//description and rules of the game, this is only displayed once

  vector<Item*>Inventory;//vector of item pointers used for player inventory, starts out as empty
  //creates item pointers and names  for the 5 Covid variants
  Item* itemA = new Item();
  strcpy(itemA->itemname, "ALPHA");
  Item* itemB = new Item();
  strcpy(itemB->itemname, "BETA");
  Item* itemD = new Item();
  strcpy(itemD->itemname, "DELTA");
  Item* itemG = new Item();
  strcpy(itemG->itemname, "GAMMA");
  Item* itemO = new Item();
  strcpy(itemO->itemname, "OMICRON");

  //creates room class pointers for each room, including their name and description
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
  //sets exits for each room including the direction and destination of each exit
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
  //sets items in the rooms with items
  t1->setItem(itemA);
  t2->setItem(itemG);
  tsa->setItem(itemD);
  foodcourt->setItem(itemO);
  t8->setItem(itemB);
  
  Room* currentroom = entrance;//the game starts with the user in entrance
  bool wincondition=false;//wincondition in a while loop to check wether or not the game ends
  
  while (!wincondition){//if win conditions are true the game ends, otherwise it continues to display all the room information and prompt for all player moves
    cout<<endl<<endl<<currentroom->getDescription()<<endl;//displays the description of the current room
    //for loop goes through the item pointer vector from the room class and displays each item in the room using iterators
    cout<<"items: ";
    for(vector<Item*>::iterator it = currentroom->getItem()->begin(); it!= currentroom->getItem()->end(); it++){
      cout<<(*it)->itemname<<" ";
    }
    //for loop goes through the map of directions and destinations for the exits of the current room and displats the directions using iterators
    cout<<endl<<"exits: ";
    for(map<const char*, Room*>::iterator it = currentroom->getExits()->begin(); it!= currentroom->getExits()->end(); it++){
      cout<<it->first<<" ";
    }
    //prompts the user for the item they want to pick up
    cout<<endl<<endl<<"pick up: ";
    char get[50];
    cin.get(get, 50);
    cin.get();
    //if statements check if the user entered the name of an item and add matching items to the inventory as well as remove the item from the current room
    if(strcmp(get, itemA->itemname)==0){
      currentroom->takeItem(itemA);
      Inventory.push_back(itemA);
    }else if(strcmp(get, itemB->itemname)==0){
      currentroom->takeItem(itemB);
      Inventory.push_back(itemB);
    }else if(strcmp(get, itemD->itemname)==0){
      currentroom->takeItem(itemD);
      Inventory.push_back(itemD);
    }else if(strcmp(get, itemG->itemname)==0){
      currentroom->takeItem(itemG);
      Inventory.push_back(itemG);
    }else if(strcmp(get, itemO->itemname)==0){
      currentroom->takeItem(itemO);
      Inventory.push_back(itemO);
    }
    //prompts the user to drop items
    cout<<"drop: ";
    char drop[50];
    cin.get(drop, 50);
    cin.get();
    //if statements check if the users input matches one of the items, removes items from the inventory, and adds items to the current room
    if(strcmp(drop, itemA->itemname)==0){
      currentroom->setItem(itemA);
      Inventory.erase(find(Inventory.begin(), Inventory.end(), itemA));
    }else if(strcmp(drop, itemB->itemname)==0){
      currentroom->setItem(itemB);
      Inventory.erase(find(Inventory.begin(), Inventory.end(), itemB));
    }else if(strcmp(drop, itemD->itemname)==0){
      currentroom->setItem(itemD);
      Inventory.erase(find(Inventory.begin(), Inventory.end(), itemD));
    }else if(strcmp(drop, itemG->itemname)==0){
      currentroom->setItem(itemG);
      Inventory.erase(find(Inventory.begin(), Inventory.end(), itemG));
    }else if(strcmp(drop, itemO->itemname)==0){
      currentroom->setItem(itemO);
      Inventory.erase(find(Inventory.begin(), Inventory.end(), itemO));
    }
    //prompts the user for the direction they want to move out of their current room
    cout<<"move: ";
    char move[50];
    cin.get(move, 50);
    cin.get();
    for(map<const char*, Room*>::iterator it = currentroom->getExits()->begin(); \
	it!= currentroom->getExits()->end(); it++){//for loop goes through the map of directions and destination and if what the user entered matches a direction, sets the current room to the corresponding destination
      if(strcmp(move, it->first)==0){
	currentroom = it->second;
	break;
      }
    }
    if(Inventory.size()==5 && currentroom==exit){//if the user's inventory is full of all 5 covid variants, and they are at the exit, the user wins, and the program stops running
      cout<<"Nice job, you have brought all the variants to the exit and you win!";
      wincondition=true;
      //break;
    }
  }  
  return 0;
}
