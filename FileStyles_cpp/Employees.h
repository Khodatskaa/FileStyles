#ifndef Employees_h
#define Employees_h

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

struct Employee
{
    string name;
    string surname;
    int age;
};

struct EmployeesSystem 
{
public:
    void addEmployee();
    void editEmployee();
    void deleteEmployee();
    void searchByName();
    void displayByAgeOrSurname();
    void saveToFile();
    void loadFromFile();

private:
    int MAX_EMPLOYEES = 20; 
    Employee * employees = new Employee[MAX_EMPLOYEES];
    int numEmployees = 0; 
};


#endif 