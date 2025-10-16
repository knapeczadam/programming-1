// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Game.h"

#include <iostream>

//Basic game functions
#pragma region gameFunctions
void Start()
{
	// initialize game resources here
	InitGame();
}

void Draw()
{
	// Put your own draw statements here
	DrawGame();
}

void Update(float elapsedSec)
{
	// process input, do physics 

	g_Die1->Update(elapsedSec);
	g_Die2->Update(elapsedSec);
	if (g_Die1->GetState() == State::rolled && g_Die2->GetState() == State::rolled)
	{
		int max{g_Die1->GetDots()};
		if (max < g_Die2->GetDots())
		{
			max = g_Die2->GetDots();
		}
		g_Players[g_CurrPlayer].score += max;
		std::cout << "Player " << (g_CurrPlayer + 1) << ": " << g_Players[g_CurrPlayer].score << std::endl;

		g_Die1->ResetState();
		g_Die2->ResetState();
		g_CurrPlayer = ++g_CurrPlayer % g_NrPlayers;
	}
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
	//if (pStates[SDL_SCANCODE_LSHIFT] || pStates[SDL_SCANCODE_RSHIFT])
	//{
	//	std::cout << "Shift key is pressed.\n";
	//}
}

void End()
{
	// free game resources here
	EndGame();
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
	if (g_IsPlaying)
	{
		Point2f mousePos{float(e.x), float(g_WindowHeight - e.y)};
		switch (e.button)
		{
		case SDL_BUTTON_LEFT:
			g_Die1->CheckHit(mousePos);
			g_Die2->CheckHit(mousePos);
			break;
		}
	}
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
void InitGame()
{
	InitTextures();
	StartGame();
}

void StartGame()
{
	g_IsPlaying = true;

	g_CurrPlayer = 0;

	const int minPlayer{4};
	const int range{4};
	g_NrPlayers = std::rand() % range; // [0 - 3]
	g_NrPlayers += minPlayer; // [4 - 7]
	g_Players = new Player[g_NrPlayers]{};
	for (int idx{0}; idx < g_NrPlayers; ++idx)
	{
		g_Players[idx].color.r = std::rand() % 11 / 10.0f;
		g_Players[idx].color.g = std::rand() % 11 / 10.0f;
		g_Players[idx].color.b = std::rand() % 11 / 10.0f;
		g_Players[idx].color.a = 1.0f;
	}
	const float bottom{2 * 10.0f + GetPlayerHeight()};
	const float offset{10.0f};
	g_Die1 = new Die{Point2f{}, 0.8f};
	g_Die1->SetPosition(Point2f{g_WindowWidth / 2 - g_Die1->GetDieWidth() - offset, bottom});
	g_Die2 = new Die{Point2f{}, 0.8f};
	g_Die2->SetPosition(Point2f{g_WindowWidth / 2 + offset, bottom});
}

void InitTextures()
{
	utils::TextureFromFile("Resources/actual_winner.png", g_Winner);
	utils::TextureFromFile("Resources/temp_winner.png", g_TempWinner);
	utils::TextureFromString("WE HAVE A WINNER!", "Resources/Minercraftory.ttf", 30, Color4f{0, 0, 0, 1.0f},
	                         g_WinnerText);
}

void DeleteTextures()
{
	utils::DeleteTexture(g_Winner);
	utils::DeleteTexture(g_TempWinner);
	utils::DeleteTexture(g_WinnerText);
}

void DeleteDice()
{
	delete g_Die1;
	delete g_Die2;
}


void DrawGame()
{
	ClearBackground(1.0f, 1.0f, 1.0f);
	DrawPlayers();
	if (g_IsPlaying)
	{
		DrawDice();
	}
	else
	{
		DrawWinnerText();
	}
}

void DrawPlayers()
{
	const Point2f firstPos{10.0f, 10.0f};
	const float distance{8.0f};
	const float bottom{firstPos.y};
	for (int idx{0}; idx < g_NrPlayers; ++idx)
	{
		utils::SetColor(g_Players[idx].color);
		const float left{firstPos.x + (GetPlayerWidth() + distance) * idx};
		utils::FillRect(left, bottom, GetPlayerWidth(), GetPlayerHeight());

		const int totalScore{15};
		if (GetMaxScore() >= totalScore)
		{
			if (g_Players[idx].score == GetMaxScore())
			{
				utils::DrawTexture(g_Winner, Point2f{left, bottom});
			}
			if (g_IsPlaying)
			{
				PrintMessage();
				g_IsPlaying = false;
			}
		}
		else
		{
			if (g_Players[idx].score == GetMaxScore())
			{
				utils::DrawTexture(g_TempWinner, Point2f{left, bottom});
			}
		}
	}
	if (g_IsPlaying)
	{
		const float left{firstPos.x + (GetPlayerWidth() + distance) * g_CurrPlayer};
		utils::SetColor(0, 0, 0, 1.0f);
		const float lineWidth{3.0f};
		utils::DrawRect(left, bottom, GetPlayerWidth(), GetPlayerHeight(), lineWidth);
	}
}

void DrawDice()
{
	g_Die1->Draw();
	g_Die2->Draw();
}

void DrawTempWinner()
{
	for (int idx{0}; idx < g_NrPlayers; ++idx)
	{
		if (g_Players[idx].score == GetMaxScore())
		{
			const Point2f firstPos{10.0f, 10.0f};
			const float distance{8.0f};
			const float left{firstPos.x + (GetPlayerWidth() + distance) * idx};
			const float bottom{firstPos.y};
			Rectf dst;
			dst.left = left;
			dst.bottom = bottom;
			utils::DrawTexture(g_TempWinner, dst);
		}
	}
}


float GetPlayerWidth()
{
	return g_TempWinner.width;
}

float GetPlayerHeight()
{
	return g_TempWinner.height;
}

int GetMaxScore()
{
	int max{};
	for (int idx{0}; idx < g_NrPlayers; ++idx)
	{
		if (g_Players[idx].score > max)
		{
			max = g_Players[idx].score;
		}
	}
	return max;
}


void DrawWinnerText()
{
	Rectf dst;
	const float bottom{10.0f * 2 + GetPlayerHeight()};
	dst.width = g_WinnerText.width;
	dst.height = g_WinnerText.height;
	dst.left = g_WindowWidth / 2 - dst.width / 2;
	dst.bottom = bottom;
	utils::DrawTexture(g_WinnerText, dst);
}

void PrintMessage()
{
	std::cout << "========!!WINNER!!========" << std::endl;
}

void ResetGame()
{
	DeleteDice();
	DeletePlayers();
	StartGame();
}

void DeletePlayers()
{
	delete[] g_Players;
}

void EndGame()
{
	DeletePlayers();
	DeleteDice();
	DeleteTextures();
}
#pragma endregion ownDefinitions
