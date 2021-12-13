//This is the Videogames.cpp file for classes
#include "Videogames.h"
#include <cstring>
#include <iostream>
using namespace std;
Videogames::Videogames(){
}
Videogames::Videogames(char* newDescription, int newId, char* newPublisher, int newRating):Parent(newDescription, newId){//Converts the users inputs into usable values
  publisher = new char[80];
  strcpy(publisher, newPublisher);
  rating = newRating;
}
char* Videogames::getPublisher(){//returns the publisher
  return publisher;
}
int Videogames::getRating(){//returns the rating
  return rating;
}
int Videogames :: getType(){//returns the type which is used to check what type of media this is in the main vector
  return 3;
}
