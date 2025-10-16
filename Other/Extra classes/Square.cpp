// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Square.h"

#include <iostream>

Square::Square(float size) : m_Left{}, m_Bottom{}, m_Size(size)
{
}

Square::Square(float size, float left, float bottom)
	: m_Left{left}
	  , m_Bottom{bottom}
	  , m_Size{size}
{
}

Square::~Square()
{
	std::cout << "Square destructor: release the resources\n";
}

void Square::Print() const
{
	std::cout << "Left: " << m_Left << ", bottom: " << m_Bottom << std::endl;
	std::cout << "Size: " << m_Size << std::endl;
	std::cout << "Perimeter: " << GetPerimeter() << std::endl;
	std::cout << "Area: " << GetArea() << std::endl;
	std::cout << std::endl;
}

void Square::Translate(float deltaLeft, float deltaBottom)
{
	m_Left += deltaLeft;
	m_Bottom += deltaBottom;
}

void Square::SetSize(float newSize)
{
	m_Size = newSize;
}

float Square::GetArea() const
{
	return m_Size * m_Size;
}

float Square::GetPerimeter() const
{
	return 4 * m_Size;
}

