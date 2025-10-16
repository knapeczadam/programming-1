// Knapecz, Adam - 1DAE11
#include "pch.h"
#include <iostream>
#include <string>

void UseModuloOperatorExample();
void UseRandFuncExamples();
void GetCharacterFromUser();
void GenerateRandomLetter();
void CastFloats();
void CalculateAspectRatio();
void TestPrefixPostfix();
void ExploreStrings();
void ConvertNumberToString();
void ConvertStringToNumber();

void UseModuloOperatorExample()
{
	// % operator
	std::cout << "Please type an integer: ";
	int userInput{};
	std::cin >> userInput;
	std::cout << "Even (0) / Odd (1): " << userInput % 2 << std::endl;
	std::cout << std::endl;
}

void UseRandFuncExamples()
{
	// rand function
	std::cout << std::rand() << std::endl;

	// % operator + random number
	// [0, 50]
	std::cout << std::rand() % 51 << std::endl;

	//[10, 80]
	std::cout << std::rand() % 71 + 10 << std::endl;

	// [-20, +20]
	std::cout << std::rand() % 41 - 20 << std::endl;

	// [-2, +2]
	std::cout << std::rand() % 5 - 2 << std::endl;

	// [-5.00, 10.00]
	std::cout << std::rand() % 51 + 50 / 100.0f << std::endl;

	// [-5.00, +5.00]
	std::cout << std::rand() % 101 - 50 / 100.0f << std::endl;
	std::cout << std::endl;
}

void GetCharacterFromUser()
{
	unsigned char userCharacter{};
	std::cout << "Letter? ";
	std::cin >> userCharacter;
	std::cout << "Letter " << userCharacter << ", ASCII value " << static_cast<unsigned int>(userCharacter) <<
		std::endl;
	std::cout << std::endl;
}

void GenerateRandomLetter()
{
	unsigned char randomLetter = std::rand() % 26 + 97;
	std::cout << "Random letter " << randomLetter << ", ASCII value " << static_cast<int>(randomLetter) << std::endl;
	std::cout << std::endl;
}

void CastFloats()
{
	float f1{5.44f};
	float f2{5.45f};
	float f3{5.51f};

	int i1 = static_cast<int>(f1);
	int i2 = static_cast<int>(f2);
	int i3 = static_cast<int>(f3);

	std::cout << f1 << ", rounded: " << std::roundf(f1) << ", int cast: " << i1 << std::endl;
	std::cout << f2 << ", rounded: " << std::roundf(f2) << ", int cast: " << i2 << std::endl;
	std::cout << f3 << ", rounded: " << std::roundf(f3) << ", int cast: " << i3 << std::endl;
	std::cout << std::endl;
}

void CalculateAspectRatio()
{
	std::cout << "The aspect ratio of full HD (1920 x 1080) is: " << 1920.0f / 1080 << std::endl;
	std::cout << std::endl;
}

void TestPrefixPostfix()
{
	int i{10};
	int j{++i};
	std::cout << "i: " << i << ", j: " << j << std::endl;

	int k{10};
	int l{k++};
	std::cout << "k: " << k << ", l: " << l << std::endl;
	std::cout << std::endl;
}

void ExploreStrings()
{
	std::string s;
	std::cout << s << std::endl;
	std::string sentence{"I am a string literal"};
	std::cout << sentence << std::endl;
	sentence = "nope";
	std::cout << sentence << std::endl << std::endl;
	std::cout << "Please enter a word without using space: ";
	std::cin >> s;
	std::cout << "The user entered: " << s << std::endl;
	std::cout << std::endl;
	std::string firstWord;
	std::string secondWord;
	std::cout << "First word? ";
	std::cin >> firstWord;
	std::cout << "Second word? ";
	std::cin >> secondWord;
	std::cout << firstWord + secondWord << std::endl;

	// string-character combinations
	s += "this is a string literal";
	char c = 'A';
	s += c;
	std::string s2 = "More powerful than yo" + 'u';

	std::cout << std::endl;
}

void ConvertNumberToString()
{
	std::string numbersLog;
	int enteredNr{};
	std::cout << "Enter an integer value: ";
	std::cin >> enteredNr;
	numbersLog += std::to_string(enteredNr) + ' ';
	std::cout << "Enter an integer value: ";
	std::cin >> enteredNr;
	numbersLog += std::to_string(enteredNr) + ' ';
	std::cout << "Enter an integer value: ";
	std::cin >> enteredNr;
	numbersLog += std::to_string(enteredNr);
	std::cout << "Log of entered numbers : " << numbersLog << std::endl;
	std::cout << std::endl;
}

void ConvertStringToNumber()
{
	std::string s1{"3"};
	std::string s2{"3.1415"};
	std::cout << "One string contains " << s1 << std::endl;
	std::cout << "Other string contains " << s2 << std::endl;
	std::cout << "Adding strings " << s1 + s2 << std::endl;
	std::cout << "Adding numbers " << std::stoi(s1) + std::stod(s2) << std::endl;
	std::cout << std::endl;
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	UseModuloOperatorExample();
	UseRandFuncExamples();
	GetCharacterFromUser();
	GenerateRandomLetter();
	CastFloats();
	CalculateAspectRatio();
	TestPrefixPostfix();
	ExploreStrings();
	ConvertNumberToString();
	ConvertStringToNumber();
}
