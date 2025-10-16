// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Square.h"
#include "Time.h"

#include <iomanip>
#include <iostream>

void DoSquareTests();
void TestSquare(Square* pSquare);

void DoTimeTests();

int main()
{
	DoSquareTests();
	DoTimeTests();
}

void DoSquareTests()
{
	std::cout << std::fixed << std::setprecision(2);
	Square* pSq3{new Square(4.0f)};
	std::cout << pSq3 << std::endl;
	delete pSq3;
	pSq3 = nullptr;
	std::cout << pSq3 << std::endl;
	std::cout << std::endl;

	Square s{3.0f, 10.0f, 20.0f};
	s.Print();
	s.SetSize(5.0f);
	s.Print();
	s.Translate(1.5f, -5.0f);
	s.Print();

	Square* pSq4{new Square{5.0f}};
	TestSquare(pSq4);
	pSq4->Print();
	delete pSq4;
	pSq4 = nullptr;
}

void TestSquare(Square* pSquare)
{
	pSquare->Translate(10.0f, 20.0f);
}

void DoTimeTests()
{
	Time* pT1{new Time{66}};
	pT1->Print();
	pT1->AddSeconds(120);
	pT1->Print();
	pT1->AddMinutes(59);
	pT1->Print();
	pT1->AddHours(25);
	pT1->Print();
	delete pT1;
	pT1 = nullptr;
	std::cout << std::endl;

	Time* pt2{new Time{99, 99}};
	pt2->Print();
	std::cout << pt2->GetHours() << std::endl;
	std::cout << pt2->GetMinutes() << std::endl;
	std::cout << pt2->GetSeconds() << std::endl;
	delete pt2;
	pt2 = nullptr;
	std::cout << std::endl;

	Time* pt3{new Time{1, 60, 3600}};
	pt3->Print();
	delete pt3;
	pt3 = nullptr;
}

