//This project checks if the user's input is a palindrome after removing capitals, punctuation, and spaces.
//Thomas Huelskamp
//October 3, 2021
#include <iostream>
#include <cstring>

using namespace std;
int main()
{
  char input[80];
  char input2[80];
  int a=0;
  bool notPalindrome = false;
  //Prompts the user to enter characters for character array input
  cin.get(input, 80);
  cin.get();
  
  for(int i=0; i<80 && input[i]!='\0'; i++){//Goes through the input
    if(input[i]>='A' && input[i]<='Z')
      {//Replaces capitals with the corresponding lowercase letter
	input[i]=input[i]+32;
      }
  }
  for(int i=0; i<80 && input[i]!='\0'; i++){//Goes through the input (with capitals removed)
    if(input[i] >= 'a' && input[i] <= 'z')
      {//if the carachter isn't a space or punctuation, adds the carachter to a new input named input2
	input2[a]=input[i];
	++a;
      }
  }
  a--;
  
  for(int i=0; i<a; i++){//Goes through input2, using variables i and a for the parrallel characters
    if(input2[i]!=input2[a]){//Checks if the parrallel characters are the same
      notPalindrome = true;
    }
    a--;
  }
  if(notPalindrome){//If the user's input isn't a palindrome, tell the user
    cout<<"Not a Palindrome"<<endl;
  }
  else{//If the user's input was a palindrome, tell the user
    cout<<"Palindrome."<<endl;
  }
  return 0;
}
