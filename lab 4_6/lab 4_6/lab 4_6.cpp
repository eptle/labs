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

    eptel::in_matr(arr, str, row);

    int min = eptel::min(arr, str, row);
    
    if (eptel::second_min(arr, str, row, min) and (eptel::primeCnt(arr, str, row) >= 2))
        eptel::arrSort(arr, str, row);

    std::cout << std::endl;
    eptel::printArray(arr, str, row);
}
