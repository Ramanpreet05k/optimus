/*
What is an Enumeration (enum)?
An Enumeration (commonly known as an enum) is a user-defined data type in C++ used to assign names to integer constants. It allows you to group a set of related constants together under a single type name.
*/

#include <iostream>
using namespace std;

// 1. DEFINING THE ENUM
// Syntax: enum EnumName { CONSTANT1, CONSTANT2, ... };
enum Difficulty {
    EASY,   // Automatically assigned 0
    MEDIUM, // Automatically assigned 1
    HARD    // Automatically assigned 2
};

int main() {
    // 2. CREATING AN ENUM VARIABLE
    // 'Difficulty' is now a valid data type, just like int or double!
    Difficulty selectedLevel = MEDIUM;

    // 3. USING THE ENUM IN A CONDITION
    if (selectedLevel == EASY) {
        cout << "Enemy health set to 50 HP." << endl;
    } 
    else if (selectedLevel == MEDIUM) {
        cout << "Enemy health set to 100 HP." << endl; // This will print
    } 
    else if (selectedLevel == HARD) {
        cout << "Enemy health set to 200 HP." << endl;
    }

    // Proving they are just integers under the hood:
    cout << "The underlying integer value of MEDIUM is: " << selectedLevel << endl; // Outputs: 1

    return 0;
}