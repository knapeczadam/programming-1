// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions
void Start()
{
	// initialize game resources here
	const float minRadius{10.0f};
	const float maxRadius{30.0f};
	g_Circle.radius = utils::GetRand(minRadius, maxRadius);
	g_Circle.center.x = utils::GetRand(g_Circle.radius, g_WindowWidth - g_Circle.radius);
	g_Circle.center.y = utils::GetRand(g_Circle.radius, g_WindowHeight - g_Circle.radius);

	const float minWidth{10.0f};
	const float maxWidth{100.0f};
	const float minHeight{10.0f};
	const float maxHeight{100.0f};
	g_Rect.width = utils::GetRand(minWidth, maxWidth);
	g_Rect.height = utils::GetRand(minHeight, maxHeight);
	g_Rect.left = utils::GetRand(0, g_WindowWidth - g_Rect.width);
	g_Rect.bottom = utils::GetRand(0, g_WindowHeight - g_Rect.height);

	g_MouseCircle.radius = 20.0f;
	g_MouseRect.width = 20.0f;
	g_MouseRect.height = 10.0f;
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawStaticCircle();
	DrawStaticRect();
	DrawPlayerRect();
	DrawPlayerCircle();
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
	g_MousePos.x = float(e.x);
	g_MousePos.y = float(g_WindowHeight - e.y);
	g_MouseRect.left = g_MousePos.x - g_MouseRect.width;
	g_MouseRect.bottom = g_MousePos.y;
	g_MouseCircle.center.x = g_MousePos.x + g_MouseCircle.radius;
	g_MouseCircle.center.y = g_MousePos.y;
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
void DrawStaticCircle()
{
	SetColor(g_White);
	FillEllipse(g_Circle.center.x, g_Circle.center.y, g_Circle.radius, g_Circle.radius);
	if (utils::IsPointInCircle(g_MousePos, g_Circle))
	{
		SetColor(g_Red);
		DrawEllipse(g_Circle.center.x, g_Circle.center.y, g_Circle.radius, g_Circle.radius, 2.0f);
	}
}

void DrawStaticRect()
{
	SetColor(g_White);
	FillRect(g_Rect.left, g_Rect.bottom, g_Rect.width, g_Rect.height);
	if (utils::IsPointInRect(g_MousePos, g_Rect))
	{
		SetColor(g_Red);
		DrawRect(g_Rect.left, g_Rect.bottom, g_Rect.width, g_Rect.height, 2.0f);
	}
}

void DrawPlayerRect()
{
	Color4f midGreen{g_Green};
	midGreen.a = 0.5f;
	SetColor(midGreen);
	if (utils::IsOverlapping(g_MouseRect, g_Rect))
	{
		Color4f midRed{g_Red};
		midRed.a = 0.5f;
		SetColor(midRed);
	}
	FillRect(g_MouseRect.left, g_MouseRect.bottom, g_MouseRect.width, g_MouseRect.height);
}

void DrawPlayerCircle()
{
	Color4f midGreen{g_Green};
	midGreen.a = 0.5f;
	SetColor(midGreen);
	if (utils::IsOverlapping(g_MouseCircle, g_Circle))
	{
		Color4f midRed{g_Red};
		midRed.a = 0.5f;
		SetColor(midRed);
	}
	FillEllipse(g_MouseCircle.center.x, g_MouseCircle.center.y, g_MouseCircle.radius, g_MouseCircle.radius);
}
#pragma endregion ownDefinitions
