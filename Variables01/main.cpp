// Knapecz, Adam - 1DAE11

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>

template <typename T>
void PrintLine(const T& value)
{
	std::cout << '(' << value << ')' << '\n';
}

template <typename First, typename... Rest>
void PrintLine(const First& firstValue, const Rest&... rest)
{
	PrintLine(firstValue);
	PrintLine(rest...);
}

template <typename T>
void AskUser(T& value, const char* subString, const std::string& indefiniteArt = "a")
{
	std::string userInput{};
	std::stringstream ss{};
	while (true)
	{
		std::cout << "Please enter " << indefiniteArt << " " << subString << " value:";
		std::getline(std::cin, userInput);
		ss << userInput;
		ss >> value;
		if (!ss.fail())
		{
			break;
		}
		ss.clear();
		ss.str(std::string{});
	}
	std::cout << "-> The " << subString << " that was entered by the user is " << value << '.' << '\n' << '\n';
}

int main()
{
	// 4.1.3. 
	// a. Defining variables without initialization
	int deadPlayerCount;
	char deadlyCharacter;
	bool isDead;
	float myPie;
	double myDoublePie;
	//PrintLine(deadPlayerCount, deadlyCharacter, isDead, myPie, myDoublePie);

	// b. Defining with default initialization
	int defaultInteger{};
	char defaultCharacter{};
	bool defaultBoolean{};
	float defaultSinglePrecisionFloatingPNumber{};
	double defaultDoublePrecisionFloatingPNumber{};
	PrintLine(defaultInteger, defaultCharacter, defaultBoolean, defaultSinglePrecisionFloatingPNumber, defaultDoublePrecisionFloatingPNumber);
	std::cout << '\n';

	// c. Defining with literal constants initialization 
	int integer{42};
	char character{'c'};
	bool boolean{true};
	float singlePrecisionFloatingPNumber{3.14f};
	double doublePrecisionFloatingPNumber{3.14};
	PrintLine(integer, character, boolean, singlePrecisionFloatingPNumber, doublePrecisionFloatingPNumber);
	std::cout << '\n';

	// d. Assigning a literal constant using the assignment operator 
	integer = 99;
	character = 'f';
	boolean = true;
	singlePrecisionFloatingPNumber = 1.23f;
	doublePrecisionFloatingPNumber = 4.56;
	PrintLine(integer, character, boolean, singlePrecisionFloatingPNumber, doublePrecisionFloatingPNumber);
	std::cout << '\n';

	// e. Assigning a user value using the “get from” (>>) operator 
	AskUser(integer, "integer", "an");
	AskUser(character,"character");
	AskUser(boolean, "boolean");
	AskUser(singlePrecisionFloatingPNumber,  "float");
	AskUser(doublePrecisionFloatingPNumber,  "double");
}

