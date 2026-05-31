/*
The Diamond Problem is a famous ambiguity issue that occurs in Object-Oriented Programming when using Multiple Inheritance.

It happens when a class inherits from two classes, and both of those classes inherit from the exact same base class. This creates a "diamond" shape in the inheritance family tree.


The Solution (Virtual Inheritance)
To fix this, C++ uses the virtual keyword when the parent classes inherit from the grandparent class.

By writing virtual public Animal, you are telling the compiler: "If anyone down the line inherits from both of us, only give them one shared copy of Animal, not two."
*/

#include <iostream>
using namespace std;

// 1. Grandparent Class
class Animal {
public:
    int age;
};

// 2. Parent Class 1 (Notice the 'virtual' keyword)
class Tiger : virtual public Animal { 
};

// 3. Parent Class 2 (Notice the 'virtual' keyword)
class Lion : virtual public Animal { 
};

// 4. Child Class 
class Liger : public Tiger, public Lion { 
};

int main() {
    Liger myLiger;
    
    // SUCCESS! Liger only has one shared copy of 'age' now.
    myLiger.age = 5; 
    cout << "The Liger is " << myLiger.age << " years old." << endl;
    
    return 0;
}