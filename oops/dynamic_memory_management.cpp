/*
Dynamic memory management is the process of allocating memory during the execution of a program (run-time) rather than before the program runs (compile-time).

1. The Stack vs. The Heap
When a C++ program runs, it primarily uses two areas of memory:

The Stack: Used for static memory allocation. This is where normal local variables live. The compiler must know the exact size of these variables before the program runs. The stack is fast, but its size is limited, and variables here are automatically destroyed when their function ends.

The Heap: Used for dynamic memory allocation. This is a massive pool of memory. You use the heap when you don't know how much memory you will need until the program is actually running (e.g., asking a user how many items they want to store), or when you want a variable to survive after a function finishes.

2. The new and delete Operators
In C++, you control the heap manually using two keywords:

new: Requests a block of memory from the heap. If successful, it returns a pointer to the beginning of that memory block.

delete: Gives the memory back to the system when you are done with it.

The Golden Rule: Every time you use new, you must eventually use delete. If you forget, your program will hold onto that memory forever, causing a memory leak which will eventually crash your program.


Key Takeaways
Pointers are mandatory: Dynamic memory always relies on pointers because new returns a memory address.

Arrays vs. Single Items: Use delete for single variables/objects, and delete[] for arrays.

Nullptr: Always set your pointers to nullptr immediately after deleting them. If you try to access a pointer after you have deleted its memory, your program will crash (this is called a "dangling pointer").
*/


#include<iostream>
using namespace std;

class Player{
    public:
    string name;
    Player(string n){
        name = n;
        cout<<"Player "<<name<<" spawned in the heap"<<endl;
    }
    ~Player() {
            cout<<"Player "<<name<<" destroyed. memory freed"<<endl;
        }
};

int main(){
    // ==========================================
    // EXAMPLE 1: Dynamically allocating an array
    // ==========================================
    int size;
    cout<<"How many enemies should we spawn?";
    cin>>size; // We don't know this size until the program runs!

    // Allocate an array of integers on the heap. 
    // 'new' returns a pointer to the first element.
    int* enemyhealth = new int[size];


    //use the dynamically allocated array
    for(int i=0;i<size;i++){
        enemyhealth[i]=100;
    }

    cout<<"spawned "<<size<<" enemies"<<endl;

    // We MUST free the array memory. Notice the [] for arrays!
    delete[] enemyhealth;

    enemyhealth = nullptr;


    // ==========================================
    // EXAMPLE 2: Dynamically allocating an object
    // ==========================================
    cout << "\n--- Creating a Player ---" << endl;

    Player* p1 = new Player("Arthur");

    cout << "Accessing player: " << p1->name << endl;

    delete p1;
    p1 = nullptr;

    return 0;
}