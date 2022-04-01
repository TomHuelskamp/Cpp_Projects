#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;
void add(int* &MAXheap,int input,int i);
void add1(int* &MAXheap,int input);
void test(int* MAXheap);
int main(){
  int* MAXheap = new int[100];
  MAXheap[1]=0;//array is 'empty' when the highest value is 0
  for(int i=0; i<100;i++){
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
      test(MAXheap);
    }else if(strcmp(name,"file")==0){
      cout<<"available files: ";
      cout<<"file1"<<endl;
      cout<<"enter a file name: ";
      char fileName[100];
      cin.get(fileName, 100);
      cin.get();
      if(strcmp(fileName,"file1")==0){
	//cout<<"adding file1 to the tree..."<<endl;
	string numberString;
	int input;
	ifstream file1;
	file1.open("file1.txt");
	while(file1){
	  file1>>numberString;
	  input=stoi(numberString);
	  add1(MAXheap,input);
	}
	file1.close();
      }else{
	cout<<"file not found"<<endl;
      }
    }else if(strcmp(name,"clear")==0){
    }else if(strcmp(name,"display")==0){
    }else{
      cout<<"invalid input"<<endl;
      
    }
  }
  return 0;
}
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
}
void test(int* MAXheap){
  for(int i=0; i<100;i++){
    if(MAXheap[i]!=0){
      cout<<i<<". "<<MAXheap[i]<<endl;
    }
    }
  cout<<endl;
  
}
void add1(int* &MAXheap, int input){
  for(int i=1; i<100;i++){
    if(input>MAXheap[i]){
      int a=MAXheap[i];
      MAXheap[i]=input;
      add1(MAXheap,a);
      break;
    }
  }
}
