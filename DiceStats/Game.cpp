// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Game.h"
#include "DiceSimulator.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	const float border{ 20 };
	const Point2f bottomLeft1{ border, border };
	const Color4f color1{ 0.8f, 0.1f, 0.1f, 1.0f };
	g_Simulator1 = new DiceSimulator{bottomLeft1, color1, 6, 1};

	const Point2f bottomLeft2{ border, g_Simulator1->GetHeight() };
	const Color4f color2{ 0.1f, 0.1f, 0.8f, 1.0f };
	g_Simulator2 = new DiceSimulator{bottomLeft2, color2, 11, 2};
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	g_Simulator1->Draw();
	g_Simulator2->Draw();

}

void Update(float elapsedSec)
{
	// process input, do physics 
	g_Simulator1->Simulate();
	g_Simulator2->Simulate();
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
	delete g_Simulator1;
	delete g_Simulator2;
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