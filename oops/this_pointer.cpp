/*
this pointer is a hidden pointer that exists inside every non-static member function. It automatically points to the exact object that is currently calling the function.

You can think of this as the code's way of saying "my." Just like you would say "my name is..." instead of just "name is...", the this pointer tells the class, "use my specific variable, not a general one."


1. Resolving Name Conflicts (Shadowing)
The most frequent use of this is when a function parameter has the exact same name as a class member variable. Without this, the compiler gets confused and just assigns the parameter to itself, leaving the class variable unchanged.

2. Returning the Current Object (Method Chaining)
Sometimes you want to call multiple functions on the exact same object in a single line of code (like player.setHealth(100).setName("Arthur");). To do this, the function needs to return the object itself. You achieve this by returning *this (dereferencing the pointer to get the actual object).


In C++, when you put an asterisk * in front of a pointer, it means "go grab the actual thing the arrow is pointing at." This is called dereferencing.

this = The address of the object (e.g., Memory Slot #104).

*this = The actual object itself (The physical Box).
*/


#include<iostream>
using namespace std;

class Player{
    private:
    int health;

    public:

    // The parameter is named 'health', which is the exact same name as the private variable
    void setHealth(int health){
        // health = health;  <-- WRONG! The compiler thinks you are just assigning the parameter to itself.
        
        // RIGHT! 'this->health' specifically means the class's private variable.
        // The 'health' on the right is the parameter passed into the function.

        this->health = health;
    }
    void printHealth(){
        cout<<"Player health is : "<<health<<endl;
    }
};

class Box {
private:
    int length;
    int width;

public:
    // Notice the return type is a reference to the Box class (Box&)
    Box& setLength(int l) {
        length = l;
        return *this; // Returns the actual object that called this function
    }

    Box& setWidth(int w) {
        width = w;
        return *this; // Returns the actual object
    }

    void displayDimensions() {
        cout << "Box is " << length << "x" << width << endl;
    }
};

int main(){
    Player p1;
    p1.setHealth(100);
    p1.printHealth();



    Box myBox;
    // Because each function returns '*this', we can chain them together!
    myBox.setLength(10).setWidth(5); 

    myBox.displayDimensions(); // Outputs: Box is 10x5
    return 0;
}