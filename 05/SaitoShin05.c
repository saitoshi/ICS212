/*

A program that asks for the user's birthday and calculates the different between the current date and their birthday
*/
#include <stdio.h>
#include "getdouble.h"


//Symbolic Constant
#define YRDAY 365.25 //one year == 365.25
#define MTDAY 365.25/12.0

int main(void) {
  //variable delcaration
  //variables for the birth and current difference
  double agesDays = 0.0;

  //variable for the month, year, and day inputs
  double monthInput = 0.0;
  double dayInput = 0.0;
  double yrInput = 0.0;
  //variable for the current dates
  double currentMth = 2.0;
  double currentDy = 2.0;
  double currentYr = 2021.0;
  //variables to help with the calculations
  double sinceCurrent = 0.0; //number of days since current
  //number of days since birthday
  double sinceBirth = 0.0;
  //tell the user waht this does
  puts("Welcome. This program will calculate your age in days.");
  //ask the user to input the birth date by month, date, and year
  printf("Enter the month you were born (1-12):");
  monthInput = getdouble();
  printf("Enter the day you were born (1-30(31)):");
  dayInput = getdouble();
  printf("Enter the year you were born:");
  yrInput = getdouble();
  //print the current date
  printf("Today's date is %d/%d/%d \n", (int)currentMth, (int) currentDy, (int) currentYr);
  //print the inputted birth dates
  printf("Birthdate is: %d/%d/%d \n",(int) monthInput,(int)  dayInput, (int) yrInput);
  sinceCurrent = (currentYr * YRDAY) + ((currentMth - 1) * YRDAY/12.0) + currentDy;
  sinceBirth = (yrInput * YRDAY) + ((dayInput - 1) * YRDAY/12.0) + dayInput;
  agesDays = (sinceCurrent - sinceBirth);
  printf("Your age in days is: %d \n", (int) agesDays);


}
