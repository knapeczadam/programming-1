// Knapecz, Adam - 1DAE11
#include "pch.h"

#include <chrono>
#include <iomanip>
#include <iostream>

#include "structs.h"

void Sum(int a, int b);
void Print(int value, char delimiter);
// void Print(unsigned int value, char delimiter);
void Print(char value, char delimiter);
void Print(float value, char delimiter);
int Multiply(int a, int b);
int Modulo(int dividend, int divisor);
void PrintNumbers(int min, int max);
void CalcElapsedTime(int min, int max);
void PrintMessage(int indentation = 0);
bool IsEven(int n);
bool IsLeapYear();
int GetRand(int min, int max);
float GetRand(float min, float max);
float GetDistance(const Point2f& p1, const Point2f& p2);
float GetDistance(float x1, float y1, float x2, float y2);


void TestSum();
void TestPrint();
void TestMultiply();
void TestModulo();
void TestPrintNumbers();
void TestCalcElapsedTime();
void TestPrintMessage();
void TestIsEven();
void TestIsLeapYear();
void TestGetIntRand();
void TestGetFloatRand();
void TestGetDistance();

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	TestSum();
	TestPrint();
	TestMultiply();
	TestModulo();
	TestPrintNumbers();
	TestCalcElapsedTime();
	TestPrintMessage();
	TestIsEven();
	TestIsLeapYear();
	TestGetIntRand();
	TestGetFloatRand();
	TestGetDistance();
}

void Sum(int a, int b)
{
	int sum{a + b};
	std::cout << a << " + " << b << " = " << sum << std::endl;
	std::cout << std::endl;
}

void Print(char value, char delimiter)
{
	std::cout << value << delimiter << std::endl;
}

// void Print(unsigned int value, char delimiter)
void Print(int value, char delimiter)
{
	std::cout << value << delimiter << std::endl;
}

void Print(float value, char delimiter)
{
	std::cout << value << delimiter << std::endl;
}

int Multiply(int a, int b)
{
	return a * b;
}

int Modulo(int dividend, int divisor)
{
	int q{dividend / divisor};
	int m{dividend - q * divisor};
	return m;
}

void PrintNumbers(int min, int max)
{
	for (int i{min}; i <= max; ++i)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;
}

void CalcElapsedTime(int min, int max)
{
	auto startTime{std::chrono::steady_clock::now()};
	PrintNumbers(min, max);
	auto endTime{std::chrono::steady_clock::now()};
	std::chrono::duration<float, std::milli> elapsedTime{endTime - startTime};
	std::cout << "This print task took " << elapsedTime.count() << " milliseconds" << std::endl;
}

void PrintMessage(int indentation)
{
	if (indentation == 0)
	{
		std::cout << "No indentation specified" << std::endl;
		return;
	}
	std::cout << std::setw(indentation);
	std::cout << indentation << " spaces indentation specified" << std::endl;
}

bool IsEven(int n)
{
	return n % 2 == 0;
}

bool IsLeapYear(int year)
{
	bool isLeap{false};
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				isLeap = true;
			}
		}
		else
		{
			isLeap = true;
		}
	}
	return isLeap;
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

float GetDistance(const Point2f& p1, const Point2f& p2)
{
	return std::sqrtf(std::powf(p1.x - p2.x, 2) + std::powf(p1.y - p2.y, 2));
}

float GetDistance(float x1, float y1, float x2, float y2)
{
	return std::sqrtf(std::powf(x1 - x2, 2) + std::powf(y1 - y2, 2));
}

// TEST FUNCTIONS

void TestSum()
{
	Sum(1, 2);
}

void TestPrint()
{
	Print('a', ',');
	Print(20, ',');
	Print(20.0f, ',');
}

void TestMultiply()
{
	std::cout << "-- Function that calculates the product of 2 integers --" << std::endl;
	std::cout << "2 numbers to multiply? ";
	int a{}, b{}, c{}, d{};
	std::cin >> a >> b;
	std::cout << a << " * " << b << " = " << Multiply(a, b) << std::endl;
	std::cout << "4 numbers to multiply? ";
	std::cin >> a >> b >> c >> d;
	std::cout << a << " * " << b << " * " << c << " * " << d << " = " << Multiply(a, Multiply(b, Multiply(c, d))) <<
		std::endl;;
	std::cout << std::endl;
}

