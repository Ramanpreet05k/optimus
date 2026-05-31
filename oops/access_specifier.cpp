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