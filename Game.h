#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 400 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Point2f g_StickSphereCenter{ g_WindowWidth / 2, g_WindowHeight / 2 };
std::vector<float> g_StickSphereDirection{ 2.0f, 2.0f };
float g_StickRotation{ .05f };
float g_StickAngle{ .0f };
float g_StickSphereRadius{ 100.0f };

std::vector<float> g_TopNormal{ 0, -1 };
std::vector<float> g_LeftNormal{ 1, 0 };
std::vector<float> g_BottomNormal{ 0, 1 };
std::vector<float> g_RightNormal{ -1, 0 };

int g_NrFrames{ 0 };

// Declare your own functions here
void DrawStick();
float DotProduct2d(std::vector<float> &v1, std::vector<float> &v2);

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
