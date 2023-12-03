#include "Employees.h"
using namespace std;

void EmployeesSystem::addEmployee()
{
	if (numEmployees < MAX_EMPLOYEES)
	{
		cout << "Enter name: ";
		cin >> employees[numEmployees].name;
		cout << "Enter surname: ";
		cin >> employees[numEmployees].surname;
		cout << "Enter age: ";
		cin >> employees[numEmployees].age;
		numEmployees++;
	}
	else
	{
		cout << "No more employees can be added" << endl;
	}
}

void EmployeesSystem::editEmployee()
{
	string name;
	cout << "Enter name of employee to edit: ";
	cin >> name;
	for (int i = 0; i < numEmployees; i++)
	{
		if (employees[i].name == name)
		{
			cout << "Enter new name: ";
			cin >> employees[i].name;
			cout << "Enter new surname: ";
			cin >> employees[i].surname;
			cout << "Enter new age: ";
			cin >> employees[i].age;
			return;
		}
	}
	cout << "Employee not found" << endl;
}

void EmployeesSystem::deleteEmployee()
{
	string name;
	cout << "Enter name of employee to delete: ";
	cin >> name;
	for (int i = 0; i < numEmployees; i++)
	{
		if (employees[i].name == name)
		{
			for (int j = i; j < numEmployees - 1; j++)
			{
				employees[j] = employees[j + 1];
			}
			numEmployees--;
			return;
		}
	}
	cout << "Employee not found" << endl;
}

void EmployeesSystem::searchByName()
{
	string name;
	cout << "Enter name of employee to search for: ";
	cin >> name;
	for (int i = 0; i < numEmployees; i++)
	{
		if (employees[i].name == name)
		{
			cout << "Employee found: " << employees[i].name << " " << employees[i].surname << " " << employees[i].age << endl;
			return;
		}
	}
	cout << "Employee not found" << endl;
}

void EmployeesSystem::displayByAgeOrSurname()
{
	int choice;
	cout << "1. Display by age" << endl;
	cout << "2. Display by surname" << endl;
	cout << "Enter choice: ";
	cin >> choice;
	if (choice == 1)
	{
		for (int i = 0; i < numEmployees; i++)
		{
			for (int j = 0; j < numEmployees - 1; j++)
			{
				if (employees[j].age > employees[j + 1].age)
				{
					Employee temp = employees[j];
					employees[j] = employees[j + 1];
					employees[j + 1] = temp;
				}
			}
		}
	}
	else if (choice == 2)
	{
		for (int i = 0; i < numEmployees; i++)
		{
			for (int j = 0; j < numEmployees - 1; j++)
			{
				if (employees[j].surname > employees[j + 1].surname)
				{
					Employee temp = employees[j];
					employees[j] = employees[j + 1];
					employees[j + 1] = temp;
				}
			}
		}
	}

	else
	{
		cout << "Invalid choice" << endl;
		return;
	}

	for (int i = 0; i < numEmployees; i++)
	{
		cout << employees[i].name << " " << employees[i].surname << " " << employees[i].age << endl;
	}
}

void EmployeesSystem::saveToFile()
{
	ofstream file;
	file.open("employees.txt");
	for (int i = 0; i < numEmployees; i++)
	{
		file << employees[i].name << " " << employees[i].surname << " " << employees[i].age << endl;
	}
	file.close();
}

void EmployeesSystem::loadFromFile()
{
	ifstream file;
	file.open("employees.txt");
	if (file.is_open())
	{
		/*eof - end of file*/
		while (!file.eof())
		{
			file >> employees[numEmployees].name >> employees[numEmployees].surname >> employees[numEmployees].age;
			numEmployees++;
		}
	}

	else
	{
		cout << "File not found" << endl;
	}
	file.close();
}
