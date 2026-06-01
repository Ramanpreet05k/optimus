/*
What is a Static Data Member?
Normally, when you create objects from a class, each individual object gets its own private copy of the class variables. If you change a variable in Object A, Object B is completely unaffected.

A static data member is a variable that is shared by all objects of that class. Instead of creating a new copy for every object, the computer allocates memory for this variable exactly once. All objects look at and modify that same exact memory slot.
*/

#include<iostream>
using namespace std;

class Player {
    public:
    string name;

    static int totalPlayers;

    Player(string n){
        name = n;

        totalPlayers++;
    }

    ~Player(){
        totalPlayers--;
    }
};
int Player::totalPlayers = 0;

int main(){
    cout<<"Initial Players: "<<Player::totalPlayers<<endl;

    Player* p1 = new Player("Arthur");
    Player* p2 = new Player("John");

    // Both objects see the EXACT same value because they share it
    cout << "Players online (checked via Class): " << Player::totalPlayers << endl; // Outputs: 2
    cout << "Players online (checked via p1): " << p1->totalPlayers << endl;       // Outputs: 2
    cout << "Players online (checked via p2): " << p2->totalPlayers << endl;       // Outputs: 2

    cout << "\n--- Arthur leaves the game ---" << endl;
    delete p1; // Triggers the destructor, which does totalPlayers--

    // The remaining player instantly sees the updated count
    cout << "Players online now: " << Player::totalPlayers << endl; // Outputs: 1

    delete p2; // Clean up memory
    return 0;
}