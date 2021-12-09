//main.cpp
#include <iostream>
#include <cstring>
#include <vector>
#include "Parent.h"
#include <algorithm>
using namespace std;
void printVectorDescription(vector<Parent*> &);
void addMedia(vector<Parent*> &);
void searchMedia(vector<Parent*> &);
void deleteMedia();
void printMedia();

//int SIZE=2;
int main(){//don't need vector and list 
  // Parent* list[SIZE];
  vector<Parent*> vect;
  char input[50];
  bool quit=false;
  while(!quit){ 
  cout<<"enter: ";
  cin.get(input, 50);
  cin.get();
  if(strcmp(input, "ADD")==0){
    addMedia(vect);
  }else if(strcmp(input, "SEARCH")==0){
    searchMedia(vect);
  }else if(strcmp(input, "DELETE")==0){
    deleteMedia();
  }
  }
  //printMedia();

  //char* firstDescription=new char[80];
  //strcpy(firstDescription, "First");
  // list[0]=new Parent(firstDescription);
  //char* secondDescription=new char[80];
  //strcpy(secondDescription, "Second");
  // list[1]=new Parent(secondDescription);
  // vect.push_back(list[0]);
  // vect.push_back(list[1]);
    // vect.push_back(new Parent(firstDescription));
    // vect.push_back(new Parent(secondDescription));
  //printVectorDescription(vect);
  //searchMedia(vect);
  
  
  return 0;
}
void printVectorDescription(vector<Parent*> &newVect){
  for(vector<Parent*>::iterator it = newVect.begin(); it != newVect.end(); it++){
    cout<<(*it)->getDescription()<<", "<<(*it)->getId()<<endl;
  }
}
void addMedia(vector<Parent*> &addVect){
  char titleInput[80];
  cout<<"enter title: ";
  cin.get(titleInput, 80);
  cin.get();
  //cin.ignore(80,'\n');
  char* titlePtr = new char[80];
  strcpy(titlePtr, titleInput);


  int yearInput;
  cout<<"enter year: ";
  cin>>yearInput;
  cin.get();
  addVect.push_back(new Parent(titlePtr,yearInput));
  
  // list[2]=new Parent(titlePtr);
  // addVect.push_back(list[2]);
  //cout<<yearInput<<endl;
}
void searchMedia(vector<Parent*> &searchVect){
  char YearTitle[80];
  cout<<"YEAR or TITLE?: ";
  cin.get(YearTitle, 80);
  cin.get();
  
  char title[80];
  int year;
  if(strcmp(YearTitle, "YEAR")==0){
    cout<<"enter year: ";
    cin>>year;
    cin.get();
    for(vector<Parent*>::iterator it = searchVect.begin(); it != searchVect.end(); it++){
      if((*it)->getId()==year){//year match
	cout<<(*it)->getDescription()<<", "<<(*it)->getId()<<endl;
      }
    }
  }else if(strcmp(YearTitle, "TITLE")==0){
    cout<<"enter title: ";
    cin.get(title,80);
    cin.get();
    for(vector<Parent*>::iterator it = searchVect.begin(); it != searchVect.end(); it++){
      if(strcmp(title, (*it)->getDescription())==0){
	cout<<(*it)->getDescription()<<", "<<(*it)->getId()<<endl;
      }
    }
  }else{
    cout<<"invalid input, restart the program";
  }
  
  
}
void deleteMedia(){
}
void printMedia(){
}
