// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Time.h"

#include <iostream>


void TestArrays();

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	TestArrays();
}

void TestArrays()
{
	const int n{4};
	Time* arr[n]{};
	for (int iTime{}; iTime < n; ++iTime)
	{
		arr[iTime] = new Time{std::rand() % 10000};
	}

	arr[0]->Print();
	arr[0]->AddMinutes(-10);
	arr[0]->Print();
	std::cout << std::endl;

	arr[1]->Print();
	arr[1]->AddSeconds(1);
	arr[1]->AddMinutes(2);
	arr[1]->AddHours(3);
	arr[1]->Print();
	std::cout << std::endl;

	arr[2]->Print();
	arr[2]->AddHours(4);
	arr[2]->Print();
	std::cout << std::endl;

	arr[3]->Print();
	std::cout << arr[3]->GetSeconds() << std::endl;

	for (int iTime{}; iTime < n; ++iTime)
	{
		delete arr[iTime];
	}
}

