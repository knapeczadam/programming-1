// Knapecz, Adam - 1DAE11
#pragma once
class Fraction
{
public:
	Fraction(int numerator, int denominator);
	void Draw(const Point2f& pos, float size) const;
	float GetValue() const;
private:
	int m_Numerator;
	int m_Denominator;
};

