// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator) : m_Numerator{numerator}, m_Denominator{denominator}
{
}

void Fraction::Draw(const Point2f& pos, float size) const
{
	if (m_Numerator >= m_Denominator)
	{
		const int numerator{m_Numerator % m_Denominator};
		const int whole{m_Numerator / m_Denominator};
		const float spacing{5.0f};
		float left{pos.x};
		for (int iCell{}; iCell < whole; ++iCell)
		{
			utils::SetColor(1.0f, 0.1f, 0.7f, 1.0f);
			utils::FillRect(left, pos.y, size, size);
			utils::SetColor(1.0f, 1.0f, 1.0f, 1.0f);
			utils::DrawRect(left, pos.y, size, size);
			left += size + spacing;
		}
		for (int iCell{0}; iCell < m_Denominator * (numerator ? 1 : 0); ++iCell)
		{
			if (iCell < numerator)
			{
				utils::SetColor(0.1f, 0.1f, 0.7f, 1.0f);
				utils::FillRect(left, pos.y, size, size);
			}
			utils::SetColor(1.0f, 1.0f, 1.0f, 1.0f);
			utils::DrawRect(left, pos.y, size, size);
			left += size;
		}
	}
	else
	{
		for (int iCell{0}; iCell < m_Denominator; ++iCell)
		{
			const float left{pos.x + iCell * size};
			if (iCell < m_Numerator)
			{
				utils::SetColor(0.1f, 0.1f, 0.7f, 1.0f);
				utils::FillRect(left, pos.y, size, size);
			}
			utils::SetColor(1.0f, 1.0f, 1.0f, 1.0f);
			utils::DrawRect(left, pos.y, size, size);
		}
	}
}

float Fraction::GetValue() const
{
	return float(m_Numerator) / m_Denominator;
}

