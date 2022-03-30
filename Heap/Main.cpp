#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
void add(int* &MAXheap,int input,int i);
int main(){
  int* MAXheap = new int[100];
  MAXheap[1]=0;//array is 'empty' when the highest value is 0
  for(int i=0; i<100;i++){
    MAXheap[i]=0;
  }
  bool forever=true;
  while(forever){
    cout<<"add a number: ";
    int input;
    cin>>input;
    add(MAXheap,input,1);
  }
  return 0;
}
void add(int* &MAXheap,int input,int i){
  if(MAXheap[i]==0){//index is empty, place int at index
    MAXheap[i]=input;
  }else if(input>MAXheap[i]){//more than index
  }else if(input<MAXheap[i]){//less than index
    if(input>MAXheap[i*2]){//more than left
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
    }else if(input<MAXheap[i*2]){//less than left
      add(MAXheap,input,i*2);
    }else if(input<MAXheap[i*2+1]){//less than right
      add(MAXheap,input,i*2+1);
    }
  }
};
