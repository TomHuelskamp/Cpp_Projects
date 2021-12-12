#include "Movies.h"
#include<cstring>
#include<iostream>
using namespace std;
Movies::Movies(){
}
Movies::Movies(char* newDescription,int newId,char* newDirector,int newDuration, int newRating):Parent(newDescription, newId){
  director=new char[80];
  strcpy(director, newDirector);
  duration=newDuration;
  rating=newRating;
}
char* Movies::getDirector(){
  return director;
}
int Movies::getDuration(){
  return duration;
}
int Movies::getRating(){
  return rating;
}
