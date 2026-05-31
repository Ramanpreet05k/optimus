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