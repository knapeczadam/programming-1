// Knapecz, Adam - 1DAE11

#include "pch.h"
#include <iostream>

int main()
{
	int integer{ 42 };
	float singlePrecisionFloatingPNumber{ 3.14f };
	char character{ 'c' };

	//	4.2.1. Binary operators +, - 	
	integer = 3 + 2;
	character = 'c' - 2;
	std::cout << integer << ' ' << character << '\n';

	int heaven = 999;
	integer = heaven + 42;
	float myPi = 3.14f;
	float result = myPi + 3.14f;
	char first = 'a';
	char unknown = first + 'b';
	auto whoKnows = heaven + myPi + unknown;

	// 4.2.2. Binary operators *, /  
	integer = 4 / 2;
	integer = heaven * 666;
	myPi = whoKnows / 2.0f;
	auto chaos = heaven / unknown * myPi / 2.71;

	// 4.2.3. Compound expressions 
	double theEnd = heaven * myPi / (first - unknown) + chaos;

	// 4.2.4. Compound assignment and Unary operators 
	integer += 44;
	singlePrecisionFloatingPNumber += 3.14f;
	character += 2 + integer;

	++character;
	++integer;

	integer += ++integer;
}
