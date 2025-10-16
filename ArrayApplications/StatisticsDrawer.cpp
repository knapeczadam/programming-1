// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "StatisticsDrawer.h"
#include "Core.h"

#include <iostream>

StatisticsDrawer::StatisticsDrawer()
	: m_Rows{nullptr}
	  , m_Textures{nullptr}
	  , m_NrRows{5}
	  , m_RectColor{0.7f, 0.7f, 0, 1.0f}
	  , m_TexColor{0, 0, 0, 1.0f}
	  , m_TexSize{8}
	  , m_Spacing{10.0f} // terkoz
	  , m_PaddingLeft{10.0f}
	  , m_BottomLeft{20.0f, g_WindowHeight / 2 + 50.0f}
	  , m_Height{10.0f}
	  , m_OutOfWindow{false}
{
	m_Rows = new int[m_NrRows]{};
	m_Textures = new utils::Texture[m_NrRows]{};
	InitTexts();
}

StatisticsDrawer::~StatisticsDrawer()
{
	for (int idx{0}; idx < m_NrRows; ++idx)
	{
		utils::DeleteTexture(m_Textures[idx]);
	}
	delete[] m_Rows;
	delete[] m_Textures;
}

void StatisticsDrawer::InitTexts()
{
	for (int idx{0}; idx < m_NrRows; ++idx)
	{
		utils::TextureFromString(std::to_string(idx), "Resources/DIN-Light.otf", m_TexSize, m_TexColor, m_Textures[idx]);
	}
}

void StatisticsDrawer::DrawRandStats() const
{
	utils::SetColor(m_RectColor);
	for (int idx{0}; idx < m_NrRows; ++idx)
	{
		utils::FillRect(m_BottomLeft.x + m_PaddingLeft, m_BottomLeft.y + idx * (m_Height + m_Spacing), float(m_Rows[idx]), m_Height);
		const float x{m_BottomLeft.x};
		const float y{m_BottomLeft.y + idx * (m_Height + m_Spacing)};
		utils::DrawTexture(m_Textures[idx], Point2f{x, y});
	}
}

void StatisticsDrawer::UpdateRandStats(float deltaTime)
{
	if (!m_OutOfWindow)
	{
		const int randIdx{utils::GetRand(0, m_NrRows - 1)};
		++m_Rows[randIdx];
		if (m_Rows[randIdx] + m_BottomLeft.x + m_PaddingLeft >= int(g_WindowWidth))
		{
			m_OutOfWindow = true;
		}
	}
}
