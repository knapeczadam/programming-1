// Knapecz, Adam - 1DAE11
#pragma once

enum class BombState
{
	WAIT,
	EXPLODE,
};

class Bomb
{
public:
	explicit Bomb();
	void ProcessMouseClick(float mouseX, float mouseY);
	void Draw() const;
	void Update(float deltaTime);
private:
	void Init();
	void Reset();
	void DrawParticles() const;
	void SetAngle();
	void SetPositions();
	bool IsParticleOutOfWindow() const;

	const Point2f m_Center;
	Color4f m_Color;
	const Color4f m_ColorGray;
	const Color4f m_ColorRed;
	const Color4f m_ColorBlack;

	float m_Angle;
	Point2f m_Dir;
	float m_Width;

	Point2f m_Pa;
	Point2f m_Pb;
	Point2f m_Pc;
	Point2f m_Pd;

	const float m_Speed;
	BombState m_State;
};

