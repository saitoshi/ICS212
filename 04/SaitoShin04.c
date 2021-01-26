#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "getdouble.h"

/**
The program that takes 2 characters and 2 doubles. After that it retursn it to the user.

@author: Shinya Saito
@assignment ICS 212 Assignment 04
@date 2021-01-28
*/

int main(void){
  //Variables to store the input characters
  char inputChar1 = 'A';
  char inputChar2 = 'A';
  //Variables to store the input doubles
  double inputD1 = 0.0;
  double inputD2 = 0.0;
  //ask the user to input a letter of their choice
  printf("Please input the first letter of your choice:");
  inputChar1 = getchar();
  //use as a buffer for the first input
  getchar();
  //print the stored user variable
  printf("Your first letter is:'%c' \n",inputChar1);
  //Ask for another character input
  printf("Please input the second letter of your choice:");
  inputChar2 = getchar();
  //use as a buffer
  getchar();
  //print the second letter
  printf("Your second letter is:'%c' \n",inputChar2);
  //Ask the user for a double input
  printf("Enter a number of your choice:");
  inputD1 = getdouble();
  //Store and Print the first double
  printf("The first number inputted is:'%f' \n", inputD1);
  //Ask for another double of the users choice
  printf("Enter another number of your choice:");
  inputD2 = getdouble();
  //print the second double
  printf("The second number inputted is: '%f' \n", inputD2);
}
