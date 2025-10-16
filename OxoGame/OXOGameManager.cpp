// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "OXOGameManager.h"
#include "Core.h"

#include <iomanip>
#include <iostream>

OXOGameManager::OXOGameManager()
	:
	m_CellWidth{}
	, m_CellHeight{}
	, m_GridWidth{}
	, m_GridHeight{}
	, m_Path{"Resources/OXO/"}
	, m_ImageExtension{".png"}
	, m_ErrorMsg{"Failed to load file: "}
	, m_NrRows{4}
	, m_NrCols{4}
	, m_NrCells{}
	, m_Border{30.0f}
	, m_Spacing{5.0f}
	, m_Grid{}
	, m_Scale{1.0f}
	, m_Debug{}
	, m_ColorBackground{0.3f, 0.3f, 0.3f, 1.0f}
	, m_Overwrite{}
{
	Init();
}

OXOGameManager::~OXOGameManager()
{
	DeleteResources();
}

void OXOGameManager::DeleteResources()
{
	const int nrFiles{7};
	utils::Texture* textures[nrFiles]{&m_tFreeCell, &m_tGreenO, &m_tGreenX, &m_tOXO, &m_tWhiteO, &m_tWhiteX, &m_tWin};
	for (int idx{0}; idx < nrFiles; ++idx)
	{
		utils::DeleteTexture(*textures[idx]);
	}
}

void OXOGameManager::Init()
{
	InitResources();
	InitGame();
	SetDefaults();
	CalculateDimensions();
	if (m_Debug)
	{
		PrintDebug();
	}
}

void OXOGameManager::InitResources()
{
	const int nrFiles{7};
	const std::string files[nrFiles]{"FreeCell", "GreenO", "GreenX", "OXO", "WhiteO", "WhiteX", "Win"};
	utils::Texture* textures[nrFiles]{&m_tFreeCell, &m_tGreenO, &m_tGreenX, &m_tOXO, &m_tWhiteO, &m_tWhiteX, &m_tWin};
	for (int idx{0}; idx < nrFiles; ++idx)
	{
		if (!utils::TextureFromFile(m_Path + files[idx] + m_ImageExtension, *textures[idx]))
		{
			std::cout << m_ErrorMsg << (files[idx] + m_ImageExtension) << std::endl;
		}
	}
}

void OXOGameManager::InitGame()
{
	m_NrCells = m_NrRows * m_NrCols;
	m_Grid = new CellState[m_NrCells]{};
	m_Overwrite = false;
	m_Debug = true;
}

void OXOGameManager::SetDefaults()
{
	m_GameState = GameState::PLAY;
	m_LeftPlayer.state = PlayerState::PLAY;
	m_RightPlayer.state = PlayerState::WAIT;
	for (int idx{0}; idx < m_NrCells; ++idx)
	{
		m_Grid[idx] = CellState::FREE;
	}
}

void OXOGameManager::CalculateDimensions()
{
	const Point2f center{g_WindowWidth / 2, g_WindowHeight / 2};
	m_CellWidth = m_tFreeCell.width;
	m_CellHeight = m_tFreeCell.height;
	m_GridWidth = m_CellWidth * m_NrCols + m_Spacing * (m_NrCols - 1);
	m_GridHeight = m_CellHeight * m_NrRows + m_Spacing * (m_NrRows - 1);
	m_BottomLeft.x = center.x - m_GridWidth / 2;
	m_BottomLeft.y = center.y - m_GridHeight / 2;
}

