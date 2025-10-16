// Knapecz, Adam - 1DAE11
#pragma once

class CardManager
{
public:
	explicit CardManager();
	void Shuffle();
	void Draw() const;
	~CardManager();
private:
	void InitDeck();
	utils::Texture* m_Deck;
	const int m_NrSuits;
	const int m_NrRanks;
	int m_NrCards;
	const float m_Width;
	const float m_Height;
	int m_NrSwaps;
};

