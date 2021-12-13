//This is the main cpp file for a program which stores different types of media, letting the user add, search, and delete from the database
//Thomas Huelskamp
//December 12, 2021
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include "Movies.h"
#include "Music.h"
#include "Videogames.h"
using namespace std;
void addMedia(vector<Parent*> &);
void searchanddestroyMedia(vector<Parent*> &, bool);

int main(){//The main function allows the user to run functions to Add, Search, Delete, and Quit
  vector<Parent*> vect;
  char input[50];
  bool quit=false;
  while(!quit){//While loop which is used to let the user quit from the program
    //prompts the user to enter their function of choice
  cout<<"enter: ";
  cin.get(input, 50);
  cin.get();
  if(strcmp(input, "ADD")==0){//runs the Add function
    addMedia(vect);
  }else if(strcmp(input, "SEARCH")==0){//runs the Search/Delete function with the delete boolean set to false
    searchanddestroyMedia(vect, false);
  }else if(strcmp(input, "DELETE")==0){//runs the Search/Delete function with the delete boolean ser to true
    searchanddestroyMedia(vect, true);
  }else if(strcmp(input, "QUIT")==0){//exits the program
    quit=true;
  }
  }
  return 0;
}

void addMedia(vector<Parent*> &addVect){//Function lets the user add to the media vector
  //prompts the user to choose the type of media which they're going to add
  char mediaInput[80];
  cout<<"MOVIE, MUSIC, or VIDEOGAME?: ";
  cin.get(mediaInput, 80);
  cin.get();
  //asks for the title and year regardless of the media type
  char titleInput[80];
  cout<<"enter title: ";
  cin.get(titleInput, 80);//title
  cin.get();
  char* titlePtr = new char[80];
  strcpy(titlePtr, titleInput);
  int yearInput;
  cout<<"enter year: ";
  cin>>yearInput;//year
  cin.get();
  if(strcmp(mediaInput, "MOVIE")==0){//asks the user for the special Movie inputs and adds the new movie to the media vector
    char directorInput[80];
    cout<<"enter director: ";
    cin.get(directorInput, 80);//director
    cin.get();
    char* directorPtr = new char[80];
    strcpy(directorPtr, directorInput);
    int durationInput;
    cout<<"enter duration: ";
    cin>>durationInput;//duration
    cin.get();
    int ratingInput;
    cout<<"enter rating: ";
    cin>>ratingInput;//rating
    cin.get();  
    Movies *ms  = new Movies(titlePtr, yearInput, directorPtr, durationInput, ratingInput);
    addVect.push_back(ms);
  }else if(strcmp(mediaInput, "MUSIC")==0){//asks the user for the special Music inputs and adds the new music to the media vector
    char artistInput[80];
    cout<<"enter artist: ";
    cin.get(artistInput, 80);//artist
    cin.get();
    char* artistPtr = new char[80];
    strcpy(artistPtr, artistInput);
    int durationInput;
    cout<<"enter duration: ";
    cin>>durationInput;//duration
    cin.get();
    char publisherInput[80];
    cout<<"enter publisher: ";
    cin.get(publisherInput, 80);//publisher
    cin.get();
    char* publisherPtr = new char[80];
    strcpy(publisherPtr, publisherInput);
    Music * mc = new Music(titlePtr, yearInput, artistPtr, durationInput, publisherPtr);
    addVect.push_back(mc);
  }else if(strcmp(mediaInput, "VIDEOGAME")==0){//asks the user for the special Videogame inputs and adds the new videogame to the media vector
    char publisherInput[80];
    cout<<"enter publisher: ";
    cin.get(publisherInput, 80);//publisher
    cin.get();
    char* publisherPtr = new char[80];
    strcpy(publisherPtr, publisherInput);
    int ratingInput;
    cout<<"enter rating: ";
    cin>>ratingInput;//rating
    cin.get();
    Videogames *v = new Videogames(titlePtr, yearInput, publisherPtr, ratingInput);
     addVect.push_back(v);
  }  
}

