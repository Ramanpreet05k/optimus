/*
2. Multilevel Inheritance
A child class is derived from a parent class, and then that child class acts as a parent for another new class. 
It forms a chain or a lineage.
Structure: A->B -> C (C inherits from B, which inherited from A)
*/

#include<iostream>
using namespace std;

class Animal{
    public:
    void eat(){
        cout<<"Eating.."<<endl;
    }
};

class Dog : public Animal{
    public:
    void bark(){
        cout<<"Barking.."<<endl;
    }
};

class puppy : public Dog{
    public:
    void weep(){
        cout<<"Whining.."<<endl;
    }
};

int main(){
    puppy mypuppy;
    mypuppy.eat();   //Inherited from Grandparent (Animal)
    mypuppy.bark();  // Inherited from Parent (Dog)
    mypuppy.weep();

    return 0;
}