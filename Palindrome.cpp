#include <iostream>
#include <cstring>

using namespace std;
int main()
{
  char input[80];
  char input2[80];
  int a=0;
  bool notPalindrome = false;
  cin.get(input, 80);
  cin.get();
  
  for(int i=0; i<80 && input[i]!='\0'; i++){
    if(input[i]>='A' && input[i]<='Z')//Converts uppercase to lowercase
      {
	input[i]=input[i]+32;
      }
  }
  for(int i=0; i<80 && input[i]!='\0'; i++){
    if(input[i] >= 'a' && input[i] <= 'z')
      {
	input2[a]=input[i];
	++a;
      }
  }
  a--;
  // cout<<input<<endl;
  // cout<<input2<<endl;
  // cout<<"(length)a:"<<a<<endl;
  
  for(int i=0; i<a; i++){
    //cout<<i<<":"<<input2[i]<<endl;
    //cout<<a<<":"<<input2[a]<<endl;
    if(input2[i]!=input2[a]){
      //cout<<"tick"<<endl;
      notPalindrome = true;
    }
    a--;
    }
  if(notPalindrome){
    cout<<"Not a Palindrome"<<endl;
  }
  else{
    cout<<"Palindrome."<<endl;
  }
  return 0;
}
