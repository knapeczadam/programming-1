// Knapecz, Adam - 1DAE11
#pragma once
class RandomRectangle
{
public:
	explicit RandomRectangle();
	void Draw();
private:
	void Init();
	void GeneratePos();
	void GenerateDim();
	void GenerateColor();

	Point2f m_Pos;
	float m_Width;
	float m_Height;
	Color4f m_Color;
	const Color4f m_ColorWhite;

	const float m_MinWidth;
	const float m_MinHeight;
	const float m_Border;
};

