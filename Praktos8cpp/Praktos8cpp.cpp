#include <iostream>
#include "..\StaticLib\Header.h"
#include <Windows.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    std::cout << "StaticLib: " << Sum(2, 2) << std::endl;
    HINSTANCE load;
    load = LoadLibrary(L"DynamicLib.dll");
    typedef int (*sum) (int, int);
    typedef const char* (*search) (const char*, const char*);
    sum Sum;
    Sum = (sum)GetProcAddress(load, "Sum");
    std::cout << "DynamicLib: " << Sum(2, 3) << std::endl;
    search Search = (search)GetProcAddress(load, "Search");
    while (true)
    {
        std::string str;
        std::string str2;
        std::cout << "Введите строку: ";
        std::cin >> str;
        std::cout << "Введите что в ней искать: ";
        std::cin >> str2;
        const char* result = Search(str.c_str(), str2.c_str());
        if (result) {
            std::cout << "Строка содержит введенное слово: " << std::endl;
        }
        else {
            std::cout << "Строка не содержит введеное слово" << std::endl;
        }
    }
    FreeLibrary(load);
}