// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Tile.h"

Tile::Tile(const Rectf& dstRect, const std::string& texPath, int nrAnimals)
	: m_DstRect{dstRect}
	  , m_TexPath{texPath}
	  , m_NrAnimals{nrAnimals}
	  , m_CurrAnimal{}
	  , m_Active{false}
	  , m_ColorGrey{0.2f, 0.2f, 0.2f, 0.5f}
	  , m_ColorRed{1.0f, 0, 0, 1.0f}
	  , m_SmallRectRatio{4}
{
	utils::TextureFromFile(texPath, m_Texture);
}

void Tile::Draw() const
{
	Rectf srcRect;
	srcRect.width = m_Texture.width / m_NrAnimals;
	srcRect.height = m_Texture.height;
	srcRect.left = srcRect.width * m_CurrAnimal;;
	srcRect.bottom = srcRect.height;
	utils::DrawTexture(m_Texture, m_DstRect, srcRect);
	if (m_Active)
	{
		utils::SetColor(m_ColorGrey);
		utils::FillRect(m_DstRect);
		utils::SetColor(m_ColorRed);
		utils::DrawRect(m_DstRect.left, m_DstRect.bottom, m_DstRect.width / m_SmallRectRatio,
		                m_DstRect.height / m_SmallRectRatio);
		utils::DrawRect(m_DstRect.left + m_DstRect.width - m_DstRect.width / m_SmallRectRatio, m_DstRect.bottom,
		                m_DstRect.width / m_SmallRectRatio, m_DstRect.height / m_SmallRectRatio);
	}
}

void Tile::CheckActivation(const Point2f& pos)
{
	const bool withinX{m_DstRect.left <= pos.x && pos.x <= m_DstRect.left + m_DstRect.width};
	const bool withinY{m_DstRect.bottom <= pos.y && pos.y <= m_DstRect.bottom + m_DstRect.height};
	if (withinX && withinY)
	{
		m_Active = true;
	}
	else
	{
		m_Active = false;
	}
}

bool Tile::CheckHit(const Point2f& pos)
{
	const bool withinLeftX{m_DstRect.left <= pos.x && pos.x <= m_DstRect.left + m_DstRect.width / m_SmallRectRatio};
	const bool withinRightX{
		m_DstRect.left + (m_DstRect.width - m_DstRect.width / m_SmallRectRatio) <= pos.x && pos.x <= m_DstRect.left +
		m_DstRect.width
	};
	const bool withinY{m_DstRect.bottom <= pos.y && pos.y <= m_DstRect.bottom + m_DstRect.height / m_SmallRectRatio};
	if (withinLeftX && withinY)
	{
		--m_CurrAnimal;
		if (m_CurrAnimal < 0)
		{
			m_CurrAnimal = m_NrAnimals - 1;
		}
		return true;
	}
	if (withinRightX && withinY)
	{
		++m_CurrAnimal %= m_NrAnimals;
		return true;
	}
	return false;
}

int Tile::GetCurrentAnimal() const
{
	return m_CurrAnimal;
}

void Tile::Deactivate()
{
	m_Active = false;
}

void Tile::Randomize()
{
	m_CurrAnimal = std::rand() % m_NrAnimals;
}

