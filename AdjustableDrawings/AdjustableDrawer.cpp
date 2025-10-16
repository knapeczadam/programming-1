// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "AdjustableDrawer.h"
#include "Core.h"

#include <iostream>

AdjustableDrawer::AdjustableDrawer()
	: m_Border{10.0f}
	  , m_MiniWindowWidth(g_WindowWidth / 2)
	  , m_MiniWindowHeight(g_WindowHeight / 2)
	  , m_ColorRed{1.0f, 0.6f, 0.7f, 1.0f}
	  , m_ColorGreen{0.5f, 1.0f, 0.7f, 1.0f}
	  , m_ColorBlue{0.1f, 0.8f, 1.0f, 1.0f}
	  , m_ColorYellow{1.0f, 1.0f, 0.6f, 1.0f}
	  , m_LineWidth{2.0f}
	  , m_NumOfIters{}
	  , m_MinNumOfIter{5}
	  , m_MaxNumOfIter{20}
{
	m_NumOfIters = m_MinNumOfIter;
	std::cout << m_NumOfIters << std::endl;
}

void AdjustableDrawer::Draw() const
{
	DrawStairs();
	DrawSpinningLines();
	DrawConcentricSquares();
	DrawSpiral();
}

void AdjustableDrawer::DrawStairs() const
{
	const float width{(m_MiniWindowWidth - 2 * m_Border) / m_NumOfIters};
	for (int i{}; i < m_NumOfIters; ++i)
	{
		const float x1{m_Border + i * width};
		const float y1{m_MiniWindowHeight + m_Border + i * width};
		const float x2{x1 + width};
		const float y2{y1};
		const float x3{x2};
		const float y3{y2 + width};

		if (i % 2 == 0)
		{
			utils::SetColor(m_ColorRed);
		}
		else
		{
			utils::SetColor(m_ColorBlue);
		}
		utils::DrawLine(x1, y1, x2, y2, m_LineWidth);
		if (i % 2 == 0)
		{
			utils::SetColor(m_ColorGreen);
		}
		else
		{
			utils::SetColor(m_ColorYellow);
		}
		utils::DrawLine(x2, y2, x3, y3, m_LineWidth);
	}
}

void AdjustableDrawer::DrawSpinningLines() const
{
	const float left{m_MiniWindowWidth + m_Border};
	const float bottom{m_MiniWindowHeight + m_Border};
	const float width{m_MiniWindowWidth - 2 * m_Border};
	const float segmentWidth{width / m_NumOfIters};

	// RED - bottom
	utils::SetColor(m_ColorRed);
	utils::DrawLine(left, bottom, left + width, bottom, m_LineWidth);
	for (int i{1}; i < m_NumOfIters; ++i)
	{
		utils::DrawLine(left + i * segmentWidth, bottom, left + width, bottom + i * segmentWidth, m_LineWidth);
	}

	// GREEN - right
	utils::SetColor(m_ColorGreen);
	utils::DrawLine(left + width, bottom, left + width, bottom + width, m_LineWidth);
	for (int i{1}; i < m_NumOfIters; ++i)
	{
		utils::DrawLine(left + width, bottom + i * segmentWidth, left + width - i * segmentWidth, bottom + width,
		                m_LineWidth);
	}

	// BLUE - top
	utils::SetColor(m_ColorBlue);
	utils::DrawLine(left, bottom + width, left + width, bottom + width, m_LineWidth);
	for (int i{1}; i < m_NumOfIters; ++i)
	{
		utils::DrawLine(left, bottom + i * segmentWidth, left + i * segmentWidth, bottom + width, m_LineWidth);
	}

	// YELLOW - left
	utils::SetColor(m_ColorYellow);
	utils::DrawLine(left, bottom, left, bottom + width, m_LineWidth);
	for (int i{1}; i < m_NumOfIters; ++i)
	{
		utils::DrawLine(left, bottom + i * segmentWidth, left + width - i * segmentWidth, bottom, m_LineWidth);
	}
}

void AdjustableDrawer::DrawConcentricSquares() const
{
	utils::SetColor(m_ColorGreen);
	const float innerBorder{(m_MiniWindowWidth - 2 * m_Border) / 2 / m_NumOfIters};

	for (int i{}; i < m_NumOfIters; ++i)
	{
		const float p{m_Border + i * innerBorder};
		const float width{m_MiniWindowWidth - 2 * m_Border - 2 * i * innerBorder};

		utils::DrawLine(p, p, p + width, p, m_LineWidth);
		utils::DrawLine(p, p, p, p + width, m_LineWidth);
		utils::DrawLine(p + width, p, p + width, p + width, m_LineWidth);
		utils::DrawLine(p, p + width, p + width, p + width, m_LineWidth);
	}
}

void AdjustableDrawer::DrawSpiral() const
{
	utils::SetColor(m_ColorBlue);
	const float innerBorder{(m_MiniWindowWidth - 2 * m_Border) / 2 / m_NumOfIters};

	for (int i{}; i < m_NumOfIters; ++i)
	{
		const float x{m_MiniWindowWidth + m_Border + i * innerBorder};
		const float y{m_Border + i * innerBorder};
		const float width{m_MiniWindowWidth - 2 * m_Border - 2 * i * innerBorder};

		utils::DrawLine(x, y, x + width, y, m_LineWidth);
		utils::DrawLine(x + width, y, x + width, y + width, m_LineWidth);
		utils::DrawLine(x + innerBorder, y + innerBorder, x + innerBorder, y + width, m_LineWidth);
		utils::DrawLine(x + innerBorder, y + width, x + width, y + width, m_LineWidth);
	}
}

void AdjustableDrawer::IncNumOfIter()
{
	if (m_NumOfIters < m_MaxNumOfIter)
	{
		++m_NumOfIters;
		std::cout << m_NumOfIters << std::endl;
	}
}

void AdjustableDrawer::DecNumOfIter()
{
	if (m_NumOfIters > m_MinNumOfIter)
	{
		--m_NumOfIters;
		std::cout << m_NumOfIters << std::endl;
	}
}
