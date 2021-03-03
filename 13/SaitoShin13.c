#include <stdio.h>

//function prototype
void increaseIntViaPointer(int *);

int main(void) {
  //variable declaration
  //array of size 5 with inputs in them
  int intArray[] = {13, 72, 88, 100, 17};
  //declare an integer pointer with the address of the array
  int *pointer = intArray;
  pointer= &intArray[0];
  //declare an integer value initialized to 5
  int integer = 10;
  //print the last element of the array sing different methods
  puts("Printing the last element in the array:");
  //Using array subscript notation with the array name
  printf("intArray[4]=%d\n", intArray[4]);
  //Using pointer/offset notation with the array name
  printf("*(intArray+4) = %d\n", *(intArray+4));
  //Using array subscript notation with the pointer
  printf("intArrayPointer[4]= %i\n", pointer[4]);
  //Using pointer/offset notation with the pointer
  printf("*(intArrayPointer + 4)= %i\n", *(pointer + 4));
  //create a space
  printf("\n");
  //print the contents of the array in multiple ways
  puts("Printing the contents of the array:");
  //Using array subscript notation with the array name
  puts("  Using array subscript notation with array name...");
  //declare the step variable
  int j;
  //initate a for loop
  for(j = 0; j<5; j++) {
    printf("   %d", intArray[j]);
  }
  printf("\n");
  //Using pointer/offset notation with the array name
  puts("   Using pointer/offset notation with array name...");
  //initiate a for loop
  for(j=0; j<5;j++) {
    printf("   %d", *(intArray+j));
  }
    printf("\n");
  //Using array subscript notation with the pointer
  puts("   Using array subscript notation with pointer...");
  for(j=0; j<5;j++) {
    printf("   %i", pointer[j]);
  }

  //Using pointer/offset notation with the pointer
  printf("\n");
  puts("   Using pointer/offset notation with pointer...");
  //initiate a for loop to print the array
  for(j=0; j<5;j++) {
    printf("   %i", *(pointer+j));
  }
  printf("\n");
  //Output the addresses of each element in the array in hexadecimal.
  puts("Printing the addresses of each element in the array:");
  //iniitate a for loop to print the address per each item in the array
  for(j=0; j<5;j++) {
    printf("   &array[%d] = %p\n", j, &intArray[j]);
  }
  //print the value before calling to the function
  puts("Integer variable BEFORE function call...");
  printf("intVariable = %d\n", integer);
  //call the to the function
  increaseIntViaPointer(&integer);
  //return 0 to terminate the program
  return 0;
}
//a function that will increase the
void increaseIntViaPointer(int *input) {
  puts("Inside increaseIntViaPointer() function, increasing parameter by 100...");
  *input +=100;
  printf("*intParam = %i\n", *input);
  puts("Integer variable AFTER function call...");
  printf(" intVariable = %d\n", *input);

}
