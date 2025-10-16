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
	DrawLines();
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
	switch (key)
	{
	case SDLK_RIGHT:
		SwitchColor();
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
	g_MousePosX = float(e.x);
	g_MousePosY = float(g_WindowHeight - e.y);
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
	switch (g_Color)
	{
	case Color::red:
		SetColor(1.0f, 0, 0, 1.0f);
		break;
	case Color::green:
		SetColor(0, 1.0f, 0, 1.0f);
		break;
	case Color::blue:
		SetColor(0, 0, 1.0f, 1.0f);
		break;
	}

	for (float i{}; i <= g_WindowWidth; i += 9.0f)
	{
		DrawLine(i, 0, g_MousePosX, g_MousePosY);
		DrawLine(i, g_WindowHeight, g_MousePosX, g_MousePosY);
	}
	for (float i{}; i < g_WindowHeight; i += 9.0f)
	{
		DrawLine(0, i, g_MousePosX, g_MousePosY);
		DrawLine(g_WindowWidth, i, g_MousePosX, g_MousePosY);
	}
}

void SwitchColor()
{
	int color{int(g_Color)};
	g_Color = (Color)(++color % 3);
}

#pragma endregion ownDefinitions
