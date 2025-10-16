// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "RandomLine.h"
#include "utils.h"

RandomLine::RandomLine()
	: m_Color{}
	  , m_ColorYellow{1.0f, 1.0f, 0, 1.0f}
	  , m_Transparent{0, 0, 0, 0}
	  , m_State{}
{
	Init();
}

void RandomLine::Init()
{
	m_State = MotionState::MOVING;
	m_P2.SetAngle(m_P1.GetAngle());
	SetColor();
}

void RandomLine::SetColor()
{
	switch (m_State)
	{
	case MotionState::FROZEN:
		m_Color = m_Transparent;
		break;
	case MotionState::MOVING:
		m_Color = m_ColorYellow;
		break;
	}
}

void RandomLine::Draw() const
{
	utils::SetColor(m_Color);
	utils::DrawLine(m_P1.GetPos(), m_P2.GetPos());
}

void RandomLine::ToggleMotion()
{
	switch (m_State)
	{
	case MotionState::FROZEN:
		m_State = MotionState::MOVING;
		m_Color = m_ColorYellow;
		break;
	case MotionState::MOVING:
		m_State = MotionState::FROZEN;
		m_Color = m_Transparent;
		break;
	}
}

void RandomLine::Update(float deltaTime)
{
	switch (m_State)
	{
	case MotionState::FROZEN:
		break;
	case MotionState::MOVING:
		m_P1.Update(deltaTime);
		m_P2.Update(deltaTime);
		break;
	}
}
