/*
Operator overloading allows you to redefine how standard C++ operators (like +, -, *, ==, or <) work when they are applied to your own custom objects.
*/

#include<iostream>
using namespace std;

class Vector2D{
    public:
    int x,y;

    Vector2D(int x=0,int y=0){
        this->x=x;
        this->y=y;
    }

    Vector2D operator+(const Vector2D& other){

        // Create a new Vector to hold the result
        Vector2D result;

        // Add the X of this object to the X of the other object
        result.x = this->x + other.x;

        // Add the Y of this object to the Y of the other object
        result.y = this->y + other.y;

        return result;
    }

    // Let's overload the '==' operator too, just to see if two vectors are the exact same!
    bool operator==(const Vector2D& other){
        return (this->x== other.x && this->y==other.y);
 
    }

    void print() {
        cout << "X: " << x << ", Y: " << y << endl;
    }
};

int main(){
    Vector2D v1(5, 10);
    Vector2D v2(3, 4);

    // Because we overloaded the '+' operator, we can add them just like normal numbers!
    Vector2D v3 = v1 + v2; 

    cout << "Vector 3 Result: ";
    v3.print(); // Outputs: X: 8, Y: 14


    //Testing our overloaded '==' operator
    if (v1 == v2) {
        cout << "The vectors are identical!" << endl;
    } else {
        cout << "The vectors are different." << endl;
    }

    return 0;
}