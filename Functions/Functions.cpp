// Knapecz, Adam - 1DAE11
#include "pch.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

void ShowData();
void ShowStudentHistory();
void Quit();

void TestOneParFunctions();
void TestTwoParFunctions();

void ShowData()
{
	// 1. Show my data
	std::cout << "My name is Knapecz, Adam" << std::endl;
	std::cout << "I am in group 1DAE11" << std::endl << std::endl;
}

void ShowStudentHistory()
{
	// 2. Show my student history
	std::cout << "Name of my high school: Budapesti Egyetetemi Katolikus Gimnázium és Kollégium" << std::endl;
	std::cout << "In the last year I had 5 hours math a week" << std::endl << std::endl;
}

void Quit()
{
	// Wait
	std::cout << "Push ENTER to quit" << std::endl;
	std::cin.get();
}

// c. EXERCISES: Math functions
void TestOneParFunctions()
{
	std::cos(55.0 * M_PI / 180);

	// 0
	double angle{};
	std::cout << "Angle: " << angle << std::endl;
	std::cout << "  cos: " << std::cos(angle) << std::endl;

	// 1 * pi / 4
	angle += M_PI / 4;
	std::cout << "Angle: " << angle << std::endl;
	std::cout << "  cos: " << std::cos(angle) << std::endl;

	// 2 * pi / 4
	angle += M_PI / 4;
	std::cout << "Angle: " << angle << std::endl;
	std::cout << "  cos: " << std::cos(angle) << std::endl;

	// 3 * pi / 4
	angle += M_PI / 4;
	std::cout << "Angle: " << angle << std::endl;
	std::cout << "  cos: " << std::cos(angle) << std::endl;

	// pi
	angle += M_PI / 4;
	std::cout << "Angle: " << angle << std::endl;
	std::cout << "  cos: " << std::cos(angle) << std::endl << std::endl;;

	const double pi = 3.1415926535;
}

void TestTwoParFunctions()
{
	// pow
	int base = 2;
	int exponent = 8;
	double result = std::pow(base, exponent);
	std::cout << "pow(2, 8) is: " << result << std::endl << std::endl;

	// Pythagoras Theorem
	double a = 3;
	double b = 4;
	double c = std::sqrt(std::pow(a, 2) + std::pow(b, 2));
	std::cout << "Value of hypotenuse: " << c << std::endl << std::endl;
}


int main()
{
	ShowData();
	ShowStudentHistory();

	TestOneParFunctions();
	TestTwoParFunctions();

	Quit();
	return 0;
}
