/*
4. Hierarchical Inheritance
Multiple child classes inherit from a single parent class. This is the opposite of multiple inheritance.
Structure: A -> B and A -> C (Both B and C inherit from A)
*/

#include <iostream>
using namespace std;

class Shape {                  // Parent Class
public:
    void getArea() { cout << "Calculating area..." << endl; }
};

class Circle : public Shape {  // Child 1
public:
    void drawCircle() { cout << "Drawing Circle." << endl; }
};

class Square : public Shape {  // Child 2
public:
    void drawSquare() { cout << "Drawing Square." << endl; }
};

int main() {
    Circle c;
    Square s;
    
    // Both children share the same parent function
    c.getArea(); 
    s.getArea();
    return 0;
}