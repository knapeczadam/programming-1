// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Game.h"
#include <vector>
#include <cmath>
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

	// CONSTANTS
	const float fullPeriod{ 360.0f };
	const float D2R{ g_Pi / (fullPeriod / 2) };
	const float speed{ 1.0f / 5 };
	const float angle{ g_NrFrames * D2R * speed };

	// CENTER
	Point2f center{ g_WindowWidth / 2, g_WindowHeight / 2 };

	// RADIUS
	float outerRadius = std::sinf(angle) * 50 + 150;
	float midRadius = outerRadius * 2 / 3;
	float innerRadius = outerRadius / 3;

	// NUMBER OF OUTER POINTS
	int outerPointsNum = 100;

	// DEGREE
	float outerAngleDeg = 360.0f / outerPointsNum;
	float midAngleDeg = outerAngleDeg / 2;
	float innerAngleDeg = outerAngleDeg / 3;

	// RADIAN
	float outerAngleRad = outerAngleDeg * D2R;
	float midAngleRad = midAngleDeg * D2R;
	float innerAngleRad = innerAngleDeg * D2R;

	std::vector<Point2f> points;
	int numOfPointsInBlock = 4;
	points.reserve(outerPointsNum * numOfPointsInBlock);

	for (int i = 0; i < outerPointsNum; ++i)
	{
		float outerX = std::cosf(angle + outerAngleRad * i) *  (outerRadius + i * -2 * std::sinf(angle)) + center.x;
		float outerY = std::sinf(angle + outerAngleRad * i) *  (outerRadius + i * 3 * std::cosf(angle)) + center.y;
		points.push_back(Point2f{outerX, outerY});

		float innerX1 = std::cosf(angle + outerAngleRad * i + innerAngleRad) * (innerRadius + i * -13 * std::sinf(angle)) + center.x;
		float innerY1 = std::sinf(angle + outerAngleRad * i + innerAngleRad) * (innerRadius + i * 21 * std::cosf(angle)) + center.y;
		points.push_back(Point2f{ innerX1, innerY1 });
		
		float midX = std::cosf(angle + outerAngleRad * i + midAngleRad) * (midRadius + i * 13 * std::cosf(angle)) + center.x;
		float midY = std::sinf(angle + outerAngleRad * i + midAngleRad) * (midRadius + i * -8 * std::sinf(angle)) + center.y;
		points.push_back(Point2f{ midX, midY });
		
		float innerX2 = std::cosf(angle + outerAngleRad * i + innerAngleRad * 2) * (innerRadius + i * std::sinf(angle)) + center.x;
		float innerY2 = std::sinf(angle + outerAngleRad * i + innerAngleRad * 2) * (innerRadius + i * std::cosf(angle)) + center.y;
		points.push_back(Point2f{ innerX2, innerY2 });
	}

	for (int i = 0; i < outerPointsNum; ++i)
	{
		SetColor(std::sinf(angle), std::cosf(angle), std::tanf(angle));
		DrawLine(points[i * numOfPointsInBlock], points[i * numOfPointsInBlock + 1]);
		SetColor(std::sinf(angle), std::cosf(angle), std::sinf(angle));
		DrawLine(points[i * numOfPointsInBlock + 1], points[i * numOfPointsInBlock + 2]);
		SetColor(std::cosf(angle), std::sinf(angle), std::cosf(angle));
		DrawLine(points[i * numOfPointsInBlock + 2], points[i * numOfPointsInBlock + 3]);
		SetColor(std::tanf(angle), std::cosf(angle), std::sinf(angle));
		DrawLine(points[i * numOfPointsInBlock + 3], points[(i * numOfPointsInBlock + 4) % points.size() ]);
	}
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
#pragma endregion ownDefinitions