//This is the Videogames.h file for classes
#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H
#include <iostream>
#include <cstring>
#include "Parent.h"
using namespace std;
class Videogames: public Parent{//Videogames is a child class of Parent which will act as a constructor with publisher and rating
 public:
  Videogames();
  Videogames(char*,int,char*,int);
  virtual char* getPublisher();
  virtual int getRating();
  int getType();
 private:
  char* publisher;
  int rating;
};
#endif
