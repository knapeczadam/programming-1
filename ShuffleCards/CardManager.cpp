// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "CardManager.h"
#include "structs.h"

#include <string>

CardManager::CardManager()
	: m_Deck{nullptr}
	  , m_NrSuits{4}
	  , m_NrRanks{13}
	  , m_NrCards{}
	  , m_Width{140.0f / 2}
	  , m_Height{190.0f / 2}
	  , m_NrSwaps{}
{
	m_NrCards = m_NrSuits * m_NrRanks;
	m_Deck = new utils::Texture[m_NrCards]{};
	InitDeck();
}

CardManager::~CardManager()
{
	for (int idx{0}; idx < m_NrCards; ++idx)
	{
		utils::DeleteTexture(m_Deck[idx]);
	}
	delete[] m_Deck;
}

void CardManager::Draw() const
{
	for (int i{m_NrSuits - 1}, h{}; i >= 0; --i, ++h)
	{
		for (int j{0}; j < m_NrRanks; ++j)
		{
			const int idx{utils::GetIndex(i, j, m_NrRanks)};
			const Point2f bottomLeft{j * m_Width, h * m_Height};
			Rectf destRect{bottomLeft.x, bottomLeft.y, m_Width, m_Height};
			utils::DrawTexture(m_Deck[idx], destRect);
		}
	}
}

void CardManager::InitDeck()
{
	for (int rIdx{0}; rIdx < m_NrSuits; ++rIdx)
	{
		for (int cIdx{0}; cIdx < m_NrRanks; ++cIdx)
		{
			const int idx{utils::GetIndex(rIdx, cIdx, m_NrRanks)};
			m_Deck[idx].width = m_Width;
			m_Deck[idx].height = m_Height;
			const std::string suit{std::to_string(rIdx + 1)};
			std::string rank;
			if (cIdx < 9)
			{
				rank = "0" + std::to_string(cIdx + 1);
			}
			else
			{
				rank = std::to_string(cIdx + 1);
			}
			const std::string path{"Resources/" + suit + rank + ".png"};
			utils::TextureFromFile(path, m_Deck[idx]);
		}
	}
}

void CardManager::Shuffle()
{
	m_NrSwaps = utils::GetRand(1, 5);
	utils::Shuffle(m_Deck, m_NrCards, m_NrSwaps);
}