void searchanddestroyMedia(vector<Parent*> &searchVect, bool destroyBoolean){//Function uses while for loops to let the user search and delete media by title or year
  //prompts the user to decide between year or title as the filter for searching or deleting
  char YearTitle[80];
  cout<<"YEAR or TITLE?: ";
  cin.get(YearTitle, 80);
  cin.get();  
  char title[80];
  int year;
  int deleteCounter = 0;
  if(strcmp(YearTitle, "YEAR")==0){//If the user chose to search by Year
    cout<<"enter year: ";//prompts the user for the year to search by
    cin>>year;
    cin.get();
    for(vector<Parent*>::iterator it = searchVect.begin(); it != searchVect.end(); it++){//goes through the media vector using iterators
      if((*it)->getId()==year){//if there is a year match, print title and year
	cout<<(*it)->getDescription()<<", "<<(*it)->getId()<<", ";
	if((*it)->getType()==1){//if the media is a movie, print the movie information
	cout<<((Movies*)(*it))->getDirector()<<", ";
	cout<<((Movies*)(*it))->getDuration()<<", ";
	cout<<((Movies*)(*it))->getRating()<<endl;
	}else if((*it)->getType()==2){//if the media is music, print the music information
	cout<<((Music*)(*it))->getArtist()<<", ";
	cout<<((Music*)(*it))->getDuration()<<", ";
	cout<<((Music*)(*it))->getPublisher()<<endl;
	}else if((*it)->getType()==3){//if the media is a videogame, print the videogame information
	cout<<((Videogames*)(*it))->getPublisher()<<", ";
	cout<<((Videogames*)(*it))->getRating()<<endl;
	}
	if(destroyBoolean){//if the user called the Delete function and not just search
	  char doublecheck[80];
	  cout<<"are you sure you want to delete this?: ";//checks for verification that the user wants to delete the media which was just listed
	  cin.get(doublecheck, 80);
	  cin.get();
	  if(strcmp(doublecheck, "YES")==0){//deletion verified, deletes media
	    cout<<"deleted"<<endl;
	    searchVect.erase(searchVect.begin()+ deleteCounter);
	    break;
	  }else{
	    continue;
	  }
	}
	deleteCounter++;
      }
    }
  }else if(strcmp(YearTitle, "TITLE")==0){//If the user chose to search by Title
    cout<<"enter title: ";//prompts the user for title to search by
    cin.get(title,80);
    cin.get();
    for(vector<Parent*>::iterator it = searchVect.begin(); it != searchVect.end(); it++){//goes through the media vector using iterators
      if(strcmp(title, (*it)->getDescription())==0){//if there is a title match, prints title and year
	cout<<(*it)->getDescription()<<", "<<(*it)->getId()<<", ";
	if((*it)->getType()==1){//if the media is a movie, print the movie information
	cout<<((Movies*)(*it))->getDirector()<<", ";
	cout<<((Movies*)(*it))->getDuration()<<", ";
	cout<<((Movies*)(*it))->getRating()<<endl;
	}else if((*it)->getType()==2){//if the media is music, print the music information
	cout<<((Music*)(*it))->getArtist()<<", ";
	cout<<((Music*)(*it))->getDuration()<<", ";
	cout<<((Music*)(*it))->getPublisher()<<endl;
	}else if((*it)->getType()==3){//if the media is a videogame, print the videogame information
	cout<<((Videogames*)(*it))->getPublisher()<<", ";
	cout<<((Videogames*)(*it))->getRating()<<", ";
	}
	if(destroyBoolean){//if the user called the Delete function and not just search
	  char doublecheck[80];
	  cout<<"are you sure you want to delete this?: ";//checks for verification that the user wants to delete the media which was just listed
	  cin.get(doublecheck, 80);
	  cin.get();
	  if(strcmp(doublecheck, "YES")==0){//deletion verified, deletes media
	    cout<<"deleted"<<endl;
	    searchVect.erase(searchVect.begin()+deleteCounter);
	    break;
	  }else{
	    continue;
	  }
	}
	deleteCounter++;	
       }
    }
  }  
}
