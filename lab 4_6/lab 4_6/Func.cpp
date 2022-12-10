#include "Func.hpp"
#include <cmath>

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
}