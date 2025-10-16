// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "MatchGameManager.h"
#include "Core.h"

#include <numeric>
#include <iostream>

MatchGameManager::MatchGameManager()
	: m_PlayerMoves{}
	  , m_AIMoves{}
	  , m_MinRemove{1}
	  , m_MaxRemove{3}
	  , m_MatchWidth{5.0f}
	  , m_MatchHeadHeight{10.0f}
	  , m_MatchBodyHeight{40.0f}
	  , m_MatchHeight{m_MatchHeadHeight + m_MatchBodyHeight}
	  , m_ColorMatchHead{1.0f, 1.0f, 0, 1.0f}
	  , m_ColorMatchBody{0.8f, 0.2f, 0, 1.0f}
	  , m_Border{20.0f}
	  , m_Spacing{10.0f}
	  , m_CurrentMatches{21}
	  , gameOver{false}
	  , playerWin{false}
{

}

void MatchGameManager::Draw() const
{
	DrawTop();
	DrawPlayer();
	DrawAI();
}

void MatchGameManager::DrawTop() const
{
	for (int i{}; i < m_CurrentMatches; ++i)
	{
		const float left{m_Border + i * m_MatchWidth + i * m_Spacing};
		const float bottom{g_WindowHeight - m_Border - m_MatchHeight};
		DrawMatch(left, bottom);
	}
}

void MatchGameManager::DrawPlayer() const
{
	const int playerMatches{std::accumulate(std::begin(m_PlayerMoves), std::end(m_PlayerMoves), 0)};
	for (int i{}; i < playerMatches; ++i)
	{
		const float left{m_Border + i * m_MatchWidth + i * m_Spacing};
		const float bottom{m_Border};
		DrawMatch(left, bottom);
	}
}

void MatchGameManager::DrawAI() const
{
	const int aiMatches{std::accumulate(std::begin(m_AIMoves), std::end(m_AIMoves), 0)};
	for (int i{}; i < aiMatches; ++i)
	{
		const float left{g_WindowWidth / 2 + m_Border + i * m_MatchWidth + i * m_Spacing};
		const float bottom{m_Border};
		DrawMatch(left, bottom);
	}
}

void MatchGameManager::DrawMatch(float left, float bottom) const
{
	// HEAD
	utils::SetColor(m_ColorMatchHead);
	utils::FillRect(left, bottom + m_MatchBodyHeight, m_MatchWidth, m_MatchHeadHeight);
	// BODY
	utils::SetColor(m_ColorMatchBody);
	utils::FillRect(left, bottom, m_MatchWidth, m_MatchBodyHeight);
}

void MatchGameManager::OnKeyPressed(int val)
{
	if (!gameOver && val <= m_CurrentMatches)
	{
		m_PlayerMoves.push_back(val);
		CalculatePlayerScore();
	}
}

void MatchGameManager::GenerateAIMove()
{
	switch (m_CurrentMatches)
	{
	case 1:
		m_AIMoves.push_back(1);
		break;
	case 2:
	case 3:
	case 4:
		m_AIMoves.push_back(m_CurrentMatches - 1);
		break;
	default:
		const int val{std::rand() % m_MaxRemove + m_MinRemove};
		m_AIMoves.push_back(val);
		break;
	}
	CalculateAIScore();
}

void MatchGameManager::CalculatePlayerScore()
{
	const int lastMove{m_PlayerMoves[m_PlayerMoves.size() - 1]};
	m_CurrentMatches -= lastMove;
	if (m_CurrentMatches <= 0)
	{
		gameOver = true;
		PrintInfo();
		return;
	}
	GenerateAIMove();
}

void MatchGameManager::CalculateAIScore()
{
	const int lastMove{m_AIMoves[m_AIMoves.size() - 1]};
	m_CurrentMatches -= lastMove;
	if (m_CurrentMatches <= 0)
	{
		gameOver = true;
		playerWin = true;
		PrintInfo();
	}
}

void MatchGameManager::PrintMoves() const
{
	std::cout << "PC moves:  ";
	for (const int& move : m_AIMoves)
	{
		std::cout << ' ' << move;
	}
	std::cout << std::endl;

	std::cout << "Your moves:";
	for (const int& move : m_PlayerMoves)
	{
		std::cout << ' ' << move;
	}
	std::cout << std::endl;
}

void MatchGameManager::PrintResult() const
{
	std::cout << "You " << (playerWin ? "win" : "lose") << std::endl;
}

void MatchGameManager::PrintInfo() const
{
	PrintMoves();
	PrintResult();
}

