#pragma once
#include "Car.h"

#include <string>

#define DEBUG 1

#if DEBUG
#define LOG(x) std::cout << x << std::endl;
#define LOG_FUNCTION_NAME() std::cout << __FUNCTION__ << std::endl;
#else
#define LOG(x)
#define LOG_FUNCTION_NAME()
#endif

enum class Movement
{
	left,
	right,
	up,
	down
};

class RushHour
{
#pragma region Functions

public:
	RushHour();
	~RushHour();
	void CleanUp();

	// LEVEL
	void ResetLevel();

	// DRAW
	void Draw();

	// INPUT
	void MoveCar(Movement dir);
	void ProcessMouseInput(float mouseX, float mouseY);
	void ToggleInstructionsCanvas();

private:
	// INIT
	void Init();
	void InitGrid();
	void InitCars();
	void InitSteps();
	void InitText();
	void InitImages();

	// LEVEL 
	void LoadLevel(int levelID);
	void SetUpPositions();
	bool HasWon() const;

	// DRAW
	void DrawGrid() const;
	void DrawCar() const;
	void DrawPadding() const;
	void DrawBorder() const;
	void DrawExit() const;
	void DrawWonCanvas() const;
	void DrawInstructionsCanvas() const;
	void DrawNextButton() const;
	void DrawResetButton() const;
	void DrawUIBackGround() const;
	void DrawBackground() const;
	void DrawSteps();
	void DrawDifficulty();

	// GRID
	int GetIndex(int rowIdx, int colIdx, int nrCols) const;
	bool IsCellEmpty(int rowIdx, int colIdx) const;

	// INPUT
	void SelectCar(float mouseX, float mouseY);
	void OnNextButtonClicked(float mouseX, float mouseY);
	void OnResetButtonClicked(float mouseX, float mouseY);

	// DEBUG
	void DebugGrid() const;
	void DebugSteps() const;
#pragma endregion Functions
#pragma region Members

private:
	// GAME
	bool m_isPaused;
	bool m_hasGameWon;

	// GRID
	int* m_ptrGrid;
	const int m_nrRows;
	const int m_nrCols;
	const int m_emptyCell;
	const int m_playerID;
	const Point2 m_exitPos;

	// LEVEL
	int m_currentLevel;
	const int m_nrLevels;
	int* m_ptrSteps;
	int m_currentSteps;

	// CARS
	const int m_nrCars;
	Car* m_ptrCars;
	int m_selectedCarId;

	// UI
	GridBottomLeft m_gridBottomLeft;
	float m_nextButtonLeft;
	float m_nextButtonBottom;
	float m_resetButtonLeft;
	float m_resetButtonBottom;
	const float m_cellWidth;
	const float m_border;
	const float m_padding;
	const float m_lineWidth;
	const float m_nextButtonWidth;
	const float m_nextButtonHeight;
	const float m_resetButtonWidth;
	const float m_resetButtonHeight;
	const std::string m_fontPath;

	// TEXTURES
	utils::Texture m_creditsTexture;
	utils::Texture m_instructionsTitleTexture;
	utils::Texture m_explanationPart1Texture;
	utils::Texture m_explanationPart2Texture;
	utils::Texture m_controlsTitleTexture;
	utils::Texture m_mouseControlsTexture;
	utils::Texture m_resetTexture;
	utils::Texture m_continueTexture;
	utils::Texture m_horizontalCarControlsTexture;
	utils::Texture m_verticalCarControlsTexture;

	utils::Texture m_wonTitleTexture;
	utils::Texture m_trophyTexture;
	utils::Texture m_mouseTexture;

	utils::Texture m_redCarHorTexture;
	utils::Texture m_redCarVerTexture;

	utils::Texture m_greenCarHorTexture;
	utils::Texture m_greenCarVerTexture;

	utils::Texture m_orangeCarHorTexture;
	utils::Texture m_orangeCarVerTexture;

	utils::Texture m_turquoiseCarHorTexture;
	utils::Texture m_turquoiseCarVerTexture;

	utils::Texture m_roseCarHorTexture;
	utils::Texture m_roseCarVerTexture;

	utils::Texture m_purpleCarHorTexture;
	utils::Texture m_purpleCarVerTexture;

	utils::Texture m_darkGreenCarHorTexture;
	utils::Texture m_darkGreenCarVerTexture;

	utils::Texture m_lightGrayCarHorTexture;
	utils::Texture m_lightGrayCarVerTexture;

	utils::Texture m_lightYellowCarHorTexture;
	utils::Texture m_lightYellowCarVerTexture;

	utils::Texture m_yellowCarHorTexture;
	utils::Texture m_yellowCarVerTexture;

	utils::Texture m_brownCarHorTexture;
	utils::Texture m_brownCarVerTexture;

	utils::Texture m_darkYellowCarHorTexture;
	utils::Texture m_darkYellowCarVerTexture;

	utils::Texture m_goldTruckHorTexture;
	utils::Texture m_goldTruckVerTexture;

	utils::Texture m_lavenderTruckHorTexture;
	utils::Texture m_lavenderTruckVerTexture;

	utils::Texture m_blueTruckHorTexture;
	utils::Texture m_blueTruckVerTexture;

	utils::Texture m_darkTealTruckHorTexture;
	utils::Texture m_darkTealTruckVerTexture;

	utils::Texture m_backgroundTexture;
	utils::Texture m_currentStepsTexture;
	utils::Texture m_roadTexture;

	utils::Texture m_easyDifficultyTexture;
	utils::Texture m_mediumDifficultyTexture;
	utils::Texture m_hardDifficultyTexture;
	utils::Texture m_expertDifficultyTexture;
	utils::Texture m_levelTexture;
#pragma endregion Members
};
