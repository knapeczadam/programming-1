#include "pch.h"
#include "RushHour.h"
#include "Core.h"
#include "LevelData.h"

#include <iostream>
#include <vector>

RushHour::RushHour()
	: m_isPaused{false}
	, m_hasGameWon{ false }
	, m_ptrGrid{nullptr}
	, m_nrRows{6}
	, m_nrCols{6}
	, m_emptyCell{-1}
	, m_playerID{0}
	, m_exitPos{3, 6}
	, m_currentLevel{29}
	, m_nrLevels{40}
	, m_ptrSteps{nullptr}
	, m_currentSteps{0}
	, m_nrCars{16}
	, m_ptrCars{nullptr}
	, m_selectedCarId{-1}
	, m_gridBottomLeft{}
	, m_nextButtonLeft{}
	, m_nextButtonBottom{}
	, m_resetButtonLeft{}
	, m_resetButtonBottom{}
	, m_cellWidth{50.0f}
	, m_border{20.0f}
	, m_padding{5.0f}
	, m_lineWidth{1.0f}
	, m_nextButtonWidth{40.0f}
	, m_nextButtonHeight{40.0f}
	, m_resetButtonWidth{40.0f}
	, m_resetButtonHeight{40.0f}
	, m_fontPath{"Resources/Helvetica-Bold.ttf"}
	, m_creditsTexture{}
	, m_instructionsTitleTexture{}
	, m_explanationPart1Texture{}
	, m_explanationPart2Texture{}
	, m_controlsTitleTexture{}
	, m_mouseControlsTexture{}
	, m_resetTexture{}
	, m_continueTexture{}
	, m_horizontalCarControlsTexture{}
	, m_verticalCarControlsTexture{}
	, m_wonTitleTexture{}
	, m_trophyTexture{}
	, m_mouseTexture{}
	, m_redCarHorTexture{}
	, m_redCarVerTexture{}
	, m_greenCarHorTexture{}
	, m_greenCarVerTexture{}
	, m_orangeCarHorTexture{}
	, m_orangeCarVerTexture{}
	, m_turquoiseCarHorTexture{}
	, m_turquoiseCarVerTexture{}
	, m_roseCarHorTexture{}
	, m_roseCarVerTexture{}
	, m_purpleCarHorTexture{}
	, m_purpleCarVerTexture{}
	, m_darkGreenCarHorTexture{}
	, m_darkGreenCarVerTexture{}
	, m_lightGrayCarHorTexture{}
	, m_lightGrayCarVerTexture{}
	, m_lightYellowCarHorTexture{}
	, m_lightYellowCarVerTexture{}
	, m_yellowCarHorTexture{}
	, m_yellowCarVerTexture{}
	, m_brownCarHorTexture{}
	, m_brownCarVerTexture{}
	, m_darkYellowCarHorTexture{}
	, m_darkYellowCarVerTexture{}
	, m_goldTruckHorTexture{}
	, m_goldTruckVerTexture{}
	, m_lavenderTruckHorTexture{}
	, m_lavenderTruckVerTexture{}
	, m_blueTruckHorTexture{}
	, m_blueTruckVerTexture{}
	, m_darkTealTruckHorTexture{}
	, m_darkTealTruckVerTexture{}
	, m_backgroundTexture{}
	, m_currentStepsTexture{}
	, m_roadTexture{}
	, m_easyDifficultyTexture{}
	, m_mediumDifficultyTexture{}
	, m_hardDifficultyTexture{}
	, m_expertDifficultyTexture{}
	, m_levelTexture{}
{
	Init();
}

RushHour::~RushHour()
{
	CleanUp();
}

void RushHour::CleanUp()
{
	LOG_FUNCTION_NAME()

	delete[] m_ptrGrid;
	delete[] m_ptrCars;
	delete[] m_ptrSteps;

	utils::DeleteTexture(m_creditsTexture);
	utils::DeleteTexture(m_instructionsTitleTexture);
	utils::DeleteTexture(m_explanationPart1Texture);
	utils::DeleteTexture(m_explanationPart2Texture);
	utils::DeleteTexture(m_controlsTitleTexture);
	utils::DeleteTexture(m_mouseControlsTexture);
	utils::DeleteTexture(m_horizontalCarControlsTexture);
	utils::DeleteTexture(m_verticalCarControlsTexture);
	utils::DeleteTexture(m_currentStepsTexture);
	utils::DeleteTexture(m_resetTexture);
	utils::DeleteTexture(m_continueTexture);

	utils::DeleteTexture(m_wonTitleTexture);
	utils::DeleteTexture(m_trophyTexture);
	utils::DeleteTexture(m_mouseTexture);
	utils::DeleteTexture(m_backgroundTexture);
	utils::DeleteTexture(m_roadTexture);
	utils::DeleteTexture(m_easyDifficultyTexture);
	utils::DeleteTexture(m_mediumDifficultyTexture);
	utils::DeleteTexture(m_hardDifficultyTexture);
	utils::DeleteTexture(m_expertDifficultyTexture);

	utils::DeleteTexture(m_redCarHorTexture);
	utils::DeleteTexture(m_redCarVerTexture);
	utils::DeleteTexture(m_greenCarHorTexture);
	utils::DeleteTexture(m_greenCarVerTexture);
	utils::DeleteTexture(m_orangeCarHorTexture);
	utils::DeleteTexture(m_orangeCarVerTexture);
	utils::DeleteTexture(m_turquoiseCarHorTexture);
	utils::DeleteTexture(m_turquoiseCarVerTexture);
	utils::DeleteTexture(m_roseCarHorTexture);
	utils::DeleteTexture(m_roseCarVerTexture);
	utils::DeleteTexture(m_purpleCarHorTexture);
	utils::DeleteTexture(m_purpleCarVerTexture);
	utils::DeleteTexture(m_darkGreenCarHorTexture);
	utils::DeleteTexture(m_darkGreenCarVerTexture);
	utils::DeleteTexture(m_lightGrayCarHorTexture);
	utils::DeleteTexture(m_lightGrayCarVerTexture);
	utils::DeleteTexture(m_lightYellowCarHorTexture);
	utils::DeleteTexture(m_lightYellowCarVerTexture);
	utils::DeleteTexture(m_yellowCarHorTexture);
	utils::DeleteTexture(m_yellowCarVerTexture);
	utils::DeleteTexture(m_brownCarHorTexture);
	utils::DeleteTexture(m_brownCarVerTexture);
	utils::DeleteTexture(m_darkYellowCarHorTexture);
	utils::DeleteTexture(m_darkYellowCarVerTexture);
	utils::DeleteTexture(m_goldTruckHorTexture);
	utils::DeleteTexture(m_goldTruckVerTexture);
	utils::DeleteTexture(m_lavenderTruckHorTexture);
	utils::DeleteTexture(m_lavenderTruckVerTexture);
	utils::DeleteTexture(m_blueTruckHorTexture);
	utils::DeleteTexture(m_blueTruckVerTexture);
	utils::DeleteTexture(m_darkTealTruckHorTexture);
	utils::DeleteTexture(m_darkTealTruckVerTexture);
	utils::DeleteTexture(m_levelTexture);
}

