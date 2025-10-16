// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Game.h"
#include <vector>
#include <cmath>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	SetColor(1.0f, 0, 0);
	// Put your own draw statements here

	// CONSTANTS
	const float pi = 3.14f;
	const float halfCircleDeg = 180.0f;

	// CENTER
	Point2f center{ g_WindowWidth / 2, g_WindowHeight / 2 };

	// RADIUS
	float outerRadius = 200.0f;
	float midRadius = outerRadius * 2 / 3;
	float innerRadius = outerRadius / 3;

	// NUMBER OF OUTER POINTS
	int outerPointsNum = 20;

	// OFFSET TRICK AGAINST OVERFLOW
	float offset = pi / 180.0f;

	// DEGREE
	float outerAngleDeg = 360.0f / outerPointsNum;
	float midAngleDeg = outerAngleDeg / 2;
	float innerAngleDeg = outerAngleDeg / 3;

	// RADIAN
	float outerAngleRad = outerAngleDeg * (pi / halfCircleDeg);
	// outerAngleRad += offset;
	float midAngleRad = midAngleDeg * (pi / halfCircleDeg);
	// midAngleRad += offset;
	float innerAngleRad = innerAngleDeg * (pi / halfCircleDeg);
	// innerAngleRad += offset;

	std::vector<Point2f> points;
	int numOfPointsInBlock = 4;
	points.reserve(outerPointsNum * numOfPointsInBlock);

	for (int i = 0; i < outerPointsNum; ++i)
	{
		float outerX = std::cosf(outerAngleRad * i) * outerRadius + center.x;
		float outerY = std::sinf(outerAngleRad * i) * outerRadius + center.y;
		points.push_back(Point2f{outerX, outerY});

		float innerX1 = std::cosf(outerAngleRad * i + innerAngleRad) * innerRadius + center.x;
		float innerY1 = std::sinf(outerAngleRad * i + innerAngleRad) * innerRadius + center.y;
		points.push_back(Point2f{ innerX1, innerY1 });
		
		float midX = std::cosf(outerAngleRad * i + midAngleRad) * midRadius + center.x;
		float midY = std::sinf(outerAngleRad * i + midAngleRad) * midRadius + center.y;
		points.push_back(Point2f{ midX, midY });
		
		float innerX2 = std::cosf(outerAngleRad * i + innerAngleRad * 2) * innerRadius + center.x;
		float innerY2 = std::sinf(outerAngleRad * i + innerAngleRad * 2) * innerRadius + center.y;
		points.push_back(Point2f{ innerX2, innerY2 });
	}

	for (int i = 0; i < outerPointsNum; ++i)
	{
		DrawLine(points[i * numOfPointsInBlock], points[i * numOfPointsInBlock + 1]);
		DrawLine(points[i * numOfPointsInBlock + 1], points[i * numOfPointsInBlock + 2]);
		DrawLine(points[i * numOfPointsInBlock + 2], points[i * numOfPointsInBlock + 3]);
		DrawLine(points[i * numOfPointsInBlock + 3], points[(i * numOfPointsInBlock + 4) % points.size()]);
	}

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