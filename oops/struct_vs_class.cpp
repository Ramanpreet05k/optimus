/*
In C++, a struct (structure) and a class are practically identical. They can both contain variables, functions, constructors, and they can both use inheritance.

The only technical difference between them comes down to default privacy (access specifiers).

Here is the breakdown of the differences, followed by a clear example.

1. Default Access Specifiers
If you don't explicitly write public:, private:, or protected: inside them:

Class: Everything defaults to private. The outside world cannot access it.

Struct: Everything defaults to public. The outside world can access it freely.
*/

#include<iostream>
using namespace std;

class MyClass{
    int secretData = 10;
};

struct  MyStruct
{
    int openData = 10;
};

int main(){
    MyClass objclass;
    MyStruct objstruct;

    // --- Testing the Class ---
    // ERROR! The line below will cause the program to crash. 
    // Classes hide their data (private) by default.
    // objClass.secretData = 20; 

    // --- Testing the Struct ---
    // SUCCESS! The line below works perfectly. 
    // Structs leave their data out in the open (public) by default.


    objstruct.openData = 20;

    cout<<"Struct data successfully changed: "<<objstruct.openData<< endl;
}
