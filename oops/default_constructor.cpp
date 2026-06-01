/*
1. Default Constructor
A default constructor takes no arguments (no parameters). If you do not write a constructor for your class, the C++ compiler will automatically generate a hidden, empty default constructor for you.
*/

#include <iostream>
using namespace std;

class Player{
    public:
    int health;
    int score;

    // DEFAULT CONSTRUCTOR
    // Takes no inputs and sets baseline values automatically

    Player(){
        health=100;
        score=0;
        cout<<"A new player has spawned"<<endl;
    }
};

int main(){
    Player p1; // The moment this line runs, the Default Constructor is called.
}
