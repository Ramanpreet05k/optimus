/*
What is Inheritance?
Inheritance is a mechanism where a new class (the Child or Derived class) automatically acquires all the properties (variables) and behaviors (functions) of an existing class (the Parent or Base class).

The primary purpose of inheritance is code reusability. Instead of writing the same code over and over again for different classes that share similar traits, you write the common code once in a parent class and have the child classes inherit it.
*/

/*
Types of Inheritance in C++
There are 5 main types of inheritance.

1. Single InheritanceThis is the simplest form. One child class inherits from exactly one parent class.
Structure: A->B (B inherits from A)
*/

#include<iostream>
using namespace std;

class Animal{
    public:
    void eat() {
        cout<<"Eating.."<<endl;
    }
};

class Dog : public Animal{
    public:
    void bark(){
        cout<<"Woof"<<endl;
    }
};
int main(){
    Dog myDog;
    myDog.eat(); //inherited from animal
    myDog.bark();
}
