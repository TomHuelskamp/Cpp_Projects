//Main
#include <iostream>
#include "Student.h"
#include "Node.h"
#include <cstring>
using namespace std;
void add();
void print();
void remove();
void average();
int main(){
  bool quitIfTrue = false;
  while(!quitIfTrue){
    char input[50];
    cin.get(input, 50);
    cin.get();
    if(strcmp(input,"QUIT")==0){
      cout<<"exiting...";
      quitIfTrue=true;
    }else if(strcmp(input,"ADD")==0){
      add();
    }else if(strcmp(input, "PRINT")==0){
      print();
    }else if(strcmp(input,"DELETE")==0){
      remove();
    }else if(strcmp(input, "AVERAGE")==0){
      average();
    }
  }
  return 0;
}
void add(){
}
void print(){
}
void remove(){
}
void average(){
}
