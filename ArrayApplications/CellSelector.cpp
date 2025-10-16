// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "CellSelector.h"

CellSelector::CellSelector()
	: m_NrRow{3}
	  , m_NrCol{4}
	  , m_Cells{nullptr}
	  , m_ColorOuterBorder{0, 0, 0, 1.0f}
	  , m_ColorInnerBorder{1.0f, 1.0f, 1.0f, 1.0f}
	  , m_ColorInactive{0.5f, 0.5f, 0.5f, 1.0f}
	  , m_ColorActive{0.8f, 0.2f, 0, 1.0f}
	  , m_CellSize{50.0f}
	  , m_OuterBorderWidth{5.0f}
	  , m_InnerBorderWidth{2.0f}
	  , m_BottomLeft{10.0f, 10.0f}
{
	m_Cells = new bool[m_NrRow * m_NrCol]{};
}

CellSelector::~CellSelector()
{
	delete[] m_Cells;
}

int CellSelector::GetIndex(int rowIdx, int colIdx, int numOfCol) const
{
	return rowIdx * numOfCol + colIdx;
}


void CellSelector::DrawGrid() const
{
	for (int i{0}; i < m_NrRow; ++i)
	{
		for (int j{0}; j < m_NrCol; ++j)
		{
			if (m_Cells[GetIndex(i, j, m_NrCol)])
			{
				utils::SetColor(m_ColorActive);
			}
			else
			{
				utils::SetColor(m_ColorInactive);
			}
			const float left{m_BottomLeft.x + j * m_CellSize};
			const float bottom{m_BottomLeft.y + i * m_CellSize};
			utils::FillRect(left, bottom, m_CellSize, m_CellSize);
			utils::SetColor(m_ColorInnerBorder);
			utils::DrawRect(left, bottom, m_CellSize, m_CellSize, m_InnerBorderWidth);
		}
	}
	utils::SetColor(m_ColorOuterBorder);
	utils::DrawRect(m_BottomLeft.x, m_BottomLeft.y, GetGridWidth(), GetGridHeight(), m_OuterBorderWidth);
}

float CellSelector::GetGridHeight() const
{
	return m_NrRow * m_CellSize;
}

float CellSelector::GetGridWidth() const
{
	return m_NrCol * m_CellSize;
}


void CellSelector::ProcessMouseClick(const Point2f& mouseClick)
{
	const bool withinX{m_BottomLeft.x <= mouseClick.x && mouseClick.x <= m_BottomLeft.x + GetGridWidth()};
	const bool withinY{m_BottomLeft.y <= mouseClick.y && mouseClick.y <= m_BottomLeft.y + GetGridHeight()};
	if (withinX && withinY)
	{
		const float x{mouseClick.x - m_BottomLeft.x};
		const float y{mouseClick.y - m_BottomLeft.y};
		const int rowIdx{int(y / m_CellSize)};
		const int colIdx{int(x / m_CellSize)};
		ToggleCell(rowIdx, colIdx);
	}
}

void CellSelector::ToggleCell(int rowIdx, int colIdx)
{
	m_Cells[GetIndex(rowIdx, colIdx, m_NrCol)] = !m_Cells[GetIndex(rowIdx, colIdx, m_NrCol)];
}