void TestModulo()
{
	std::cout << "-- Function that prints the remainder of a given number --" << std::endl;
	const int divisor{4};
	for (int dividend{0}; dividend < 15; ++dividend)
	{
		std::cout << dividend << " % " << divisor << " is " << Modulo(dividend, divisor) << std::endl;
	}
	std::cout << std::endl;
}

void TestPrintNumbers()
{
	std::cout << "-- Function that prints the integers in a given interval --" << std::endl;
	int min{10}, max{20};
	std::cout << "Interval [" << min << ", " << max << ']' << std::endl;
	PrintNumbers(min, max);

	min = 90;
	max = 115;
	std::cout << "Interval [" << min << ", " << max << ']' << std::endl;
	PrintNumbers(min, max);
	std::cout << std::endl;
}

void TestCalcElapsedTime()
{
	std::cout << "-- Function that counts the time of a printing task --" << std::endl;
	int min{0}, max{30};
	std::cout << "Interval [" << min << ", " << max << ']' << std::endl;
	CalcElapsedTime(min, max);

	min = 90;
	max = 115;
	std::cout << "Interval [" << min << ", " << max << ']' << std::endl;
	CalcElapsedTime(min, max);
	std::cout << std::endl;
}

void TestPrintMessage()
{
	std::cout << "-- Function that prints an indented message --" << std::endl;
	PrintMessage();
	PrintMessage(2);
	PrintMessage(4);
	std::cout << std::endl;
}

void TestIsEven()
{
	std::cout << "-- Function that checks whether a number is even --" << std::endl;
	const int arr[]{41, 18467, 6334, 26500, 19169};
	for (const int& e : arr)
	{
		std::cout << e << " is " << (IsEven(e) ? "even" : "odd") << std::endl;
	}
	std::cout << std::endl;
}

void TestIsLeapYear()
{
	std::cout << "-- Function that checks whether year is leap --" << std::endl;
	int userInput{};
	while (true)
	{
		std::cout << "Year ? ";
		std::cin >> userInput;
		if (userInput == -1)
		{
			break;
		}
		std::cout << userInput << " has " << (IsLeapYear(userInput) ? 29 : 28) << " days in February" << std::endl;
	}
}

void TestGetIntRand()
{
	std::cout << "-- Function that generates a random number in a given integer interval --" << std::endl;
	int min{1}, max{6};
	std::cout << "In [" << min << ", " << max << "] " << GetRand(min, max) << std::endl;
	min = 10;
	max = 20;
	std::cout << "In [" << min << ", " << max << "] " << GetRand(min, max) << std::endl;
	min = -5;
	max = 0;
	std::cout << "In [" << min << ", " << max << "] " << GetRand(min, max) << std::endl;
	std::cout << std::endl;
}

void TestGetFloatRand()
{
	std::cout << "-- Function that generates a random number in a given float interval --" << std::endl;
	float min{0}, max{3.14159f};
	std::cout << "In [" << min << ", " << max << "] " << GetRand(min, max) << std::endl;
	min = -2;
	max = 3;
	std::cout << "In [" << min << ", " << max << "] " << GetRand(min, max) << std::endl;
	std::cout << std::endl;
}

void TestGetDistance()
{
	std::cout << "-- Function that calculates distance between 2 points --" << std::endl;
	Point2f p1{ GetRand(0.0f, 200.0f), GetRand(100.0f, 200.0f) };
	Point2f p2{ GetRand(50.0f, 200.0f), GetRand(150.0f, 400.0f) };
	std::cout << "Distance between [" << p1.x << ", " << p1.y << "] and [" << p2.x << ", " << p2.y << "]" << std::endl;
	std::cout << "Calling one version: " << GetDistance(p1, p2) << std::endl;
	std::cout << "Calling the other version: " << GetDistance(p1.x, p1.y, p2.x, p2.y) << std::endl;

	std::cout << std::endl;
	p1 = Point2f{ GetRand(-100.0f, 50.0f), GetRand(400.0f, 1000.0f) };
	p2 = Point2f{ GetRand(50.0f, 200.0f), GetRand(300.0f, 600.0f) };
	std::cout << "Distance between [" << p1.x << ", " << p1.y << "] and [" << p2.x << ", " << p2.y << "]" << std::endl;
	std::cout << "Calling one version: " << GetDistance(p1, p2) << std::endl;
	std::cout << "Calling the other version: " << GetDistance(p1.x, p1.y, p2.x, p2.y) << std::endl;
	std::cout << std::endl;
}
