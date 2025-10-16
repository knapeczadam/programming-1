// Knapecz, Adam - 1DAE11
#pragma once

class AdjustableDrawer
{
public:
	explicit AdjustableDrawer();
	void Draw() const;
	void IncNumOfIter();
	void DecNumOfIter();
private:
	void DrawStairs() const;
	void DrawSpinningLines() const;
	void DrawConcentricSquares() const;
	void DrawSpiral() const;

	const float m_Border;
	const float m_MiniWindowWidth;
	const float m_MiniWindowHeight;

	const Color4f m_ColorRed;
	const Color4f m_ColorGreen;
	const Color4f m_ColorBlue;
	const Color4f m_ColorYellow;
	const float m_LineWidth;

	int m_NumOfIters;
	const int m_MinNumOfIter;
	const int m_MaxNumOfIter;
};
