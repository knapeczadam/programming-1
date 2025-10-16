// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "PolygonClicker.h"

PolygonClicker::PolygonClicker()
	: m_NrPoints{5}
	  , m_Points{nullptr}
	  , m_CurrIdx{}
	  , m_Rad{5.0f}
	  , m_ColorCircle{0.8f, 0, 0, 1.0f}
	  , m_LineWidth{2.0f}
	  , m_ColorLine{1.0f, 1.0f, 1.0f, 1.0f}
	  , m_IsFull{false}
{
	m_Points = new Point2f[m_NrPoints]{};
}

PolygonClicker::~PolygonClicker()
{
	delete[] m_Points;
}

void PolygonClicker::AddClickedPoint(Point2f p)
{
	if (m_CurrIdx == m_NrPoints && !m_IsFull)
	{
		m_IsFull = true;
	}
	if (m_IsFull)
	{
		for (int idx{0}; idx < m_NrPoints - 1; ++idx)
		{
			m_Points[idx] = m_Points[idx + 1];
		}
		m_Points[m_NrPoints - 1] = p;
	}
	else
	{
		m_Points[m_CurrIdx] = p;
		++m_CurrIdx;
	}
}

void PolygonClicker::DrawClickedPoints() const
{
	if (m_CurrIdx == m_NrPoints)
	{
		for (int idx{0}; idx < m_NrPoints; ++idx)
		{
			utils::SetColor(m_ColorCircle);
			utils::FillArc(m_Points[idx].x, m_Points[idx].y, m_Rad, m_Rad, 0, 2 * utils::g_Pi);
			if (idx != m_NrPoints - 1)
			{
				utils::SetColor(m_ColorLine);
				utils::DrawLine(m_Points[idx], m_Points[idx + 1], m_LineWidth);
			}
		}
	}
}
