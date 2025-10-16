// Knapecz, Adam - 1DAE11
#pragma once

class CellSelector
{
public:
	explicit CellSelector();
	void DrawGrid() const;
	void ProcessMouseClick(const Point2f& mouseClick);
	~CellSelector();
private:
	void ToggleCell(int rowIdx, int colIdx);
	int GetIndex(int rowIdx, int colIdx, int numOfCol) const;
	float GetGridWidth() const;
	float GetGridHeight() const;

	const int m_NrRow;
	const int m_NrCol;
	bool* m_Cells;

	const Color4f m_ColorOuterBorder;
	const Color4f m_ColorInnerBorder;
	const Color4f m_ColorInactive;
	const Color4f m_ColorActive;

	const float m_CellSize;
	const float m_OuterBorderWidth;
	const float m_InnerBorderWidth;
	
	const Point2f m_BottomLeft;
};
