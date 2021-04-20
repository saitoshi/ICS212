#include <iostream>
using namespace std;

/**
* Circle ADT
* Base Class for a Circle and its specific information
*/
class Circle {
public:
  //the static const double variable PI
  static const double PI;

  //default constructor that creates a circle with radius 1.
  Circle() {
    //set the radius into 1
    setRadius(1);
  }

  //constructs a cricle with the given radius
  Circle(double length) {
    //set the radius with the given circle
    setRadius(length);
  }

  //a function that returns the radius
  double getRadius() const {
    //return the radius
    return radius;
  }

  //a function that sets the radius
  void setRadius(double length) {
    //per class instruction
    //if the input length is 0
    if (length == 0) {
      //set the radius into 1
      radius = 1;
    }
    //otherwise if the length is less than 0
    else if (length < 0) {
      //take the magnitude of the radius
      radius = -length;
    }
    //otherwsie
    else {
      //set the radius equal to the input
      radius = length;
    }
  }

  //a function that returns the area of a circle
  double area() const {
    //update the radius
    double r2 = radius * radius;
    //calculate the area of a Circle
    double areaCirc = PI * r2;
    //return it
    return areaCirc;
  }
protected:
  //the protected double varaible called radius
  double radius;
};//end f the class Circle

//the default value of PI
const double Circle::PI = 3.1415926;

/**
* Cylinder ADT.
* Derived from Circle class
* A cylinder is like a circle except with height as its 3d
*/
class Cylinder: public Circle {
public:
  //default constructor and that sets the Cylinder with radius and height
  Cylinder(double raidus1, double height1): Circle(raidus1) {
    //set the height of the cylinder
    setHeight(height1);
  }
  //a get method for the height
  double getHeight() const {
    //return the height
    return height;
  }
  //a set method for the height
  void setHeight(double length) {
    //per class instruction
    if (length < 0) {
      //if the length is negative
      //take the magnitude
      length = -length;
    }
    //otherwise if it is 0
    else if (length == 0) {
      //set the height into 1
      length = 1;
    }
    //set height into legnth
    height = length;
  }
  //a function tht computes the surface area of a cylinder
  double area() const {
    //store the outcome of pi*r*h
    double leftPart = 2*PI * radius * height;
    //store the outcome of pi * r^2
    double rightPart = 2*PI * radius * radius;
    //take the sum and multiply by two
    double surfaceArea = leftPart + rightPart;
    //return the surface area
    return surfaceArea;
  }

  //a function that computes the volume
  double volume() const {
    //compute the volume
    double vol = PI*radius*radius*height;
    //return it
    return vol;
  }
protected:
  //protected variables
  //variable that stores the height
  double height;
};
//end of the cylinder class

// main function provided by Professor Ed Meyer
int main() {

  cout << "Test Circle class default constructor and area() function:" << endl;
  Circle circle1;

  cout << "Circle circle1: radius = " << circle1.getRadius() << endl;
  cout << "area = " << circle1.area() << endl;

  cout << "\n";

  cout << "Test Circle class constructor with radius:" << endl;
  Circle circle2(-10);

  cout << "Circle circle2: radius = " << circle2.getRadius() << endl;
  cout << "Test set method, set circle2 to radius -5..." << endl;
  circle2.setRadius(-5);
  cout << "radius = " << circle2.getRadius() << endl;

  cout << "\n";

  cout << "Test Cylinder class given radius and height:" << endl;
  Cylinder cylinder1(20, -30);

  cout << "Cylinder cylinder1: radius = " << cylinder1.getRadius();
  cout << "; height = " << cylinder1.getHeight() << endl;
  cout << "surface area = " << cylinder1.area() << endl;
  cout << "volume = " << cylinder1.volume() << endl;

  cout << "\n";

  cout << "Test set method, set cylinder1 to radius 40 and height 50..." << endl;
  cylinder1.setRadius(40);
  cylinder1.setHeight(50);
  cout << "radius = " << cylinder1.getRadius() << "; height = " << cylinder1.getHeight() << endl;
  cout << "surface area = " << cylinder1.area() << endl;
  cout << "volume = " << cylinder1.volume() << endl;

  return 0;
}
