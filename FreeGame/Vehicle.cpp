// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Vehicle.h"
#include "Core.h"

Vehicle::Vehicle(int id)
	: m_MaxSpeed{200}
	  , m_MinSpeed{20}
	  , m_Speed{}
	  , m_Position{}
	  , m_IsActive{}
	  , m_Texture{}
{
	utils::TextureFromFile("Resources/car-truck" + std::to_string(id) + ".bmp", m_Texture);
	m_Speed = float(std::rand() % (m_MaxSpeed + 1) + m_MinSpeed);
}

void Vehicle::Reset()
{
	m_Position.x = float(std::rand() % (int(g_WindowWidth) + 1) - int(g_WindowWidth));
	m_Speed = float(std::rand() % (m_MaxSpeed + 1) + m_MinSpeed);
}

Vehicle::~Vehicle()
{
	utils::DeleteTexture(m_Texture);
}

void Vehicle::Update(float elapsedSec, float windowWidth)
{
	if (m_IsActive)
	{
		m_Position.x += m_Speed * elapsedSec;
		if (m_Position.x >= windowWidth)
		{
			Reset();
		}
	}
}

void Vehicle::Draw()
{
	utils::DrawTexture(m_Texture, m_Position);
}

bool Vehicle::IsIntersecting(const Point2f& pt)
{
	const bool withinX{m_Position.x <= pt.x && pt.x <= m_Position.x + m_Texture.width};
	const bool withinY{m_Position.y <= pt.y && pt.y <= m_Position.y + m_Texture.height};
	return withinX && withinY;
}

void Vehicle::SetActive(bool isActive)
{
	m_IsActive = isActive;
}

void Vehicle::SetYPos(float posY)
{
	m_Position.y = posY;
}
