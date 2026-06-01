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