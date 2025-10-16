// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "PentagramRotator.h"

#include "Core.h"
#include <cmath>

PentagramRotator::PentagramRotator()
	: m_n{5}
	  , m_NrVertices{5}
	  , m_Speeds{nullptr}
	  , m_UnitAngle{}
	  , m_Radius{50.0f}
	  , m_Color{0, 1.0f, 0, 1.0f}
	  , m_LineWidth{2.0f}
	  , m_Center{g_WindowWidth / 2 + 50.0f, g_WindowHeight / 2}
{
	m_Speeds = new AngleSpeed[m_n]{};
	m_UnitAngle = 2 * utils::g_Pi / m_NrVertices;
	InitPentagrams();
}

PentagramRotator::~PentagramRotator()
{
	delete[] m_Speeds;
}

void PentagramRotator::DrawPentagrams() const
{
	utils::SetColor(m_Color);
	for (int i{0}; i < m_n; ++i)
	{
		for (int j{0}; j < m_NrVertices; ++j)
		{
			float x1{std::cosf(m_UnitAngle * j + m_Speeds[i].angle) * m_Radius};
			float y1{std::sinf(m_UnitAngle * j + m_Speeds[i].angle) * m_Radius};
			float x2{std::cosf(m_UnitAngle * ((j + 2) % m_NrVertices) + m_Speeds[i].angle) * m_Radius};
			float y2{std::sinf(m_UnitAngle * ((j + 2) % m_NrVertices) + m_Speeds[i].angle) * m_Radius};
			x1 += m_Center.x;
			x2 += m_Center.x;
			y1 += m_Center.y;
			y2 += m_Center.y;
			utils::DrawLine(x1, y1, x2, y2, m_LineWidth);
		}
	}
}

void PentagramRotator::InitPentagrams()
{
	for (int idx{0}; idx < m_n; ++idx)
	{
		m_Speeds[idx].speed = utils::GetRand(0.2f, 1.1f);
	}
}

void PentagramRotator::UpdatePentagrams(float deltaTime)
{
	for (int i{0}; i < m_n; ++i)
	{
		m_Speeds[i].angle += m_Speeds[i].speed * deltaTime;
	}
}
