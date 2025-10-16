// Knapecz, Adam - 1DAE11
#include "pch.h"

#include "CrosierDrawer.h"
#include "Core.h"

#include <cmath>

using utils::g_Pi;


CrosierDrawer::CrosierDrawer()
	: m_NumOfPoints{}
	  , m_Points{}
	  , m_Steps{0.01f}
	  , m_Center{g_WindowWidth * 3 / 4, g_WindowHeight / 2}
	  , m_Color{1.0f, 0, 0, 1.0f}
	  , m_a{g_WindowWidth / 4}
	  , m_b{8.0f}
{
	Init();
}

void CrosierDrawer::Init()
{
	m_NumOfPoints = std::roundf(((m_b * 2 * g_Pi + g_Pi / 2) - (g_Pi / 2)) / m_Steps);
	m_Points.reserve(int(m_NumOfPoints));
	GeneratePoints();
}

void CrosierDrawer::Draw() const
{
	utils::SetColor(m_Color);
	for (int i{}; i < m_Points.size() - 1; ++i)
	{
		utils::DrawLine(m_Points[i], m_Points[(i + 1)]);
	}
}

void CrosierDrawer::GeneratePoints()
{
	for (int i{}; i < m_NumOfPoints; ++i)
	{
		const float rad{g_Pi / 2 + i * m_Steps};
		const float r{m_a / std::sqrtf(rad)};
		float x{std::cosf(rad) * r};
		float y{std::sinf(rad) * r};
		x += m_Center.x;
		y += m_Center.y;
		m_Points.push_back(Point2f{x, y});
	}
}

