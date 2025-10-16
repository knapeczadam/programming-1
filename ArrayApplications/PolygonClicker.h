// Knapecz, Adam - 1DAE11
#pragma once
class PolygonClicker
{
public:
	explicit PolygonClicker();
	void AddClickedPoint(Point2f p);
	void DrawClickedPoints() const;
	~PolygonClicker();
private:
	const int m_NrPoints;
	Point2f* m_Points;
	int m_CurrIdx;
	const float m_Rad;
	const Color4f m_ColorCircle;
	const float m_LineWidth;
	const Color4f m_ColorLine;
	bool m_IsFull;
};
