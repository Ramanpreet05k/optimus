1. Core Foundations: Classes and Objects
What is a class? 
A class is a blueprint or a template. It defines the properties (variables) and behaviors (functions) that a certain type of object should have, but it doesn't actually exist in memory yet.

What is an object? 
An object is a real-world instance of a class. It takes up memory and holds actual data.

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

/*
1. Function Overloading (Compile-Time Polymorphism)
What is it? Function overloading happens when you have multiple functions with the exact same name in the same class (or scope), but they have different parameters (either a different number of parameters or different data types).

How it works:
When you call the function, the C++ compiler looks at the arguments you passed in and automatically decides which version of the function to run. Because this decision is made while the code is compiling, it is called compile-time polymorphism.
*/

#include<iostream>
using namespace std;

class Solution{
    public:
    int add(int a,int b){
        return a+b;
    }
    int add(int a,int b,int c){
        return a+b+c;
    }
    double add(double a, double b){
        return a+b;
    }
};

int main(){
    Solution sol;
    cout<<sol.add(10,5)<<endl;
     cout<<sol.add(10,5,5)<<endl;
      cout<<sol.add(10.9,5.2)<<endl;
}

/*
2. Function Overriding (Run-Time Polymorphism)
What is it?
Function overriding happens when a child class (derived class) provides its own specific implementation for a function that is already defined in its parent class (base class). For overriding to work, the function in the child class must have the exact same name, exact same parameters, and exact same return type as the function in the parent class.

How it works:
To allow a function to be overridden, the parent class must declare it with the virtual keyword. The decision of which function to run (the parent's or the child's) is made while the program is actually running
*/

#include<iostream>
using namespace std;

//base class
class Animal{
    public:

    // virtual keyword tells compliler that this can be overriden by child class
    virtual void makesound(){
        cout<<"Some generic animal sound.."<<endl;
    }
};

class Dog : public Animal{
    public:


    //this func override the parent class makesound() func
    //the override keyword is optional but recommended
    void makesound() override{
        cout<<"Woof woof"<<endl;
    }
};

int main(){
    Animal genericanimal;
    genericanimal.makesound();
    Dog mydog;
    mydog.makesound();

// real power of overriding : using a pointer of base class
    Animal* animalptr = &mydog;


//even though pointer is of animal, it knows to call the dog's ersion bcz of virtual keyword in base class
    animalptr->makesound();
}

/*
this pointer is a hidden pointer that exists inside every non-static member function. It automatically points to the exact object that is currently calling the function.

You can think of this as the code's way of saying "my." Just like you would say "my name is..." instead of just "name is...", the this pointer tells the class, "use my specific variable, not a general one."


1. Resolving Name Conflicts (Shadowing)
The most frequent use of this is when a function parameter has the exact same name as a class member variable. Without this, the compiler gets confused and just assigns the parameter to itself, leaving the class variable unchanged.

2. Returning the Current Object (Method Chaining)
Sometimes you want to call multiple functions on the exact same object in a single line of code (like player.setHealth(100).setName("Arthur");). To do this, the function needs to return the object itself. You achieve this by returning *this (dereferencing the pointer to get the actual object).


In C++, when you put an asterisk * in front of a pointer, it means "go grab the actual thing the arrow is pointing at." This is called dereferencing.

this = The address of the object (e.g., Memory Slot #104).

*this = The actual object itself (The physical Box).
*/


#include<iostream>
using namespace std;

class Player{
    private:
    int health;

    public:

    // The parameter is named 'health', which is the exact same name as the private variable
    void setHealth(int health){
        // health = health;  <-- WRONG! The compiler thinks you are just assigning the parameter to itself.
        
        // RIGHT! 'this->health' specifically means the class's private variable.
        // The 'health' on the right is the parameter passed into the function.

        this->health = health;
    }
    void printHealth(){
        cout<<"Player health is : "<<health<<endl;
    }
};

class Box {
private:
    int length;
    int width;

public:
    // Notice the return type is a reference to the Box class (Box&)
    Box& setLength(int l) {
        length = l;
        return *this; // Returns the actual object that called this function
    }

    Box& setWidth(int w) {
        width = w;
        return *this; // Returns the actual object
    }

    void displayDimensions() {
        cout << "Box is " << length << "x" << width << endl;
    }
};

int main(){
    Player p1;
    p1.setHealth(100);
    p1.printHealth();



    Box myBox;
    // Because each function returns '*this', we can chain them together!
    myBox.setLength(10).setWidth(5); 

    myBox.displayDimensions(); // Outputs: Box is 10x5
    return 0;
}

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

#include<iostream>
using namespace std;

