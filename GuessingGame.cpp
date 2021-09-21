
#include <iostream>
using namespace std;
int main()
{
  int guessCount = 5;
  int lowerLimit = 0;
  int upperLimit = 100;
  int input = 0;
  int randomNum = 50;
  char yesNo = 'n';
  bool playAgain =true;
  bool winCondition = false;
  while(playAgain = true){
    guessCount = 5;
    srand(time(NULL));
    randomNum=(rand()%101);
    cout << "Welcome to Guessing Game, you have " << guessCount << " guesses to guess the random number between " << lowerLimit << " and " << upperLimit << endl;
    while(winCondition == false){
      cout<<"Enter your guess: ";
      cin>>input;
      if(input == randomNum)
	{
	  cout<<"Your number was correct!"<<endl;
	  winCondition = true;
	}
      else if(input < randomNum && input > lowerLimit){
	cout<<"Your number was too low. You have "<<--guessCount<<" more guesses."<<endl;
      }
      else if(input > randomNum && input < upperLimit){
	cout<<"Your number was too high. You have "<<--guessCount<<" more guesses."<<endl;
      }
      else{
	cout<<"Your input was invalid."<<endl;
	break;
      }
      if(guessCount <= 0){
	cout<<"You ran out of guesses."<<endl;
	break;
      }
    }
    cout<<"Would you like to play again? Respond y or n: ";
    cin>>yesNo;

    if(yesNo != 'y'){
      playAgain = false;
      break;
    }
    else{
      playAgain = true;
    }
  }
  
  return 0;
}
//Guessing Game
