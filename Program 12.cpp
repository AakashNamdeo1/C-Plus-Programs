/*Create a base class shape. Use this class to store two double type values that could be used to compute 
area of figures. Derive two specific classes called triangle and rectangle from the base shape. Add to the base a 
member function getdata() to initialize base class data member and another member function display_area() to 
compute and display the area of figures. Make display_area() as a virtual function and redefine it the derived 
class.*/




#include <iostream>

// Base class
class Shape {
protected:
    double width, height;

public:
    // Function to initialize base class members
    void getData(double w, double h) {
        width = w;
        height = h;
    }

    // Virtual function for displaying area
    virtual void displayArea() {
        std::cout << "This is the base shape class" << std::endl;
    }
};

// Derived class for Triangle
class Triangle : public Shape {
public:
    // Override displayArea for Triangle
    void displayArea() override {
        std::cout << "Area of Triangle: " << (width * height) / 2 << std::endl;
    }
};

// Derived class for Rectangle
class Rectangle : public Shape {
public:
    // Override displayArea for Rectangle
    void displayArea() override {
        std::cout << "Area of Rectangle: " << width * height << std::endl;
    }
};

int main() {
    Triangle tri;
    Rectangle rect;

    // Initialize triangle data
    tri.getData(5.0, 3.0);
    tri.displayArea(); // Display area of triangle

    // Initialize rectangle data
    rect.getData(4.0, 6.0);
    rect.displayArea(); // Display area of rectangle

    return 0;
}
