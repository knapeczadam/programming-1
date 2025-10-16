// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "MouseTracer.h"

#include <iostream>

MouseTracer::MouseTracer()
	: m_NrPoints{10}
	  , m_Points{nullptr}
	  , m_CurrIdx{}
	  , m_Rad{20.0f}
	  , m_ColorCircle{0, 0.6f, 0, 1.0f}
	  , m_IsFull{false}
{
	m_Points = new Point2f[m_NrPoints]{};
}

MouseTracer::~MouseTracer()
{
	delete[] m_Points;
}

void MouseTracer::AddClickedPoint(Point2f p)
{
	if (m_CurrIdx == m_NrPoints && !m_IsFull)
	{
		m_IsFull = true;
	}
	if (m_IsFull)
	{
		m_CurrIdx = ++m_CurrIdx % m_NrPoints;
		m_Points[m_CurrIdx] = p;
	}
	else
	{
		m_Points[m_CurrIdx] = p;
		++m_CurrIdx;
	}
}

void MouseTracer::DrawClickedPoints() const
{
	if (m_IsFull)
	{
		for (int idx{0}; idx < m_NrPoints; ++idx)
		{
			int weight{m_NrPoints};
			if (idx < m_CurrIdx)
			{
				weight -= m_CurrIdx - idx;
			}
			else if (idx > m_CurrIdx)
			{
				weight = idx - m_CurrIdx;
			}
			const float perc{1.0f / m_NrPoints * weight};
			utils::SetColor(0, 1.0f * perc, 0, 1.0f * perc);
			utils::FillArc(m_Points[idx].x, m_Points[idx].y, m_Rad * perc, m_Rad * perc, 0, 2 * utils::g_Pi);
		}
	}
}
