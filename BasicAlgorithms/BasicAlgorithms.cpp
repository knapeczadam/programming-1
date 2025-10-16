// Knapecz, Adam - 1DAE11
#include "pch.h"
#include <iostream>

int Count(int* arr, int n, int c);
int MinElement(int* arr, int n);
int MaxElement(int* arr, int n);
void Swap(int* arr, int idx1, int idx2);
void Shuffle(int* arr, int n, int swaps);
void BubbleSort(int* arr, int n);
int GetRand(int min, int max);
void PrintElements(int* arr, int n);
void InitArray(int* arr, int n);

void TestCount();
void TestMinMax();
void TestSwap();
void TestShuffle();
void TestBubbleSort();

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	TestCount();
	TestMinMax();
	TestSwap();
	TestShuffle();
	TestBubbleSort();
}

int GetRand(int min, int max)
{
	if (min < 0)
	{
		max += -min;
	}
	else if (min > 0)
	{
		max -= min;
	}
	return std::rand() % (max + 1) + min;
}

void PrintElements(int* arr, int n)
{
	for (int idx{0}; idx < n; ++idx)
	{
		std::cout << arr[idx] << ' ';
	}
	std::cout << std::endl;
}

void InitArray(int* arr, int n)
{
	for (int idx{0}; idx < n; ++idx)
	{
		arr[idx] = GetRand(-10, 10);
	}
}

int Count(int* arr, int n, int c)
{
	int count{};
	for (int idx{0}; idx < n; ++idx)
	{
		if (arr[idx] == c)
		{
			++count;
		}
	}
	return count;
}

int MinElement(int* arr, int n)
{
	if (n == 0)
	{
		return 0;
	}
	int min{arr[0]};
	for (int idx{1}; idx < n; ++idx)
	{
		if (arr[idx] < min)
		{
			min = arr[idx];
		}
	}
	return min;
}

int MaxElement(int* arr, int n)
{
	if (n == 0)
	{
		return 0;
	}
	int max{arr[0]};
	for (int idx{1}; idx < n; ++idx)
	{
		if (arr[idx] > max)
		{
			max = arr[idx];
		}
	}
	return max;
}

void Swap(int* arr, int idx1, int idx2)
{
	arr[idx1] += arr[idx2];
	arr[idx2] = arr[idx1] - arr[idx2];
	arr[idx1] -= arr[idx2];
}

void Shuffle(int* arr, int n, int swaps)
{
	for (int idx{0}; idx < swaps; ++idx)
	{
		int idx1{GetRand(0, n - 1)};
		int idx2{GetRand(0, n - 1)};
		while (idx1 == idx2)
		{
			idx2 = GetRand(0, n - 1);
		}
		Swap(arr, idx1, idx2);
	}
}

void BubbleSort(int* arr, int n)
{
	for (int i{0}; i < n - 1; ++i)
	{
		for (int j{i + 1}; j < n; ++j)
		{
			if (arr[j] < arr[i])
			{
				Swap(arr, i, j);
			}
		}
	}
}

void TestCount()
{
	std::cout << "-- Test of Count function --" << std::endl;
	const int n1{10};
	int arr1[n1]{};
	InitArray(arr1, n1);
	PrintElements(arr1, n1);
	int c{2};
	std::cout << c << " occurs " << Count(arr1, n1, c) << " times in this array" << std::endl;
	std::cout << std::endl;

	const int n2{20};
	int arr2[n2]{};
	InitArray(arr2, n2);
	PrintElements(arr2, n2);
	c = 1;
	std::cout << c << " occurs " << Count(arr2, n2, c) << " times in this array" << std::endl;
	std::cout << std::endl;
}

void TestMinMax()
{
	std::cout << "-- Test of MinElement and MaxElement functions --" << std::endl;
	const int n1{10};
	int arr1[n1]{};
	InitArray(arr1, n1);
	PrintElements(arr1, n1);
	std::cout << MinElement(arr1, n1) << " is the smallest value in this array" << std::endl;
	std::cout << MaxElement(arr1, n1) << " is the largest value in this array" << std::endl;
	std::cout << std::endl;

	const int n2{20};
	int arr2[n2]{};
	InitArray(arr2, n2);
	PrintElements(arr2, n2);
	std::cout << MinElement(arr2, n2) << " is the smallest value in this array" << std::endl;
	std::cout << MaxElement(arr2, n2) << " is the largest value in this array" << std::endl;
	std::cout << std::endl;
}

void TestSwap()
{
	std::cout << "-- Test of Swap function --" << std::endl;
	std::cout << "Before swapping" << std::endl;
	const int n1{10};
	int arr1[n1]{};
	InitArray(arr1, n1);
	PrintElements(arr1, n1);
	std::cout << "After swapping the first and last element" << std::endl;
	Swap(arr1, 0, n1 - 1);
	PrintElements(arr1, n1);
	std::cout << std::endl;

	const int n2{20};
	int arr2[n2]{};
	InitArray(arr2, n2);
	std::cout << "Before swapping" << std::endl;
	PrintElements(arr2, n2);
	std::cout << "After swapping the second and last element" << std::endl;
	Swap(arr2, 1, n2 - 1);
	PrintElements(arr2, n2);
	std::cout << std::endl;
}

void TestShuffle()
{
	std::cout << "-- Test of Shuffle function --" << std::endl;
	std::cout << "Before shuffling" << std::endl;
	const int n1{10};
	int arr1[n1]{};
	InitArray(arr1, n1);
	PrintElements(arr1, n1);
	int swaps{10};
	std::cout << "After shuffling " << swaps << " times" << std::endl;
	Shuffle(arr1, n1, swaps);
	PrintElements(arr1, n1);
	std::cout << std::endl;

	const int n2{20};
	int arr2[n2]{};
	InitArray(arr2, n2);
	PrintElements(arr2, n2);
	swaps = 20;
	std::cout << "After shuffling " << swaps << " times" << std::endl;
	Shuffle(arr2, n2, swaps);
	PrintElements(arr2, n2);
	std::cout << std::endl;
	std::cout << std::endl;
}

void TestBubbleSort()
{
	std::cout << "-- Test of BubbleSort function --" << std::endl;
	const int n1{10};
	int arr1[n1]{};
	InitArray(arr1, n1);
	std::cout << "Before sort" << std::endl;
	PrintElements(arr1, n1);
	BubbleSort(arr1, n1);
	std::cout << "After sort" << std::endl;
	PrintElements(arr1, n1);
	std::cout << std::endl;

	const int n2{20};
	int arr2[n2]{};
	InitArray(arr2, n2);
	std::cout << "Before sort" << std::endl;
	PrintElements(arr2, n2);
	BubbleSort(arr2, n2);
	std::cout << "After sort" << std::endl;
	PrintElements(arr2, n2);
}
