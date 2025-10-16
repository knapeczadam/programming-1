// Knapecz, Adam - 1DAE11
#pragma once
#include "utils.h"

#include <string>

enum class GameState
{
	PLAY,
	END
};

enum class PlayerState
{
	PLAY,
	WAIT,
	WIN,
	LOSE
};

enum class CellState
{
	FREE,
	GREENO,
	GREENX,
	WHITEO,
	WHITEX
};

enum class PlayerChoice
{
	O,
	X
};

struct Player
{
	PlayerState state{PlayerState::WAIT};
	PlayerChoice choice{PlayerChoice::O};
};

class OXOGameManager
{
public:
	explicit OXOGameManager();
	void Draw() const;
	void ToggleLeftChoice();
	void ToggleRightChoice();
	void ProcessClick(float mouseX, float mouseY);
	void Reset();
	~OXOGameManager();
private:
	void Init();
	void InitResources();
	void InitGame();
	void SetDefaults();

	void CalculateDimensions();
	void DeleteResources();

	void DrawLeftPlayer() const;
	void DrawRightPlayer() const;
	void DrawGrid() const;
	void DrawCell(const utils::Texture& tex, const Point2f& bottomLeft) const;
	void DrawBackground() const;

	void ToggleTurn();

	int GetIndex(int rowIdx, int colIdx, int cols) const;
	bool SetCell(int rowIdx, int colIdx);

	bool WithinCell(float mouseX, float mouseY, int& rowIdx, int& colIdx) const;
	bool CanOverwriteCell(const CellState& cellState) const;
	bool HasWinner();

	void PrintDebug() const;

	utils::Texture m_tFreeCell;
	utils::Texture m_tGreenO;
	utils::Texture m_tGreenX;
	utils::Texture m_tOXO;
	utils::Texture m_tWhiteO;
	utils::Texture m_tWhiteX;
	utils::Texture m_tWin;

	float m_CellWidth;
	float m_CellHeight;
	float m_GridWidth;
	float m_GridHeight;

	const std::string m_Path;
	const std::string m_ImageExtension;
	const std::string m_ErrorMsg;

	const int m_NrRows;
	const int m_NrCols;
	int m_NrCells;

	GameState m_GameState;
	Player m_LeftPlayer;
	Player m_RightPlayer;

	const float m_Border;
	const float m_Spacing;

	CellState* m_Grid;

	float m_Scale;
	Point2f m_BottomLeft;

	const Color4f m_ColorBackground;
	bool m_Overwrite;
	bool m_Debug;
};
