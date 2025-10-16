// Knapecz, Adam - 1DAE11
#pragma once

class RandomPoint
{
public:
	explicit RandomPoint();
	Point2f GetPos() const;
	float GetAngle() const;
	void SetAngle(float angle);
	void Update(float deltaTime);
private:
	void Init();
	void GeneratePos();
	void GenerateAngle();
	void GenerateDir();

	Point2f m_Pos;
	Point2f m_Dir;
	float m_Angle;
	const float m_Speed;
};

