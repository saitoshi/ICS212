#include <iostream>
#include <cmath>

/**
 * Starter code for assignment 24.
 */

#define NUM 7
#define PI 3.14

using namespace std;

class Shape {
  public:
   virtual void printDetails() const = 0;
   virtual const char* name() const = 0;
   virtual void inputData() = 0;
   virtual double area() const = 0;
   virtual double volume() const {
      return 0.0;
   }
};

class Circle : public Shape {
  public:
    // syntax "datatype variable = value"  will give a default value for the variable
    // this constructor will be called with no arguments or one argument
    // for example: shapeArray[0] = new Circle();
    // for example:  Circle c = new  Circle(10);
   Circle (double r = 0.0) {
      if (r<0) r=-r;
      radius = r;
   }

   const char* name() const{
      return "Circle";
   }

   void printDetails() const{
      cout << "The " << name() << "'s area = " << area() << endl;
   }

   void inputData() {
      cout << "Enter the " << name() << "'s radius: ";
      cin >> radius;
   }

   double area() const {
      return PI * radius * radius;
   }

  protected:
   double radius;
};
//a sphere ADT classs
class Sphere : public Circle {
public:
  Sphere(double radius1 = 0.0) : Circle(radius1){
    //do nothing here as the Circle function will set radius
  }
  //function to return the name Sphere
  const char* name() const{
     return "Sphere";
  }
  //function to print the values
  void printDetails() const{
    //print the surface are3
     cout << "The " << name() << "'s surface area = " << area() << endl;
     //print the value of the volume
     cout << "The " << name() << "'s volume = " << volume() << endl;
  }
  //ask for user input for the sphere radius
  void inputData() {
     cout << "Enter the " << name() << "'s radius: ";
     cin >> radius;
  }
  //function to calculate the area
  double area() const {
    //create a double to store the area
    double area = 4 * PI * radius * radius;
    //return it
    return area;
  }
  //function to calculate the volume
  double volume() const {
    //create a double to store the volume
    double vol = 4 * PI * radius * radius * radius;
    vol = vol/3;
    //return the volß
    return vol;
  }

}; //

//a cylinder ADT
class Cylinder : public Circle {
public:
  Cylinder(double radius1 =0.0, double height1 = 0.0) : Circle(radius1) {
    //if the height is negative
    if (height1 < 0) {
      //take the magnitude of the negative value
      height = -height1;
    }
  }
  //function to return the name Sphere
  const char* name() const{
     return "Cylinder";
  }
  //function to print the values
  void printDetails() const{
    //print the surface area value
     cout << "The " << name() << "'s surface area = " << area() << endl;
     //print the value of the volume
     cout << "The " << name() << "'s volume = " << volume() << endl;
  }
  //ask for user input for the sphere radius
  void inputData() {
     cout << "Enter the " << name() << "'s radius: ";
     cin >> radius;
     cout << "Enter the " << name() << "'s height: ";
     cin >> height;
  }
  //function to calculate the area
  double area() const {
    //create a double to store the area
    double area = 2*PI*radius*height + 2*PI*radius*radius;
    //return it
    return area;
  }
  //function to calculate the volume
  double volume() const {
    //create a double to store the volume
    double vol = PI * radius * radius * height;
    //return the volß
    return vol;
  }
  //protected values
protected:
  //set a double variable for height
  double height;
};

//Square classs
class Square : public Shape {
public:
  // syntax "datatype variable = value"  will give a default value for the variable
  // this constructor will be called with no arguments or one argument
  // for example: shapeArray[0] = new Circle();
  // for example:  Circle c = new  Circle(10);
 Square (double side1 = 0.0) {
   //if side1 is negative
   //take the magnitude of it
    if (side1<0) side1=-side1;
    side = side1;
 }
//function to reurn the name
 const char* name() const{
   //return the name Square
    return "Square";
 }
 //function to return the name and area
 void printDetails() const{
   //print Square and its area
    cout << "The " << name() << "'s area = " << area() << endl;
 }
 //function to get the input
 void inputData() {
   //ask for user input
    cout << "Enter the " << name() << "'s side: ";
    //store the user input to side
    cin >> side;
 }
//function to compute the area
 double area() const {
   //return the area
    return side * side;
 }
//protected variables
protected:
  //a double type variable to store the side
 double side;
}; //closing for Square ADT

//start the ADT for Cube using Square class
class Cube : public Square {
public:
  Cube(double side1 = 0.0): Square(side1) {
    //do nothing as the Square class will set the side
  }
  //function return the name
  const char* name() const{
    //return the name Cube
     return "Cube";
  }

