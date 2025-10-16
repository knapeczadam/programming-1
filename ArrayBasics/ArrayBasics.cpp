// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "structs.h"
#include <iostream>

void PrintArrays();
void PrintSize();
void PrintMemoryLocation();
void PrintElements(int* pNumbers, int size);
void PrintElements(int* pNumbers, int startIdx, int endIdx);
int GetIndex(int rowIdx, int colIdx, int nrCols);
void Print2DMatrix();
void TestPrintElements();

int main()
{
	PrintArrays();
	PrintSize();
	PrintMemoryLocation();
	TestPrintElements();
	Print2DMatrix();
}

void PrintArrays()
{
	const int n{5};
	int arr1[n]{};
	int arr2[]{10, 20, 30, 40, 50};
	int arr3[n]{1, 2, 3};

	std::cout << "-- Accessing elements --" << std::endl;
	std::cout << "First element: " << arr3[0] << std::endl;
	std::cout << "Last element: " << arr3[n - 1] << std::endl;
	std::cout << std::endl;
	std::cout << "Iterating over the elements" << std::endl;
	for (int idx{0}; idx < n; ++idx)
	{
		std::cout << arr3[idx] << ' ';
	}
	std::cout << std::endl << std::endl;
}

void PrintSize()
{
	int arr2[]{10, 20, 30, 40, 50};
	std::cout << "-- Size of arrays --" << std::endl;
	std::cout << "2nd array" << std::endl;
	std::cout << "  nr of bytes: " << sizeof(arr2) << std::endl;
	std::cout << "  size of one element: " << sizeof(int) << std::endl;
	const int n{ sizeof(arr2) / sizeof(int) };
	std::cout << "  nr of elements: " << n << std::endl;
	PrintElements(arr2, n);
	std::cout << std::endl;
}

void PrintMemoryLocation()
{
	const int n{5};
	int arr1[n]{};
	std::cout << "-- The elements occupy consecutive memory locations --" << std::endl;
	std::cout << "Array of int types" << std::endl;
	for (int idx{0}; idx < n; ++idx)
	{
		std::cout << "Address of element with index " << idx << " is " << &arr1[idx] << std::endl;
	}
	std::cout << std::endl;
	Point2f arr2[n]{};
	std::cout << "Array of Point2f types" << std::endl;
	for (int idx{0}; idx < n; ++idx)
	{
		std::cout << "Address of element with index " << idx << " is " << &arr2[idx] << std::endl;
	}
	std::cout << std::endl;
}

void PrintElements(int* pNumbers, int size)
{
	for (int idx{0}; idx < size; ++idx)
	{
		std::cout << pNumbers[idx] << ' ';
	}
	std::cout << std::endl;
}

void PrintElements(int* pNumbers, int startIdx, int endIdx)
{
	for (int idx{startIdx}; idx <= endIdx; ++idx)
	{
		std::cout << pNumbers[idx] << ' ';
	}
	std::cout << std::endl;
}

void TestPrintElements()
{
	const int n{5};
	int arr1[n]{};
	int arr2[]{10, 20, 30, 40, 50};
	int arr3[n]{1, 2, 3};
	std::cout << "-- Passing an array to a function, PrintElements --" << std::endl;
	std::cout << "Print all elements" << std::endl;
	PrintElements(arr1, n);
	PrintElements(arr2, n);
	PrintElements(arr3, n);
	std::cout << std::endl;
	std::cout << "Print a range of elements" << std::endl;
	PrintElements(arr2, 1, 3);
	std::cout << std::endl;
}

int GetIndex(int rowIdx, int colIdx, int nrCols)
{
	return rowIdx * nrCols + colIdx;
}

void Print2DMatrix()
{
	const int row{4};
	const int col{5};
	int arr[row * col]{};
	for (int rIdx{}; rIdx < row; ++rIdx)
	{
		for (int cIdx{}; cIdx < col; ++cIdx)
		{
			arr[GetIndex(rIdx, cIdx, col)] = 10 * (rIdx + 1) + cIdx + 1;
		}
	}
	std::cout << "-- 2D arrays --" << std::endl;
	for (int rIdx{}; rIdx < row; ++rIdx)
	{
		for (int cIdx{}; cIdx < col; ++cIdx)
		{
			std::cout << arr[GetIndex(rIdx, cIdx, col)] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
