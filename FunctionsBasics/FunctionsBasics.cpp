// Knapecz, Adam - 1DAE11
#include "pch.h"

#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
#include <iostream>

void Print(char value, char delimiter = ' ');
void CalcCosSin(float angle, float& cos, float& sin);
float GetRand(float min, float max);

void TestPrint();
void TestCalcCosSin();

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	TestPrint();
	TestCalcCosSin();
}

void Print(char value, char delimiter)
{
	std::cout << value << delimiter << std::endl;
}

void CalcCosSin(float angle, float& cos, float& sin)
{
	cos = std::cosf(angle);
	sin = std::sinf(angle);
}

float GetRand(float min, float max)
{
	min *= 100;
	max *= 100;
	if (min < 0)
	{
		max += -min;
	}
	else if (min > 0)
	{
		max -= min;
	}
	return (std::rand() % int((max + 1)) + min) / 100;
}

void TestPrint()
{
	Print('5');
}

void TestCalcCosSin()
{
	std::cout << "-- Function that calculates cosine and sine --" << std::endl;
	std::cout << std::setw(10) << "Radians" << std::setw(10) << "Cos" << std::setw(10) << "Sin" << std::endl;
	std::cout << std::fixed << std::setprecision(2);
	for (int i{0}; i < 10; ++i)
	{
		const float angle{GetRand(0, 2 * float(M_PI))};
		float cos{};
		float sin{};
		CalcCosSin(angle, cos, sin);
		std::cout << std::setw(10) << angle << std::setw(10) << cos << std::setw(10) << sin << std::endl;
	}
}
