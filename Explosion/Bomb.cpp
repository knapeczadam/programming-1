// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Bomb.h"
#include "Core.h"

#include <cmath>

Bomb::Bomb()
	: m_Center{g_WindowWidth / 2, g_WindowHeight / 2}
	  , m_Color{}
	  , m_ColorGray{0.5f, 0.5f, 0.5f, 0.5f}
	  , m_ColorRed{1.0f, 0, 0, 1.0f}
	  , m_ColorBlack{0, 0, 0, 1.0f}
	  , m_Angle{}
	  , m_Dir{}
	  , m_Width{100.0f}
	  , m_Pa{}
	  , m_Pb{}
	  , m_Pc{}
	  , m_Pd{}
	  , m_Speed{400.0f}
	  , m_State{}
{
	Init();
}

void Bomb::Init()
{
	SetAngle();
	SetPositions();
}

void Bomb::SetAngle()
{
	const float adjacent{m_Center.x};
	const float opposite{m_Center.y};
	m_Angle = std::atan2f(opposite, adjacent);
	m_Dir.x = std::cos(m_Angle);
	m_Dir.y = std::sin(m_Angle);
}

void Bomb::SetPositions()
{
	m_Pa = Point2f{m_Center.x - m_Width / 2, m_Center.y - m_Width / 2};
	m_Pb = m_Pc = m_Pd = m_Pa;
}

void Bomb::Draw() const
{
	if (m_State == BombState::EXPLODE)
	{
		DrawParticles();
	}
	utils::SetColor(m_Color);
	utils::FillRect(m_Center.x - m_Width / 2, m_Center.y - m_Width / 2, m_Width, m_Width);
}

void Bomb::DrawParticles() const
{
	utils::SetColor(m_ColorRed);
	utils::FillRect(m_Pa.x, m_Pa.y, m_Width, m_Width);
	utils::FillRect(m_Pb.x, m_Pb.y, m_Width, m_Width);
	utils::FillRect(m_Pc.x, m_Pc.y, m_Width, m_Width);
	utils::FillRect(m_Pd.x, m_Pd.y, m_Width, m_Width);
}

void Bomb::ProcessMouseClick(float mouseX, float mouseY)
{
	const bool withinX{m_Center.x - m_Width / 2 <= mouseX && mouseX <= m_Center.x + m_Width / 2};
	const bool withinY{m_Center.y - m_Width / 2 <= mouseY && mouseY <= m_Center.y + m_Width / 2};
	if (withinX && withinY)
	{
		m_State = BombState::EXPLODE;
		m_Color = m_ColorGray;
	}
}

void Bomb::Reset()
{
	m_State = BombState::WAIT;
	m_Color = m_ColorBlack;
	SetPositions();
}

void Bomb::Update(float deltaTime)
{
	if (m_State == BombState::EXPLODE)
	{
		m_Pa.x += m_Dir.x * m_Speed * deltaTime;
		m_Pa.y += m_Dir.y * m_Speed * deltaTime;

		m_Pb.x += m_Dir.x * m_Speed * deltaTime;
		m_Pb.y -= m_Dir.y * m_Speed * deltaTime;

		m_Pc.x -= m_Dir.x * m_Speed * deltaTime;
		m_Pc.y -= m_Dir.y * m_Speed * deltaTime;

		m_Pd.x -= m_Dir.x * m_Speed * deltaTime;
		m_Pd.y += m_Dir.y * m_Speed * deltaTime;

		if (IsParticleOutOfWindow())
		{
			Reset();
		}
	}
}

bool Bomb::IsParticleOutOfWindow() const
{
	return m_Pa.x > g_WindowWidth;
}

