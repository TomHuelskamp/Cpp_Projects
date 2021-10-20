//This is a recreation of the game Tic Tac Toe
//Thomas Huelskamp
//October 20, 2021

#include <iostream>
#include <cstring>
using namespace std;

int main(){

  bool X_turn = true;
  bool Win_condition = false;
  int X_win_count = 0;
  int O_win_count = 0;
  int one=1;
  char letter;
  char number;
  int int_letter;
  int int_number;
  char Board[4][4];
  bool First_turn=true;

  while(one==1){//the while condition is created so that it will never be false, so this is an infinite loop
    
    for(int row=0; row<4; row++){//Creates an empty board entirely filled with spaces
      for(int column=0; column<4; column++){
	Board[row][column]=' ';
      }
    }
    
    //Creates labels for the board's columns and rows
    Board[0][0]=' ';
    Board[0][1]='1';
    Board[0][2]='2';
    Board[0][3]='3';
    Board[1][0]='A';
    Board[2][0]='B';
    Board[3][0]='C';

    //Resets the win checking boolean and turn to X, so that the user can play a new game
    Win_condition=false;
    X_turn=true;
    First_turn=true;
    
    while(Win_condition==false){//The loop for each time there is a new game
     
      cout<<endl;
      for(int row=0; row<4; row++){//Prints out the board (including any pieces on the board)
	for(int column=0; column<4; column++){
	  cout<<Board[row][column]<<'\t';
	}
	cout<<endl;
      }
      cout<<endl;
 
      if(X_turn){//If it is X's turn
	//Lets the user enter the coordinates for where X should be placed
	cout<<"Place an X"<<endl;
	X_turn=false;
	cout<<"(row)letter: ";
	cin>>letter;
	cout<<"(column)number: ";
	cin>>number;
	//Converts what the user entered into integers
	letter=letter-64;
	number=number-48;
	int_letter = (int)letter;
	int_number = (int)number;
	if(Board[int_letter][int_number]!=' '){//If the user chose invalid coordinates, alerts the user and restarts the turn
	  X_turn=true;
	  cout<<"INVALID MOVE"<<endl;
	}else{//If the user chose valid coordinates, places an X
	  Board[int_letter][int_number]='X';
	}
      }
      else{//If it is O's turn
	//Lets the user enter the coordinates for where O should be placed
	cout<<"Place an O"<<endl;
	X_turn=true;
	cout<<"(row)letter: ";
	cin>>letter;
	cout<<"(column)number: ";
	cin>>number;
	//Converts what the user entered into integers
	letter=letter-64;
	number=number-48;
	int_letter = (int)letter;
	int_number = (int)number;
	if(Board[int_letter][int_number]!=' '){//If the user chose invalid coordinates, alerts the user and restarts the turn
	  X_turn=false;
	  cout<<"INVALID MOVE"<<endl;
	}else{//If the user chose valid coordinates, places an O
	  Board[int_letter][int_number]='O';
	}
      }
      if(//Checks for possible conditions of X winning
	 //Horizontal
	 Board[1][1]=='X'&&Board[1][2]=='X'&&Board[1][3]=='X' ||
	 Board[2][1]=='X'&&Board[2][2]=='X'&&Board[2][3]=='X' ||
	 Board[3][1]=='X'&&Board[3][2]=='X'&&Board[3][3]=='X' ||
	 //Vertical
	 Board[1][1]=='X'&&Board[2][1]=='X'&&Board[3][1]=='X' ||
	 Board[1][2]=='X'&&Board[2][2]=='X'&&Board[3][2]=='X' ||
	 Board[1][3]=='X'&&Board[2][3]=='X'&&Board[3][3]=='X' ||
	 //Diagonal
	 Board[1][1]=='X'&&Board[2][2]=='X'&&Board[3][3]=='X' ||
	 Board[1][3]=='X'&&Board[2][2]=='X'&&Board[3][1]=='X' 
	 )
	{
	  Win_condition=true;
	}else if(//Checks for possible conditions of O winning
		 //Horizontal
		 Board[1][1]=='O'&&Board[1][2]=='O'&&Board[1][3]=='O' ||
		 Board[2][1]=='O'&&Board[2][2]=='O'&&Board[2][3]=='O' ||
		 Board[3][1]=='O'&&Board[3][2]=='O'&&Board[3][3]=='O' ||
		 //Vertical
		 Board[1][1]=='O'&&Board[2][1]=='O'&&Board[3][1]=='O' ||
		 Board[1][2]=='O'&&Board[2][2]=='O'&&Board[3][2]=='O' ||
		 Board[1][3]=='O'&&Board[2][3]=='O'&&Board[3][3]=='O' ||
		 //Diagonal
		 Board[1][1]=='O'&&Board[2][2]=='O'&&Board[3][3]=='O' ||
		 Board[1][3]=='O'&&Board[2][2]=='O'&&Board[3][1]=='O'
		 )
	{
	  Win_condition=true;
	}
      else{
	Win_condition=false;
      }

      if(Win_condition){//If the conditions for winning were met
	if(X_turn){//If it was O's turn last, tell the user that O won, and add to O's win count
	  cout<<"O Wins!"<<endl;
	  O_win_count++;
	  cout<<"X has: "<<X_win_count<<" wins"<<endl;
	  cout<<"O has: "<<O_win_count<<" wins"<<endl;
	}
	else{//If it were X's turn last, tell the user that X won, and add to X's win count
	  cout<<"X Wins!"<<endl;
	  X_win_count++;
	  cout<<"X has: "<<X_win_count<<" wins"<<endl;
	  cout<<"O has: "<<O_win_count<<" wins"<<endl;
	}
      }else if(Board[1][1]!=' '&&Board[1][2]!=' '&&Board[1][3]!=' '&&
	       Board[2][1]!=' '&&Board[2][2]!=' '&&Board[2][3]!=' '&&
	       Board[3][1]!=' '&&Board[3][2]!=' '&&Board[3][3]!=' '&& First_turn==false){//If there were no wins, but the board is full, so there is a tie
	cout<<"Tie Game"<<endl;	
	cout<<"X has: "<<X_win_count<<" wins"<<endl;
	cout<<"O has: "<<O_win_count<<" wins"<<endl;
	Win_condition=true;
      }
      First_turn=false;
    }
  }

  
  return 0;
}



  

