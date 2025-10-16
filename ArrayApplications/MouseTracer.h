// Knapecz, Adam - 1DAE11
#pragma once

class MouseTracer
{
public:
	explicit MouseTracer();
	void AddClickedPoint(Point2f p);
	void DrawClickedPoints() const;
	~MouseTracer();
private:
	const int m_NrPoints;
	Point2f* m_Points;
	int m_CurrIdx;
	const float m_Rad;
	const Color4f m_ColorCircle;
	bool m_IsFull;
};
