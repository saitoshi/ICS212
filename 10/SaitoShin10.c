#include <stdio.h>
#include <stdlib.h>
#include "getdouble.h"
/**
A user inputs two values.
The program returns its Count, SUmmation, Product, Power, and GCD.

@author Saito, Shin
@assignment ICS 212 Assignment 10
@date Febrauary 25
*/

//declare the neceesary functions used in the program
void recursiveCount(int, int);
int recursiveAdd(int, int);
int recursiveMultiply(int, int);
int recursivePower(int, int);
int recursiveGcd(int, int);



int main(void) {
  //variable decalaration
  //to store the user inputs
  int input1 = 1;
  int input2 = 1;
  //variable for the return for recursive multiply
  int resultA = 0;
  int resultS = 0;
  //ask the user to input 2 integers smallest to larger
  printf("Enter two positive integers, separated by a space, the first being smaller than the second: ");
  input1 = (int)getdouble();
  input2 =(int)getdouble();
  //if first input is not smaller
  if(input1 > input2) {
    //print an error statement
    printf("Error: %d, is not smaller than %d \n", input1, input2);
    return 0;
  }
  //otherwise input 1 is not postive
  else if (0 > input1) {
    //return an error statement and close
    printf("%d, is not positive\n", input1);
    return 0;
  }
  //otherwise input 2 is not positive
  else if (input2 < 0) {
    printf("%d, is not positive\n", input2);
    return 0;
  }
  //operate the count from input1 to input2
  printf("Counting from %d to %d: ", input1, input2);
  //call the recusrive count function
  recursiveCount(input1, input2);
  //print the results of sum function
  printf("\nThe sum of %d to %d =  %d\n", input1, input2, recursiveAdd(input1, input2));
  //print the result of the product function
  printf("The product of %d to %d =  %d\n", input1, input2, recursiveMultiply(input1, input2));
  //print the results of the power function
  printf("The power  of %d to %d =  %d\n", input1, input2, recursivePower(input1, input2));
  //print the results of the gcd function
  printf("The GCD of %d to %d =  %d\n", input1, input2, recursiveGcd(input1, input2));
  return 0;
}
//a recursive function to print count up from A to B
void recursiveCount(int inputA,int inputB) {
  //if second input is larger thatn input A
  if(inputB >= inputA) {
    //print the current input A
    printf(" %d ", inputA);
    //go higher
    recursiveCount(inputA+1, inputB);
  }
}
//a recrusive sum function
int recursiveAdd(int inputA, int inputB) {
  //if the two inputs are not equal
  if (inputA != inputB) {
    //add input A and the recusrive function of inputA + 1, and inputB
    return inputA + recursiveAdd(inputA+1, inputB);
  }
  //otherwise just reutrn inputB
  else {
    return inputB;
  }
}
//a recursive function for multiplying
int recursiveMultiply(int inputA, int inputB) {
  if(inputA != inputB) {
    return inputA * recursiveMultiply(inputA+1,inputB);
  }
  else {
    return inputB;
  }
}
//recursive function to do the powers
int recursivePower(int base, int power) {
  //if the power is not 0
  if (power != 0) {
    //then recursivel call the power function
    return (base * recursivePower(base, power - 1));
  }
  //otherwsie return 1
  else {
    return 1;
  }
}
//recursive function to find the GCD of 2 inputs
int recursiveGcd(int inputA, int inputB) {
  //if inputB is not 0
  if(inputB != 0) {
    //return the recursive call of GCD to inputB and inputA mod inputB
    return recursiveGcd(inputB, inputA % inputB);
  }
  //otherwise return inputA
  else {
    return inputA;
  }
}
//
