#pragma once

namespace eptel
{
	bool isPrime(int n);
	int min(int arr[100][100], int str, int row);
	int multOfStr(int arr[100][100], int row, int n);
	bool second_min(int arr[100][100], int str, int row, int min);
	void printArray(int arr[100][100], int str, int row);
	int in_matr(int arr[100][100], int str, int row);
	int arrSort(int arr[100][100], int str, int row);
	int primeCnt(int arr[100][100], int str, int row);
}