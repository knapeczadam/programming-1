// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Elevator.h"

#include "Core.h"

Elevator::Elevator()
	: m_Border{30.0f}
	  , m_WallThickness{10.0f}
	  , m_Width{40.0f}
	  , m_Height{60.0f}
	  , m_Speed{100.0f}
	  , m_WallColor{1.0f, 1.0f, 0, 1.0f}
	  , m_ColorUp{1.0f, 0, 0, 1.0f}
	  , m_ColorDown{0, 1.0f, 0, 1.0f}
	  , m_ColorIdle{0.5f, 0.5f, 0.5f, 1.0f}
	  , m_State{ElevatorStates::BOOT}
	  , m_PreviousState{ElevatorStates::BOOT}
	  , m_IsActive{}
	  , m_BottomLeft{g_WindowWidth - m_Border - m_Width, m_Border}
{
}

void Elevator::Draw() const
{
	utils::SetColor(m_WallColor);
	utils::FillRect(m_BottomLeft.x, m_BottomLeft.y, m_Width, m_Height);
	switch (m_State)
	{
	case ElevatorStates::BOOT:
	case ElevatorStates::IDLE:
		utils::SetColor(m_ColorIdle);
		break;
	case ElevatorStates::UP:
		utils::SetColor(m_ColorUp);
		break;
	case ElevatorStates::DOWN:
		utils::SetColor(m_ColorDown);
		break;
	}
	utils::FillRect(m_BottomLeft.x + m_WallThickness, m_BottomLeft.y + m_WallThickness, m_Width - 2 * m_WallThickness,
	                m_Height - 2 * m_WallThickness);
}

void Elevator::ProcessClick(float mouseX, float mouseY)
{
	if (IsWallClicked(mouseX, mouseY))
	{
		m_IsActive = !m_IsActive;
		SwitchState();
	}
}

void Elevator::SwitchState()
{
	switch (m_State)
	{
	case ElevatorStates::BOOT:
		m_State = ElevatorStates::UP;
		m_PreviousState = ElevatorStates::IDLE;
		break;
	case ElevatorStates::IDLE:
		m_State = m_PreviousState;
		m_PreviousState = ElevatorStates::IDLE;
		break;
	case ElevatorStates::UP:
		m_State = ElevatorStates::IDLE;
		m_PreviousState = ElevatorStates::UP;
		break;
	case ElevatorStates::DOWN:
		m_State = ElevatorStates::IDLE;
		m_PreviousState = ElevatorStates::DOWN;
		break;
	}
}

bool Elevator::IsWallClicked(float mouseX, float mouseY) const
{
	if (m_BottomLeft.x <= mouseX && mouseX <= m_BottomLeft.x + m_Width && m_BottomLeft.y <= mouseY && mouseY <=
		m_BottomLeft.y + m_WallThickness)
	{
		return true;
	}
	if (m_BottomLeft.x <= mouseX && mouseX <= m_BottomLeft.x + m_WallThickness && m_BottomLeft.y <= mouseY && mouseY <=
		m_BottomLeft.y + m_Height)
	{
		return true;
	}
	if (m_BottomLeft.x + m_Width - m_WallThickness <= mouseX && mouseX <= m_BottomLeft.x + m_Width && m_BottomLeft.y <=
		mouseY && mouseY <= m_BottomLeft.y + m_Height)
	{
		return true;
	}
	if (m_BottomLeft.x <= mouseX && mouseX <= m_BottomLeft.x + m_Width && m_BottomLeft.y + m_Height - m_WallThickness <=
		mouseY && mouseY <= m_BottomLeft.y + m_Height)
	{
		return true;
	}
	return false;
}

bool Elevator::IsTouchingBorder()
{
	if (m_BottomLeft.y < m_Border)
	{
		m_State = ElevatorStates::UP;
		return true;
	}
	if (m_BottomLeft.y + m_Height > g_WindowHeight - m_Border)
	{
		m_State = ElevatorStates::DOWN;
		return true;
	}
	return false;
}

void Elevator::Update(float deltaTime)
{
	if (m_IsActive)
	{
		IsTouchingBorder();
		switch (m_State)
		{
		case ElevatorStates::UP:
			m_BottomLeft.y += m_Speed * deltaTime;
			break;
		case ElevatorStates::DOWN:
			m_BottomLeft.y -= m_Speed * deltaTime;
			break;
		case ElevatorStates::BOOT:
		case ElevatorStates::IDLE:
			break;
		}
	}
}

