// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Game.h"
#include "Vehicle.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions
void Start()
{
	// initialize game resources here
	CreateStreet();
	CreateChicken();
	CreateCars();
	LoadTexts();
	PrintStartMessage();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawStreet();
	DrawChicken();
	DrawCars();
	PrintText();
}

void Update(float elapsedSec)
{
	switch (g_Game.m_Sate)
	{
	case GameState::reset:
		break;
	case GameState::lose:
		UpdateCars(elapsedSec);
		break;
	case GameState::pause:
		break;
	case GameState::win:
		UpdateCars(elapsedSec);
		break;
	case GameState::play:
		UpdateChicken(elapsedSec);
		UpdateCars(elapsedSec);
		break;
	}
	// process input, do physics 
	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	// free game resources here
	DestroyChicken();
	DestroyStreet();
	DestroyCars();
	DestroyTexts();
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling
void OnKeyDownEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_r:
		ResetGame();
		break;
	case SDLK_p:
		PauseGame();
		break;
	}
}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void CreateChicken()
{
	TextureFromFile(g_Chicken.path, g_Chicken.m_Tex);
	g_Chicken.m_Pos = g_Chicken.m_StarPos;
}

void DrawChicken()
{
	int nrSprite{0};
	switch (g_Chicken.m_HorizonatlDir)
	{
	case ChickenDir::left:
		nrSprite = 1;
		break;
	case ChickenDir::right:
		nrSprite = 2;
		break;
	case ChickenDir::idle:
		break;
	}
	switch (g_Chicken.m_VerticalDir)
	{
	case ChickenDir::down:
		if (nrSprite)
		{
		}
		break;
	case ChickenDir::idle:
		break;
	}
	Rectf src;
	src.width = g_Chicken.m_Tex.width / 3;
	src.height = g_Chicken.m_Tex.height;
	src.left = src.width * nrSprite;
	src.bottom = src.height;

	Rectf dst;
	dst.width = src.width * g_Chicken.m_Scale;
	dst.height = src.height * g_Chicken.m_Scale;
	dst.left = g_Chicken.m_Pos.x - dst.width / 2;
	dst.bottom = g_Chicken.m_Pos.y - dst.height / 2;
	DrawTexture(g_Chicken.m_Tex, dst, src);
}

void UpdateChicken(float deltaTime)
{
	g_Chicken.m_HorizonatlDir = ChickenDir::idle;
	g_Chicken.m_VerticalDir = ChickenDir::idle;

	const Uint8* pStates{SDL_GetKeyboardState(nullptr)};
	Vector2f tmpDir{};
	if (pStates[SDL_SCANCODE_LEFT])
	{
		tmpDir = Dir::LEFT;
		g_Chicken.m_HorizonatlDir = ChickenDir::left;
	}
	if (pStates[SDL_SCANCODE_RIGHT])
	{
		tmpDir = Dir::RIGHT;
		g_Chicken.m_HorizonatlDir = ChickenDir::right;
	}
	if (pStates[SDL_SCANCODE_DOWN])
	{
		tmpDir = Add(tmpDir, Dir::DOWN);
		g_Chicken.m_HorizonatlDir = ChickenDir::down;
	}
	tmpDir = Normalize(tmpDir);
	g_Chicken.m_Pos.x += tmpDir.x * g_Chicken.m_Speed * deltaTime;
	g_Chicken.m_Pos.y += tmpDir.y * g_Chicken.m_Speed * deltaTime;
	if (g_Chicken.m_Pos.y <= g_Street.m_PavementHeight)
	{
		g_Game.m_Sate = GameState::win;
	}
}

void DestroyChicken()
{
	DeleteTexture(g_Chicken.m_Tex);
}

void CreateStreet()
{
	TextureFromFile(g_Street.path, g_Street.m_Tex);
}

void DrawStreet()
{
	DrawTexture(g_Street.m_Tex, g_Street.m_Pos);
}

void DestroyStreet()
{
	DeleteTexture(g_Street.m_Tex);
}

void CreateCars()
{
	for (int iCar{1}; iCar <= ChickenGame::s_NrCars; ++iCar)
	{
		g_Game.m_Cars[iCar - 1] = new Vehicle{iCar};
	}
	ShuffleCars();
}

