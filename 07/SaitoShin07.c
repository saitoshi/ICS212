/**
This program returns 1 to 999 in Japanese Romaji.
Returns it through a combo of for and switch statements.

@author Saito, SaitoShin07
@assignement ICS 212 Assignment 7
@date 2021 - 02 - 11
*/

#include <stdio.h>

int main(void) {
  //variable declaration
  //how high the program will count up to
  int i = 1;
  //int variables to store the digit places 
  int one = 0;
  int ten = 0;
  int hundred = 0;
  //initiate the for loop
  puts("This program will print the Romaji pronounciation of Japanese counting from 1 to 999");
  for(i = 1; i < 1000; i++) {
    //formula to store the hundredth place
    hundred = (i/100) % 10;
    //formula to check the tenth place
    ten = (i/10) % 10;
    //formula to check the ones digit
    one = i % 10;
    //Print statement for the current i count
    printf("%d = ",i);
    //switch the hundredth digit to accordingly
    switch(hundred) {
      case 1:
        printf("hyaku");
        break;
      case 2:
        printf("nihyaku");
        break;
      case 3:
        printf("sanbyaku");
        break;
      case 4:
        printf("yonhyaku");
        break;
      case 5:
        printf("gohyaku");
        break;
      case 6:
        printf("roppyaku");
        break;
      case 7:
        printf("nanahyaku");
        break;
      case 8:
        printf("happyaku");
        break;
      case 9:
        printf("kyuhyaku");
        break;
      default:
        break;
    }
    //switch the ten to accordingly
    switch(ten) {
      case 1:
        printf(" jyuu");
        break;
      case 2:
        printf(" nijyuu");
        break;
      case 3:
        printf(" sanjyuu");
        break;
      case 4:
        printf(" yonjyuu");
        break;
      case 5:
        printf(" gojyuu");
        break;
      case 6:
        printf(" rokujyuu");
        break;
      case 7:
        printf(" nanajyuu");
        break;
      case 8:
        printf(" hachijyuu");
        break;
      case 9:
        printf(" kyujyuu");
        break;
      default:
        break;
    }
    //switch one to accordingly
    switch(one) {
      case 1:
        printf(" ichi \n");
        break;
      case 2:
        printf(" ni \n");
        break;
      case 3:
        printf(" san \n");
        break;
      case 4:
        printf(" yon \n");
        break;
      case 5:
        printf(" go \n");
        break;
      case 6:
        printf(" roku \n");
        break;
      case 7:
        printf(" nana \n");
        break;
      case 8:
        printf(" hachi \n");
        break;
      case 9:
        printf(" kyu \n");
        break;
      default:
        printf("\n");
        break;
    }
  }
  return 0;
}
/*
./program < program.txt

This will print out the text of counting from 1 to 999 in Japanese.
*/
