// Knapecz, Adam - 1DAE11
#pragma once

#include <vector>

class PolygonDrawer
{
public:
	explicit PolygonDrawer();
	void Draw() const;

private:
	void Init();
	void GeneratePoints();

	const int m_NumOfPoints;
	std::vector<Point2f> m_Points;
	float m_Angle;
	const Point2f m_Center;
	const Color4f m_Color;
	const float m_a;
	const float m_b;
};
