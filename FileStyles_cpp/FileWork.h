#ifndef FileWork_h
#define FileWork_h

#include <fstream>

template <typename T>
struct FileWork
{
public:
    static void writeToFile(const T* data, int size, const std::string& filename);
    static T* readFromFile(int& size, const std::string& filename);
};

#endif