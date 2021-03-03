/**
Stores the letter input into an array.
And returns the frequency of each letter appearances.

@author Saito, SHin
@assignment ICS 212 Assignment 11
@date 2021-02-28
**/

#include <stdio.h>
/**function prototypes declaration
 that will be used for the program**/
void printInstructions(void);
void loopAndCountLetters(int[]);
void outputResults(int[],int);
//the main function for the program
int main() {
  //initialize the array with 26slots
  int letters[26] = {0};
  //call the print instruction functions
  printInstructions();
  //call the loopAndCountLetters functions with letter input
  loopAndCountLetters(letters);
  //call the outputResults functions
  outputResults(letters, 26);

  return 0;
}

//input: none output: returns a set of instructions
void printInstructions(void) {
  puts("This program will count the letters of the alphabet.");
  puts("Type several sentences, or use input redirection to input a file.");
  puts("To exit program, enter EOF (end of File) by pressing Ctrl-D");
}
//function to count the loop
void loopAndCountLetters(int in[]) {
  //initialize the variables for the functions
  //variable for the index
  int index = 0;
  //initialize the variable to store char
  char input='A';
  while (input != EOF) {
    //get the user input
    input = getchar();
    //while the user input is a letter
    if (input >= 'a' && input<= 'z') {
      //subtract from 'a'
      index = (input - 'a');
      //increment the array
      in[index] = in[index] + 1;
    }
    //else if the input is an upper case
    else if (input >= 'A' && 'Z'>= input) {
      //subtract from 'A'
      index = (input - 'A');
      //increment the array
      in[index] = in[index] + 1;
    }

  }
  }
//function to output the result
void outputResults(int input[],int count) {
  //initialize the variables
  int i;
  printf("\n");
  //print the title for the two columns
  printf("Character     Count\n");
  //initiate a for loop
  for(i = 0; i < count; i++) {
    //print the letter and its frequncy of appearance
      printf("%c              %d\n", i +'a', input[i]);
  }
  }

/*
./program < program.txt

This will print out the text of counting from 1 to 999 in Japanese.
*/
