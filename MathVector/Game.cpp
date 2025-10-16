// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Game.h"

#include <iomanip>
#include <iostream>

//Basic game functions
#pragma region gameFunctions
void Start()
{
	// initialize game resources here
	PrintVectorInfo();
}

void Draw()
{
	ClearBackground(0, 0, 0.3f);

	// Put your own draw statements here
	DrawInitialVectors();
	DrawAddition();
	DrawSubtraction();
	DrawProjection();
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
void PrintVectorInfo()
{
	// DOT
	std::cout << std::fixed << std::setprecision(6);
	std::cout << utils::ToString(g_V1) << std::endl;
	std::cout << std::endl;
	std::cout << "Dot product:" << std::endl;
	std::cout << "hor = " << utils::ToString(g_V2);
	std::cout << std::setw(15);
	std::cout << "ver = " << utils::ToString(g_V3);
	std::cout << std::setw(15);
	std::cout << "Dot product: " << utils::DotProduct(g_V2, g_V3) << std::endl;
	std::cout << "ver = " << utils::ToString(g_V3);
	std::cout << std::setw(15);
	std::cout << "para = " << utils::ToString(g_V4);
	std::cout << std::setw(15);
	std::cout << "Dot product: " << utils::DotProduct(g_V3, g_V4) << std::endl;
	std::cout << std::endl;

	// CROSS
	std::cout << "Cross product:" << std::endl;
	std::cout << "hor = " << utils::ToString(g_V2);
	std::cout << std::setw(15);
	std::cout << "ver = " << utils::ToString(g_V3);
	std::cout << std::setw(17);
	std::cout << "Cross product: " << utils::CrossProduct(g_V2, g_V3) << std::endl;
	std::cout << "ver = " << utils::ToString(g_V2);
	std::cout << std::setw(15);
	std::cout << "hor = " << utils::ToString(g_V3);
	std::cout << std::setw(17);
	std::cout << "Cross product: " << utils::CrossProduct(g_V3, g_V2) << std::endl;
	std::cout << std::endl;

	// LENGTH
	std::cout << "Length of " << utils::ToString(g_V1) << " is " << utils::Length(g_V1) << std::endl;
	std::cout << std::endl;

	// SCALAR
	std::cout << "Scaled " << utils::ToString(g_V1) << " is " << utils::ToString(utils::Scale(g_V1, 0.1f)) << std::endl;
	std::cout << std::endl;

	// NORMALIZED
	const Vector2f n{utils::Normalize(g_V1)};
	std::cout << "Normalized " << utils::ToString(g_V1) << " is " << utils::ToString(n) << " its length is: " <<
		utils::Length(n) << std::endl;
	std::cout << std::endl;

	// ANGLE
	const float angle{utils::AngleBetween(g_V5, g_V6)};
	std::cout << "Angle between " << utils::ToString(g_V5) << " and " << utils::ToString(g_V6) << " is: " << angle <<
		" radians, or " << angle * 180 / g_Pi << " degrees." << std::endl;
}

void DrawInitialVectors()
{
	SetColor(g_Yellow);
	const Point2f p1{50.0f, 30.0f};
	const Point2f p2{80.0f, 30.0f};

	utils::DrawVector(g_V1);
	utils::DrawVector(p1, g_V1);
	utils::DrawVector(p2, g_V1);
}

void DrawAddition()
{
	SetColor(g_Green);
	const Point2f p3{200.0f, 20.0f};
	const Point2f p4{Add(p3, g_V1)};
	const Vector2f add{utils::Add(g_V1, g_V7)};

	utils::DrawVector(p3, g_V1);
	utils::DrawVector(p4, g_V7);
	utils::DrawVector(p3, add);
}

void DrawSubtraction()
{
	SetColor(g_White);
	const Point2f p5{20.0f, 200.0f};
	const Vector2f sub{utils::Subtract(g_V1, g_V7)};
	const Point2f p6{Add(p5, g_V7)};

	utils::DrawVector(p5, g_V1);
	utils::DrawVector(p5, g_V7);
	utils::DrawVector(sub, p6);
}

void DrawProjection()
{
	SetColor(g_Red);
	float cos{std::cosf(g_NrFrames * g_Speed * g_Pi / 180)};
	float sin{std::sinf(g_NrFrames * g_Speed * g_Pi / 180)};
	const Point2f center{g_WindowWidth / 2, g_WindowHeight / 2};
	const float r{80.0f};
	const Vector2f movingVector{cos * r, sin * r};

	const float dotProduct{utils::DotProduct(utils::Normalize(movingVector), utils::Normalize(g_V8))};
	const Vector2f projectedVector{utils::Scale(g_V8, dotProduct)};

	utils::DrawVector(center, movingVector);
	utils::DrawVector(center, projectedVector);
}
#pragma endregion ownDefinitions
