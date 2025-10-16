// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Game.h"

#include <iostream>


//Basic game functions
#pragma region gameFunctions
void Start()
{
	// initialize game resources here
	Generate();
	PrintRandomNumbers();
}

void Draw()
{
	ClearBackground();
	g_Elevator.Draw();

	// Put your own draw statements here
}

void Update(float elapsedSec)
{
	// process input, do physics 
	g_AccSeconds += elapsedSec;
	if (g_AccSeconds >= 1.0f)
	{
		Generate();
		PrintRandomNumbers();
		g_AccSeconds = 0;
	}

	g_Elevator.Update(elapsedSec);
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
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling
void OnKeyDownEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_n:
		Generate();
		PrintRandomNumbers();
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
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		g_Elevator.ProcessClick(float(e.x), float(g_WindowHeight - e.y));
		break;
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
void Generate()
{
	int randEven{};
	int randOdd{};
	int randAny{};
	while (randEven % 2 != 0 || randEven == g_Even)
	{
		randEven = rand() % 10;
	}
	g_Even = randEven;
	while (randOdd % 2 == 0 || randOdd == g_Odd)
	{
		randOdd = rand() % 10;
	}
	g_Odd = randOdd;
	while (randAny == g_Any)
	{
		randAny = rand() % 10;
	}
	g_Any = randAny;
}

void PrintRandomNumbers()
{
	std::cout << "Even: " << g_Even << ", odd: " << g_Odd << ", any: " << g_Any << std::endl;
}

#pragma endregion ownDefinitions
