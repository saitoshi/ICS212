#include <stdio.h>
#include <stdlib.h> // For the random generator function
#include <time.h> //time function

//create the structure of a node
struct node{
  int data;
  struct node *next;
};

//declare the new data types
typedef struct node Node;
typedef struct node* NodePointer;

//function prototype declaration
//creates a LinkedList with int and NodePointer as a param
void insertLinkedList(int, NodePointer*);
//displays the LinkedList with the NodePointer aa a param
void displayLinkedList(NodePointer);
//function that calulcates the sum of all integers in the LinkedList
int sumLinkedList(NodePointer);


int main(void) {
  //use this to store the randomally generated numbers
  int numbers[75] = { 0 };
  //variables to store the sum and average of the LinkedList
  double average = 0.00;
  int sum = 0;
  srand(time(NULL));
  //declare the variable for size
  int size = 25 + rand() % 51;
  //declare a pointer for the 1st node in the linked list
  NodePointer head = NULL;
  //begin a for loop counter so the count does not exceed the size
  int count = 0;
  for(count = 0; count < size; count++) {
    int randomData = rand() % 101;
    //create the LinkedList by inserting numbers by calling the function
    insertLinkedList(randomData, &head);
  }
  //display the Linked List using the function
  displayLinkedList(head);
  //calculate the sum of the inputs of the LinkedList
  sum = sumLinkedList(head);
  //display the sum to the user
  printf("sum = %d\n", sum);
  //display the size of the LinedList
  printf("size = %d\n", size);
  //calcuate the average from the sum and size
  average = (double)sum/size;
  //print the average up to two decimal places
  printf("average = %.2f \n", average);
  //print new line
  printf("\n");
  //return 0 to close the program
  return 0;
}
//function that inserts a randomally generated integer to the LinkedList
//@params integer2 and head and returns nothing
void insertLinkedList(int integer, NodePointer *head) {
  //create a temp NodePointer
  NodePointer temp;
  //if head is null or otherwise the integer input is less than the data in head
  if( *head == NULL ||integer < (*head) -> data) {
    //create a new node on Temp
    temp = malloc(sizeof(Node));
    //have temp data with integer
    temp-> data=integer;
    //update temp's location
    temp -> next = *head;
    *head = temp;
    //otheriswe if not NULL or integer is greater than head data
  } else {
    //set temp equal to head
    temp = *head;
    //while temp is not NULL
    while(temp != NULL) {
      //if temp data is less than equal to integer input and next is not null or next data is greater than integer
      if(temp -> data <= integer && (temp->next==NULL || temp->next->data> integer)) {
        //create a new node
        NodePointer newNode = malloc(sizeof(Node));
        //attache new node data with integer
        newNode -> data = integer;
        //set newNode next with temp next
        newNode -> next = temp-> next;
        //move temp next with newNode
        temp -> next = newNode;
        return;
      }
      //move temp to temp next
      temp = temp-> next;
    }
  }
}
//a function to display the current LinkedList
//@param current: Node pointer
//returns nothing
void displayLinkedList(NodePointer current) {
  //if the list is empty
  if (NULL == current) {
    //print that the linkedlist is empty
    printf("The list is empty \n \n");
  }
  //otherwise
  else {
    //print out the linkedlist
    printf("The list is:  ");
    // while the current is not NULL
    while(current != NULL) {
      //print each node
      printf(" %d ", current -> data);
      //update to go to the next node
      current = current->next;
    }
    printf("\n\n");
  }
}
//a function to take the sum of the linked list
//@param taks the Node pointer current
//@returns the sum of the LinkedList
int sumLinkedList(NodePointer current) {
  //variable declaration (local)
  int total = 0;
  while(current != NULL) {
    //update sum with the current Node
    total += current->data;
    //update to go to the next
    current = current -> next;
  }
  return total;
}
