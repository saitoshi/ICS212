#include <iostream>
using namespace std;

//class name: Complex
class Complex {
public:
  //constructs the complex constructor
  //default values
  Complex() {
    //set realNum into 0
    realNum = 0.0;
    //set imagNum into 0
    imagNum = 0.0;
  }
  //a function that will print out the complex numbers
  void print() const{
    //set the double variable a equal to realNum
    double a = realNum;
    //set the double variable b equal to Imagi Num
    double b = imagNum;
    //if b is greater than or equal to 0 print
    if (b >= 0) {
      //print out the a+bi format
      cout<<"(" <<a<<"+"<<b<< "i)" << endl;
    } //otherwise do a-bi format
    else {
      cout<<"("<<a<<b<< "i)" << endl;
    }
    return;
  }
  //function that sets both the real and imaginary data members.
  void set(double real, double imag) {
    //set the real input as realNum
    realNum = real;
    //set the imaginary input as imaginary
    imagNum = imag;
  }
  //a function that gets the real poriton of the complex number
  double getReal() const{
    //returns the realNum
    return realNum;
  }
  //a function that gets the imaginary portion of the complex number
  double getImaginary() const{
    //returns the complex number
    return imagNum;
  }
  //a complex function  that allows a Complex object to be created with the specified real and imaginary parts.
  Complex (double realParam, double imaginaryParam) {
    //use the set function to create the complex object
    set(realParam, imaginaryParam);
  }
  //a copy constructor that copies data members from copyComplex to this object
  Complex(const Complex &copyComplex) {
    //set the realNum and imagNum from copyComplex
    set(copyComplex.realNum, copyComplex.imagNum);
  }
  //Output a message, that includes the data members, to show which Complex object is being destructed
  ~Complex() {
    //if imagNum is a negative
    if(imagNum < 0) {
      //print out a - bi
      cout << "Destructor ("<< realNum << imagNum <<"i)" << endl;
    }
    //otherwise imagNum is positive then
    else {
      //print out a + bi format where a is real and b is imagNum
      cout << "Destructor (" << realNum << "+" << imagNum << "i)" << endl;
    }
  }
  //a function that adds the Complex numbers
  Complex add(const Complex &addComplex) const{
    //create a double variable that stores the updated real
    double updateReal = realNum + addComplex.realNum;
    //create a double variable that stores the updated imag portion
    double updateImag = imagNum + addComplex.imagNum;
    //create a new Complex number with the updated vairables
    Complex updateComplex(updateReal, updateImag);
    //return the new updated complex
    return updateComplex;
  }
  //a function that subtracts the Complex numbers
  Complex subtract(const Complex &subtractComplex) const {
    //create a double variable to store the updated real result
    double updateReal = realNum - subtractComplex.realNum;
    //create a double variable to store the updated imaginary result
    double updateImag = imagNum - subtractComplex.imagNum;
    //crate a new Complex num with the updated variables
    Complex updateComplex(updateReal, updateImag);
    //return the subtracted result
    return updateComplex;
  }
  //Returns a new Complex object that is this object multiplied by the specified object.
  Complex multiply(const Complex &multiplyComplex) const {
    //create four new double variables to store the work process results
    double first = realNum * multiplyComplex.realNum;
    double out = realNum * multiplyComplex.imagNum;
    double in = imagNum * multiplyComplex.realNum;
    double last = imagNum * multiplyComplex.imagNum;
    //make sure that the - bd is -
    last = -last;
    //create a double variable to combine the first, out, in, last appropraitely
    double updateReal = first + last;
    double updateImag = in + out;
    //create a new Complex num with the updated variables
    Complex updateComplex(updateReal, updateImag);
    //return the outcome
    return updateComplex;
  }
  //Returns a new Complex object that is this object divided by the specified object
  Complex divide(const Complex &divideComplex) {
    //calculate the real portion that will be updated
    double first = realNum * divideComplex.realNum;
    double last = imagNum * divideComplex.imagNum;
    //find the cSared and Dsqred portion of the formula
    double cSqred = divideComplex.realNum * divideComplex.realNum;
    double dSqred = divideComplex.imagNum * divideComplex.imagNum;
    //compute the sum of cSqred and dSqred
    double sqredSum = cSqred + dSqred;
    //compute the numerator for the real portion
    double realNumerator = first + last;
    //compute the updated real
    double updateReal = realNumerator/sqredSum;
    //calculate the imaginary portion that will be updated
    //caluclate the in and out portion
    double in = imagNum * divideComplex.realNum;
    double out = realNum * divideComplex.imagNum;
    //caluclate the sum of the previous variables
    double imagNumerator = in - out;
    //compute the updated imaginary number protion
    double updateImag = imagNumerator/ sqredSum;
    //create a complex number out of it
    Complex updateComplex(updateReal, updateImag);
    return updateComplex;
  }

