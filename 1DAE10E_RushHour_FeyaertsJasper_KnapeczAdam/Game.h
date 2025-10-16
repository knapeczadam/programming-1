#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Rush Hour - Jasper Feyaerts, Adam Knapecz" };

// Change the window dimensions here
float g_WindowWidth{ 1280 };
float g_WindowHeight{ 720 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
class RushHour;
RushHour* g_RushHour{nullptr};
// Declare your own functions here

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
