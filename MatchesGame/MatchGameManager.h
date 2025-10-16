// Knapecz, Adam - 1DAE11
#pragma once
#include <vector>

class MatchGameManager
{
public:
	explicit MatchGameManager();
	void Draw() const;
	void OnKeyPressed(int val);
private:
	void GenerateAIMove();

	void DrawTop() const;
	void DrawPlayer() const;
	void DrawAI() const;
	void DrawMatch(float left = 0, float bottom = 0) const;

	void PrintInfo() const;
	void PrintMoves() const;
	void PrintResult() const;

	void CalculatePlayerScore();
	void CalculateAIScore();

	std::vector<int> m_PlayerMoves;
	std::vector<int> m_AIMoves;
	const int m_MinRemove;
	const int m_MaxRemove;

	const float m_MatchWidth;
	const float m_MatchHeadHeight;
	const float m_MatchBodyHeight;
	const float m_MatchHeight;
	const Color4f m_ColorMatchHead;
	const Color4f m_ColorMatchBody;

	const float m_Border;
	const float m_Spacing;

	int m_CurrentMatches;

	bool gameOver;
	bool playerWin;
};

