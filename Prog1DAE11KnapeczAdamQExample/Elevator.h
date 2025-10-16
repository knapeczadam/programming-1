// Knapecz, Adam - 1DAE11
#pragma once

enum class ElevatorStates
{
	BOOT,
	IDLE,
	UP,
	DOWN
};

class Elevator
{
public:
	Elevator();
	void Draw() const;
	void ProcessClick(float mouseX, float mouseY);
	void Update(float deltaTime);
private:
	bool IsWallClicked(float mouseX, float mouseY) const;
	bool IsTouchingBorder();
	void SwitchState();

	const float m_Border;
	const float m_WallThickness;
	const float m_Width;
	const float m_Height;
	const float m_Speed;
	const Color4f m_WallColor;
	const Color4f m_ColorUp;
	const Color4f m_ColorDown;
	const Color4f m_ColorIdle;
	ElevatorStates m_State;
	ElevatorStates m_PreviousState;
	bool m_IsActive;
	Point2f m_BottomLeft;
};

