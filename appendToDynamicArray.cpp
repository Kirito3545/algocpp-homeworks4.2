#include "appendToDynamicArray.h"

enum class DynamicArrayMessage
{
    Exit
};

void appendToDynamicArray(int*& arr, int* arrActualSize, int* arrLogicalSize)
{
    int appendUserData = 0;
    bool stoppingActions = false;

    do
    {
        std::cout << "Введите элемент для добавления(0 - выход без добавлений):> ";
        std::cin >> appendUserData;

        while (!std::cin.good())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Вы ввели неверные даннные. Массив для целочисленных значений.\n";
            std::cout << "Введите элемент для добавления(0 - выход без добавлений):> ";
            std::cin >> appendUserData;
        }
        if (appendUserData == static_cast<int> (DynamicArrayMessage::Exit))
        {
            bool stoppingActions = true;
            PrintDynamicArray(arr, *arrActualSize, *arrLogicalSize, stoppingActions);

            return;
        }

        if (*arrActualSize == *arrLogicalSize)
        {
            *arrActualSize *= 2;
            int* arr2 = new int[*arrActualSize] {};

            
            for (int i = 0; i < *arrLogicalSize; i++)
            {
                arr2[i] = arr[i];
            };

            arr = arr2; 
            arr2 = nullptr; 
        }
        arr[*arrLogicalSize] = appendUserData; 
        ++* arrLogicalSize;

        PrintDynamicArray(arr, *arrActualSize, *arrLogicalSize, stoppingActions);

    } while (true);
};