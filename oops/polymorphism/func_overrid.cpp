/*
2. Function Overriding (Run-Time Polymorphism)
What is it?
Function overriding happens when a child class (derived class) provides its own specific implementation for a function that is already defined in its parent class (base class). For overriding to work, the function in the child class must have the exact same name, exact same parameters, and exact same return type as the function in the parent class.

How it works:
To allow a function to be overridden, the parent class must declare it with the virtual keyword. The decision of which function to run (the parent's or the child's) is made while the program is actually running
*/

#include<iostream>
using namespace std;

//base class
class Animal{
    public:

    // virtual keyword tells compliler that this can be overriden by child class
    virtual void makesound(){
        cout<<"Some generic animal sound.."<<endl;
    }
};

class Dog : public Animal{
    public:


    //this func override the parent class makesound() func
    //the override keyword is optional but recommended
    void makesound() override{
        cout<<"Woof woof"<<endl;
    }
};

int main(){
    Animal genericanimal;
    genericanimal.makesound();
    Dog mydog;
    mydog.makesound();

// real power of overriding : using a pointer of base class
    Animal* animalptr = &mydog;


//even though pointer is of animal, it knows to call the dog's ersion bcz of virtual keyword in base class
    animalptr->makesound();
}