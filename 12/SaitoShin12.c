/**
Stores 3 variables and prints is pointers.
Updates the pointers and print its value.

@author Saito, SHin
@assignment ICS 212 Assignment 12
@date 2021-02-28
**/

#include <stdio.h>

int main() {
  //declare the 3 variables: char, int, and double
  char variable1 = 'f';
  int variable2 = 5;
  double variable3 = 3.14;
  //print the user what the current variable values are
  puts("Variable values:");
  printf("charVariable = %c\n", variable1);
  printf("intVaraible = %d\n", variable2);
  printf("doubleVariable = %f\n", variable3);
  printf("\n");
  //declare and initialize 3 pointers
  //character pointer
  char *pointer1 = &variable1;
  //intger pointer
  int *pointer2 = &variable2;
  //double pointer
  double *pointer3 = &variable3;

  //output the hexadecimal value o the address of the 3 variables
  puts("Pointer names and addresses stored:");
  //print the char, integer, and double pointer
	printf("charPointer = %p\n", &pointer1);
	printf("intPointer = %p\n", &pointer2);
	printf("doublePointer = %p\n", &pointer3);
	printf("\n");

  //output the pointers using deferencing
  puts("Pointer names and values using dereferencing:");
  //print the char, int, double dereferenced pointers
	printf("dereferenced charPointer = %c\n", *pointer1);
  printf("dereferenced intPointer = %d\n", *pointer2);
  printf("dereferenced doublePointer = %f\n", *pointer3);
  printf("\n");
  //add 4 to the values of the pointers
  *pointer1 += 4;
  *pointer2 += 4;
  *pointer3 += 4;
  //print the pointers using +4 dereferencing
  puts("Pointer names and values using dereferencing after + 4:");
  printf("dereferenced charPointer = %c\n", *pointer1);
  printf("dereferenced intPointer = %d\n", *pointer2);
  printf("dereferenced doublePointer = %f\n", *pointer3);
  printf("\n");
  //print the updated variable values
  puts("Variable values");
	printf("charVariable = %c\n", *pointer1);
  printf("intVaraible = %i\n", *pointer2);
  printf("doubleVariable = %f\n", *pointer3);
  //return 0 to finish the program
  return 0;
}
