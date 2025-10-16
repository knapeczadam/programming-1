// Knapecz, Adam - 1DAE11
#pragma once

struct AngleSpeed
{
	float angle;
	float speed;
};

class PentagramRotator
{
public:
	explicit PentagramRotator();
	void DrawPentagrams() const;
	void UpdatePentagrams(float deltaTime);
	~PentagramRotator();
private:
	void InitPentagrams();
	const int m_n;
	AngleSpeed* m_Speeds;
	const int m_NrVertices;
	float m_UnitAngle;
	const float m_Radius;
	const Color4f m_Color;
	const float m_LineWidth;
	const Point2f m_Center;
};

