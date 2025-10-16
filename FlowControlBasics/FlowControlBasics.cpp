// Knapecz, Adam - 1DAE11

#include "pch.h"
#include "FlowControlBasics.h"
#include "structs.h"

#include <iostream>
#include <string>

int main()
{
	PrintTruthTable();
	CompareTwoNumbers();
	CalculatePrice();
	ConvertDayNumber();
	CheckLeapYear();
	ConvertSeconds();
	UseActorState();
	UsePoint2f();
}

void PrintTruthTable()
{
	bool t{true};
	bool f{false};

	std::cout << std::boolalpha;
	std::cout << "-- Print truth table --" << std::endl;
	std::cout << "Logical binary AND-operator (&&)" << std::endl;
	std::cout << "true && true is " << (t && t) << std::endl;
	std::cout << "true && false is " << (t && f) << std::endl;
	std::cout << "false && true is " << (f && t) << std::endl;
	std::cout << "false && false is " << (f && f) << std::endl;
	std::cout << "Logical binary OR-operator (||)" << std::endl;
	std::cout << "true || true is " << (t || t) << std::endl;
	std::cout << "true || false is " << (t || f) << std::endl;
	std::cout << "false || true is " << (f || t) << std::endl;
	std::cout << "false || false is " << (f || f) << std::endl;
	std::cout << "Logical unary NOT-operator (!)" << std::endl;
	std::cout << "!true is " << (!t) << std::endl;
	std::cout << "!false is " << (!f) << std::endl;
	std::cout << std::endl;
}

void CompareTwoNumbers()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	const int max{10 + 1};
	int a{std::rand() % max};
	int b{std::rand() % max};

	while (a == b)
	{
		b = std::rand() % max;
	}

	std::cout << "-- Compare 2 numbers --" << std::endl;
	std::cout << "First number is " << a << std::endl;
	std::cout << "Second number is " << b << std::endl;

	std::string words[2]{"First", "second"};
	std::string firstWord, secondWord;

	if (a > b)
	{
		firstWord = words[0];
		secondWord = words[1];
	}
	else
	{
		firstWord = words[1];
		firstWord[0] = 'S';
		secondWord = words[0];
		secondWord[0] = 'f';
	}
	std::cout << firstWord << " number is larger than " << secondWord << " one" << std::endl;
	std::cout << std::endl;
}

void CalculatePrice()
{
	int ballpoints{};
	std::cout << "-- Calculate price --" << std::endl;
	std::cout << "Nr of ballpoints? ";
	std::cin >> ballpoints;
	float totalPrice{};
	if (0 <= ballpoints && ballpoints < 20)
	{
		totalPrice = ballpoints * 4.0f;
	}
	else if (20 <= ballpoints && ballpoints <= 49)
	{
		totalPrice = ballpoints * 3.5f;
	}
	else if (50 <= ballpoints && ballpoints <= 100)
	{
		totalPrice = ballpoints * 3.25f;
	}
	else if (101 <= ballpoints)
	{
		totalPrice = ballpoints * 3.1f;
	}
	std::cout << "Total price is " << totalPrice << std::endl;
	std::cout << std::endl;
}

void ConvertDayNumber()
{
	std::cout << "Day number [1, 7] ? ";
	int userInput{};
	std::cin >> userInput;
	/*
	if (1 <= userInput && userInput <= 5)
	{
		// std::cout << "no weekend" << std::endl;
		if (userInput == 1)
		{
			std::cout << "Start of the week" << std::endl;
		}
		else if (2 <= userInput && userInput <= 4)
		{
			std::cout << "Middle of the week" << std::endl;
		}
		else if (userInput == 5)
		{
			std::cout << "Nearly weekend" << std::endl;
		}
	}
	else if (6 <= userInput && userInput <= 7)
	{
		// std::cout << "weekend" << std::endl;
		std::cout << "Weekend" << std::endl;
	}
	else
	{
		std::cout << "Wrong day number" << std::endl;
	}
	*/

	switch (userInput)
	{
	case 1:
		std::cout << "Monday" << std::endl;
		break;
	case 2:
		std::cout << "Tuesday" << std::endl;
		break;
	case 3:
		std::cout << "Wednesday" << std::endl;
		break;
	case 4:
		std::cout << "Thursday" << std::endl;
		break;
	case 5:
		std::cout << "Friday" << std::endl;
		break;
	case 6:
		std::cout << "Saturday" << std::endl;
		break;
	case 7:
		std::cout << "Sunday" << std::endl;
		break;
	default:
		std::cout << "Wrong day number" << std::endl;
		break;
	}
	std::cout << std::endl;
}

