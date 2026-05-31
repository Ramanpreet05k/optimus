/*
3. Multiple InheritanceOne 
child class inherits from more than one parent class simultaneously. It combines the features of multiple base classes.
Structure: A + B -> C (C inherits from both A and B)
*/

#include <iostream>
using namespace std;

class Printer {                 // Parent 1
public:
    void print() { cout << "Printing document..." << endl; }
};

class Scanner {                // Parent 2
public:
    void scan() { cout << "Scanning document..." << endl; }
};

// Child inherits from BOTH Printer and Scanner
class MultiFunctionMachine : public Printer, public Scanner {
public:
    void copy() { cout << "Copying document..." << endl; }
};

int main() {
    MultiFunctionMachine mfm;
    mfm.print(); // Inherited from Parent 1
    mfm.scan();  // Inherited from Parent 2
    mfm.copy();  // Its own function
    return 0;
}