class Employee {
    private:
    double salary; // Extremely sensitive. ONLY the Employee class can touch this.

    protected:
    string department; // Sensitive, but we trust Child classes (like Manager) to see it.

    public:
    string name; // Not sensitive. Anyone can see the employee's name.

    Employee(string empName, string empDept, double empSalary){
        name = empName;
        department = empDept;
        salary = empSalary;
    }

    void showSalary(){
        cout<<name<<"'s salary is $"<<salary<<endl;
    }
};

class Manager : public Employee{
    public:

    // Constructor
    Manager(string empName, string empDept, double empSalary) 
        : Employee(empName, empDept, empSalary) {}


    void showDepartment() {
        // ALLOWED: Manager is a Child class, so it CAN access the protected 'department' variable directly.
        cout << name << " manages the " << department << " department." << endl;


        // ERROR: If we tried to write 'cout << salary;' here, the code would break. 
        // Salary is PRIVATE to the Parent class. Even children cannot touch it directly!
    
}
};

int main(){
    Manager m1("Alice","IT",34000);
    // Allowed! 'name' is public, so we can access it directly from outside.
    cout << "Employee Name: " << m1.name << endl;

    // --- 2. PROTECTED ACCESS ---
    // m1.department = "Sales"; <-- ERROR! The outside world cannot access protected data.
    // However, the child class accessed it successfully via its own method:
    m1.showDepartment(); 

    // --- 3. PRIVATE ACCESS ---
    // m1.salary = 100000; <-- ERROR! The outside world cannot access private data.
    // We must use the public function provided by the class to see it:
    m1.showSalary();
}

/*
What is Inheritance?
Inheritance is a mechanism where a new class (the Child or Derived class) automatically acquires all the properties (variables) and behaviors (functions) of an existing class (the Parent or Base class).

The primary purpose of inheritance is code reusability. Instead of writing the same code over and over again for different classes that share similar traits, you write the common code once in a parent class and have the child classes inherit it.
*/

/*
Types of Inheritance in C++
There are 5 main types of inheritance.

1. Single InheritanceThis is the simplest form. One child class inherits from exactly one parent class.
Structure: A->B (B inherits from A)
*/

#include<iostream>
using namespace std;

class Animal{
    public:
    void eat() {
        cout<<"Eating.."<<endl;
    }
};

class Dog : public Animal{
    public:
    void bark(){
        cout<<"Woof"<<endl;
    }
};
int main(){
    Dog myDog;
    myDog.eat(); //inherited from animal
    myDog.bark();
}


/*
2. Multilevel Inheritance
A child class is derived from a parent class, and then that child class acts as a parent for another new class. 
It forms a chain or a lineage.
Structure: A->B -> C (C inherits from B, which inherited from A)
*/

#include<iostream>
using namespace std;

class Animal{
    public:
    void eat(){
        cout<<"Eating.."<<endl;
    }
};

class Dog : public Animal{
    public:
    void bark(){
        cout<<"Barking.."<<endl;
    }
};

class puppy : public Dog{
    public:
    void weep(){
        cout<<"Whining.."<<endl;
    }
};

int main(){
    puppy mypuppy;
    mypuppy.eat();   //Inherited from Grandparent (Animal)
    mypuppy.bark();  // Inherited from Parent (Dog)
    mypuppy.weep();

    return 0;
}


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


/*
4. Hierarchical Inheritance
Multiple child classes inherit from a single parent class. This is the opposite of multiple inheritance.
Structure: A -> B and A -> C (Both B and C inherit from A)
*/

#include <iostream>
using namespace std;

class Shape {                  // Parent Class
public:
    void getArea() { cout << "Calculating area..." << endl; }
};

class Circle : public Shape {  // Child 1
public:
    void drawCircle() { cout << "Drawing Circle." << endl; }
};

class Square : public Shape {  // Child 2
public:
    void drawSquare() { cout << "Drawing Square." << endl; }
};

int main() {
    Circle c;
    Square s;
    
    // Both children share the same parent function
    c.getArea(); 
    s.getArea();
    return 0;
}

The Diamond Problem is a famous ambiguity issue that occurs in Object-Oriented Programming when using Multiple Inheritance.

It happens when a class inherits from two classes, and both of those classes inherit from the exact same base class. This creates a "diamond" shape in the inheritance family tree.

#include <iostream>
using namespace std;

// 1. Grandparent Class
class Animal {
public:
    int age;
};

// 2. Parent Class 1
class Tiger : public Animal { 
};

// 3. Parent Class 2
class Lion : public Animal { 
};

// 4. Child Class (Inherits from both)
class Liger : public Tiger, public Lion { 
};

