//This is the Music.cpp file for Classes
#include "Music.h"
#include <iostream>
#include <cstring>
using namespace std;
Music::Music(){
}
Music::Music(char* newDescription, int newId, char* newArtist, int newDuration, char* newPublisher):Parent(newDescription, newId){//Converts the users inputs into usable values
  artist=new char[80];
  strcpy(artist, newArtist);
  duration=newDuration;
  publisher=new char[80];
  strcpy(publisher, newPublisher);
}
char* Music:: getArtist(){//returns the artist
  return artist;
}
int Music::getDuration(){//returns the duration
  return duration;
}
char* Music :: getPublisher(){//returns the publisher
  return publisher;
}
int Music :: getType(){//returns the type which is used to check what type of media this is in the main vector
return 2;
}
