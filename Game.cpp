#include "pch.h"
#include "Game.h"

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
	DrawStick();
}

void Update(float elapsedSec)
{
	if (g_NrFrames % 3 == 0)
	{
		// Check if collision 
		Point2f stickEnd1{ g_StickSphereCenter.x + g_StickSphereRadius * cosf(g_StickAngle), g_StickSphereCenter.y + g_StickSphereRadius * sinf(g_StickAngle) };
		Point2f stickEnd2{ g_StickSphereCenter.x + g_StickSphereRadius * cosf(g_StickAngle + g_Pi), g_StickSphereCenter.y + g_StickSphereRadius * sinf(g_StickAngle + g_Pi) };

		// Collision with one of borders
		if (stickEnd1.y >= g_WindowHeight || stickEnd2.y >= g_WindowHeight)
		{
			float tmp{ 2 * DotProduct2d(g_StickSphereDirection, g_TopNormal) };
			g_StickSphereDirection[0] -= tmp * g_TopNormal[0];
			g_StickSphereDirection[1] -= tmp * g_TopNormal[1];
			g_StickRotation = -g_StickRotation;
		}
		if (stickEnd1.y <= 0 || stickEnd2.y <= 0)
		{
			float tmp{ 2 * DotProduct2d(g_StickSphereDirection, g_BottomNormal) };
			g_StickSphereDirection[0] -= tmp * g_BottomNormal[0];
			g_StickSphereDirection[1] -= tmp * g_BottomNormal[1];
			g_StickRotation = -g_StickRotation;
		}
		if (stickEnd1.x <= 0 || stickEnd2.x <= 0)
		{
			float tmp{ 2 * DotProduct2d(g_StickSphereDirection, g_LeftNormal) };
			g_StickSphereDirection[0] -= tmp * g_LeftNormal[0];
			g_StickSphereDirection[1] -= tmp * g_LeftNormal[1];
			g_StickRotation = -g_StickRotation;
		}
		if (stickEnd1.x >= g_WindowWidth || stickEnd2.x > g_WindowWidth)
		{
			float tmp{ 2 * DotProduct2d(g_StickSphereDirection, g_RightNormal) };
			g_StickSphereDirection[0] -= tmp * g_RightNormal[0];
			g_StickSphereDirection[1] -= tmp * g_RightNormal[1];
			g_StickRotation = -g_StickRotation;
		}


		// Update the stick location parameters
		g_StickAngle += g_StickRotation;
		g_StickSphereCenter.x += g_StickSphereDirection[0];
		g_StickSphereCenter.y += g_StickSphereDirection[1];
	}

	// Update framecount
	g_NrFrames++;
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

void DrawStick()
{
	Point2f stickEnd1{ g_StickSphereCenter.x + g_StickSphereRadius * cosf(g_StickAngle), g_StickSphereCenter.y + g_StickSphereRadius * sinf(g_StickAngle) };
	Point2f stickEnd2{ g_StickSphereCenter.x + g_StickSphereRadius * cosf(g_StickAngle + g_Pi), g_StickSphereCenter.y + g_StickSphereRadius * sinf(g_StickAngle + g_Pi) };
	DrawLine(stickEnd1, stickEnd2, 2.0f);
}

float DotProduct2d(std::vector<float>& v1, std::vector<float>& v2)
{
	return v1[0] * v2[0] + v1[1] * v2[1];
}

#pragma endregion ownDefinitions