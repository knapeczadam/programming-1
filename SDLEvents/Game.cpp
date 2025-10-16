// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Game.h"

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
	const float width{ 10.0f };
	SetColor(1, 0, 0);
	FillRect(g_MousePos.x - width / 2, g_MousePos.y - width / 2, width, width);
}

void Update(float elapsedSec)
{
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
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling
void OnKeyDownEvent(SDL_Keycode key)
{
	std::cout << "SDL_KEYDOWN" << std::endl << std::endl;
}

void OnKeyUpEvent(SDL_Keycode key)
{
	std::cout << "SDL_KEYUP" << std::endl;
	switch (key)
	{
	case SDLK_LEFT:
		std::cout << "  Left arrow is released" << std::endl;
		break;
	case SDLK_RIGHT:
		std::cout << "  Right arrow is released" << std::endl;;
		break;
	}
	std::cout << std::endl;
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	// std::cout << "  [" << e.x << ", " << e.y << "]\n";
	// Point2f mousePos{float(e.x), float(g_WindowHeight - e.y)};
	g_MousePos.x = float(e.x);
	g_MousePos.y = float(g_WindowHeight - e.y);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	std::cout << "SDL_MOUSEBUTTONDOWN" << std::endl;
	switch (e.button)
	{
		case SDL_BUTTON_LEFT:
		{
			std::cout << "  [" << e.x << ", " << e.y << "]" << std::endl;
			std::cout << "  Left mouse button went down" << std::endl;
			break;
		}
		case SDL_BUTTON_RIGHT:
		{
			std::cout << "  [" << e.x << ", " << e.y << "]" << std::endl;
			std::cout << "  Right mouse button went down" << std::endl;
			break;
		}
		case SDL_BUTTON_MIDDLE:
		{
			std::cout << "  [" << e.x << ", " << e.y << "]" << std::endl;
			std::cout << "  Middle mouse button went down" << std::endl;
			break;
		}
	}
	std::cout << std::endl;
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	std::cout << "SDL_MOUSEBUTTONUP" << std::endl << std::endl;
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions
