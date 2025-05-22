/*
Title of the Assignment: Implement a class Complex which represents the Complex Number data type. Implement the following 1. Constructor (including a default constructor which creates the complex number 0+0i). 2. Overload operator+ to add two complex numbers. 3. Overload operator* to multiply two complex numbers. 4. Overload operators << and >> to print and read Complex Numbers.
*/

#include <iostream>
using namespace std;

class Complex {
    float x; // Real part
    float y; // Imaginary part
public:
    // Default Constructor
    Complex() {
        x = 0;
        y = 0;
    }

    // Overloaded operators
    Complex operator+(Complex);
    Complex operator*(Complex);

    // Friend functions for input and output
    friend istream &operator>>(istream &in, Complex &t) {
        cout << "Enter the real part: ";
        in >> t.x;
        cout << "Enter the imaginary part: ";
        in >> t.y;
        return in;
    }

    friend ostream &operator<<(ostream &out, const Complex &t) {
        out << t.x << (t.y >= 0 ? " + " : " - ") << abs(t.y) << "i";
        return out;
    }
};

// Overloaded + operator
Complex Complex::operator+(Complex c) {
    Complex temp;
    temp.x = x + c.x;
    temp.y = y + c.y;
    return temp;
}

// Overloaded * operator
Complex Complex::operator*(Complex c) {
    Complex temp2;
    temp2.x = (x * c.x) - (y * c.y);
    temp2.y = (y * c.x) + (x * c.y);
    return temp2;
}

int main() {
    Complex c, c1, c2, c3, c4;

    // Default constructor values
    cout << "Default constructor value: ";
    cout << c << "\n";

    // Input first and second complex numbers
    cout << "\nEnter the 1st number:\n";
    cin >> c1;
    cout << "\nEnter the 2nd number:\n";
    cin >> c2;

    // Perform addition and multiplication
    c3 = c1 + c2;
    c4 = c1 * c2;

    // Display results
    cout << "\nThe first number is: " << c1 << "\n";
    cout << "The second number is: " << c2 << "\n";
    cout << "The addition is: " << c3 << "\n";
    cout << "The multiplication is: " << c4 << "\n";

    return 0;
}
