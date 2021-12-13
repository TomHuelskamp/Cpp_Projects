//This is the Movies.cpp file for classes
#include "Movies.h"
#include<cstring>
#include<iostream>
using namespace std;
Movies::Movies(){
}
Movies::Movies(char* newDescription,int newId,char* newDirector,int newDuration, int newRating):Parent(newDescription, newId){//Converts the users inputs into usable values
  director=new char[80];
  strcpy(director, newDirector);
  duration=newDuration;
  rating=newRating;
}
char* Movies::getDirector(){//returns the director
  return director;
}
int Movies::getDuration(){//returns the duration
  return duration;
}
int Movies::getRating(){//returns the rating
  return rating;
}
int Movies :: getType(){//returns the type which is used to check what type of media this is in the main vector
  return 1;
}
