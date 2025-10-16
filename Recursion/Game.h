// Knapecz, Adam - 1DAE11
#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{"Recursion - Knapecz, Adam - 1DAE11"};

// Change the window dimensions here
float g_WindowWidth{500};
float g_WindowHeight{300};
#pragma endregion gameInformation


#pragma region ownDeclarations
// Declare your own global variables here
const Point2f g_Left{0, 0};
const Point2f g_Top{g_WindowWidth / 2, g_WindowHeight};
const Point2f g_Right{g_WindowWidth, 0};
const Color4f g_Red{1.0f, 0, 0, 1.0f};
const Color4f g_Green{0, 1.0f, 0, 1.0f};
const Color4f g_Blue{0, 0, 1.0f, 1.0f};
// Declare your own functions here
void DrawSierpinskiTriangle(const Point2f& left, const Point2f& top, const Point2f right);
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
