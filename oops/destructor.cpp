#include <iostream>
using namespace std;

class Player {
private:
    string name;
    int* scorePointer; // A pointer that will use dynamic memory

public:
    // CONSTRUCTOR (Setup)
    Player(string n) {
        name = n;
        // Borrowing memory from the heap
        scorePointer = new int; 
        *scorePointer = 0;
        
        cout << "[CONSTRUCTOR] Player " << name << " has joined the game." << endl;
    }

    // DESTRUCTOR (Cleanup)
    // Notice the tilde (~)
    ~Player() {
        // Returning the borrowed memory back to the system
        delete scorePointer; 
        
        cout << "[DESTRUCTOR] Player " << name << " has left the game. Memory freed." << endl;
    }
};

int main() {
    cout << "--- Game Starting ---" << endl;
    
    // We create an artificial "scope" using curly braces to see the destructor in action
    {
        Player p1("Arthur"); 
        
        cout << "Arthur is playing..." << endl;
        
    } // The moment we hit this closing brace, p1 goes out of scope and is destroyed!

    cout << "--- Game Over ---" << endl;
    
    return 0;
}