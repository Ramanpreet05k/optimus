/*
What is an Abstract Class?
An Abstract Class is a class that is meant to be used only as a base (parent) class. You cannot create an object directly from an abstract class. It acts as a strict blueprint for child classes to follow.

How does a class become abstract in C++?
A class automatically becomes abstract if it contains at least one Pure Virtual Function.

A pure virtual function is a function that has no body and is assigned the value = 0.

It is a strict rule that says: "Any child class that inherits from me MUST write their own code for this function, otherwise they cannot exist either."
*/

#include<iostream>
using namespace std;

class smartDevice{
    public:

    void showbatterylevel(){
        cout<<"Battery level is sufficient"<<endl;
    }

    // THIS IS THE PURE VIRTUAL FUNCTION. 
    // The "= 0" tells the compiler this class is now Abstract.
    // It has no code body here.
    virtual void turnon() = 0;
};

class Smartphone : public smartDevice {
    public:

    // The child MUST provide the actual code for turnOn()
    void turnon() override{
        cout<<"Smartphone booting up: loading os,"<<endl;
    }
};

class SmartBulb : public smartDevice {
public:
    // The child MUST provide the actual code for turnOn()
    void turnon() override {
        cout << "Smart Bulb turning on: Setting LED color to Warm White..." << endl;
    }
};

int main(){
    // ERROR: You CANNOT do this. 
    // SmartDevice myDevice;  <-- The compiler will stop you. An abstract class is just a concept, not a real object.

    // SUCCESS: You CAN create objects of the child classes.
    Smartphone myPhone;
    SmartBulb myBulb;

    cout << "--- Interacting with Phone ---" << endl;
    myPhone.showbatterylevel();
    myPhone.turnon(); 

    cout << "\n--- Interacting with Bulb ---" << endl;
    myBulb.showbatterylevel();
    myBulb.turnon();
}

