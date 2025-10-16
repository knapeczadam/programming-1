// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "RandomRectangle.h"
#include "Core.h"

RandomRectangle::RandomRectangle()
	:
	m_Pos{}
	, m_Width{}
	, m_Height{}
	, m_Color{}
	, m_ColorWhite{1.0f, 1.0f, 1.0f, 1.0f}
	, m_MinWidth{10.0f}
	, m_MinHeight{10.0f}
	, m_Border{10.0f}
{
	Init();
}

void RandomRectangle::Init()
{
	GeneratePos();
	GenerateDim();
	GenerateColor();
}

void RandomRectangle::GeneratePos()
{
	m_Pos.x = rand() % int(g_WindowWidth - 2 * m_Border - m_MinWidth + 1) + m_Border; // [10 - (windowWidth - 11)]
	m_Pos.y = rand() % int(g_WindowHeight - 2 * m_Border - m_MinHeight + 1) + m_Border; // [10 - (windowHeight - 11)]
}

void RandomRectangle::GenerateDim()
{
	const float maxWidth{g_WindowWidth - m_Border - m_Pos.x - m_MinWidth};
	const float maxHeight{g_WindowHeight - m_Border - m_Pos.y - m_MinHeight};
	m_Width = m_MinWidth;
	if (maxWidth != 0)
	{
		m_Width = rand() % int(maxWidth) + m_MinWidth;
	}
	m_Height = m_MinHeight;
	if (maxHeight != 0)
	{
		m_Height = rand() % int(maxHeight) + m_MinHeight;
	}
}

void RandomRectangle::GenerateColor()
{
	m_Color.r = rand() % 101 / 100.0f;
	m_Color.g = rand() % 101 / 100.0f;
	m_Color.b = rand() % 101 / 100.0f;
	m_Color.a = 1.0f;
}

void RandomRectangle::Draw()
{
	utils::SetColor(m_ColorWhite);
	utils::DrawRect(m_Pos, m_Width, m_Height, 2);
	utils::SetColor(m_Color);
	utils::FillRect(m_Pos, m_Width, m_Height);
}
