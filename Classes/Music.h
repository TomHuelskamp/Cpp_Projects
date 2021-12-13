//This is the Music.h file for Classes
#ifndef MUSIC_H
#define MUSIC_H
#include <iostream>
#include <cstring>
#include "Parent.h"
using namespace std;
class Music: public Parent{//Music is a child class of Parent which will act as a constructor with artist, duration, and publisher
 public:
  Music();
  Music(char*,int,char*,int,char*);
  virtual char* getArtist();
  virtual int getDuration();
  virtual char* getPublisher();
  int getType();
 private:
  char* artist;
  int duration;
  char* publisher;
};
#endif