  //function to print the area and volume
  void printDetails() const{
    //print the surface area
     cout << "The " << name() << "'s surface area = " << area() << endl;
     //print the volume
     cout << "The " << name() << "'s volume = " << volume() << endl;
  }
  //function to get the user input
  void inputData() {
    //ask for the side
     cout << "Enter the " << name() << "'s side: ";
     //store the side input
     cin >> side;
  }
  //function to calculate the area
  double area() const {
    //return the surface area
     return 6 *side * side;
  }
  //function to calculate the volume
  double volume() const {
    //store the volume
    double vol = side * side * side;
    //return the volume
    return vol;
  }


}; //closing for the Cube class

//start the ADT for the Triangle
class Triangle : public Shape {
public:
//default constructor of a Triangle
 Triangle (double side1 = 0.0) {
   //if side1 is negative then get its magnitude
    if (side1<0) side1=-side1;
//set side to side1
    side = side1;
 }
//function to return the shape name
 const char* name() const{
   //return triangle
    return "Triangle";
 }
//function to print out the area
 void printDetails() const{
   //print out the area of a triangle
    cout << "The " << name() << "'s area = " << area() << endl;
 }
//function to get the user input
 void inputData() {
   //ask for the user input
    cout << "Enter the " << name() << "'s side: ";
    //stopre the user input
    cin >> side;
 }
//return the area of a triangle
 double area() const {
   //calculate and return the area of triangle
    return side * side * sqrt(3) * 0.25;
 }
//protected variables
protected:
  //double variable for side
 double side;
};

//start the ADT for the Tetrahedron
class Tetrahedron : public Triangle {
public:
  //public constructor for Tetrahedron
  Tetrahedron(double side1=0.0): Triangle(side1) {
    //do nothing as Triangle() will set the side
  }
  //function return the name
  const char* name() const{
    //return the name Cube
     return "Tetrahedron";
  }
  //function to print the area and volume
  void printDetails() const{
    //print the surface area
     cout << "The " << name() << "'s surface area = " << area() << endl;
     //print the volume
     cout << "The " << name() << "'s volume = " << volume() << endl;
  }
  //function to get the user input
  void inputData() {
    //ask for the side
     cout << "Enter the " << name() << "'s side: ";
     //store the side input
     cin >> side;
  }
  //function to calculate the area
  double area() const {
    //return the surface area
     return side * side * sqrt(3);
  }
  //function to calculate the volume
  double volume() const {
    //store the volume
    double vol = side * side * side * sqrt(2) * 1/12;
    //return the volume
    return vol;
  }

}; //close the Tetrahedron ADT
int displayMenu(Shape *s[]);

int main() {

   Shape *shapeArray[NUM];
   shapeArray[0] = new Circle();

  // Uncomment the line below when you have completed its corresponding classs for that shape.
  // The shape will be added to the array and the corresponding menu option will be shown.
  shapeArray[1] = new Sphere();
  //shapeArray[2] = new Square();
  //shapeArray[3] = new Cube();
  shapeArray[2] = new Cylinder();
  shapeArray[3] = new Square();
  shapeArray[4] = new Cube();
  shapeArray[5] = new Triangle();
  shapeArray[6] = new Tetrahedron();

   int choice = displayMenu(shapeArray);
   while (choice >= 0 && choice <= 6) {
      shapeArray[choice]->inputData();
      shapeArray[choice]->printDetails();
      cout << endl;
      choice = displayMenu(shapeArray);
   }
   return 0;
}

/**
 * Displays the menu for which shape to perform calculations.
 *
 * @param s array of shapes that this program supports
 * @return choice the choice from the user
 */
int displayMenu(Shape *s[]) {
   int choice = 0;
   cout << "Select an object from the menu (enter 7 to quit)." << endl;
   for (int i = 0; i < NUM; i++) {
      cout << '\t' << i << ". " << s[i]->name() << endl;
   }
   cin >> choice;
   return choice;
}

/*
Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
0
Enter the Circle's radius: 10
The Circle's area = 314

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
1
Enter the Sphere's radius: 20
The Sphere's surface area = 5024
The Sphere's volume = 33493.3

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
2
Enter the Cylinder's radius: 30
Enter the Cylinder's height: 40
The Cylinder's surface area = 13188
The Cylinder's volume = 113040

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
3
Enter the Square's side: 50
The Square's area = 2500

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
4
Enter the Cube's side: 60
The Cube's surface area = 21600
The Cube's volume = 216000

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
5
Enter the Triangle's side: 70
The Triangle's area = 2121.76

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
6
Enter the Tetrahedron's side: 80
The Tetrahedron's surface area = 11085.1
The Tetrahedron's volume = 60339.8

Select an object from the menu (enter 7 to quit).
        0. Circle
        1. Sphere
        2. Cylinder
        3. Square
        4. Cube
        5. Triangle
        6. Tetrahedron
7
*/
