#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printbits.h"

// Function prototypes.
//a function that calculates the twos complement of the input
unsigned int twosComplement(unsigned int);
//a function that packs four character into one integer and returns it
unsigned int packCharacters(unsigned char, unsigned char, unsigned char, unsigned char);
//Unpacks an integer into four characters and assigns them to the character pointer parameters.
void unpackCharacters(unsigned int, unsigned char*, unsigned char*,
                      unsigned char*, unsigned char*);
//Returns an unsigned integer that is the second parameter's bits circular shifted to the left the first parameter number of times.
unsigned int circularLeftShift(unsigned int, unsigned int);
int main(int argc, char *argv[]) {

  int i = 0;

  // ::::: Begin error checking for the command line arguments. :::::
  // ::::::::::::::::::::     DO NOT MODIFY     :::::::::::::::::::::
  // Ensures there is the correct amount of arguments.
  if (argc != 7) {
    printf("Error: 7 commandline arguments are expected, only %d present.\n", argc);
    printf("Enter four characters followed by two integers.\n");
    exit(1);
  }
  // Ensures 4 character arguments.
  for (i = 1; i <= 4; i++) {
    if (strlen(argv[i]) != 1) {
      printf("Error: Please enter a single character for character #%i on the commandline.\n", i);
      printf("You entered %i characters: %s\n", strlen(argv[i]), argv[i]);
      exit(1);
    }
  }
  // Ensures an integer argument.
  unsigned int integer1 = atoi(argv[5]);
  if (0 == integer1 && '0' != argv[5][0]) {
    printf("Error: Expected an integer argument.\n");
    printf("You entered \"%s\" instead.\n", argv[5]);
    exit(1);
  }
  // Ensures an integer argument.
  unsigned int integer2 = atoi(argv[6]);
  if (0 == integer2 && '0' != argv[6][0]) {
    printf("Error: Expected an integer argument.\n");
    printf("You entered \"%s\" instead.\n", argv[6]);
    exit(1);
  }
  // ::::: End error checking for command line arguments. :::::


  puts("function #1:");
  puts("Input is unsigned integer:");
  printbits(integer1);
  unsigned int result = twosComplement(integer1);
  puts("Output is the two's complement of the integer:");
  printbits(result);

  puts("");

  puts("function #2:");
  puts("Input is 4 characters:");
  for (i = 1; i <= 4; i++) {
    print8bits(*argv[i]);
  }
  puts("Output is packed unsigned integer variable in bit format:");
  result = packCharacters(*argv[1], *argv[2], *argv[3], *argv[4]);
  printbits(result);

  puts("");

  puts("function #3:");
  puts("Input is unsigned integer:");
  printbits(integer1);
  unsigned char unpack1, unpack2, unpack3, unpack4;
  unpackCharacters(integer1, &unpack1, &unpack2, &unpack3, &unpack4);
  puts("Output is four unpacked characters: ");
  print8bits(unpack1);
  print8bits(unpack2);
  print8bits(unpack3);
  print8bits(unpack4);

  puts("");

  puts("function #4");
  puts("Input is unsigned integer:");
  printbits(integer2);
  printf("Shifted %i bit(s) to the left.\n", integer1);
  integer2 = circularLeftShift(integer1, integer2);
  printbits(integer2);

  return 0;

}

//function to calculate the two's complement
unsigned int twosComplement(unsigned int input) {
  //initialize the function variables
  //int variable to store the result
  unsigned int result = 0x0000ffff;
  //find the ones complement of the input
  result = ~input;
  //increment result
  result++;
  //return the two's complement result
  return result;
}
//function that Packs four characters into one integer and returns it
unsigned int packCharacters(unsigned char inputA, unsigned char inputB, unsigned char inputC, unsigned char inputD) {
  //variable declaration
  //variable to declare the result that will be returned
  unsigned int result = 0;
  //shift inputA by 24 bits to the left and inclusive or to to to result
  result |= inputA << 24;
  //shift inputB by 16 bits to the left
  result |= inputB << 16;
  //shift inputC by 8 bits to the left
  result |= inputC << 8;
  //inclusive inputD to result
  result |= inputD;
  //return the result
  return result;
}
//Unpacks an integer into four characters and assigns them to the character pointer parameters.
void unpackCharacters(unsigned int input, unsigned char* outputA, unsigned char* outputB,unsigned char* outputC, unsigned char* outputD) {
  //declare the mask variable
  unsigned int mask1 = 0x0000ffff;
  //shift the so that the first character is the first octet to the input
  *outputA = input >> 24;
  //shift so taht the second character has the second octet
  *outputB = (input >> 16) & mask1;
  //shift so that the third character has the third octet of input
  *outputC = (input>>8) & mask1;
  //apply the mask to store to the fourth character
  *outputD = (input) & mask1;
}
//Returns an unsigned integer that is the second parameter's bits circular shifted to the left the first parameter number of times.
unsigned int circularLeftShift(unsigned int rotation, unsigned int input) {
  //declare the variable for the return and initialize it
  unsigned int result = 0;
  //set result to the bit or of input shifted to the left rotation times and input shifted 32-rotation to the right
  result = (input << rotation) | (input >> (32-rotation));
  //return the result
  return result;
}
