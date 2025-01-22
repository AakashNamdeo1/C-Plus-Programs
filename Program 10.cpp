/* Design a C++ Class ‘Complex’ with data members for real and imaginary part. Provide default and 
parameterized constructors. Write a program to perform arithmetic operations of two complex numbers 
using operator overloading (using either member functions or friend functions).*/



#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Parameterized constructor
    Complex(double r, double i) : real(r), imag(i) {}

    // Overloading the '+' operator to add two Complex numbers
    Complex operator+(const Complex obj) const {
        return Complex(real + obj.real, imag + obj.imag);
    }

    // Overloading the '-' operator to subtract two Complex numbers
    Complex operator-(const Complex obj) const {
        return Complex(real - obj.real, imag - obj.imag);
    }

    // Overloading the '*' operator to multiply two Complex numbers
    Complex operator*(const Complex obj) const {
        return Complex((real * obj.real - imag * obj.imag), (real * obj.imag + imag * obj.real));
    }

    // Function to display the complex number
    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() {
    Complex num1(3, 4); // Using parameterized constructor
    Complex num2(2, -5); // Using parameterized constructor
    Complex sum, diff, prod;

    sum = num1 + num2; // Adding two complex numbers
    diff = num1 - num2; // Subtracting two complex numbers
    prod = num1 * num2; // Multiplying two complex numbers

    std::cout << "The sum is: ";
    sum.display();
    std::cout << "The difference is: ";
    diff.display();
    std::cout << "The product is: ";
    prod.display();

    return 0;
}
