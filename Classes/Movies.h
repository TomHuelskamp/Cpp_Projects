//This is the Movies.h file for classes
#ifndef MOVIES_H
#define MOVIES_H
#include<iostream>
#include<cstring>
#include "Parent.h"
using namespace std;
class Movies: public Parent{//Movies is a child class of Parent which will act as a constructor with director, duration, and rating
 public:
  Movies();
  Movies(char*,int,char*,int,int);
  virtual char* getDirector();
  virtual int getDuration();
  virtual int getRating();
  int getType();
 private:
  char* director;
  int duration;
  int rating;
};
#endif
