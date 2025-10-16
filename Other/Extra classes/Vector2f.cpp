// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Vector2f.h"

#include <cmath>

Vector2f::Vector2f(float x, float y) : x{x}, y{y}
{
}

Vector2f Vector2f::Add(const Vector2f& a, const Vector2f& b)
{
	return Vector2f{a.x + b.x, a.y + b.y};
}

Point2f Vector2f::Add(const Point2f& p, const Vector2f& v)
{
	return Point2f{p.x + v.x, p.y + v.y};
}

Vector2f Vector2f::Subtract(const Vector2f& a, const Vector2f& b)
{
	return Vector2f{a.x - b.x, a.y - b.y};
}

float Vector2f::DotProduct(const Vector2f& a, const Vector2f& b)
{
	return a.x * b.x + a.y * b.y;
}

float Vector2f::CrossProduct(const Vector2f& a, const Vector2f& b)
{
	return a.x * b.y - a.y * b.x;
}

std::string Vector2f::ToString(const Vector2f& v)
{
	return "[" + std::to_string(v.x) + ", " + std::to_string(v.y) + "]";
}

Vector2f Vector2f::Scale(const Vector2f& v, float s)
{
	return Vector2f{v.x * s, v.y * s};
}

float Vector2f::Length(const Vector2f& v)
{
	return std::sqrtf(std::powf(v.x, 2) + std::powf(v.y, 2));
}

Vector2f Vector2f::Normalize(const Vector2f& v)
{
	const float l{Length(v)};
	if (l == 0) return v;
	return Vector2f{v.x / l, v.y / l};
}

float Vector2f::AngleBetween(const Vector2f& a, const Vector2f& b)
{
	return std::atan2f(CrossProduct(a, b), DotProduct(a, b));
}

bool Vector2f::AreEqual(const Vector2f& a, const Vector2f& b)
{
	const float delta{0.001f};
	const float diffX{std::abs(a.x - b.x)};
	const float diffY{std::abs(a.y - b.y)};
	return diffX <= delta && diffY <= delta;
}

void Vector2f::DrawVector(const Vector2f& v, const Point2f& start)
{
	const Point2f from{start.x, start.y};
	const Point2f to{from.x + v.x, from.y + v.y};
	utils::DrawLine(from, to);

	const float dist{Length(v)};
	// proportional arrow
	float smallAngle{5 * utils::g_Pi / 180};
	// fixed sized arrow
	smallAngle = std::atan2f(5.0f, dist);
	const float angle{std::atan2f(v.y, v.x)};
	const float alpha{angle + smallAngle};
	const float beta{angle - smallAngle};
	const float hyp{dist / std::cosf(smallAngle)};
	const float x1{std::cosf(alpha) * hyp + from.x};
	const float y1{std::sinf(alpha) * hyp + from.y};
	const float x2{std::cosf(beta) * hyp + from.x};
	const float y2{std::sinf(beta) * hyp + from.y};
	const Point2f a{x1, y1};
	const Point2f b{x2, y2};

	const float arrowAngle{60 * utils::g_Pi / 180};
	const float halfSide{std::sinf(smallAngle) * hyp};
	const float altitude{std::sinf(arrowAngle) * 2 * halfSide};
	Vector2f norm{Normalize(v)};
	const Point2f apex{to.x + norm.x * altitude, to.y + norm.y * altitude};

	utils::FillTriangle(a, apex, b);
}

void Vector2f::DrawVector(const Point2f& start, const Vector2f& v)
{
	DrawVector(v, start);
}
