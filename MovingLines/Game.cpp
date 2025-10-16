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
	ClearBackground(100.0f/255.0f, 100.0f/255.0f, 170.0f/255.0f);

	// Put your own draw statements here
	DrawLines();

}

void Update(float elapsedSec)
{
	// process input, do physics 
	++g_NrFrames;
	std::cout << g_NrFrames << std::endl;
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
void DrawLines()
{
	SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	// float offset{ float(g_NrFrames % int(g_WindowWidth)) };
	float offset{fmodf(float(g_NrFrames), g_WindowWidth)};

	DrawLine(offset, 0, offset, g_WindowHeight);
	DrawLine(g_WindowWidth - offset, 0, g_WindowWidth - offset, g_WindowHeight);
	DrawLine(0, offset, g_WindowWidth, offset);
	DrawLine(0, g_WindowHeight - offset, g_WindowWidth, g_WindowHeight - offset);

	SetColor(1.0f, 1.0f, 0, 1.0f);
	DrawLine(offset, 0, g_WindowWidth, offset);
	DrawLine(g_WindowWidth, offset, g_WindowWidth - offset, g_WindowHeight);
	DrawLine(g_WindowWidth - offset, g_WindowHeight, 0, g_WindowHeight - offset);
	DrawLine(0, g_WindowHeight - offset, offset, 0);
}
#pragma endregion ownDefinitions