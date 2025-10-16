// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground(0, 0, 0);

	// Put your own draw statements here
	float r = std::rand() % 256 / 100.0f;
	float g = std::rand() % 256 / 100.0f;
	float b = std::rand() % 256 / 100.0f;
	float a = std::rand() % 256 / 100.0f;
	SetColor(r, g, b, a);
	float offset = 10;
	float randWidth = rand() % int(g_WindowWidth - 2 * offset) + 1.0f;
	float randHeight = rand() % int(g_WindowHeight - 2 * offset) + 1.0f;
	float randLeft = rand() % int(g_WindowWidth - 2 * offset) + offset + 1.0f;
	float randBottom = rand() % int(g_WindowHeight - 2 * offset) + offset + 1.0f;
	float maxX = int(g_WindowWidth) - offset;
	float maxY = int(g_WindowHeight) - offset;
	if (randLeft + randWidth > maxX)
	{
		randWidth = maxX - randLeft;
	}
	if (randBottom + randHeight > maxY)
	{
		randHeight = maxY - randBottom;
	}
	FillRect(randLeft, randBottom, randWidth, randHeight);

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

#pragma endregion ownDefinitions