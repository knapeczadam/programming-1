// Knapecz, Adam - 1DAE11
#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "GameFunctions - Knapecz, Adam - 1DAE11" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Circlef g_Circle;
Circlef g_MouseCircle;
Rectf g_Rect;
Rectf g_MouseRect;
Point2f g_MousePos;
// COLORS
const Color4f g_White{ 1.0f, 1.0f, 1.0f, 1.0f };
const Color4f g_Red{ 1.0, 0, 0, 1.0f };
const Color4f g_Green{ 0, 1.0f, 0, 1.0f };
// Declare your own functions here
void DrawStaticCircle();
void DrawStaticRect();
void DrawPlayerRect();
void DrawPlayerCircle();
#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