void RushHour::Init()
{
	LOG_FUNCTION_NAME()
	m_ptrGrid = new int[m_nrRows * m_nrCols]{};
	m_ptrCars = new Car[m_nrCars]{};
	m_ptrSteps = new int[m_nrLevels]{};

	const Point2f center{g_WindowWidth / 2.f, g_WindowHeight / 2.f};
	const float offset{m_nrCols * m_cellWidth / 2.f};
	const Point2f bottomLeft{center.x - offset, center.y - offset};

	m_gridBottomLeft.pixel = bottomLeft;
	m_gridBottomLeft.cell.x = m_nrRows - 1;
	m_gridBottomLeft.cell.y = 0;

	m_nextButtonLeft = m_gridBottomLeft.pixel.x + m_nrCols * m_cellWidth - m_nextButtonWidth / 2;
	m_nextButtonBottom = m_gridBottomLeft.pixel.y - m_border * 2 - m_nextButtonHeight;

	m_resetButtonLeft = m_gridBottomLeft.pixel.x + m_nrCols * m_cellWidth - m_resetButtonWidth / 2;
	m_resetButtonBottom = m_gridBottomLeft.pixel.y - m_border * 2 - m_resetButtonHeight;

	InitText();
	InitImages();
	InitCars();
	LoadLevel(m_currentLevel);
	InitSteps();
}

void RushHour::InitGrid()
{
	LOG_FUNCTION_NAME()
	for (int idx{0}; idx < m_nrRows * m_nrCols; ++idx)
	{
		m_ptrGrid[idx] = m_emptyCell;
	}
}

