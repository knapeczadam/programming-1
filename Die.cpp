#include "pch.h"
#include "Die.h"

#include <iostream>


Die::Die(const Point2f& pos, float scale)
	: Die(pos, scale, "Resources/dice_sprites.png")
{
}

Die::Die(const Point2f& pos, float scale, const std::string& path)
	: m_Pos{pos}
	  , m_Scale{scale}
	  , m_SpritePath{path}
	  , m_SpriteSheet{}
	  , m_ColorIdx{0}
	  , m_DieIdx{0}
	  , m_NrRows{10}
	  , m_NrCols{9}
	  , m_AccuSec{}
	  , m_FrameSec{0.05f}
	  , m_State{State::idle}
{
	if (m_Scale < 0 || m_Scale > 1.0f)
	{
		m_Scale = 1.0f;
	}
	m_ColorIdx = std::rand() % m_NrRows;
	m_DieIdx = std::rand() % 6;
	utils::TextureFromFile(m_SpritePath, m_SpriteSheet);
}

Die::~Die()
{
	utils::DeleteTexture(m_SpriteSheet);
}


int Die::GetDots()
{
	if (m_State == State::rolled)
	{
		return m_DieIdx + 1;
	}
	return 0;
}

void Die::SetScale(float scale)
{
	m_Scale = scale;
}

void Die::Draw()
{
	Rectf src;
	src.width = m_SpriteSheet.width / m_NrCols;
	src.height = m_SpriteSheet.height / m_NrRows;
	src.left = src.width * m_DieIdx;
	src.bottom = src.height + src.height * m_ColorIdx;

	Rectf dst;
	dst.width = src.width;
	dst.height = src.height;
	dst.left = m_Pos.x;
	dst.bottom = m_Pos.y;

	utils::DrawTexture(m_SpriteSheet, dst, src);
}

void Die::Update(float deltaTime)
{
	if (m_State == State::rolling)
	{
		m_AccuSec += deltaTime;
		if (m_AccuSec >= m_FrameSec)
		{
			m_AccuSec = 0;
			m_DieIdx = Randomize(true);
		}
	}
}


void Die::CheckHit(const Point2f& pos)
{
	CheckHit(pos.x, pos.y);
}

void Die::CheckHit(float mouseX, float mouseY)
{
	const bool withinX{m_Pos.x <= mouseX && mouseX <= m_Pos.x + GetDieWidth()};
	const bool withinY{m_Pos.y <= mouseY && mouseY <= m_Pos.y + GetDieHeight()};
	if (withinX && withinY)
	{
		if (m_State == State::idle)
		{
			m_State = State::rolling;
			return;
		}
		if (m_State == State::rolling)
		{
			m_State = State::rolled;
			m_DieIdx = Randomize(false);
			return;
		}
	}
}

int Die::Randomize(bool isRolling)
{
	if (isRolling)
	{
		return std::rand() % 3 + 6;
	}
	return std::rand() % 6;
}

float Die::GetDieWidth()
{
	return m_SpriteSheet.width / m_NrCols * m_Scale;
}

float Die::GetDieHeight()
{
	return m_SpriteSheet.height / m_NrRows * m_Scale;
}

State Die::GetState()
{
	return m_State;
}

void Die::ResetState()
{
	m_State = State::idle;
}

void Die::SetPosition(const Point2f& pos)
{
	m_Pos = pos;
}


