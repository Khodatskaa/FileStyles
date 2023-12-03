#include "FileWork.h"
#include "Employees.h"  
#include <iostream>
#include <fstream>


#ifndef MAX_DATA_SIZE
#define MAX_DATA_SIZE 20
#endif

void FileWork<Employee>::writeToFile(const Employee* data, int size, const std::string& filename) {
    if (!data) {
        std::cout << "Error: Null pointer passed to writeToFile\n";
        return;
    }

    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Unable to open file for writing\n";
        return;
    }

    for (int i = 0; i < size; ++i) {
        file << data[i].name << ' ' << data[i].surname << ' ' << data[i].age << '\n';
    }

    file.close();
    std::cout << "Data written to file successfully.\n";
}

Employee* FileWork<Employee>::readFromFile(int& size, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Unable to open file for reading\n";
        return nullptr;
    }

    Employee* data = new Employee[MAX_DATA_SIZE];
    size = 0;

    while (size < MAX_DATA_SIZE && file >> data[size].name >> data[size].surname >> data[size].age) {
        ++size;
    }

    file.close();
    std::cout << "Data read from file successfully\n";

    return data;
}

template class FileWork<Employee>;
