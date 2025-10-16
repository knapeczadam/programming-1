// Knapecz, Adam - 1DAE11
#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "MathVector - Knapecz, Adam - 1DAE11" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
// VECTORS
Vector2f g_V1{ 100.0f, 30.0f };
Vector2f g_V2{ 80.0f, 0.0f };
Vector2f g_V3{ 0.0f, 50.0f };
Vector2f g_V4{ 0.0f, 25.0f };
Vector2f g_V5{ 10.0f, 0.0f };
Vector2f g_V6{ 10.0f, 10.0f };
Vector2f g_V7{ 30.0f, 40.0f };
Vector2f g_V8{ 40.0f, 10.0f };
// COLORS
const Color4f g_White{ 1.0f, 1.0f, 1.0f, 1.0f };
const Color4f g_Red{ 1.0f, 0, 0, 1.0f };
const Color4f g_Green(0, 1.0f, 0, 1.0f);
const Color4f g_Yellow{ 1.0f, 1.0f, 0, 1.0f };
int g_NrFrames{};
const float g_Speed{ 0.5f };
// Declare your own functions here
void PrintVectorInfo();
void DrawInitialVectors();
void DrawAddition();
void DrawSubtraction();
void DrawProjection();
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