int main() {
    Liger myLiger;
    
    // ERROR: Request for 'age' is ambiguous!
    // The compiler doesn't know if you mean Tiger::age or Lion::age
    myLiger.age = 5; 
    
    return 0;
}


The Solution (Virtual Inheritance)
To fix this, C++ uses the virtual keyword when the parent classes inherit from the grandparent class.

By writing virtual public Animal, you are telling the compiler: "If anyone down the line inherits from both of us, only give them one shared copy of Animal, not two."

#include <iostream>
using namespace std;

// 1. Grandparent Class
class Animal {
public:
    int age;
};

// 2. Parent Class 1 (Notice the 'virtual' keyword)
class Tiger : virtual public Animal { 
};

// 3. Parent Class 2 (Notice the 'virtual' keyword)
class Lion : virtual public Animal { 
};

// 4. Child Class 
class Liger : public Tiger, public Lion { 
};

int main() {
    Liger myLiger;
    
    // SUCCESS! Liger only has one shared copy of 'age' now.
    myLiger.age = 5; 
    cout << "The Liger is " << myLiger.age << " years old." << endl;
    
    return 0;
}

Polymorphism is one of the core pillars of Object-Oriented Programming (OOP). The word comes from Greek, meaning "many forms" (poly = many, morph = form).

In programming, polymorphism is the ability of a function, object, or operator to behave differently depending on the context or the data it is working with.

1. Compile-Time Polymorphism (Static Binding)
This happens when the compiler determines exactly which function to execute before the program even runs. It looks at the code, sees the inputs, and locks in the decision during compilation. Because the decision is made early, it is very fast.

There are two ways to achieve this: Function Overloading and Operator Overloading.

2. Run-Time Polymorphism (Dynamic Binding)
This happens when the compiler cannot determine which function to execute until the program is actually running. This occurs when you use Pointers and Inheritance.

This is achieved using Function Overriding.

What is Abstraction?
Abstraction is the concept of hiding complex background details and showing only the essential, relevant features to the user. It simplifies the way we interact with systems.

2. What is an Abstract Class?
An Abstract Class is a class that is meant to be used only as a base (parent) class. You cannot create an object directly from an abstract class. It acts as a strict blueprint for child classes to follow.

How does a class become abstract in C++?
A class automatically becomes abstract if it contains at least one Pure Virtual Function.

A pure virtual function is a function that has no body and is assigned the value = 0.

It is a strict rule that says: "Any child class that inherits from me MUST write their own code for this function, otherwise they cannot exist either."

 #include<iostream>
using namespace std;

class smartDevice{
    public:

    void showbatterylevel(){
        cout<<"Battery level is sufficient"<<endl;
    }

    // THIS IS THE PURE VIRTUAL FUNCTION. 
    // The "= 0" tells the compiler this class is now Abstract.
    // It has no code body here.
    virtual void turnon() = 0;
};

class Smartphone : public smartDevice {
    public:

    // The child MUST provide the actual code for turnOn()
    void turnon() override{
        cout<<"Smartphone booting up: loading os,"<<endl;
    }
};

class SmartBulb : public smartDevice {
public:
    // The child MUST provide the actual code for turnOn()
    void turnon() override {
        cout << "Smart Bulb turning on: Setting LED color to Warm White..." << endl;
    }
};

int main(){
    // ERROR: You CANNOT do this. 
    // SmartDevice myDevice;  <-- The compiler will stop you. An abstract class is just a concept, not a real object.

    // SUCCESS: You CAN create objects of the child classes.
    Smartphone myPhone;
    SmartBulb myBulb;

    cout << "--- Interacting with Phone ---" << endl;
    myPhone.showbatterylevel();
    myPhone.turnon(); 

    cout << "\n--- Interacting with Bulb ---" << endl;
    myBulb.showbatterylevel();
    myBulb.turnon();
}


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

Types of constructor

1. Default Constructor
A default constructor takes no arguments (no parameters). If you do not write a constructor for your class, the C++ compiler will automatically generate a hidden, empty default constructor for you.

#include <iostream>
using namespace std;

class Player {
public:
    int health;
    int score;

    // DEFAULT CONSTRUCTOR
    // Takes no inputs and sets baseline values automatically
    Player() {
        health = 100;
        score = 0;
        cout << "A new player has spawned with 100 health!" << endl;
    }
};

int main() {
    // The moment this line runs, the Default Constructor is called.
    Player p1; 
    
    return 0;
}


2. Parameterized Constructor
A parameterized constructor takes arguments (parameters). This allows you to pass in specific data the moment you create the object, allowing you to customize it immediately rather than setting it up later.

