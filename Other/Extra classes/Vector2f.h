// Knapecz, Adam - 1DAE11
#pragma once

class Vector2f
{
public:
	explicit Vector2f(float x, float y);

	Vector2f Add(const Vector2f& a, const Vector2f& b);
	Point2f Add(const Point2f& p, const Vector2f& v);
	Vector2f Subtract(const Vector2f& a, const Vector2f& b);
	float DotProduct(const Vector2f& a, const Vector2f& b);
	float CrossProduct(const Vector2f& a, const Vector2f& b);
	std::string ToString(const Vector2f& v);
	Vector2f Scale(const Vector2f& v, float s);
	float Length(const Vector2f& v);
	Vector2f Normalize(const Vector2f& v);
	float AngleBetween(const Vector2f& a, const Vector2f& b);
	bool AreEqual(const Vector2f& a, const Vector2f& b);
	void DrawVector(const Vector2f& v, const Point2f& start = Point2f{0, 0});
	void DrawVector(const Point2f& start, const Vector2f& v);

	float x;
	float y;
};
