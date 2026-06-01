/*
Pure Virtual Function
A pure virtual function is a virtual function that has no code body at all. Instead of curly braces {}, you simply assign it the value = 0.

Why do we need it?
It is used when a function is so specific to the Child classes that it makes absolutely no sense for the Parent class to have a default version.

Crucial Rule: Any class that contains a pure virtual function instantly becomes an Abstract Class. You cannot create objects from it. It exists purely as a strict blueprint to force child classes to do the work.
*/

#include<iostream>
using namespace std;

class Shape{
    public:
    virtual void calculateArea()=0;
};

class Circle : public Shape{
    public:
    void calculateArea(){
        cout<<"Calculate the area of a circle using pi * r^2"<<endl;
    }

};

class Square : public Shape{
    public:
    void calculateArea(){
        cout<<"Calculate the area of a circlue using length * breadth"<<endl;
    }
};

int main(){
    Circle mycircle;
    Square mysquare;
    mycircle.calculateArea();
    mysquare.calculateArea();
}