// Knapecz, Adam - 1DAE11
#pragma once
class Square
{
public:
	Square(float size);
	Square(float size, float left, float bottom);
	~Square();

	void Print() const;
	void Translate(float deltaLeft, float deltaBottom);
	void SetSize(float newSize);
private:
	float m_Left;
	float m_Bottom;
	float m_Size;

	float GetArea() const;
	float GetPerimeter()const ;
};

