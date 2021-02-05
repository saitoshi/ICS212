/**
This program calculates exponential growth for a missing part.
User will input three out of the four parts: total population after time,
initial population, rate of growth, time.
Then the program will calculate the missing part.

The following functions were used:
- exponential was used to calcaulte the exponential calculations
- floor was used twice to round to the nearest whole number
- ceiling
- natural logarithm to calculate
- logarithm to use the change of base formula

@author Saito, Shin
@assignment ICS 212 Assignment 8
@date February 11, 2021
*/

#include <stdio.h>
#include "getdouble.h"
#include <math.h>

int main(void) {
//variable declaration

//variable for population after certain time
double Paftert = 0.0;
//variable for time
double time = 0.0;
//variable for the growth/decay rate
double rate = 0.0;
//variable for the initial population amount
double initial_P = 0.0;
//variable for the mode selection
char mode = 'a';

puts("This program will print out the missing part in exponential growth.");
//Print the user what the possible selections are
puts("Please indicate what you would like to calculate");
puts("a: initial population");
puts("b: population after time");
puts("c: rate of growth");
puts("d: time taken to grow");
printf("Select: ");
mode = getchar();
getchar();
//if input is a calculate the inital population
if(mode == 'a') {
  //Have the user to input known variables
  puts("Selected to calculate the initial population");
  puts("Please input the time of growth in seconds");
  time = getdouble();
  puts("Please input the rate of growth");
  rate = getdouble();
  printf("Please input the population after %0.2f seconds:",time);
  Paftert = getdouble();
  //calculate the rate times time
  double rtimest = rate * time;
  //raise the previous result to e 1 function
  double denominator = exp(rtimest);
  //calculate the initial population
  initial_P = Paftert/denominator;
  //print the initial population to the closest whole number +1 function
  printf("The initial population is: %d \n", (int)ceil(initial_P));
}
//if the user selected b 
else if (mode == 'b') {
  //Remind the user what they chose to do
  puts("Selected to calculate the population after time");
  //Ask the user for the parts needed to calculate
  printf("Please input the initial population: ");
  initial_P = getdouble();
  printf("Please input the rate of growth: ");
  rate = getdouble();
  printf("Please input time take to grow in seconds: ");
  time = getdouble();
  //calculate the parts to use for the formula
  double rtimest = rate * time;
  Paftert = initial_P * exp(rtimest);
  //print the value to the closest integer + 1 function for floor
  printf("The population after %0.2f seconds is %d \n", time, (int)floor(Paftert) );
}
//if the user selected c
else if (mode == 'c') {
  //remind what the user has selected
  puts("Selected to calculate the rate of growth");
  //ask to input the known variables
  printf("Please input the initial population: ");
  initial_P = getdouble();
  printf("Please input the time in seconds: ");
  time = getdouble();
  printf("Please input the population after time %0.2f seconds : ", time);
  Paftert = getdouble();
  //divide initial population and population post time t
  double diff = Paftert/ initial_P;
  //take the natural log of it
  diff = log(diff);
  //Solve for the rate
  rate = diff/time;
  //print the rate
  //if the rate is greater than 0 its a growth
  if(rate >= 0){
    printf("The rate of this exponential growth is: %0.2f \n", rate);
  }
  //otherwise it is a decay
  else {
    printf("The rate of this exponential decay is: %0.2f \n", rate);

  }
}
//if the user selected d
else if (mode == 'd') {
  //Remind what the user has selected to do
  puts("Selected to calculate the time of growth");
  //Ask the user for the known variables
  printf("Please input the initial population: ");
  initial_P = getdouble();
  printf("Please input the rate of growth: ");
  rate = getdouble();
  printf("Please input the population after time t: ");
  Paftert = getdouble();
  //calculate the difference by using the quotient rules of log
  double diff = (log10(Paftert)/log10(e)) - (log10(initial_P)/log10(e));
  //divide the difference by rate
  time = diff/rate;
  //show the time taken for the growth
  printf("The time take in seconds is: %f \n", (int)floor(time));
}
//otherwise return inappropriate character
else {
  printf("Input not valid.");
}
return 0;
}
