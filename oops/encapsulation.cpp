/*
What is Encapsulation?
Encapsulation is the process of bundling data (variables) and the methods (functions) that act on that data into a single, cohesive unit—which in C++ is called a Class.

The most important part of encapsulation is Data Hiding. It is the practice of keeping sensitive data hidden from the outside world by making it private, and only allowing the outside world to interact with that data through safe, controlled public functions.
*/

#include<iostream>
using namespace std;

class BankAccount{
    private:

    // HIDDEN DATA: The outside world cannot touch this directly!
    double balance;

    public:
    
    //contructor
    BankAccount(){
        balance = 0.0;
    }

    void deposit(double amount){
        if(amount>0){
            balance += amount;
            cout<< "Successfully deposited $" << amount << endl;
        }
        else {
            cout<< "Invalid deposit amount." <<endl;
    }
}

void checkBalance() {
        cout << "Current Balance: $" << balance << endl;
    }
}; 

int main(){

    BankAccount myaccount;

    // --- THE WRONG WAY ---
    // myaccount.balance = 1000000;  <-- ERROR! 
    // The compiler will crash here because 'balance' is private. 
    // We are protecting the bank vault from being tampered with.

    myaccount.deposit(500.50);
    myaccount.checkBalance();
}