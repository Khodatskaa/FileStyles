#include "FileWork.h"
#include <iostream>
#include <fstream>

template<typename T>
void FileWork<T>::writeToFile(const T* data, int size, const std::string& filename) {
    std::ofstream file(filename, std::ios::out | std::ios::binary);

    if (file.is_open()) {
        file.write(reinterpret_cast<const char*>(data), size * sizeof(T));
        file.close();
        std::cout << "Data written to file successfully\n";
    }
    else {
        std::cout << "Error opening file for writing\n";
    }
}

template<typename T>
T* FileWork<T>::readFromFile(int& size, const std::string& filename) {
    std::ifstream file(filename, std::ios::in | std::ios::binary);

    if (file.is_open()) {
        T* data = nullptr;
        T item;

        while (file.read(reinterpret_cast<char*>(&item), sizeof(T))) {
            T* newData = new T[size + 1];

            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }

            newData[size] = item;

            delete[] data;
            data = newData;

            ++size;
        }

        file.close();
        std::cout << "Data read from file successfully.\n";
        return data;
    }
    else {
        std::cerr << "Error opening file for reading.\n";
        return nullptr;
    }
}

template struct FileWork<int>;