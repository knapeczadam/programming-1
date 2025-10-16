// Knapecz, Adam - 1DAE11
#pragma once
#include "Die.h"
#include <iostream>

using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Ex59 - Knapecz, Adam - 1DAE11" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

struct Player
{
	Color4f color;
	int score;
};

int g_NrPlayers;
Player* g_Players;
int g_CurrPlayer;

Die* g_Die1;
Die* g_Die2;

bool g_IsPlaying;

utils::Texture g_TempWinner;
utils::Texture g_Winner;
utils::Texture g_WinnerText;
// Declare your own functions here
// INIT
void InitGame();
void InitTextures();
void StartGame();

// DRAW
void DrawGame();
void DrawPlayers();
void DrawDice();
void DrawWinnerText();

// DELETE
void DeleteTextures();
void DeletePlayers();
void DeleteDice();

void ResetGame();
void EndGame();

float GetPlayerWidth();
float GetPlayerHeight();
int GetMaxScore();
void PrintMessage();

#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
