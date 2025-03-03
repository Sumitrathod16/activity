#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int id;
    double salary,allowance,deduction,netsalary;

public:
    // Default constructor
    Employee() : name(""), id(0), salary(0.0),allowance(0.0),deduction(0.0) {}

    // Parameterized constructor
    Employee(string empName, int empId, double empSalary,double allowan,double deduct) {
        name = empName;
        id = empId;
        salary = empSalary;
        allowance = allowan;
        deduction = deduct;
    }

    // Copy constructor
    Employee(const Employee &other) {
        name = other.name;
        id = other.id;
        salary = other.salary;
        allowance = other.allowance;
        deduction = other.deduction;
        netsalary = other.netsalary;
        }
        
        

    // Method to display employee details
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Salary: $" << salary <<",Allowance: $"<<allowance<< ",Deduction:$"<<deduction<< endl;
    }

    // Method to set employee details
    void setDetails(string empName, int empId, double empSalary,double allowan,double deduct) {
        name = empName;
        id = empId;
        salary = empSalary;
        allowance = allowan;
        deduction = deduct;
    }
    void calculateSalary(){
        netsalary=(salary+allowance)-deduction;
    }
};

int main() {
    const int SIZE = 3; 
    Employee employees[SIZE];  
    for (int i = 0; i < SIZE; i++) {
        string name;
        int id;
        double salary;
        double allowance;
        double deduction;

        cout << "Enter details for Employee " << i + 1 << " (Name, ID, Salary,Allowance,Deduction): ";
        cin >> name >> id >> salary>>allowance>>deduction;
        employees[i].setDetails(name, id, salary,allowance,deduction);
    }
    cout << "\nOriginal Employee Details:\n";
    for (int i = 0; i < SIZE; i++) {
        employees[i].display();
        employees[i].calculateSalary();
    }
    cout << "\nCopying Employee 1 details to a new Employee object...\n";
    Employee copiedEmployee = employees[0];
    cout << "Copied Employee Details:\n";
    copiedEmployee.display();

    return 0;
}