void RushHour::InitCars()
{
	LOG_FUNCTION_NAME()
	for (int idx{0}; idx < m_nrCars; ++idx)
	{
		m_ptrCars[idx].id = idx;

		switch (idx)
		{
		// PLAYER
		case 0:
			m_ptrCars[idx].colorCode = ColorCode::X;
			m_ptrCars[idx].color = utils::Color::red;
			m_ptrCars[idx].texture.horizontal = m_redCarHorTexture;
			m_ptrCars[idx].texture.vertical = m_redCarVerTexture;
			break;
		// CARS
		case 1:
			m_ptrCars[idx].colorCode = ColorCode::A;
			m_ptrCars[idx].color = utils::Color::green;
			m_ptrCars[idx].texture.horizontal = m_greenCarHorTexture;
			m_ptrCars[idx].texture.vertical = m_greenCarVerTexture;
			break;
		case 2:
			m_ptrCars[idx].colorCode = ColorCode::B;
			m_ptrCars[idx].color = utils::Color::orange;
			m_ptrCars[idx].texture.horizontal = m_orangeCarHorTexture;
			m_ptrCars[idx].texture.vertical = m_orangeCarVerTexture;
			break;
		case 3:
			m_ptrCars[idx].colorCode = ColorCode::C;
			m_ptrCars[idx].color = utils::Color::turquoise;
			m_ptrCars[idx].texture.horizontal = m_turquoiseCarHorTexture;
			m_ptrCars[idx].texture.vertical = m_turquoiseCarVerTexture;
			break;
		case 4:
			m_ptrCars[idx].colorCode = ColorCode::D;
			m_ptrCars[idx].color = utils::Color::rose;
			m_ptrCars[idx].texture.horizontal = m_roseCarHorTexture;
			m_ptrCars[idx].texture.vertical = m_roseCarVerTexture;
			break;
		case 5:
			m_ptrCars[idx].colorCode = ColorCode::E;
			m_ptrCars[idx].color = utils::Color::purple;
			m_ptrCars[idx].texture.horizontal = m_purpleCarHorTexture;
			m_ptrCars[idx].texture.vertical = m_purpleCarVerTexture;
			break;
		case 6:
			m_ptrCars[idx].colorCode = ColorCode::F;
			m_ptrCars[idx].color = utils::Color::darkGreen;
			m_ptrCars[idx].texture.horizontal = m_darkGreenCarHorTexture;
			m_ptrCars[idx].texture.vertical = m_darkGreenCarVerTexture;
			break;
		case 7:
			m_ptrCars[idx].colorCode = ColorCode::G;
			m_ptrCars[idx].color = utils::Color::lightGray;
			m_ptrCars[idx].texture.horizontal = m_lightGrayCarHorTexture;
			m_ptrCars[idx].texture.vertical = m_lightGrayCarVerTexture;
			break;
		case 8:
			m_ptrCars[idx].colorCode = ColorCode::H;
			m_ptrCars[idx].color = utils::Color::lightYellow;
			m_ptrCars[idx].texture.horizontal = m_lightYellowCarHorTexture;
			m_ptrCars[idx].texture.vertical = m_lightYellowCarVerTexture;
			break;
		case 9:
			m_ptrCars[idx].colorCode = ColorCode::I;
			m_ptrCars[idx].color = utils::Color::yellow;
			m_ptrCars[idx].texture.horizontal = m_yellowCarHorTexture;
			m_ptrCars[idx].texture.vertical = m_yellowCarVerTexture;
			break;
		case 10:
			m_ptrCars[idx].colorCode = ColorCode::J;
			m_ptrCars[idx].color = utils::Color::brown;
			m_ptrCars[idx].texture.horizontal = m_brownCarHorTexture;
			m_ptrCars[idx].texture.vertical = m_brownCarVerTexture;
			break;
		case 11:
			m_ptrCars[idx].colorCode = ColorCode::K;
			m_ptrCars[idx].color = utils::Color::darkYellow;
			m_ptrCars[idx].texture.horizontal = m_darkYellowCarHorTexture;
			m_ptrCars[idx].texture.vertical = m_darkYellowCarVerTexture;
			break;
		// TRUCKS
		case 12:
			m_ptrCars[idx].colorCode = ColorCode::O;
			m_ptrCars[idx].color = utils::Color::gold;
			m_ptrCars[idx].texture.horizontal = m_goldTruckHorTexture;
			m_ptrCars[idx].texture.vertical = m_goldTruckVerTexture;
			m_ptrCars[idx].length = 3;
			break;
		case 13:
			m_ptrCars[idx].colorCode = ColorCode::P;
			m_ptrCars[idx].color = utils::Color::lavender;
			m_ptrCars[idx].texture.horizontal = m_lavenderTruckHorTexture;
			m_ptrCars[idx].texture.vertical = m_lavenderTruckVerTexture;
			m_ptrCars[idx].length = 3;
			break;
		case 14:
			m_ptrCars[idx].colorCode = ColorCode::Q;
			m_ptrCars[idx].color = utils::Color::blue;
			m_ptrCars[idx].texture.horizontal = m_blueTruckHorTexture;
			m_ptrCars[idx].texture.vertical = m_blueTruckVerTexture;
			m_ptrCars[idx].length = 3;
			break;
		case 15:
			m_ptrCars[idx].colorCode = ColorCode::R;
			m_ptrCars[idx].color = utils::Color::darkTeal;
			m_ptrCars[idx].texture.horizontal = m_darkTealTruckHorTexture;
			m_ptrCars[idx].texture.vertical = m_darkTealTruckVerTexture;
			m_ptrCars[idx].length = 3;
			break;
		}
	}
}

void RushHour::InitSteps()
{
	LOG_FUNCTION_NAME()
	for (int idx{0}; idx < m_nrLevels; ++idx)
	{
		m_ptrSteps[idx] = -1;
	}
}

void RushHour::InitText()
{
	LOG_FUNCTION_NAME()
	const int bigTitleFontSize{34};
	const int regularTextFontSize{14};

	bool fontSuccessfullyLoaded{utils::TextureFromString("Made by Jasper Feyaerts and Ádám Knapecz - DAE 2022", m_fontPath, regularTextFontSize, utils::Color::white, m_creditsTexture)};
	if (!fontSuccessfullyLoaded) std::cout << "Creating texture from string failed." << std::endl;

	fontSuccessfullyLoaded = utils::TextureFromString("Instructions", m_fontPath, bigTitleFontSize, utils::Color::white, m_instructionsTitleTexture);
	if (!fontSuccessfullyLoaded) std::cout << "Creating texture from string failed." << std::endl;

	fontSuccessfullyLoaded = utils::TextureFromString(
		"Rush Hours is a challenging thinking game where you attempt to free the way ", m_fontPath, regularTextFontSize,
		utils::Color::white, m_explanationPart1Texture);
	if (!fontSuccessfullyLoaded) std::cout << "Creating texture from string failed." << std::endl;

	fontSuccessfullyLoaded = utils::TextureFromString("for the red car to escape by sliding other cars out of the way.", m_fontPath, regularTextFontSize, utils::Color::white, m_explanationPart2Texture);
	if (!fontSuccessfullyLoaded) std::cout << "Creating texture from string failed." << std::endl;

	fontSuccessfullyLoaded = utils::TextureFromString("Controls", m_fontPath, bigTitleFontSize, utils::Color::white, m_controlsTitleTexture);
	if (!fontSuccessfullyLoaded) std::cout << "Creating texture from string failed." << std::endl;

	fontSuccessfullyLoaded = utils::TextureFromString("Click on a car with the left mouse button to select it.", m_fontPath, regularTextFontSize, utils::Color::white, m_mouseControlsTexture);
	if (!fontSuccessfullyLoaded) std::cout << "Creating texture from string failed." << std::endl;

	fontSuccessfullyLoaded = utils::TextureFromString(
		"When selected,press the left/right arrow key to move the horizontal car by one cell.", m_fontPath,
		regularTextFontSize, utils::Color::white, m_horizontalCarControlsTexture);
	if (!fontSuccessfullyLoaded) std::cout << "Creating texture from string failed." << std::endl;


	fontSuccessfullyLoaded = utils::TextureFromString("When selected,press the up/down arrow key to move the vertical car by one cell.", m_fontPath, regularTextFontSize, utils::Color::white, m_verticalCarControlsTexture);
	if (!fontSuccessfullyLoaded) std::cout << "Creating texture from string failed." << std::endl;

	fontSuccessfullyLoaded = utils::TextureFromString("You won!", m_fontPath, bigTitleFontSize, utils::Color::white, m_wonTitleTexture);
	if (!fontSuccessfullyLoaded) std::cout << "Creating texture from string failed." << std::endl;

	fontSuccessfullyLoaded = utils::TextureFromString(std::to_string(m_currentSteps), m_fontPath, bigTitleFontSize, utils::Color::white, m_currentStepsTexture);
	if (!fontSuccessfullyLoaded) std::cout << "Creating texture from string failed." << std::endl;

	fontSuccessfullyLoaded = utils::TextureFromString(std::to_string(m_currentLevel + 1), m_fontPath, bigTitleFontSize, utils::Color::white, m_levelTexture);
	if (!fontSuccessfullyLoaded) std::cout << "Creating texture from string failed." << std::endl;
}

