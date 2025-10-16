// Knapecz, Adam - 1DAE11
#pragma once

enum class MotionState
{
	IDLE,
	MOVING,
	FROZEN
};

enum class ColorState
{
	GREEN,
	GRAY
};

class RandomRect final
{
public:
	explicit RandomRect();
	void Draw() const;
	void FlipColor();
	void ProcessMouseClick(float mouseX, float mouseY);
	void ToggleMotion();
	void Update(float deltaTime);

private:
	void Init();
	void SetColor();

	void GenerateRect();
	void GeneratePos();
	void GenerateDim();

	void AdjustRect();
	void AdjustPos();
	void AdjustDim();
	
	bool IsMouseInside(float mouseX, float mouseY) const;

	const float m_MinWidth;
	const float m_MinHeight;
	const float m_Border;
	Point2f m_BottomLeft;
	float m_Width;
	float m_Height;
	Color4f m_Color;
	const Color4f m_ColorGreen;
	const Color4f m_ColorGray;

	const float m_Speed;

	MotionState m_MotionState;
	ColorState m_ColorState;
};

