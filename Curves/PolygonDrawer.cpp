// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "PolygonDrawer.h"
#include "Core.h"

#include <cmath>

PolygonDrawer::PolygonDrawer()
	: m_NumOfPoints{10}
	  , m_Points{}
	  , m_Angle{}
	  , m_Center{g_WindowWidth / 4, g_WindowHeight / 2}
	  , m_Color{1.0f, 0, 1.0f, 1.0f}
	  , m_a{70.0f}
	  , m_b{100.0f}
{
	Init();
}

void PolygonDrawer::Init()
{
	m_Points.reserve(m_NumOfPoints);
	GeneratePoints();
}

void PolygonDrawer::Draw() const
{
	utils::SetColor(m_Color);
	for (int i{}; i < m_NumOfPoints; ++i)
	{
		utils::DrawLine(m_Points[i], m_Points[(i + 1) % m_NumOfPoints]);
	}
}

void PolygonDrawer::GeneratePoints()
{
	const float halfPeriod{180.0f};
	const float D2R{utils::g_Pi / halfPeriod};
	m_Angle = 2 * halfPeriod / m_NumOfPoints;
	for (int i{}; i < m_NumOfPoints; ++i)
	{
		const float rad{i * m_Angle * D2R};
		float x{std::cosf(rad) * m_a};
		float y{std::sinf(rad) * m_b};
		x += m_Center.x;
		y += m_Center.y;
		m_Points.push_back(Point2f{x, y});
	}
}

