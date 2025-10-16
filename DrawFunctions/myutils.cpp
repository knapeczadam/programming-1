// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "myutils.h"

#include <cmath>

void myutils::DrawSquares(float left, float bottom, float width, int division, Color4f color)
{
	utils::SetColor(color);
	float offset{width / 2 / division};
	for (int i{0}; i < division; ++i)
	{
		float x{left + i * offset};
		float y{bottom + i * offset};
		if (i != 0)
		{
			width -= 2 * offset;
		}
		utils::DrawLine(x, y, x + width, y);
		utils::DrawLine(x, y, x, y + width);
		utils::DrawLine(x + width, y, x + width, y + width);
		utils::DrawLine(x, y + width, x + width, y + width);
	}
}

void myutils::DrawEquilateralTriangle(float left, float bottom, float width, bool outline, bool fill,
                                      Color4f outlineColor, Color4f fillColor)
{
	const float angle{60 * utils::g_Pi / 180};
	Point2f apex{std::cosf(angle) * width, std::sinf(angle) * width};
	apex.x += left;
	apex.y += bottom;
	const Point2f a{left, bottom};
	const Point2f b{left + width, bottom};
	if (fill)
	{
		utils::SetColor(fillColor);
		utils::FillTriangle(a, b, apex);
	}
	if (outline)
	{
		utils::SetColor(outlineColor);
		utils::DrawTriangle(a, b, apex);
	}
}

void myutils::DrawPentagram(float centerX, float centerY, float radius, Color4f color)
{
	utils::SetColor(color);
	const float fullPeriod{2 * utils::g_Pi};
	const float angle{fullPeriod / 5};
	for (int i{}; i < 5; ++i)
	{
		float x1{std::cosf(angle * i) * radius};
		float y1{std::sinf(angle * i) * radius};
		float x2{std::cosf(angle * i + 2 * angle) * radius};
		float y2{std::sinf(angle * i + 2 * angle) * radius};
		x1 += centerX;
		x2 += centerX;
		y1 += centerY;
		y2 += centerY;

		utils::DrawLine(x1, y1, x2, y2);
	}
}

void myutils::DrawLinearGradient(float left, float bottom, float width, float height, Color4f colorFrom,
                                 Color4f colorTo)
{
	const float ratio{1.0f / width};
	for (float i{0}; i <= 1.0f; i += ratio)
	{
		float diffR{colorTo.r - colorFrom.r};
		float diffG{colorTo.g - colorFrom.g};
		float diffB{colorTo.b - colorFrom.b};
		float diffA{colorTo.a - colorFrom.a};
		const float r{colorFrom.r + diffR * i};
		const float g{colorFrom.g + diffG * i};
		const float b{colorFrom.b + diffB * i};
		const float a{colorFrom.a + diffA * i};
		utils::SetColor(r, g, b, a);
		utils::FillRect(left + width * i, bottom, width - width * i, height);
	}
}

void myutils::DrawDotGrid(float left, float bottom, int row, int col, float radius, float spacing, Color4f color)
{
	utils::SetColor(color);
	float centerX{left + radius};
	float centerY{bottom + radius};
	for (int i{0}; i < row; ++i)
	{
		for (int j{0}; j < col; ++j)
		{
			utils::FillArc(centerX + j * spacing + j * 2 * radius, centerY + i * spacing + i * 2 * radius, radius,
			               radius, 0, 2 * utils::g_Pi);
		}
	}
}

