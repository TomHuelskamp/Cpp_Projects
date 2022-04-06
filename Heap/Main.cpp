//Thomas Huelskamp
//April 6, 2022
//This project stores numbers from user input or file into an array and displays them as a binary tree
#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;
void add(int* &MAXheap,int input,int i);//this function isn't used in this project, it adds integers to the array using traversal
void add1(int* &MAXheap,int input);//adds integers to array
void test(int* MAXheap);//used for testing, prints array
void clear(int* &MAXheap);//clears array and prints the values from greatest to least
void display(int* MAXheap,int i);//displays array as a tree
int main(){
  int* MAXheap = new int[100];
  for(int i=0; i<100;i++){//fills an array with 'empty' zeroes
    MAXheap[i]=0;
  }
  bool forever=true;
  while(forever){
    char name[100];
    cout<<"'manual' entry, 'file' entry, 'clear' heap, or 'display' tree?: ";
    ;
    cin.get(name,100);
    cin.get();
    if(strcmp(name,"manual")==0){//enter by number
      cout<<"enter a number: ";
      int input;
      cin>>input;
      cin.get();
      add1(MAXheap,input);
    }else if(strcmp(name,"file")==0){//enter by file
      cout<<"available files: ";
      cout<<"file1"<<endl;
      cout<<"enter a file name: ";
      char fileName[100];
      cin.get(fileName, 100);
      cin.get();
      if(strcmp(fileName,"file1")==0){//file1
	string numberString;
	int input;
	ifstream file1;
	file1.open("file1.txt");
	while(file1){//read in numbers from file
	  file1>>numberString;
	  input=stoi(numberString);
	  add1(MAXheap,input);
	}
	file1.close();
      }else{
	cout<<"file not found"<<endl;
      }
    }else if(strcmp(name,"clear")==0){//clear
      clear(MAXheap);
    }else if(strcmp(name,"display")==0){//display tree
      display(MAXheap,1);
    }else if(strcmp(name,"quit")==0){//quit
      break;
    }else{
      cout<<"invalid input"<<endl;
      
    }
  }
  return 0;
}
/**
void add(int* &MAXheap,int input,int i){
  if(MAXheap[i]==0){//index is empty, place int at index
    MAXheap[i]=input;
  }else if(input>MAXheap[i]){//more than index
    int replace=MAXheap[i];
    MAXheap[i]=input;
    add(MAXheap,replace,i);
  }else if(input<MAXheap[i]){//less than index
    if((input>MAXheap[i*2]&&MAXheap[i*2+1]!=0 )|| MAXheap[i*2]==0){//more than left
      if(MAXheap[i*2]==0){//left empty
	MAXheap[i*2]=input;
      }else{//left full
	int replace=MAXheap[i*2];
	MAXheap[i*2]=input;
	add(MAXheap,replace,i);
      }
    }else if(input>MAXheap[i*2+1]){//more than right
      if(MAXheap[i*2+1]==0){//right empty
	MAXheap[i*2+1]=input;
      }else{//right full
	int replace=MAXheap[i*2+1];
	MAXheap[i*2+1]=input;
	add(MAXheap,replace,i);
      }
    }else if(input<MAXheap[i*2] && MAXheap[i*2+1]!=0){//less than left
	add(MAXheap,input,i*2);
    }else if(input<MAXheap[i*2+1]){//less than right
      add(MAXheap,input,i*2+1);
    }
  }
}**/
void test(int* MAXheap){//prints array vertically in order of  descending values (used for testing)
  for(int i=0; i<100;i++){//goes through array
    if(MAXheap[i]!=0){
      cout<<i<<". "<<MAXheap[i]<<endl;
    }
    }
  cout<<endl;
}
void add1(int* &MAXheap, int input){//used for adding values to the array
  for(int i=1; i<100;i++){
    if(input>MAXheap[i]){//replaces lesser value with input
      int a=MAXheap[i];
      MAXheap[i]=input;
      add1(MAXheap,a);//recalls with the integer that was replaced
      break;
    }
  }
}
void clear(int* &MAXheap){//clears and prints the array
  while(MAXheap[1]!=0){//repeats function until the array is empty
    int i=1;
    cout<<MAXheap[1];
    if(MAXheap[2]!=0){//adds commas
      cout<<", ";
    }
    while(MAXheap[i]!=0){
      MAXheap[i]=MAXheap[i+1];//gets rid of 'head' by replacing everything with the next value, 'tail' gets replaced with a zero so the whole array is shifted over
      i++;
    }
  }
  cout<<endl;//prints value
}
void display(int* MAXheap,int i){//displays the tree
  //Kabir V helped me with this function, the most important thing was using logarithms to find position of each integer
  if(i*2<=100 && MAXheap[i*2]!=0){//traverses left
    display(MAXheap,(i*2));
  }
  int space=(int)floor((log(i)/log(2)));//uses logarithms to find the amount of spaces before each integer
  for(int b=0;b<space;b++){//prints spaces
    cout<<"      ";
  }
  cout<<MAXheap[i]<<endl;
  if(i*2+1<=100 && MAXheap[i*2+1]!=0){//traverses right
    display(MAXheap,(i*2+1));
  }
}
