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
	ClearBackground(0, 0, 0.2f);

	// Put your own draw statements here
	DrawSierpinskiTriangle(g_Left, g_Top, g_Right);
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
void DrawSierpinskiTriangle(const Point2f& left, const Point2f& top, const Point2f right)
{
	const float base{GetDistance(left, right)};
	const int minDistance{ 10 };
	if (base < minDistance)
	{
		return;
	}
	Point2f m{left.x + base / 2, right.y};
	const float height{GetDistance(m, top)};
	Point2f b{left.x + base / 4, top.y - height / 2};
	Point2f c{m.x + base / 4, top.y - height / 2};
	DrawTriangle(left, top, right, 2.0f);
	SetColor(g_Red);
	DrawSierpinskiTriangle(left, b, m);
	SetColor(g_Blue);
	DrawSierpinskiTriangle(m, c, right);
	SetColor(g_Green);
	DrawSierpinskiTriangle(b, top, c);
}

#pragma endregion ownDefinitions
