// Knapecz, Adam - 1DAE11

#include "pch.h"
#include "RandomPoint.h"
#include "Core.h"
#include "utils.h"

#include <cmath>

RandomPoint::RandomPoint()
	: m_Pos{}
	  , m_Dir{}
	  , m_Angle{}
	  , m_Speed{500.0f}
{
	Init();
}

void RandomPoint::Init()
{
	GeneratePos();
	GenerateAngle();
	GenerateDir();
}

void RandomPoint::GeneratePos()
{
	m_Pos.x = float(rand() % int(g_WindowWidth));
	m_Pos.y = float(rand() % int(g_WindowHeight));
}

void RandomPoint::GenerateAngle()
{
	const float rightAngle{90.0f};
	const float offset{2.0f};
	const float halfPeriod{180.0f};
	const float D2R{utils::g_Pi / halfPeriod};
	float angle = float(rand() % int(rightAngle - offset) + 1);
	m_Angle = angle * D2R;;
}

float RandomPoint::GetAngle() const
{
	return m_Angle;
}

void RandomPoint::SetAngle(float angle)
{
	m_Angle = angle;
}

void RandomPoint::GenerateDir()
{
	m_Dir.x = std::cosf(m_Angle);
	m_Dir.y = std::sinf(m_Angle);
}

Point2f RandomPoint::GetPos() const
{
	return m_Pos;
}

void RandomPoint::Update(float deltaTime)
{
	if (m_Pos.x <= 0 || m_Pos.x >= g_WindowWidth)
	{
		m_Dir.x = -m_Dir.x;
	}

	if (m_Pos.y <= 0 || m_Pos.y >= g_WindowHeight)
	{
		m_Dir.y = -m_Dir.y;
	}
	m_Pos.x += m_Dir.x * m_Speed * deltaTime;
	m_Pos.y += m_Dir.y * m_Speed * deltaTime;
}

