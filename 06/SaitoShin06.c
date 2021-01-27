/*
The program takes in an integer from 1 to 9.
Then returns the pronounciation of the value in Japanese.

@author Saito, Shin
@ ICS 212 Assignment 6
@date February 4, 2021

*/
#include <stdio.h>

int main(void){
  //initialize all the variables
  //variable to hold the user input
  char userInput = 'A';
  //tell the user what this program will  do
  puts("This will display the Japanese pronounciation of the digit of your choice");
  //Ask the user for a digit input
  printf("Select between a number from 0 to 9:");
  //Get the user userInput
  userInput = getchar();
  //initate the swtich statements
  switch(userInput) {
    //for the valid inputs of  0 to 9 return the appropriate pronounciation
    case '0':
      puts("rei");
      break;
    case '1':
      puts("ichi");
      break;
    case '2':
      puts("ni");
      break;
    case '3':
      puts("san");
      break;
    case '4':
      puts("yon");
      break;
    case '5':
      puts("go");
      break;
    case '6':
      puts("roku");
      break;
    case '7':
      puts("shichi");
      break;
    case '8':
      puts("hachi");
      break;
    case '9':
      puts("kyuu");
      break;
    //Otherwise for invalid inputs return a error statement
    default:
      printf("Invalid Input: '%c' is not in the range of 0 - 9\n", userInput);
      break;
  }
  return 0;
}
