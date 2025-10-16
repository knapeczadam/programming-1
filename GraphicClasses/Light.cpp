// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Light.h"

#include <iostream>

Light::Light(const Rectf& rect, const Color4f& color) : m_Rect{rect}, m_IsOn{false}, m_Color{color}
{
}

void Light::Draw() const
{
	if (m_IsOn)
	{
		utils::SetColor(m_Color);
	}
	else
	{
		utils::SetColor(0.5f, 0.5f, 0.5f, 1.0f);
	}
	utils::FillRect(m_Rect);
	utils::SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	utils::DrawRect(m_Rect);
}

bool Light::IsHit(const Point2f& pos)
{
	const bool withinX{m_Rect.left <= pos.x && pos.x <= m_Rect.left + m_Rect.width};
	const bool withinY{m_Rect.bottom <= pos.y && pos.y <= m_Rect.bottom + m_Rect.height};
	if (withinX && withinY)
	{
		m_IsOn = !m_IsOn;
		return true;
	}
	return false;
}

bool Light::IsOn() const
{
	return m_IsOn;
}

