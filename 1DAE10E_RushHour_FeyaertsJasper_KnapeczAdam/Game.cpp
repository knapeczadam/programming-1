#include "pch.h"
#include "Game.h"
#include "RushHour.h"
//Basic game functions
#pragma region gameFunctions
void Start()
{
	// initialize game resources here
	g_RushHour = new RushHour{};
}


void Draw()
{
	// Put your own draw statements here
	g_RushHour->Draw();
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
	delete g_RushHour;
	g_RushHour = nullptr;
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling
void OnKeyDownEvent(SDL_Keycode key)
{
}

void OnKeyUpEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_i:
		g_RushHour->ToggleInstructionsCanvas();
		break;
	case SDLK_LEFT:
		g_RushHour->MoveCar(Movement::left);
		break;
	case SDLK_RIGHT:
		g_RushHour->MoveCar(Movement::right);
		break;
	case SDLK_UP:
		g_RushHour->MoveCar(Movement::up);
		break;
	case SDLK_DOWN:
		g_RushHour->MoveCar(Movement::down);
		break;
	case SDLK_r:
		g_RushHour->ResetLevel();
		break;
	}
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
		g_RushHour->ProcessMouseInput(float(e.x), float(g_WindowHeight - e.y));
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

#pragma endregion ownDefinitions