  /**
 * Overload the >> to create Complex objects with cin >>.
 * User should type in the format: integer, followed by another integer, followed by an i
 *   a+bi
 *   a-bi
 * Where a and b are integers.
 * For simplicity this overloaded >> only reads in integer real and integer imaginary parts.
 *
 * This function does not enforce the i to be an i.
 *
 * @return in The cleared input stream. The Complex object c was set.
 */
friend istream &operator>>(istream &in, Complex &c) {
  // Used to store the letter 'i' from the input.
  char letter_i = 'i';

  // Used to temporarily store the real and imaginary parts entered by the user.
  int tempReal = 0;
  int tempImaginary = 0;

  // Read input a+bi and store the real and imaginary parts.
  in >> tempReal >> tempImaginary >> letter_i;

  // Use the set function for error checking.
  c.set(tempReal, tempImaginary);

  // Clear the input stream.
  in.clear();
  return in;
}
//funciton used for the overloaded << for count
//checks whether the out put is (a+bi) format
friend ostream &operator<<(ostream &out, const Complex &complexParam) {
  //check whether the imagNum is less than 0
  if (complexParam.imagNum < 0) {
    //print a-bi instead
    out <<'('<<complexParam.realNum<<complexParam.imagNum<<'i'<<')';
  }
  else {
    //otherwsie print a + bi instead
    out <<'('<<complexParam.realNum<<'+'<<complexParam.imagNum<<'i'<<')';
  }
  return out;
}
//a function that does Complex number addition
//(a + bi) + (c + di) = (a + c) + (b + d)i
friend Complex operator+(const Complex &complex1, const Complex &complex2) {
  //create a new double to store the sum of the real numbers
  double updatedReal = complex1.realNum + complex2.realNum;
  //create a new double to store the imaginary numbers
  double updatedImag = complex1.imagNum + complex2.imagNum;
  //call the set function to set
  Complex updateComplex(updatedReal, updatedImag);
  //return the updated complex
  return updateComplex;
}
//a function that computes the difference of the Complex numbers
//(a + bi) - (c + di) = (a - c) + (b - d)i
Complex operator-(const Complex &complexParam) const {
  //create a new double to stroe the results of the real
  double updateReal = realNum - complexParam.realNum;
  //create a double var to store the imag difference
  double updateImag = imagNum - complexParam.imagNum;
  //set the Complex with the updated param
  Complex updateComplex(updateReal, updateImag);
  //return the updated complex result
  return updateComplex;
}

//a function operator that computes the quotient of two Complex numbers
 Complex operator/(const Complex &complexParam) const{
   //create a double variables to store the first and last from the FOIL like operation
   double first = realNum * complexParam.realNum;
   double last = imagNum * complexParam.imagNum;

   //find the cSared and Dsqred portion of the formula
   double cSqred = complexParam.realNum * complexParam.realNum;
   double dSqred = complexParam.imagNum * complexParam.imagNum;
   //compute the sum of cSqred and dSqred
   double sqredSum = cSqred + dSqred;
   //compute the numerator for the real portion
   double realNumerator = first + last;
   //compute the updated real
   double updateReal = realNumerator/sqredSum;
   //caluclate the in and out portion
   double in = imagNum * complexParam.realNum;
   double out = realNum * complexParam.imagNum;
   //caluclate the sum of the previous variables
   double imagNumerator = in - out;
   //compute the updated imaginary number protion
   double updateImag = imagNumerator/ sqredSum;
   //create a complex number out of it
   Complex updateComplex(updateReal, updateImag);
   return updateComplex;
 }
 //function operator * that computes the product of two complex numbers
 Complex operator*(const Complex &complexParam) const {
   //create four new double variables to store the work process results in a FOIL format
   double first = realNum * complexParam.realNum;
   double out = realNum * complexParam.imagNum;
   double in = imagNum * complexParam.realNum;
   double last = imagNum * complexParam.imagNum;
   //make sure that the - bd is -
   last = -last;
   //create a double variable to combine the first, out, in, last appropraitely
   double updateReal = first + last;
   double updateImag = in + out;
   //create a new Complex num with the updated variables
   Complex updateComplex(updateReal, updateImag);
   //return the outcome
   return updateComplex;
 }
 //a function that determines whether the two complex are identical or not
 friend bool operator==(const Complex &complex1, const Complex &complex2) {
   //initialize the boolean
   bool equal = false;
   //if the real numbers are equal
   if(complex1.realNum == complex2.realNum) {
     //if the imagNum of the two are equal
     if(complex1.imagNum == complex2.imagNum) {
       //make the bool true
       equal = true;
       //return the boolean
       return equal;
     }
     else {
       return equal;
     }
   }
   else{
     return equal;
   }
 }
//a function that determines if they are not equal
friend bool operator!=(const Complex &complex1, const Complex &complex2){
  //return the negation of the == function
  return !(complex1 == complex2);
}




private:
  //data members
  //double type variables that stores the real and img of complex number
  double realNum;
  double imagNum;
};

//main function given by professor Ed Meyers
int main() {

  Complex c1;
  Complex c2;
  Complex c3;

  cout << "Enter a Complex number in the form 'a+bi': ";
  cin >> c1;
  cout << "Enter another Complex number in the form 'a+bi': ";
  cin >> c2;

  cout << endl;

  cout << "Test the + operator:" << endl;
  c3 = c1 + c2;
  cout << c1 << " + " << c2 << " = " << c3 << endl << endl;

  cout << "Test the - operator:" << endl;
  c3 = c1 - c2;
  cout << c1 << " - " << c2 << " = " << c3 << endl << endl;

  cout << "Test the / operator:" << endl;
  c3 = c1 / c2;
  cout << c1 << " / " << c2 << " = " << c3 << endl << endl;

  cout << "Test the * operator:" << endl;
  c3 = c1 * c2;
  cout << c1 << " * " << c2 << " = " << c3 << endl << endl;

  cout << "Test the == operator:" << endl;
  cout << c1 << " == " << c2 << " = " << boolalpha << (c1 == c2) << endl << endl;

  cout << "Test the != operator:" << endl;
  cout << c1 << " != " << c2 << " = " << (c1 != c2) << endl << endl;

  return 0;

}