void RushHour::InitImages()
{
	LOG_FUNCTION_NAME()
	// UI
	bool success{utils::TextureFromFile("resources/trophy.png", m_trophyTexture)};
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/mouse.png", m_mouseTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/reset.png", m_resetTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/continue.png", m_continueTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/background.png", m_backgroundTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/road.png", m_roadTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;

	// DIFFICULTY
	success = utils::TextureFromFile("resources/easy.png", m_easyDifficultyTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/medium.png", m_mediumDifficultyTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/hard.png", m_hardDifficultyTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/expert.png", m_expertDifficultyTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;

	// CARS
	success = utils::TextureFromFile("resources/redcar_hor.png", m_redCarHorTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/redcar_ver.png", m_redCarVerTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;

	success = utils::TextureFromFile("resources/greencar_hor.png", m_greenCarHorTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/greencar_ver.png", m_greenCarVerTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;

	success = utils::TextureFromFile("resources/orangecar_hor.png", m_orangeCarHorTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/orangecar_ver.png", m_orangeCarVerTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;

	success = utils::TextureFromFile("resources/turquoisecar_hor.png", m_turquoiseCarHorTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/turquoisecar_ver.png", m_turquoiseCarVerTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;

	success = utils::TextureFromFile("resources/rosecar_hor.png", m_roseCarHorTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/rosecar_ver.png", m_roseCarVerTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;

	success = utils::TextureFromFile("resources/purplecar_hor.png", m_purpleCarHorTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/purplecar_ver.png", m_purpleCarVerTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;

	success = utils::TextureFromFile("resources/darkgreencar_hor.png", m_darkGreenCarHorTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/darkgreencar_ver.png", m_darkGreenCarVerTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;

	success = utils::TextureFromFile("resources/lightgraycar_hor.png", m_lightGrayCarHorTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/lightgraycar_ver.png", m_lightGrayCarVerTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;

	success = utils::TextureFromFile("resources/lightyellowcar_hor.png", m_lightYellowCarHorTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/lightyellowcar_ver.png", m_lightYellowCarVerTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;

	success = utils::TextureFromFile("resources/yellowcar_hor.png", m_yellowCarHorTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/yellowcar_ver.png", m_yellowCarVerTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;

	success = utils::TextureFromFile("resources/browncar_hor.png", m_brownCarHorTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/browncar_ver.png", m_brownCarVerTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;

	success = utils::TextureFromFile("resources/darkyellowcar_hor.png", m_darkYellowCarHorTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/darkyellowcar_ver.png", m_darkYellowCarVerTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;

	// TRUCKS
	success = utils::TextureFromFile("resources/goldtruck_hor.png", m_goldTruckHorTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/goldtruck_ver.png", m_goldTruckVerTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;

	success = utils::TextureFromFile("resources/lavendertruck_hor.png", m_lavenderTruckHorTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/lavendertruck_ver.png", m_lavenderTruckVerTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;

	success = utils::TextureFromFile("resources/bluetruck_hor.png", m_blueTruckHorTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/bluetruck_ver.png", m_blueTruckVerTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;

	success = utils::TextureFromFile("resources/darktealtruck_hor.png", m_darkTealTruckHorTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
	success = utils::TextureFromFile("resources/darktealtruck_ver.png", m_darkTealTruckVerTexture);
	if (!success) std::cout << "Loading texture file failed." << std::endl;
}


void RushHour::LoadLevel(int levelID)
{
	LOG_FUNCTION_NAME();
	InitGrid();
	m_currentSteps = 0;

	std::vector<CarData> levelData = levels::levelData[levelID];
	for (int carIdx{0}; carIdx < m_nrCars; ++carIdx)
	{
		m_ptrCars[carIdx].isActive = false;
		for (int dataIdx{0}; dataIdx < levelData.size(); ++dataIdx)
		{
			if (levelData[dataIdx].colorCode == m_ptrCars[carIdx].colorCode)
			{
				m_ptrCars[carIdx].isActive = true;
				m_ptrCars[carIdx].dir = levelData[dataIdx].dir;
				m_ptrCars[carIdx].back = levelData[dataIdx].pos;
			}
		}
	}
	SetUpPositions();
}

void RushHour::ResetLevel()
{
	LOG_FUNCTION_NAME()
	if (m_isPaused)
	{
		return;
	}
	LoadLevel(m_currentLevel);
}

void RushHour::SetUpPositions()
{
	LOG_FUNCTION_NAME()

	for (int idx{0}; idx < m_nrCars; ++idx)
	{
		if (!m_ptrCars[idx].isActive)
		{
			continue;
		}
		const Car& car = m_ptrCars[idx];
		const int rBack{car.back.x};
		const int cBack{car.back.y};
		m_ptrGrid[GetIndex(rBack, cBack, m_nrCols)] = car.id;
		if (car.dir == Direction::horizontal)
		{
			m_ptrGrid[GetIndex(rBack, cBack + 1, m_nrCols)] = car.id;
			if (car.length == 3)
			{
				m_ptrGrid[GetIndex(rBack, cBack + 2, m_nrCols)] = car.id;
			}
		}
		else
		{
			m_ptrGrid[GetIndex(rBack + 1, cBack, m_nrCols)] = car.id;
			if (car.length == 3)
			{
				m_ptrGrid[GetIndex(rBack + 2, cBack, m_nrCols)] = car.id;
			}
		}
	}
}

bool RushHour::HasWon() const
{
	LOG_FUNCTION_NAME()
	return m_selectedCarId == m_playerID && m_ptrCars[m_playerID].back.y == m_exitPos.y;
}

void RushHour::Draw()
{
	DrawBackground();
	if (m_hasGameWon)
	{
		DrawWonCanvas();
		DrawNextButton();
	}
	else if (m_isPaused)
	{
		DrawInstructionsCanvas();
	}
	else
	{
		DrawUIBackGround();
		DrawBorder();
		DrawExit();
		DrawGrid();
		DrawPadding();
		DrawCar();
		DrawSteps();
		DrawDifficulty();
		DrawResetButton();
	}
}

void RushHour::DrawGrid() const
{
	for (int rIdx{0}; rIdx < m_nrRows; ++rIdx)
	{
		for (int cIdx{0}; cIdx < m_nrCols; ++cIdx)
		{
			utils::SetColor(utils::Color::gray);
			Rectf dst;
			dst.left = m_gridBottomLeft.pixel.x + m_cellWidth * cIdx;
			dst.bottom = m_gridBottomLeft.pixel.y + m_cellWidth * rIdx;
			dst.width = m_cellWidth;
			dst.height = m_cellWidth;
			utils::DrawTexture(m_roadTexture, dst);
		}
	}
}

void RushHour::DrawCar() const
{
	for (int idx{0}; idx < m_nrCars; ++idx)
	{
		if (!m_ptrCars[idx].isActive)
		{
			continue;
		}
		const int carLength{m_ptrCars[idx].length};

		int bottomRow{m_gridBottomLeft.cell.x - m_ptrCars[idx].back.x};
		int bottomCol{m_ptrCars[idx].back.y - m_gridBottomLeft.cell.y};

		if (m_ptrCars[idx].dir == Direction::vertical)
		{
			bottomRow -= carLength - 1;
		}

		const float leftPixel{m_gridBottomLeft.pixel.x + bottomCol * m_cellWidth};
		const float bottomPixel{m_gridBottomLeft.pixel.y + bottomRow * m_cellWidth};

		if (m_ptrCars[idx].isSelected)
		{
			utils::SetColor(utils::Color::highlight);
		}

		if (m_ptrCars[idx].dir == Direction::horizontal)
		{
			utils::DrawTexture(m_ptrCars[idx].texture.horizontal, Rectf(leftPixel, bottomPixel, m_cellWidth * carLength, m_cellWidth));
			if (m_ptrCars[idx].isSelected)
			{
				utils::FillRect(leftPixel, bottomPixel, m_cellWidth * carLength, m_cellWidth);
			}
		}
		else
		{
			utils::DrawTexture(m_ptrCars[idx].texture.vertical, Rectf(leftPixel, bottomPixel, m_cellWidth, m_cellWidth * carLength));
			if (m_ptrCars[idx].isSelected)
			{
				utils::FillRect(leftPixel, bottomPixel, m_cellWidth, m_cellWidth * carLength);
			}
		}
	}
}

void RushHour::DrawPadding() const
{
	utils::SetColor(utils::Color::gray);
	for (int i{1}; i < m_nrCols; ++i)
	{
		const float vertical{m_gridBottomLeft.pixel.x + m_cellWidth * i};
		const float horizontal{m_gridBottomLeft.pixel.y + m_cellWidth * i};
		utils::DrawLine(vertical, m_gridBottomLeft.pixel.y, vertical, m_gridBottomLeft.pixel.y + m_nrRows * m_cellWidth, m_lineWidth);
		utils::DrawLine(m_gridBottomLeft.pixel.x, horizontal, m_gridBottomLeft.pixel.x + m_nrCols * m_cellWidth, horizontal, m_lineWidth);
	}
}

void RushHour::DrawBorder() const
{
	const float left{m_gridBottomLeft.pixel.x - m_border};
	const float bottom{m_gridBottomLeft.pixel.y - m_border};
	const float width{2 * m_border + m_nrCols * m_cellWidth};
	Color4f black{utils::Color::black};
	black.a = 0.8f;
	utils::SetColor(black);
	utils::FillRect(left, bottom, width, width);
}

void RushHour::DrawExit() const
{
	Color4f red{utils::Color::red};
	red.a = 0.9f;
	utils::SetColor(red);
	const float left{m_gridBottomLeft.pixel.x + m_exitPos.y * m_cellWidth};
	const float bottom{m_gridBottomLeft.pixel.y + m_exitPos.x * m_cellWidth};
	utils::FillRect(left, bottom, m_border, m_cellWidth);
}

void RushHour::DrawWonCanvas() const
{
	const Point2f bottomLeftWonCanvasPoint{m_gridBottomLeft.pixel.x, m_gridBottomLeft.pixel.y};

	const float widthWonCanvas{300.f};
	const float heightWonCanvas{300.f};
	utils::SetColor(utils::Color::gray);
	utils::FillRect(bottomLeftWonCanvasPoint, widthWonCanvas, heightWonCanvas);

	const float wonTitleOffsetX{80.f};
	const float wonTitleOffsetY{150.f};
	const Point2f posTextureTitle{bottomLeftWonCanvasPoint.x + wonTitleOffsetX, bottomLeftWonCanvasPoint.y + wonTitleOffsetY};
	utils::DrawTexture(m_wonTitleTexture, posTextureTitle);

	const float trophyOffsetX{15.f};
	const float trophyOffsetY{120.f};
	Point2f trophyPos{posTextureTitle.x + trophyOffsetX, posTextureTitle.y - trophyOffsetY};
	const float trophyScale{0.2f};
	Rectf destRect{trophyPos.x, trophyPos.y, trophyScale * m_trophyTexture.width, trophyScale * m_trophyTexture.height};
	utils::DrawTexture(m_trophyTexture, destRect);
}

void RushHour::DrawInstructionsCanvas() const
{
	//INSTRUCTIONS CANVAS
	const float instructionsCanvasOffsetX{150.f};
	const float instructionsCanvasOffsetY{100.f};

	const Point2f bottomLeftInstructionsCanvasPoint{m_gridBottomLeft.pixel.x - instructionsCanvasOffsetX, m_gridBottomLeft.pixel.y - instructionsCanvasOffsetY};

	const float widthInstructionsCanvas{800.f};
	const float heightInstructionsCanvas{500.f};

	Color4f translucent{utils::Color::translucent};
	translucent.a = 0.7f;
	utils::SetColor(translucent);
	utils::FillRect(bottomLeftInstructionsCanvasPoint, widthInstructionsCanvas, heightInstructionsCanvas);

	//CREDITS TITLE
	const float instructionsOffset{10.f};
	const Point2f posTextureCredits{bottomLeftInstructionsCanvasPoint.x + instructionsOffset, bottomLeftInstructionsCanvasPoint.y + instructionsOffset};
	utils::DrawTexture(m_creditsTexture, posTextureCredits);

	//INSTRUCTIONS TITLE 
	const float instructionsTitleOffsetX{250.f};
	const float instructionsTitleOffsetY{450.f};
	const Point2f posTextureTitle{bottomLeftInstructionsCanvasPoint.x + instructionsTitleOffsetX, bottomLeftInstructionsCanvasPoint.y + instructionsTitleOffsetY};
	utils::DrawTexture(m_instructionsTitleTexture, posTextureTitle);

	//GAME EXPLANATION PART 1
	const float gameExplanationPart1OffsetX{150.f};
	const float gameExplanationPart1OffsetY{25.f};
	const Point2f posTextureGameExplanationPart1{posTextureTitle.x - gameExplanationPart1OffsetX, posTextureTitle.y - gameExplanationPart1OffsetY};
	utils::DrawTexture(m_explanationPart1Texture, posTextureGameExplanationPart1);

	//GAME EXPLANATION PART 2
	const float gameExplanationPart2OffsetY{15.f};
	const Point2f posTextureGameExplanationPart2{posTextureGameExplanationPart1.x, posTextureGameExplanationPart1.y - gameExplanationPart2OffsetY};
	utils::DrawTexture(m_explanationPart2Texture, posTextureGameExplanationPart2);

	//CONTROLS TITLE  
	const float controlsTitleOffsetX{10.f};
	const float controlsTitleOffsetY{75.f};
	const Point2f posTextureControlsTitle{posTextureTitle.x + controlsTitleOffsetX, posTextureGameExplanationPart2.y - controlsTitleOffsetY};
	utils::DrawTexture(m_controlsTitleTexture, posTextureControlsTitle);

	//MOUSE CONTROLS  
	const float mouseControlsOffsetX{80.f};
	const float mouseControlsOffsetY{50.f};
	const Point2f posTextureMouseControls{posTextureControlsTitle.x + mouseControlsOffsetX, posTextureControlsTitle.y - mouseControlsOffsetY};
	utils::DrawTexture(m_mouseControlsTexture, posTextureMouseControls);

	const float mouseTextureScale{0.1f};
	const float mouseTextureOffsetX{250.f};
	const float mouseTextureOffsetY{20.f};
	const Point2f posTextureMouse{posTextureMouseControls.x - mouseTextureOffsetX, posTextureMouseControls.y - mouseTextureOffsetY};
	utils::DrawTexture(m_mouseTexture, Rectf(posTextureMouse.x, posTextureMouse.y, m_mouseTexture.width * mouseTextureScale, m_mouseTexture.height * mouseTextureScale));

	//HORIZONTAL CAR CONTROLS  
	const float horizontalCarControlsOffsetX{190.f};
	const float horizontalCarControlsOffsetY{70.f};
	const Point2f posTextureHorizontalCarControls{posTextureMouseControls.x - horizontalCarControlsOffsetX, posTextureMouseControls.y - horizontalCarControlsOffsetY};
	utils::DrawTexture(m_horizontalCarControlsTexture, posTextureHorizontalCarControls);

	const float textureScale{0.2f};
	const float horizontalCarTextureOffsetX{300.f};
	const float horizontalCarTextureOffsetY{90.f};
	const Point2f posTextureHorizontalCar{posTextureMouseControls.x - horizontalCarTextureOffsetX, posTextureMouseControls.y - horizontalCarTextureOffsetY};
	utils::DrawTexture(m_greenCarHorTexture, Rectf(posTextureHorizontalCar.x, posTextureHorizontalCar.y, m_greenCarHorTexture.width * textureScale, m_greenCarHorTexture.height * textureScale));

	//VERTICAL CAR CONTROLS  
	const float verticalCarControlsOffsetX{20.f};
	const float verticalCarControlsOffsetY{100.f};
	const Point2f posTextureVerticalCarControls{posTextureHorizontalCarControls.x + verticalCarControlsOffsetX, posTextureHorizontalCarControls.y - verticalCarControlsOffsetY};
	utils::DrawTexture(m_verticalCarControlsTexture, posTextureVerticalCarControls);

	const float verticalCarTextureOffsetX{250.f};
	const float verticalCarTextureOffsetY{210.f};
	const Point2f posTextureVerticalCar{posTextureMouseControls.x - verticalCarTextureOffsetX, posTextureMouseControls.y - verticalCarTextureOffsetY};
	utils::DrawTexture(m_orangeCarVerTexture, Rectf(posTextureVerticalCar.x, posTextureVerticalCar.y, m_orangeCarVerTexture.width * textureScale, m_orangeCarVerTexture.height * textureScale));
}

void RushHour::DrawNextButton() const
{
	utils::SetColor(utils::Color::green);
	utils::DrawTexture(m_continueTexture, Rectf(m_nextButtonLeft, m_nextButtonBottom, m_nextButtonWidth, m_nextButtonHeight));
}

void RushHour::DrawResetButton() const
{
	utils::SetColor(utils::Color::red);
	utils::DrawTexture(m_resetTexture, Rectf(m_resetButtonLeft, m_resetButtonBottom, m_resetButtonWidth, m_resetButtonHeight));
}

void RushHour::DrawBackground() const
{
	utils::DrawTexture(m_backgroundTexture, Point2f{0, 0});
}

void RushHour::DrawUIBackGround() const
{
	utils::SetColor(utils::Color::translucent);
	const float offset{4 * m_border};
	const float left{m_gridBottomLeft.pixel.x - m_border - offset};
	const float bottom{m_gridBottomLeft.pixel.y - m_border - offset};
	const float width{2 * offset + 2 * m_border + m_nrCols * m_cellWidth};
	utils::FillRect(left, bottom, width, width);
}

void RushHour::DrawSteps()
{
	utils::DeleteTexture(m_currentStepsTexture);
	utils::TextureFromString(std::to_string(m_currentSteps), m_fontPath, 34, utils::Color::white, m_currentStepsTexture);
	const float left{g_WindowWidth / 2 - m_currentStepsTexture.width / 2};
	const float bottom{g_WindowHeight / 2 - m_nrRows / 2 * m_cellWidth - 2 * m_border - m_currentStepsTexture.height};
	utils::DrawTexture(m_currentStepsTexture, Point2f(left, bottom));
}

void RushHour::DrawDifficulty()
{
	const float left{g_WindowWidth / 2 - m_easyDifficultyTexture.width / 2};
	const float bottom{g_WindowHeight / 2 + m_nrRows / 2 * m_cellWidth + 2 * m_border};
	const Point2f pos{left, bottom};
	const float offsetX{42.0f};
	const float offsetY{3.0f};
	utils::DeleteTexture(m_levelTexture);
	utils::TextureFromString(std::to_string(m_currentLevel + 1), m_fontPath, 34, utils::Color::white, m_levelTexture);
	utils::DrawTexture(m_levelTexture, Point2f(pos.x - offsetX, pos.y - offsetY));
	if (m_currentLevel < 10)
	{
		utils::DrawTexture(m_easyDifficultyTexture, pos);
	}
	else if (m_currentLevel < 20)
	{
		utils::DrawTexture(m_mediumDifficultyTexture, pos);
	}
	else if (m_currentLevel < 30)
	{
		utils::DrawTexture(m_hardDifficultyTexture, pos);
	}
	else
	{
		utils::DrawTexture(m_expertDifficultyTexture, pos);
	}
}

int RushHour::GetIndex(int rowIdx, int colIdx, int nrCols) const
{
	return rowIdx * nrCols + colIdx;
}

bool RushHour::IsCellEmpty(int rowIdx, int colIdx) const
{
	LOG_FUNCTION_NAME()
	return m_ptrGrid[GetIndex(rowIdx, colIdx, m_nrCols)] == m_emptyCell;
}

void RushHour::ProcessMouseInput(float mouseX, float mouseY)
{
	LOG_FUNCTION_NAME()
	SelectCar(mouseX, mouseY);
	OnNextButtonClicked(mouseX, mouseY);
	OnResetButtonClicked(mouseX, mouseY);
}

void RushHour::SelectCar(float mouseX, float mouseY)
{
	LOG_FUNCTION_NAME()
	if (m_isPaused)
	{
		return;
	}

	m_selectedCarId = -1;
	for (int idx{0}; idx < m_nrCars; ++idx)
	{
		m_ptrCars[idx].isSelected = false;
	}

	const bool withinX{m_gridBottomLeft.pixel.x <= mouseX && mouseX <= m_gridBottomLeft.pixel.x + m_nrCols * m_cellWidth};
	const bool withinY{m_gridBottomLeft.pixel.y <= mouseY && mouseY <= m_gridBottomLeft.pixel.y + m_nrRows * m_cellWidth};
	if (!(withinX && withinY))
	{
		return;
	}
	mouseX -= m_gridBottomLeft.pixel.x;
	mouseY -= m_gridBottomLeft.pixel.y;
	const int row{m_nrRows - 1 - int(mouseY / m_cellWidth)};
	const int col{int(mouseX / m_cellWidth)};
	if (m_ptrGrid[GetIndex(row, col, m_nrCols)] == m_emptyCell)
	{
		return;
	}
	Car& car = m_ptrCars[m_ptrGrid[GetIndex(row, col, m_nrCols)]];
	car.isSelected = true;
	m_selectedCarId = car.id;
	LOG("Selected car id: " << m_selectedCarId)
}

void RushHour::MoveCar(Movement dir)
{
	LOG_FUNCTION_NAME()
	if (m_isPaused)
	{
		return;
	}
	if (m_selectedCarId == m_emptyCell)
	{
		return;
	}

	Car& car{m_ptrCars[m_selectedCarId]};
	switch (dir)
	{
	case Movement::left:
		if (car.dir == Direction::horizontal && car.back.y > 0 && IsCellEmpty(car.back.x, car.back.y - 1))
		{
			car.back.y -= 1;
			m_ptrGrid[GetIndex(car.back.x, car.back.y + car.length, m_nrCols)] = m_emptyCell;
			m_ptrGrid[GetIndex(car.back.x, car.back.y, m_nrCols)] = car.id;
			++m_currentSteps;
		}
		break;
	case Movement::right:
		if (car.dir == Direction::horizontal && car.back.y + car.length - 1 < m_nrCols - 1 && IsCellEmpty(
			car.back.x, car.back.y + car.length))
		{
			car.back.y += 1;
			m_ptrGrid[GetIndex(car.back.x, car.back.y - 1, m_nrCols)] = m_emptyCell;
			m_ptrGrid[GetIndex(car.back.x, car.back.y + car.length - 1, m_nrCols)] = car.id;
			++m_currentSteps;
		}
		else if (car.id == m_playerID && (car.back.y + car.length == m_nrCols || car.back.y == m_nrCols - 1))
		{
			car.back.y += 1;
			m_ptrGrid[GetIndex(car.back.x, car.back.y - 1, m_nrCols)] = m_emptyCell;
			++m_currentSteps;
		}
		break;
	case Movement::up:
		if (car.dir == Direction::vertical && car.back.x > 0 && IsCellEmpty(car.back.x - 1, car.back.y))
		{
			car.back.x -= 1;
			m_ptrGrid[GetIndex(car.back.x + car.length, car.back.y, m_nrCols)] = m_emptyCell;
			m_ptrGrid[GetIndex(car.back.x, car.back.y, m_nrCols)] = car.id;
			++m_currentSteps;
		}
		break;
	case Movement::down:
		if (car.dir == Direction::vertical && car.back.x + car.length - 1 < m_nrRows - 1 && IsCellEmpty(
			car.back.x + car.length, car.back.y))
		{
			car.back.x += 1;
			m_ptrGrid[GetIndex(car.back.x - 1, car.back.y, m_nrCols)] = m_emptyCell;
			m_ptrGrid[GetIndex(car.back.x + car.length - 1, car.back.y, m_nrCols)] = car.id;
			++m_currentSteps;
		}
		break;
	}
	if (HasWon())
	{
		LOG("Player wins")
		m_hasGameWon = true;
		m_ptrSteps[m_currentLevel] = m_currentSteps;
	}
#if DEBUG
		DebugGrid();
		DebugSteps();
#endif
}

void RushHour::OnNextButtonClicked(float mouseX, float mouseY)
{
	LOG_FUNCTION_NAME()
	if (m_hasGameWon)
	{
		const bool withinX{m_nextButtonLeft <= mouseX && mouseX <= m_nextButtonLeft + m_nextButtonWidth};
		const bool withinY{m_nextButtonBottom <= mouseY && mouseY <= m_nextButtonBottom + m_nextButtonHeight};
		if (withinX && withinY)
		{
			m_hasGameWon = false;
			LoadLevel(++m_currentLevel);
		}
	}
}

void RushHour::OnResetButtonClicked(float mouseX, float mouseY)
{
	LOG_FUNCTION_NAME()
	if (m_isPaused)
	{
		return;
	}
	const bool withinX{m_resetButtonLeft <= mouseX && mouseX <= m_resetButtonLeft + m_resetButtonWidth};
	const bool withinY{m_resetButtonBottom <= mouseY && mouseY <= m_resetButtonBottom + m_resetButtonHeight};
	if (withinX && withinY)
	{
		ResetLevel();
	}
}

void RushHour::ToggleInstructionsCanvas()
{
	LOG_FUNCTION_NAME()
	m_isPaused = !m_isPaused;
}

void RushHour::DebugGrid() const 
{
	for (int rIdx{0}; rIdx < m_nrRows; ++rIdx)
	{
		for (int cIdx{0}; cIdx < m_nrCols; ++cIdx)
		{
			const int cell{m_ptrGrid[GetIndex(rIdx, cIdx, m_nrCols)]};
			char toPrint{'_'};
			if (cell != m_emptyCell)
			{
				toPrint = static_cast<char>(m_ptrCars[cell].colorCode);
			}
			std::cout << toPrint << ' ';
		}
		std::cout << std::endl;
	}
}

void RushHour::DebugSteps() const
{
	for (int idx{0}; idx < m_nrLevels; ++idx)
	{
		std::cout << m_ptrSteps[idx] << ' ';
	}
	std::cout << std::endl;
}
