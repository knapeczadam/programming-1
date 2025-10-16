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
	DrawYellowBar();
	DrawRedBar();

}

void Update(float elapsedSec)
{
	// process input, do physics 
	++g_NrFrames;
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
void DrawYellowBar()
{
	const int maxWidth{ 400};
	const float height{ 100.0f };
	const Point2f bottomLeft{ 20.0f, 150.0f };
	const float p = 1.0f; // period
	const float t = 1.0f; // time
	const float f = p / t; // frequency
	const float speed = f * g_NrFrames;

	const Color4f yellow{ 200.0f, 200.0f, 0, 1.0f };

	SetColor(yellow);
	FillRect(bottomLeft.x, bottomLeft.y, float(int(speed) % maxWidth), height);
	SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	DrawRect(bottomLeft.x, bottomLeft.y, maxWidth, height);
}

void DrawRedBar()
{
	const int maxWidth{ 400 };
	const float height{ 100.0f };
	const Point2f bottomLeft{ 20.0f, 20.0f };
	const float p = 1.0f; // period
	const float t = 2.0f; // time
	const float f = p / t; // frequency
	const float speed = f * g_NrFrames;

	const float startRed{ 120.0f };
	const float remainingRed{ 255.0f - startRed };
	float red { startRed };
	red += remainingRed * (int(speed) % maxWidth / float(maxWidth));
	red /= 255.0f;
	SetColor(red, 0, 0, 1.0f);

	FillRect(bottomLeft.x, bottomLeft.y, float(int(speed) % maxWidth), height);
	SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	DrawRect(bottomLeft.x, bottomLeft.y, maxWidth, height);
}


#pragma endregion ownDefinitions