void ShuffleCars()
{
	const int minShuffle{ 5 };
	const int nrShuffle{std::rand() % 11 + minShuffle};
	for (int i{}; i < nrShuffle; ++i)
	{
		const int idx1{std::rand() % g_Game.s_NrCars};
		int idx2{std::rand() % g_Game.s_NrCars};
		while (idx1 == idx2)
		{
			idx2 = std::rand() % g_Game.s_NrCars;
		}
		std::swap(g_Game.m_Cars[idx1], g_Game.m_Cars[idx2]);
	}
	for (int iCar{}; iCar < ChickenGame::s_NrCars; ++iCar)
	{
		g_Game.m_Cars[iCar]->SetYPos(g_Street.m_PavementHeight + g_Street.m_LaneHeight * iCar);
	}
}

void DrawCars()
{
	for (int iCar{}; iCar < ChickenGame::s_NrCars; ++iCar)
	{
		g_Game.m_Cars[iCar]->SetYPos(g_Street.m_PavementHeight + g_Street.m_LaneHeight * iCar);
		g_Game.m_Cars[iCar]->Draw();
	}
}

void UpdateCars(float deltaTime)
{
	for (Vehicle* car : g_Game.m_Cars)
	{
		car->Update(deltaTime, g_WindowWidth);
		if (car->IsIntersecting(g_Chicken.m_Pos))
		{
			car->SetActive(false);
			g_Game.m_Sate = GameState::lose;
			//break;
		}
	}
}

void DestroyCars()
{
	for (Vehicle* car : g_Game.m_Cars)
	{
		delete car;
	}
}

void ResetGame()
{
	g_Game.m_Sate = GameState::play;
	for (Vehicle* car : g_Game.m_Cars)
	{
		car->SetActive(true);
		car->Reset();
	}
	ShuffleCars();
	g_Chicken.m_Pos = g_Chicken.m_StarPos;
}

void PauseGame()
{
	if (g_Game.m_Sate == GameState::play)
	{
		g_Game.m_Sate = GameState::pause;
		for (Vehicle* car : g_Game.m_Cars)
		{
			car->SetActive(false);
		}
	}
	else if (g_Game.m_Sate == GameState::pause)
	{
		g_Game.m_Sate = GameState::play;
		for (Vehicle* car : g_Game.m_Cars)
		{
			car->SetActive(true);
		}
	}
}

void PrintText()
{
	switch (g_Game.m_Sate)
	{
	case GameState::lose:
		SetColor(g_Game.m_ColorBackground);
		FillRect(g_Game.m_PosLose, g_Game.m_TexLose.width, g_Game.m_TexLose.height);
		DrawTexture(g_Game.m_TexLose, g_Game.m_PosLose);
		break;
	case GameState::win:
		SetColor(g_Game.m_ColorBackground);
		FillRect(g_Game.m_PosWin, g_Game.m_TexWin.width, g_Game.m_TexWin.height);
		DrawTexture(g_Game.m_TexWin, g_Game.m_PosWin);
		break;
	case GameState::pause:
		SetColor(g_Game.m_ColorBackground);
		FillRect(g_Game.m_PosPause, g_Game.m_TexPause.width, g_Game.m_TexPause.height);
		DrawTexture(g_Game.m_TexPause, g_Game.m_PosPause);
		break;
	}
}

void LoadTexts()
{
	TextureFromString(g_Game.m_MessageLose, g_Game.m_FontPath, g_Game.m_FontSize, g_Game.m_ColorFont, g_Game.m_TexLose);
	TextureFromString(g_Game.m_MessagePause, g_Game.m_FontPath, g_Game.m_FontSize, g_Game.m_ColorFont,
	                  g_Game.m_TexPause);
	TextureFromString(g_Game.m_MessageWin, g_Game.m_FontPath, g_Game.m_FontSize, g_Game.m_ColorFont, g_Game.m_TexWin);
	g_Game.m_PosLose = Point2f{
		g_Game.m_Center.x - g_Game.m_TexLose.width / 2, g_Game.m_Center.y - g_Game.m_TexLose.height / 2
	};
	g_Game.m_PosWin = Point2f{
		g_Game.m_Center.x - g_Game.m_TexWin.width / 2, g_Game.m_Center.y - g_Game.m_TexWin.height / 2
	};
	g_Game.m_PosPause = Point2f{
		g_Game.m_Center.x - g_Game.m_TexPause.width / 2, g_Game.m_Center.y - g_Game.m_TexPause.height / 2
	};
}

void DestroyTexts()
{
	DeleteTexture(g_Game.m_TexLose);
	DeleteTexture(g_Game.m_TexPause);
	DeleteTexture(g_Game.m_TexWin);
}

void PrintStartMessage()
{
	std::cout << "Press 'r' to reset." << std::endl;
	std::cout << "Press 'p' to pause/unpause." << std::endl;
	std::cout << "Use the arrow keys to move the chicken." << std::endl;
}
#pragma endregion ownDefinitions
