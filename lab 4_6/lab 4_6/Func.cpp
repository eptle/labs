#include "Func.hpp"
#include <cmath>
#include <iostream>

namespace eptel
{
    bool isPrime(int n)
    {
        if (n == 1)
            return false;
        else if (n == 2)
            return true;
        for (int i = 2; i < sqrt(n) + 1; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int min(int arr[100][100], int str, int row)
    {
        int min = 100000;
        for (int i = 0; i < str; i++)
            for (int j = 0; j < row; j++)
                if (arr[i][j] < min)
                    min = arr[i][j];
        return min;
    }

    int multOfStr(int arr[100][100], int row, int n)
    {
        int mult = 1;
        for (int i = 0; i < row; i++)
        {
            mult = mult * arr[n][i];
        }
        return mult;
    }

    bool second_min(int arr[100][100], int str, int row, int min)
    {
        int cnt = 0;
        for (int i = 0; i < str; i++)
            for (int j = 0; j < row; j++)
                if (arr[i][j] == min)
                {
                    cnt++;
                    if (cnt >= 2)
                        return true;
                }
        return false;
    }

    void printArray(int arr[100][100], int str, int row)
    {
        for (int i = 0; i < str; i++)
        {
            for (int j = 0; j < row; j++)
                std::cout << arr[i][j] << " ";
            std::cout << std::endl;
        }
    }

    int in_matr(int arr[100][100], int str, int row)
    {
        for (int i = 0; i < str; i++)
            for (int j = 0; j < row; j++)
                std::cin >> arr[i][j];
        return arr[100][100];
    }

    int arrSort(int arr[100][100], int str, int row)
    {
        for (int i = 0; i < str - 1; i++)
            for (int j = 0; j < str - i - 1; j++)
                if (eptel::multOfStr(arr, row, j) < eptel::multOfStr(arr, row, j + 1))
                    for (int k = 0; k < row; k++)
                    {
                        std::swap(arr[j][k], arr[j + 1][k]);
                    }
        return arr[100][100];
    }

    int primeCnt(int arr[100][100], int str, int row)
    {
        int prime = 0;
        for (int i = 0; i < str; i++)
            for (int j = 0; j < row; j++)
                if (eptel::isPrime(abs(arr[i][j])))
                    prime++;
        return prime;
    }
}