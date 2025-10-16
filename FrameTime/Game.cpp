// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Game.h"


#include <iomanip>
#include <iostream>

//Basic game functions
#pragma region gameFunctions
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawBall();
	DrawFreeFall();
}

void Update(float elapsedSec)
{
	// process input, do physics 
	++g_NrFrames;
	g_AccTime += elapsedSec;
	PrintInfo();
	UpdateBall(elapsedSec);
	UpdateFreeFall(elapsedSec);
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling
void OnKeyDownEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_s:
		g_Simulate = !g_Simulate;
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
void PrintInfo()
{
	const int maxNnFrames{100};
	if (g_NrFrames % maxNnFrames == 0)
	{
		std::cout << "Number of Frames: " << g_NrFrames << '\t';
		std::cout << " AccumulatedTime: " << g_AccTime << '\t';
		std::cout << " Frame rate: " << g_NrFrames / g_AccTime << std::endl;
	}
}

void UpdateBall(float deltaTime)
{
	if (g_BallPos.x + g_Radius >= g_WindowWidth || g_BallPos.x - g_Radius <= 0)
	{
		g_BallVelocity.x *= -1;
	}
	if (g_BallPos.y + g_Radius >= g_WindowHeight || g_BallPos.y - g_Radius <= 0)
	{
		g_BallVelocity.y *= -1;
	}
	g_BallPos.x += g_BallVelocity.x * deltaTime;
	g_BallPos.y += g_BallVelocity.y * deltaTime;
}

void DrawBall()
{
	SetColor(1.0f, 0, 0, 1.0f);
	FillArc(g_BallPos.x, g_BallPos.y, g_Radius, g_Radius, 0, 2 * g_Pi);
}

void UpdateFreeFall(float deltaTime)
{
	if (g_Simulate)
	{
		g_CubeVelocity.y += g_Gravity * deltaTime;
		g_CubePos.y += g_CubeVelocity.y * deltaTime;
		if (g_CubePos.y + g_CubeWidth <= 0)
		{
			g_Simulate = false;
		}
	}
	else
	{
		g_CubePos = g_CubeInitPos;
		g_CubeVelocity = g_CubeInitVelocity;
	}
}

void DrawFreeFall()
{
	const float width{10};
	SetColor(0, 0, 1.0f);
	FillRect(g_CubePos.x, g_CubePos.y, width, width);
}
#pragma endregion ownDefinitions
