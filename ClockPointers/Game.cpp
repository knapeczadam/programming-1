// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Game.h"
#include <cmath>

//Basic game functions
#pragma region gameFunctions
void Start()
{
	// initialize game resources here
	clockPointers.largeAngle = std::atan(clockPointers.largeOpposite / clockPointers.largeAdjacent);
	clockPointers.smallAngle = std::atan(clockPointers.smallOpposite / clockPointers.smallAdjacent);
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawSmallPointer();
	DrawLargePointer();
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
void DrawSmallPointer()
{
	Point2f apex{CreatePointerPoint(clockPointers.smallPointerSpeed, clockPointers.smallRadius)};
	Point2f a{CreatePointerPoint(clockPointers.smallPointerSpeed, clockPointers.smallAdjacent, clockPointers.smallAngle)};
	Point2f b{CreatePointerPoint(clockPointers.smallPointerSpeed, clockPointers.smallAdjacent, -clockPointers.smallAngle)};

	SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	DrawLine(clockPointers.center, a);
	DrawLine(a, apex);
	DrawLine(clockPointers.center, b);
	DrawLine(b, apex);
}

void DrawLargePointer()
{
	Point2f apex{CreatePointerPoint(clockPointers.largePointerSpeed, clockPointers.largeRadius)};
	Point2f a{CreatePointerPoint(clockPointers.largePointerSpeed, clockPointers.largeAdjacent, clockPointers.largeAngle)};
	Point2f b{CreatePointerPoint(clockPointers.largePointerSpeed, clockPointers.largeAdjacent, -clockPointers.largeAngle)};

	SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	DrawLine(clockPointers.center, a);
	DrawLine(a, apex);
	DrawLine(clockPointers.center, b);
	DrawLine(b, apex);
}

Point2f CreatePointerPoint(float speed, float radius, float angleOffset, bool clockwise)
{
	const float rotation{clockwise ? clockPointers.clockwise : clockPointers.counterClockwise};
	float x{rotation * std::cos(g_NrFrames * clockPointers.f * speed + angleOffset) * radius};
	float y{std::sin(g_NrFrames * clockPointers.f * speed + angleOffset) * radius};
	x += clockPointers.center.x;
	y += clockPointers.center.y;
	Point2f p{x, y};
	return p;
}
#pragma endregion ownDefinitions
