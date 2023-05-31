#include <iostream>
#include <string>
#include "printDynamicArray.h"
#include "appendToDynamicArray.h"


int main()
{
    setlocale(LC_ALL, "Russian");

    int arrActualSize = 0; 
    int arrLogicalSize = 0;


    std::cout << "Введите фактичеcкий размер массива:> ";
    std::cin >> arrActualSize;

    while (!std::cin.good() || arrActualSize <= 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Вы ввели неверные даннные. Размер массива положительное целое число.\n";
        std::cout << "Введите фактичеcкий размер массива:> ";
        std::cin >> arrActualSize;
    }

    bool ErrorUserData = false; 

    do
    {
        std::cout << "Введите логичеcкий размер массива:> ";
        std::cin >> arrLogicalSize;

        while (!std::cin.good() || arrActualSize <= 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Вы ввели неверные даннные. Размер массива положительное целое число.\n";
            std::cout << "Введите логичеcкий размер массива:> ";
            std::cin >> arrLogicalSize;
        }

        if (arrLogicalSize > arrActualSize)
        {
            std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
            ErrorUserData = false;
        }
        else
        {
            ErrorUserData = true;
        }

    } while (!ErrorUserData);

    int userData = 0;
    int* arr = new int[arrActualSize] {};

   
    for (int i = 0; i < arrLogicalSize; i++)
    {
        std::cout << "Введите arr[" << i << "]:> ";
        std::cin >> userData;
        arr[i] = userData;
    };

    std::cout << std::endl;
    PrintDynamicArray(arr, arrActualSize, arrLogicalSize, false);

    std::cout << std::endl;
    appendToDynamicArray(arr, &arrActualSize, &arrLogicalSize);

    std::cout << std::endl;

    delete[]arr;
    arr = nullptr;
}