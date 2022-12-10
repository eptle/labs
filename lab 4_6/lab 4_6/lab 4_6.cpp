#include <iostream>
#include "Func.hpp"
#include <cmath>

int main()
{
    
    setlocale(LC_ALL, "rus");
    int arr[100][100]{ {} };
    int str, row;

    std::cout << "Введите количество строк матрицы:" << std::endl;
    std::cin >> str;
    std::cout << "Введите количество столбцов матрицы:" << std::endl;
    std::cin >> row;

    for (int i = 0; i < str; i++)
        for (int j = 0; j < row; j++)
            std::cin >> arr[i][j];

    int min = eptel::min(arr, str, row);
    bool twoMin = false;
    for (int i = 0; i < str; i++)
        for (int j = 0; j < row; j++)
            if (arr[i][j] == min)
            {
                twoMin = true;
                break;
            }

    int prime = 0;
    for (int i = 0; i < str; i++)
        for (int j = 0; j < row; j++)
            if (eptel::isPrime(abs(arr[i][j])))
                prime++;
    
    if (twoMin and (prime >= 2))
    {
        for (int i = 0; i < str - 1; i++)
            for (int j = 0; j < str - i - 1; j++)
                if (eptel::multOfStr(arr, row, j) < eptel::multOfStr(arr, row, j+1))
                    for (int k = 0; k < row; k++)
                    {
                        std::swap(arr[j][k], arr[j + 1][k]);
                    }
    }

    std::cout << std::endl;
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < row; j++) 
            std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }
}
