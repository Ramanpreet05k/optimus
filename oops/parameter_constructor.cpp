/*
Parameterized Constructor
A parameterized constructor takes arguments (parameters). This allows you to pass in specific data the moment you create the object, allowing you to customize it immediately rather than setting it up later.
*/

#include<iostream>
using namespace std;

class Car{
    public:
    string brand;
    int year;

    Car(string carbrand, int caryear){
        brand = carbrand;
        year = caryear;
    }

    void displayinfo(){
        cout<<"Car: "<<brand<<" ("<< year << ")" << endl;
    }

};

int main(){
    Car mycar("TOYOTA",2022);

    mycar.displayinfo();
}