#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int year;

    // PARAMETERIZED CONSTRUCTOR
    // Forces the user to provide a brand and a year when creating the car
    Car(string carBrand, int carYear) {
        brand = carBrand;
        year = carYear;
    }
    
    void displayInfo() {
        cout << "Car: " << brand << " (" << year << ")" << endl;
    }
};

int main() {
    // We pass the data in parentheses right when we create the object
    Car myCar("Toyota", 2022); 
    Car dreamCar("Porsche", 2024);
    
    myCar.displayInfo();
    dreamCar.displayInfo();

    return 0;
}

3. Copy Constructor
A copy constructor is used to create a brand-new object by copying the data from an already existing object of the same class.

It takes a reference to an object of the same class as its parameter. It is commonly used when you want to duplicate an object without linking them together in memory.

#include <iostream>
using namespace std;

class Book {
public:
    string title;
    int pages;

    // Parameterized Constructor
    Book(string t, int p) {
        title = t;
        pages = p;
    }

    // COPY CONSTRUCTOR
    // Takes a reference (&) to another Book object
    // We use "const" so we don't accidentally change the original book
    Book(const Book &originalBook) {
        title = originalBook.title;
        pages = originalBook.pages;
        cout << "Copied the book: " << title << endl;
    }
};

int main() {
    // 1. Create the original book using the Parameterized Constructor
    Book book1("Harry Potter", 300);

    // 2. Create a new book by passing book1 into it. 
    // This triggers the Copy Constructor.
    Book book2 = book1; 
    
    // Alternatively, you can write it like this:
    // Book book2(book1);

    cout << "Book 1 has " << book1.pages << " pages." << endl;
    cout << "Book 2 has " << book2.pages << " pages." << endl;

    return 0;
}


/*
3. Copy Constructor
A copy constructor is used to create a brand-new object by copying the data from an already existing object of the same class.

It takes a reference to an object of the same class as its parameter. It is commonly used when you want to duplicate an object without linking them together in memory.
*/

#include<iostream>
using namespace std;

class Book{
    public:
    string title;
    int pages;


    Book(string t, int p){
        title=t;
        pages=p;
    }

    Book(const Book &originalBook){
        title = originalBook.title;
        pages = originalBook.pages;
        cout << "Copied the book: " << title << endl;
    }

};

int main(){
    Book b1("Harry Potter",300);
    // This triggers the Copy Constructor.
    Book b2 = b1;


    cout << "Book 1 has " << b1.pages << " pages." << endl;
    cout << "Book 2 has " << b2.pages << " pages." << endl;
}


Destructor

A destructor is a special member function in C++ that is called automatically the exact moment an object is destroyed (when it goes out of scope or is manually deleted).

The 4 Rules of Destructors

The Name: It must have the exact same name as the class, but preceded by a tilde (~).

No Return Type: It cannot return a value (not even void).

No Parameters: It takes exactly zero arguments.

Only One: Because it takes no arguments, you cannot overload it. A class can only have one destructor.

what is the difference between structure and a class in c++
In C++, a struct (structure) and a class are practically identical. They can both contain variables, functions, constructors, and they can both use inheritance.

The only technical difference between them comes down to default privacy (access specifiers).

Here is the breakdown of the differences, followed by a clear example.

1. Default Access Specifiers
If you don't explicitly write public:, private:, or protected: inside them:

Class: Everything defaults to private. The outside world cannot access it.

Struct: Everything defaults to public. The outside world can access it freely.

What is a Friend Function?
In C++, one of the main rules of Encapsulation is that private and protected data cannot be accessed by anyone outside the class.

A friend function is the one exception to this rule. It is a normal, standalone function that is not a member of the class, but the class explicitly grants it special permission to access its hidden private and protected data.


Pure Virtual Function
A pure virtual function is a virtual function that has no code body at all. Instead of curly braces {}, you simply assign it the value = 0.

Why do we need it?
It is used when a function is so specific to the Child classes that it makes absolutely no sense for the Parent class to have a default version.

Crucial Rule: Any class that contains a pure virtual function instantly becomes an Abstract Class. You cannot create objects from it. It exists purely as a strict blueprint to force child classes to do the work.


What is a Static Data Member?
Normally, when you create objects from a class, each individual object gets its own private copy of the class variables. If you change a variable in Object A, Object B is completely unaffected.

A static data member is a variable that is shared by all objects of that class. Instead of creating a new copy for every object, the computer allocates memory for this variable exactly once. All objects look at and modify that same exact memory slot.

What is an Enumeration (enum)?
An Enumeration (commonly known as an enum) is a user-defined data type in C++ used to assign names to integer constants. It allows you to group a set of related constants together under a single type name.