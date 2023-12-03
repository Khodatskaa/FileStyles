#include <iostream>
#include <string>
#include <fstream>
#include "FileWork.h"
#include "Employees.h"

using namespace std;

int main()
{
	EmployeesSystem employeesSystem;
	int choice;
	do
	{
		cout << "1. Add employee" << endl;
		cout << "2. Edit employee" << endl;
		cout << "3. Delete employee" << endl;
		cout << "4. Search by name" << endl;
		cout << "5. Display by age or surname" << endl;
		cout << "6. Save to file" << endl;
		cout << "7. Load from file" << endl;
		cout << "8. Exit" << endl;
		cout << endl;
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			employeesSystem.addEmployee();
			cout << "Employee added\n" << endl;
			break;
		case 2:
			employeesSystem.editEmployee();
			cout << "Employee edited\n" << endl;
			break;
		case 3:
			employeesSystem.deleteEmployee();
			cout << "Employee deleted\n" << endl;
			break;
		case 4:
			employeesSystem.searchByName();
			cout << "Employee found\n" << endl;
			break;
		case 5:
			employeesSystem.displayByAgeOrSurname();
			cout << "Employees displayed\n" << endl;
			break;
		case 6:
			employeesSystem.saveToFile();
			cout << "Employees saved\n" << endl;
			break;
		case 7:
			employeesSystem.loadFromFile();
			cout << "Employees loaded\n" << endl;
			break;
		case 8:
			break;
		default:
			cout << "Invalid choice" << endl;
		}
	} while (choice != 8);
	return 0;
}