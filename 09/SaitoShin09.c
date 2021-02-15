#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
A file that plays Jan Ken Po, better known as Rock Paper Scissors.
If the user wins then print the user win and other wise show the game state.

@author Saito, Shin
@assignment ICS212, Assignment 9
@date 2021-02-18
**/

//function declaration.
//function to convert the moves
int moveConversion(char input);
//function to determine who won or not
int matchConversion(int moveA, int moveB);
//function to print the game statements
void gameStatement(int winner, int moveA, int moveB);

int main(void) {
  //variable declaration
  //stores the user's selection
  char userChoice = 'A';
  //stores the computer's selection
  char compChoice = 'A';
  //stores the computer's move
  int userMove = 1;
  //stores the computer's moves
  int compMove = 1;
  //game condition
  int gameSet = 0;
  //count of games
  int gameCount = 0;
  //count of user win
  int winCount = 0;
  //count of losses
  int lossCount = 0;
  //count of ties
  int tieCount = 0;
  //prevent repetition
  srand(time(NULL));
  //place a welcome message
  puts("Welcome to Jan-Ken-Pon game");
  //tell the user how to play the game
  puts("To quit the game press Q or q and then Enter");
  while(userChoice != 'Q' || userChoice != 'q'){
        printf("Enter 'r', 'p','s' for rock paper scissiors:  ");
        userChoice = getchar();
        getchar();
        //if the input is Q
        if (userChoice == 'Q') {
          //show the user the score board
          printf("User Wins: winCount: %d, Ties: %d, Losses: %d\n", winCount, tieCount, lossCount);
          return 0;
        }
        //otherwsie if the choice is Q
        else if (userChoice == 'q') {
          //similar to if the choice is Q
          printf("User Wins: %d, Ties: %d, Losses: %d\n", winCount, tieCount, lossCount);
          return 0;
        }
        //if the choices are the valid inputs
        else if (userChoice == 's' || userChoice == 'r' || userChoice == 'p'){
          //increase the count played
          gameCount++;
          //convert the user's choice to the appropriate integer
          userMove = moveConversion(userChoice);
          //generate the computers move randomally
          compMove = rand() % 3;
          //determine who wins
          gameSet = matchConversion(userMove, compMove);
          //increase the counts of win lose or ties
          if (gameSet == 1) {
            winCount++;
          }
          //user has lost to computer
          else if (gameSet == 2) {
            lossCount ++;
          }
          //user has a tie between the computer
          else {
            tieCount++;
          }
          //print who won and how the user has done
          gameStatement(gameSet, userMove, compMove);
        }
        //otherwise if the inputs are not valid
        else {
          printf("%c: Invalid Input. Please Try Again\n", userChoice);
        }
  }
  }


//function to convert the user input char to int
int moveConversion(char input) {
  //variable decalration to return the move
  int move = 1;
  //switch to the char to its corresponding number
  switch(input) {
    //rock to 0
    case 'r':
      move = 0;
      return move;
      break;
    //paper to 1
    case 'p':
      move = 1;
      return move;
      break;
    //scissors to 2 
    case 's':
      move = 2;
      return move;
      break;
    default:
      break;
  }
}
//function to determine who wins
int matchConversion(int moveA, int moveB) {
  //variable declaration for the function
  int gameSet = 0;
  //if the two moves matches
  if (moveA == moveB) {
    gameSet = 0;
  }
  //if moveA beats move B set gameSet to 1
  else if (moveA == 1 && moveB == 0) {
    gameSet = 1;
  }
  else if (moveA == 2 && moveB == 1) {
    gameSet = 1;
  }
  else if (moveA == 0 && moveB == 1) {
    gameSet = 1;
  }
  //else if moveB beats move A then the computer wins
  else {
    gameSet = 2;
  }
  return gameSet;
  }

  //function to determine who wins
  void gameStatement(int winner, int moveA, int moveB) {
    //if its a tie
    if(winner == 0){
      //print why it is a tie based on the moves
      if (moveA == 0) {
        printf("Two rocks. Its a tie.\n");
      }
      else if (moveA == 1) {
        printf("Two papers. It's a tie.\n");
      }
      else {
        printf("Two scissors. It's a tie. \n");
      }
    }
    //otherwise if the user wins
    else if (winner == 1) {
      //if the user wins, print how the user won
      if (moveA == 0) {
        printf("Rock beats Scissors. YOU USER wins\n");
      }
      else if (moveA == 1) {
        puts("Paper beats Rock. YOU USER wins.");
      }
      else {
        puts("Rock beats Scissors. YOU USER wins.");
      }
    }
    //otherwise if the computer won, print how the computer wons
    else {
      if (moveB == 0) {
        printf("Rock beats Scissors. COMPUTER wins\n");
      }
      else if (moveB == 1) {
        puts("Paper beats Rock. COMPUTER wins.");
      }
      else {
        puts("Rock beats Scissors. COMPUTER wins.");
      }
    }
  }
