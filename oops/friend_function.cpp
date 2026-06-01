/*
What is a Friend Function?
In C++, one of the main rules of Encapsulation is that private and protected data cannot be accessed by anyone outside the class.

A friend function is the one exception to this rule. It is a normal, standalone function that is not a member of the class, but the class explicitly grants it special permission to access its hidden private and protected data.
*/

#include<iostream>
using namespace std;

class BankBox{
    private:
    int cash;

    public:
    BankBox(int amount){
        cash = amount;
    }

    friend void countTotalCash(BankBox box1, BankBox box2);
};


// ==========================================
// FRIEND FUNCTION DEFINITION
// Notice it is NOT tied to the class. We don't write BankBox::countTotalCash
// ==========================================

void countTotalCash(BankBox box1, BankBox box2){
    int total = box1.cash + box2.cash;
    cout << "Total cash in both boxes: $" << total << endl;
}

int main(){
    BankBox mybox(500);
    BankBox yourbox(300);

    // ERROR: We cannot do this in main() because cash is private!
    // cout << myBox.cash;

    countTotalCash(mybox, yourbox);

    return 0;

}