void OXOGameManager::PrintDebug() const
{
	std::cout << std::boolalpha;
	std::cout << "mNrOfCells = " << m_NrCells << std::endl;
	std::cout << "mOverwrite = " << m_Overwrite << std::endl;
	for (int rIdx{0}; rIdx < m_NrRows; ++rIdx)
	{
		for (int cIdx{0}; cIdx < m_NrCols; ++cIdx)
		{
			std::cout << int(m_Grid[GetIndex(rIdx, cIdx, m_NrCols)]) << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void OXOGameManager::Reset()
{
	SetDefaults();
	if (m_Debug)
	{
		PrintDebug();
	}
}

void OXOGameManager::ToggleLeftChoice()
{
	if (m_LeftPlayer.state == PlayerState::PLAY)
	{
		m_LeftPlayer.choice = m_LeftPlayer.choice == PlayerChoice::O ? PlayerChoice::X : PlayerChoice::O;
	}
}

void OXOGameManager::ToggleRightChoice()
{
	if (m_RightPlayer.state == PlayerState::PLAY)
	{
		m_RightPlayer.choice = m_RightPlayer.choice == PlayerChoice::O ? PlayerChoice::X : PlayerChoice::O;
	}
}

void OXOGameManager::ProcessClick(float mouseX, float mouseY)
{
	if (m_GameState == GameState::PLAY)
	{
		int rIdx{};
		int cIdx{};
		if (WithinCell(mouseX, mouseY, rIdx, cIdx))
			if (SetCell(rIdx, cIdx))
			{
				if (!HasWinner())
				{
					ToggleTurn();
				}
			}
	}
}

bool OXOGameManager::WithinCell(float mouseX, float mouseY, int& rowIdx, int& colIdx) const
{
	const bool withinX{m_BottomLeft.x <= mouseX && mouseX <= m_BottomLeft.x + m_GridWidth};
	const bool withinY{m_BottomLeft.y <= mouseY && mouseY <= m_BottomLeft.y + m_GridHeight};
	if (withinX && withinY)
	{
		mouseX -= m_BottomLeft.x;
		mouseY -= m_BottomLeft.y;
		int qX{int(mouseX) / int(m_CellWidth)};
		const int mX{int(mouseX) % int(m_CellWidth)};
		if (m_Spacing * (qX - 1) < mX && mX < qX * m_Spacing) // check for col - whether the player clicked on spacin
		{
			return false;
		}
		if (mX < qX * m_Spacing)
		{
			--qX;
		}
		int qY{int(mouseY) / int(m_CellHeight)};
		const int mY{int(mouseY) % int(m_CellHeight)};
		if (m_Spacing * (qY - 1) < mY && mY < qY * m_Spacing) // check for row / whether the player clicked on spacing
		{
			return false;
		}
		if (mY < qY * m_Spacing)
		{
			--qY;
		}
		rowIdx = qY;
		colIdx = qX;
		return true;
	}
	return false;
}

int OXOGameManager::GetIndex(int rowIdx, int colIdx, int cols) const
{
	return rowIdx * cols + colIdx;
}

bool OXOGameManager::SetCell(int rowIdx, int colIdx)
{
	const CellState cellState{m_Grid[GetIndex(rowIdx, colIdx, m_NrCols)]};
	if (cellState != CellState::FREE && !CanOverwriteCell(cellState)) return false;

	CellState newCellState{CellState::FREE};
	if (m_LeftPlayer.state == PlayerState::PLAY)
	{
		newCellState = m_LeftPlayer.choice == PlayerChoice::O ? CellState::WHITEO : CellState::WHITEX;
	}
	else if (m_RightPlayer.state == PlayerState::PLAY)
	{
		newCellState = m_RightPlayer.choice == PlayerChoice::O ? CellState::WHITEO : CellState::WHITEX;
	}

	m_Grid[GetIndex(rowIdx, colIdx, m_NrCols)] = newCellState;
	return true;
}

bool OXOGameManager::CanOverwriteCell(const CellState& cellState) const
{
	if (!m_Overwrite) return false;
	if (m_LeftPlayer.state == PlayerState::PLAY)
	{
		switch (cellState)
		{
		case CellState::WHITEO:
			return m_LeftPlayer.choice == PlayerChoice::X;
		case CellState::WHITEX:
			return m_LeftPlayer.choice == PlayerChoice::O;
		}
	}
	else if (m_RightPlayer.state == PlayerState::PLAY)
	{
		switch (cellState)
		{
		case CellState::WHITEO:
			return m_RightPlayer.choice == PlayerChoice::X;
		case CellState::WHITEX:
			return m_RightPlayer.choice == PlayerChoice::O;
		}
	}
	return false;
}

bool OXOGameManager::HasWinner()
{
	const int nrPatterns{3};
	bool hasWinner{};
	int idx1{};
	int idx2{};
	int idx3{};
	bool o1{};
	bool x1{};
	bool o2{};
	// check upwards - straight
	for (int rIdx{0}; rIdx <= m_NrRows - nrPatterns; ++rIdx)
	{
		for (int cIdx{0}; cIdx < m_NrCols; ++cIdx)
		{
			idx1 = GetIndex(rIdx + 0, cIdx, m_NrCols);
			idx2 = GetIndex(rIdx + 1, cIdx, m_NrCols);
			idx3 = GetIndex(rIdx + 2, cIdx, m_NrCols);
			o1 = m_Grid[idx1] == CellState::WHITEO;
			x1 = m_Grid[idx2] == CellState::WHITEX;
			o2 = m_Grid[idx3] == CellState::WHITEO;
			if (o1 && x1 && o2)
			{
				m_Grid[idx1] = CellState::GREENO;
				m_Grid[idx2] = CellState::GREENX;
				m_Grid[idx3] = CellState::GREENO;
				hasWinner = true;
				break;
			}
		}
	}

	// check to the right - straight
	for (int cIdx{0}; cIdx <= m_NrCols - nrPatterns; ++cIdx)
	{
		for (int rIdx{0}; rIdx < m_NrRows; ++rIdx)
		{
			idx1 = GetIndex(rIdx, cIdx + 0, m_NrCols);
			idx2 = GetIndex(rIdx, cIdx + 1, m_NrCols);
			idx3 = GetIndex(rIdx, cIdx + 2, m_NrCols);
			o1 = m_Grid[idx1] == CellState::WHITEO;
			x1 = m_Grid[idx2] == CellState::WHITEX;
			o2 = m_Grid[idx3] == CellState::WHITEO;
			if (o1 && x1 && o2)
			{
				m_Grid[idx1] = CellState::GREENO;
				m_Grid[idx2] = CellState::GREENX;
				m_Grid[idx3] = CellState::GREENO;
				hasWinner = true;
				break;
			}
		}
	}

	// check for for slash
	for (int rIdx{0}; rIdx <= m_NrRows - nrPatterns; ++rIdx)
	{
		for (int cIdx{0}; cIdx < m_NrCols - 2; ++cIdx)
		{
			idx1 = GetIndex(rIdx + 0, cIdx + 0, m_NrCols);
			idx2 = GetIndex(rIdx + 1, cIdx + 1, m_NrCols);
			idx3 = GetIndex(rIdx + 2, cIdx + 2, m_NrCols);
			o1 = m_Grid[idx1] == CellState::WHITEO;
			x1 = m_Grid[idx2] == CellState::WHITEX;
			o2 = m_Grid[idx3] == CellState::WHITEO;
			if (o1 && x1 && o2)
			{
				m_Grid[idx1] = CellState::GREENO;
				m_Grid[idx2] = CellState::GREENX;
				m_Grid[idx3] = CellState::GREENO;
				hasWinner = true;
				break;
			}
		}
	}

	// check for backslash
	for (int rIdx{0}; rIdx <= m_NrRows - nrPatterns; ++rIdx)
	{
		for (int cIdx{0}; cIdx < m_NrCols - 2; ++cIdx)
		{
			idx1 = GetIndex(rIdx + 0, 2 + cIdx, m_NrCols);
			idx2 = GetIndex(rIdx + 1, 1 + cIdx, m_NrCols);
			idx3 = GetIndex(rIdx + 2, 0 + cIdx, m_NrCols);
			o1 = m_Grid[idx1] == CellState::WHITEO;
			x1 = m_Grid[idx2] == CellState::WHITEX;
			o2 = m_Grid[idx3] == CellState::WHITEO;
			if (o1 && x1 && o2)
			{
				m_Grid[idx1] = CellState::GREENO;
				m_Grid[idx2] = CellState::GREENX;
				m_Grid[idx3] = CellState::GREENO;
				hasWinner = true;
				break;
			}
		}
	}
	if (hasWinner)
	{
		m_LeftPlayer.state = m_LeftPlayer.state == PlayerState::PLAY ? PlayerState::WIN : PlayerState::LOSE;
		m_RightPlayer.state = m_RightPlayer.state == PlayerState::PLAY ? PlayerState::WIN : PlayerState::LOSE;
		m_GameState = GameState::END;
	}
	return hasWinner;
}

void OXOGameManager::ToggleTurn()
{
	m_LeftPlayer.state = m_LeftPlayer.state == PlayerState::PLAY ? PlayerState::WAIT : PlayerState::PLAY;
	m_RightPlayer.state = m_LeftPlayer.state == PlayerState::PLAY ? PlayerState::WAIT : PlayerState::PLAY;
}

void OXOGameManager::DrawCell(const utils::Texture& tex, const Point2f& bottomLeft) const
{
	Rectf src;
	src.width = tex.width;
	src.height = tex.height;
	src.left = 0;
	src.bottom = src.height;

	Rectf dst;
	dst.left = bottomLeft.x;
	dst.bottom = bottomLeft.y;
	dst.width = src.width * m_Scale;
	dst.height = src.height * m_Scale;
	utils::DrawTexture(tex, dst, src);
}

void OXOGameManager::Draw() const
{
	DrawBackground();
	DrawLeftPlayer();
	DrawRightPlayer();
	DrawGrid();
}

void OXOGameManager::DrawBackground() const
{
	if (m_GameState == GameState::PLAY)
	{
		utils::ClearBackground(m_ColorBackground.r, m_ColorBackground.g, m_ColorBackground.b);
	}
	else
	{
		const float cScaleWidth{g_WindowWidth / m_tOXO.width};
		const float cScaleHeight{g_WindowHeight / m_tOXO.height};
		Rectf src;
		src.width = m_tOXO.width;
		src.height = m_tOXO.height;
		src.left = 0;
		src.bottom = src.height;

		Rectf dst;
		dst.width = src.width * cScaleWidth;
		dst.height = src.height * cScaleHeight;
		utils::DrawTexture(m_tOXO, dst, src);
	}
}

void OXOGameManager::DrawLeftPlayer() const
{
	const Point2f pos{m_Border, m_Border};
	utils::Texture tex;
	switch (m_LeftPlayer.state)
	{
	case PlayerState::PLAY:
		tex = m_LeftPlayer.choice == PlayerChoice::O ? m_tGreenO : m_tGreenX;
		break;
	case PlayerState::WAIT:
		tex = m_LeftPlayer.choice == PlayerChoice::O ? m_tWhiteO : m_tWhiteX;
		break;
	case PlayerState::WIN:
		tex = m_tWin;
		break;
	case PlayerState::LOSE:
		tex = m_tFreeCell;
		break;
	}
	DrawCell(tex, pos);
}

void OXOGameManager::DrawRightPlayer() const
{
	const Point2f pos{g_WindowWidth - m_Border - m_tFreeCell.width * m_Scale, m_Border};
	utils::Texture tex;
	switch (m_RightPlayer.state)
	{
	case PlayerState::PLAY:
		tex = m_RightPlayer.choice == PlayerChoice::O ? m_tGreenO : m_tGreenX;
		break;
	case PlayerState::WAIT:
		tex = m_RightPlayer.choice == PlayerChoice::O ? m_tWhiteO : m_tWhiteX;
		break;
	case PlayerState::WIN:
		tex = m_tWin;
		break;
	case PlayerState::LOSE:
		tex = m_tFreeCell;
		break;
	}
	DrawCell(tex, pos);
}


void OXOGameManager::DrawGrid() const
{
	for (int rIdx{0}; rIdx < m_NrRows; ++rIdx)
	{
		for (int cIdx{0}; cIdx < m_NrCols; ++cIdx)
		{
			const CellState cell{m_Grid[GetIndex(rIdx, cIdx, m_NrCols)]};
			const Point2f pos{
				m_BottomLeft.x + cIdx * (m_CellWidth + m_Spacing), m_BottomLeft.y + rIdx * (m_CellHeight + m_Spacing)
			};
			utils::Texture tex;
			switch (cell)
			{
			case CellState::FREE:
				tex = m_tFreeCell;
				break;
			case CellState::WHITEO:
				tex = m_tWhiteO;
				break;
			case CellState::WHITEX:
				tex = m_tWhiteX;
				break;
			case CellState::GREENO:
				tex = m_tGreenO;
				break;
			case CellState::GREENX:
				tex = m_tGreenX;
				break;
			}
			DrawCell(tex, pos);
		}
	}
}
