#include<iostream>
#include<cstring>
#include "Parent.h"
using namespace std;
class Movies: public Parent{
 public:
  Movies();
  Movies(char*,int,char*,int,int);
  virtual char* getDirector();
  virtual int getDuration();
  virtual int getRating();
 protected:
  char* director;
  int duration;
  int rating;
};

