#include<iostream>
using namespace std;

class Car{
    public:
    string brand;
    void honk(){
        cout<< "Beep Beep "<<brand<<endl;
    }
};

int main(){
    Car myCar;
    myCar.brand = "Toyota";
    myCar.honk();
}