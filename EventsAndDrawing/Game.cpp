// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Game.h"

#include "RandomLine.h"
#include "RandomRect.h"

#include <iostream>

//Basic game functions
#pragma region gameFunctions
void Start()
{
	// initialize game resources here
	PrintInfo();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	g_RandRect.Draw();
	g_RandLine.Draw();
}

void Update(float elapsedSec)
{
	// process input, do physics 
	g_RandRect.Update(elapsedSec);
	g_RandLine.Update(elapsedSec);
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
	case SDLK_r:
		g_RandRect.ToggleMotion();
		break;
	case SDLK_l:
		g_RandLine.ToggleMotion();
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
		g_RandRect.ProcessMouseClick(float(e.x), float(g_WindowHeight - e.y));
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
void PrintInfo()
{
	std::cout << "Press 'r' to toggle movement." << std::endl;
	std::cout << "Click the rectangle to turn it green and gray again." << std::endl;
	std::cout << "Press the 'l' key to toggle the line." << std::endl;
}
#pragma endregion ownDefinitions
