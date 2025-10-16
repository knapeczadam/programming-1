// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "IterationBasics.h"

#define  _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

int main()
{
	EvenNumbers();
	ExamScores();
	RandomGuess();
	Trigonometry();
	ASCIITable();
}

void EvenNumbers()
{
	std::cout << "-- Even numbers --" << std::endl;
	const int numRow{ 3 };
	const int numCol{ 12 };
	for (int i{}; i < numRow; ++i)
	{
		for (int j{1}; j <= numCol; ++j)
		{
			std::cout << j * 2 << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void ExamScores()
{
	std::cout << "-- Exam scores --" << std::endl;
	std::string userInput;
	std::vector<int> scores{};
	int totalScore{};
	const int exit{ -1 };
	const int minScore{};
	const int maxScore{ 20 };

	do
	{
		std::cout << "Score [0,20] ? ";
		std::cin >> userInput;
		int score{std::stoi(userInput)};
		if (minScore <= score && score <= maxScore)
		{
			totalScore += score;
			scores.push_back(score);
		}
		else if (score != exit)
		{
			std::cout << "Wrong score!" << std::endl;
		}
	}
	while (std::stoi(userInput) != exit);

	std::vector<std::pair<std::string, int>> dict{
		{"A+", 0}, {"A", 0}, {"B", 0}, {"C", 0}, {"D", 0}, {"E", 0}, {"FX", 0}, {"F", 0}
	};

	for (const int& score : scores)
	{
		if (18 <= score && score <= 20)
		{
			dict[0].second++;
		}
		else if (16 <= score && score <= 17)
		{
			dict[1].second++;
		}
		else if (score == 15)
		{
			dict[2].second++;
		}
		else if (13 <= score && score <= 14)
		{
			dict[3].second++;
		}
		else if (11 <= score && score <= 12)
		{
			dict[4].second++;
		}
		else if (score == 10)
		{
			dict[5].second++;
		}
		else if (8 <= score && score <= 9)
		{
			dict[6].second++;
		}
		else
		{
			dict[7].second++;
		}
	}

	for (const auto& pair : dict)
	{
		std::cout << pair.first << ": " << pair.second << std::endl;
	}

	std::cout << "Total score: " << totalScore << std::endl;
	std::cout << "Entered scores: ";

	for (size_t i{}; i < scores.size(); ++i)
	{
		std::cout << scores[i];
		if (i < scores.size() - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

void RandomGuess()
{
	std::cout << "-- Guess number --" << std::endl;
	std::cout << "Number to guess ? ";

	std::string userInput;
	std::cin >> userInput;

	int numberToGuess{};
	int numOfGuesses{};
	int generatedNum{};
	bool inRandRange = false;

	do
	{
		inRandRange = 0 <= (numberToGuess = std::stoi(userInput)) && numberToGuess <= RAND_MAX;
		if (!inRandRange)
		{
			std::cout << "This is a wrong number, number to guess ?";
			std::cin >> userInput;
			continue;
		}
		generatedNum = rand();
		++numOfGuesses;
	}
	while (!inRandRange || generatedNum != numberToGuess);

	std::cout << "Number found after " << numOfGuesses << " guesses" << std::endl;
	std::cout << std::endl;
}

void Trigonometry()
{
	std::cout << "-- Trigonometry --" << std::endl;
	std::cout << std::setw(10) << "Degrees";
	std::cout << std::setw(10) << "Radians";
	std::cout << std::setw(10) << "Cos";
	std::cout << std::setw(10) << "Sin" << std::endl;

	const float pi{3.141592f};
	const float D2R{float(3.14f) / 180};
	const float steps{10.0f};
	const int numDegrees{ 19 };
	const int width{ 10 };

	for (int i{}; i < numDegrees; ++i)
	{
		const float angleDeg{i * steps};
		const float rad{angleDeg * D2R};
		const float c{std::cosf(rad)};
		const float s{std::sinf(rad)};
		std::cout << std::fixed << std::setprecision(0) << std::setw(width) << angleDeg;
		std::cout << std::setw(width) << std::fixed << std::setprecision(2) << rad;
		std::cout << std::setw(width) << c;
		std::cout << std::setw(width) << s << std::endl;
	}
	std::cout << std::endl;
}

void ASCIITable()
{
	std::cout << "-- ASCII table --" << std::endl;
	const int numOfLetters{26};
	const int numCol{2};
	const int offset{97};
	const int width{ 8 };
	for (int i{}; i < numOfLetters / numCol; ++i)
	{
		const int firstColChar{i + offset};
		const int secondColChar{i + offset + numOfLetters / 2};
		std::cout << ' ' << char(firstColChar) << std::setw(width) << firstColChar;
		std::cout << std::setw(4) << char(secondColChar) << std::setw(width) << secondColChar << std::endl;
	}
}

