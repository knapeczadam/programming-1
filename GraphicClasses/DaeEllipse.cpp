// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "DaeEllipse.h"

#include <cmath>
#include <iostream>

DaeEllipse::DaeEllipse(const Point2f& center, float radX, float radY, const Color4f& fillColor)
	: m_Center{center}
	  , m_RadX{radX}
	  , m_RadY{radY}
	  , m_FillColor{fillColor}
	  , m_Area{}
	  , m_IsActive{}
	  , m_IsPrinted{}
{
	m_Area = m_RadX * m_RadY * utils::g_Pi;
}

void DaeEllipse::Draw()
{
	if (m_IsActive)
	{
		m_FillColor.a = 1.0f;
	}
	else
	{
		m_FillColor.a = 0.5f;
	}
	utils::SetColor(m_FillColor);
	utils::FillEllipse(m_Center, m_RadX, m_RadY);
}

void DaeEllipse::ActivateTest(const Point2f& pos)
{
	const float term1{std::powf((pos.x - m_Center.x), 2) / (m_RadX * m_RadX)};
	const float term2{std::powf((pos.y - m_Center.y), 2) / (m_RadY * m_RadY)};
	if (term1 + term2 <= 1)
	{
		m_IsActive = true;
	}
	else
	{
		m_IsActive = false;
		m_IsPrinted = false;
	}
	PrintArea();
}

void DaeEllipse::PrintArea()
{
	if (m_IsActive && !m_IsPrinted)
	{
		std::cout << "Area of this activated ellipse is " << m_Area << std::endl;
		m_IsPrinted = true;
	}
}

