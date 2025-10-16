// Knapecz, Adam - 1DAE11
#pragma once

#include <vector>

class CrosierDrawer
{
public:
	explicit CrosierDrawer();
	void Draw() const;

private:
	void Init();
	void GeneratePoints();

	float m_NumOfPoints;
	std::vector<Point2f> m_Points;
	const float m_Steps;
	const Point2f m_Center;
	const Color4f m_Color;
	const float m_a;
	const float m_b;
};