void CheckLeapYear()
{
	std::cout << "-- Check leap year --" << std::endl;
	int userInput{};
	std::cout << "Year ? ";
	std::cin >> userInput;
	int daysInFebruary{28};
	if (userInput % 4 == 0)
	{
		if (userInput % 100 == 0)
		{
			if (userInput % 400 == 0)
			{
				daysInFebruary = 29;
			}
		}
		else
		{
			daysInFebruary = 29;
		}
	}
	std::cout << userInput << ": " << daysInFebruary << std::endl;
	std::cout << std::endl;
}

void ConvertSeconds()
{
	std::cout << "-- Convert seconds --" << std::endl;
	std::cout << "Number of seconds? ";
	int userInput;
	std::cin >> userInput;
	const int second{1};
	const int second2minute{second * 60};
	const int second2hour{second2minute * 60};
	const int second2day{second2hour * 24};

	if (userInput < 0)
	{
		userInput = 0;
	}

	const int days{userInput / second2day};
	const int hours{userInput % second2day / second2hour};
	const int minutes{userInput % second2day % second2hour / second2minute};
	const int seconds{userInput % second2day % second2hour % second2minute};

	std::cout << days << " days" << std::endl;
	std::cout << hours << " hours" << std::endl;
	std::cout << minutes << " minutes" << std::endl;
	std::cout << seconds << " seconds" << std::endl;
	std::cout << std::endl;
}

enum class ActorState
{
	running,
	flying,
	falling
};

void UseActorState()
{
	std::cout << "-- Define and use ActorState --" << std::endl;
	ActorState aState{ActorState::running};
	switch (aState)
	{
	case ActorState::running:
		std::cout << "running" << std::endl;
		break;
	case ActorState::flying:
		std::cout << "flying" << std::endl;
		break;
	case ActorState::falling:
		std::cout << "falling" << std::endl;
		break;
	}
	std::cout << std::endl;

	std::cout << "-- Define and use ActorState --" << std::endl;
	aState = static_cast<ActorState>(rand() % 3);
	switch (aState)
	{
	case ActorState::running:
		std::cout << "running" << std::endl;
		break;
	case ActorState::flying:
		std::cout << "flying" << std::endl;
		break;
	case ActorState::falling:
		std::cout << "falling" << std::endl;
		break;
	}
	std::cout << std::endl;
}

void UsePoint2f()
{
	Point2f p1;
	Point2f p2{};
	Point2f p3{26, 25};

	std::cout << "-- Define and use Point2f --" << std::endl;
	std::cout << "Values after definition" << std::endl;
	std::cout << "p1: [" << p1.x << ", " << p1.y << "]" << std::endl;
	std::cout << "p2: [" << p2.x << ", " << p2.y << "]" << std::endl;
	std::cout << "p3: [" << p3.x << ", " << p3.y << "]" << std::endl;

	p1.x = 20;
	p1.y = 3;
	p2 = Point2f{30, 40};
	++p3.x;
	++p3.y;

	std::cout << "Values after changing the members" << std::endl;
	std::cout << "p1: [" << p1.x << ", " << p1.y << "]" << std::endl;
	std::cout << "p2: [" << p2.x << ", " << p2.y << "]" << std::endl;
	std::cout << "p3: [" << p3.x << ", " << p3.y << "]" << std::endl;
}

