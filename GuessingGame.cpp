
#include <iostream>
using namespace std;
int main()
{
  int guessCount = 0;
  int lowerLimit = 0;
  int upperLimit = 100;
  int input = 0;
  int randomNum = 50;
  char yesNo = 'n';
  bool playAgain =true;
  bool winCondition = false;
  while(playAgain = true){
    guessCount = 0;
    srand(time(NULL));
    randomNum=(rand()%101);
    cout << "Welcome to Guessing Game, guess random number between " << lowerLimit << " and " << upperLimit << "in as few guesses as possible." << endl;
    winCondition = false;
    while(winCondition == false){
      cout<<"Enter your guess: ";
      cin>>input;
      if(input == randomNum)
	{
	  cout<<"Your number was correct!It took you "<< ++guessCount <<" guesses"<<endl;
	  winCondition = true;
	}
      else if(input < randomNum && input > lowerLimit){
	cout<<"Your number was too low."<<endl;
	++guessCount;
      }
      else if(input > randomNum && input < upperLimit){
	cout<<"Your number was too high."<<endl;
	++guessCount;
      }
      else{
	cout<<"Your input was invalid."<<endl;
	break;
      }
      //if(guessCount <= 0){
      //cout<<"You ran out of guesses."<<endl;
      //break;
      //}
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
