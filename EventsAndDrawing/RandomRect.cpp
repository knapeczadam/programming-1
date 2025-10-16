// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "RandomRect.h"
#include "Core.h"

RandomRect::RandomRect()
	: m_MinWidth{60.0f}
	  , m_MinHeight{40.0f}
	  , m_Border{50.0f}
	  , m_BottomLeft{}
	  , m_Width{}
	  , m_Height{}
	  , m_Color{}
	  , m_ColorGreen{0, 1.0f, 0, 1.0f}
	  , m_ColorGray{0.5f, 0.5f, 0.5f, 1.0f}
	  , m_Speed{200.0f}
	  , m_MotionState{}
	  , m_ColorState{}
{
	Init();
}

void RandomRect::Init()
{
	m_ColorState = ColorState::GRAY;
	m_MotionState = MotionState::IDLE;
	GenerateRect();
	SetColor();
}

void RandomRect::GenerateRect()
{
	GeneratePos();
	GenerateDim();
	AdjustRect();
}

void RandomRect::GeneratePos()
{
	m_BottomLeft.x = float(rand() % int(g_WindowWidth - 2 * m_Border) + m_Border); // [50 - (width - border - 1)]
	m_BottomLeft.y = float(rand() % int(g_WindowHeight - 2 * m_Border) + m_Border); // [50 - (height - border - 1)] 
}

void RandomRect::GenerateDim()
{
	m_Width = float(rand() % int(g_WindowWidth - 2 * m_Border) + m_MinWidth); // [60 - (width - border - 1)]
	m_Height = float(rand() % int(g_WindowHeight - 2 * m_Border) + m_MinHeight); // [40 - (width - border - 1)]
}

void RandomRect::AdjustRect()
{
	AdjustPos();
	AdjustDim();
}

void RandomRect::AdjustPos()
{
	if (m_BottomLeft.x >= g_WindowWidth)
	{
		m_BottomLeft.x = 0;
	}
}

void RandomRect::AdjustDim()
{
	if (m_BottomLeft.x + m_Width > g_WindowWidth - m_Border)
	{
		m_Width = g_WindowWidth - m_Border - m_BottomLeft.x;
	}

	if (m_BottomLeft.y + m_Height > g_WindowHeight - m_Border)
	{
		m_Height = g_WindowHeight - m_Border - m_BottomLeft.y;
	}
}

void RandomRect::Draw() const
{
	utils::SetColor(m_Color);

	if (m_BottomLeft.x + m_Width > g_WindowWidth)
	{
		float offset{m_BottomLeft.x + m_Width - g_WindowWidth};
		utils::FillRect(m_BottomLeft.x, m_BottomLeft.y, m_Width, m_Height);
		utils::FillRect(0, m_BottomLeft.y, offset, m_Height);
	}
	else
	{
		utils::FillRect(m_BottomLeft.x, m_BottomLeft.y, m_Width, m_Height);
	}
}

void RandomRect::ProcessMouseClick(float mouseX, float mouseY)
{
	if (IsMouseInside(mouseX, mouseY))
	{
		FlipColor();
	}
}

bool RandomRect::IsMouseInside(float mouseX, float mouseY) const
{
	const bool withinX{m_BottomLeft.x <= mouseX && mouseX <= m_BottomLeft.x + m_Width};
	const bool withinY{m_BottomLeft.y <= mouseY && mouseY <= m_BottomLeft.y + m_Height};
	return withinX && withinY;
}

void RandomRect::FlipColor()
{
	switch (m_ColorState)
	{
	case ColorState::GRAY:
		m_ColorState = ColorState::GREEN;
		break;
	case ColorState::GREEN:
		m_ColorState = ColorState::GRAY;
		GenerateRect();
		break;
	}
	SetColor();
}

void RandomRect::SetColor()
{
	switch (m_ColorState)
	{
	case ColorState::GRAY:
		m_Color = m_ColorGray;
		break;
	case ColorState::GREEN:
		m_Color = m_ColorGreen;
		break;
	}
}

void RandomRect::ToggleMotion()
{
	switch (m_MotionState)
	{
	case MotionState::IDLE:
		m_MotionState = MotionState::MOVING;
		break;
	case MotionState::MOVING:
		m_MotionState = MotionState::IDLE;
		break;
	}
}

void RandomRect::Update(float deltaTime)
{
	switch (m_MotionState)
	{
	case MotionState::IDLE:
		break;
	case MotionState::MOVING:
		m_BottomLeft.x += m_Speed * deltaTime;
		AdjustPos();
		break;
	}
}

