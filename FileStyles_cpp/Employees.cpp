#include "Employees.h"
#include "FileWork.h"
#include <iostream>
#include <fstream>

EmployeesSystem::EmployeesSystem() : numEmployees(0) {
    // Initialize other members if needed
}

EmployeesSystem::~EmployeesSystem() {
    // Cleanup resources, e.g., delete[] employees;
}

void EmployeesSystem::addEmployee() {
    if (numEmployees < MAX_EMPLOYEES) {
        cout << "Enter name: ";
        cin >> employees[numEmployees].name;
        cout << "Enter surname: ";
        cin >> employees[numEmployees].surname;
        cout << "Enter age: ";
        cin >> employees[numEmployees].age;
        numEmployees++;
    }
    else {
        cout << "No more employees can be added" << endl;
    }
}

void EmployeesSystem::editEmployee() {
    string name;
    cout << "Enter name of employee to edit: ";
    cin >> name;

    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].name == name) {
            cout << "Employee found. What do you want to edit?\n";
            cout << "1. Edit Name\n";
            cout << "2. Edit Surname\n";
            cout << "3. Edit Age\n";
            cout << "Enter your choice: ";

            int choice;
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "Enter new name: ";
                cin >> employees[i].name;
                cout << "Name updated successfully.\n";
                break;
            case 2:
                cout << "Enter new surname: ";
                cin >> employees[i].surname;
                cout << "Surname updated successfully.\n";
                break;
            case 3:
                cout << "Enter new age: ";
                cin >> employees[i].age;
                cout << "Age updated successfully.\n";
                break;
            default:
                cout << "Invalid choice.\n";
                break;
            }

            return;
        }
    }

    cout << "Employee not found.\n";
}

void EmployeesSystem::deleteEmployee() {
    string name;
    cout << "Enter name of employee to delete: ";
    cin >> name;

    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].name == name) {
            for (int j = i; j < numEmployees - 1; j++) {
                employees[j] = employees[j + 1];
            }
            numEmployees--;
            cout << "Employee deleted successfully.\n";
            return;
        }
    }

    cout << "Employee not found\n";
}

void EmployeesSystem::searchByName() {
    string name;
    cout << "Enter name of employee to search for: ";
    cin >> name;

    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].name == name) {
            cout << "Employee found: " << employees[i].name << " " << employees[i].surname << " " << employees[i].age << endl;
            return;
        }
    }

    cout << "Employee not found\n";
}

void EmployeesSystem::displayByAgeOrSurname() {
    int choice;
    cout << "1. Display by age\n";
    cout << "2. Display by surname\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        // Sort by age
        for (int i = 0; i < numEmployees; i++) {
            for (int j = 0; j < numEmployees - 1; j++) {
                if (employees[j].age > employees[j + 1].age) {
                    Employee temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }
    else if (choice == 2) {
        // Sort by surname
        for (int i = 0; i < numEmployees; i++) {
            for (int j = 0; j < numEmployees - 1; j++) {
                if (employees[j].surname > employees[j + 1].surname) {
                    Employee temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }
    else {
        cout << "Invalid choice\n";
        return;
    }

    for (int i = 0; i < numEmployees; i++) {
        cout << employees[i].name << " " << employees[i].surname << " " << employees[i].age << endl;
    }
}

void EmployeesSystem::saveToFile() {
    string filename;
    cout << "Enter filename to save: ";
    cin >> filename;

    FileWork<Employee>::writeToFile(employees, numEmployees, filename);

    cout << "Data saved to file.\n";
}

void EmployeesSystem::displayEmployees() const {
    if (numEmployees == 0) {
        cout << "No employees to display.\n";
        return;
    }

    cout << "Saved Employees:\n";
    for (int i = 0; i < numEmployees; ++i) {
        cout << "Name: " << employees[i].name << "\n";
        cout << "Surname: " << employees[i].surname << "\n";
        cout << "Age: " << employees[i].age << "\n";
        cout << "-------------------\n";
    }
}

void EmployeesSystem::loadFromFile() {
    string filename;
    cout << "Enter filename to load: ";
    cin >> filename;

    employees = FileWork<Employee>::readFromFile(numEmployees, filename);

    displayEmployees();

    cout << "Data loaded from file.\n";
}
