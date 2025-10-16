// Knapecz, Adam - 1DAE11
#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{"FrameTime - Knapecz, Adam - 1DAE11"};

// Change the window dimensions here
float g_WindowWidth{500};
float g_WindowHeight{300};
#pragma endregion gameInformation


#pragma region ownDeclarations
// Declare your own global variables here
int g_NrFrames{};
float g_AccTime{};
float g_Radius{25.0f};
Point2f g_BallPos{g_WindowWidth / 2, g_WindowHeight / 2};
const float g_CubeWidth{10.0f};
const Point2f g_CubeInitPos{g_WindowWidth / 2 - 10.0f / g_CubeWidth, g_WindowHeight - g_CubeWidth};
Point2f g_CubePos{};
Point2f g_BallVelocity{100.0f, 80.0f};
const Point2f g_CubeInitVelocity{0.0f, 0.0f};
Point2f g_CubeVelocity{};
const float g_Gravity{-9.8f};
bool g_Simulate{false};
// Declare your own functions here
void PrintInfo();
void DrawBall();
void UpdateBall(float deltaTime);
void UpdateFreeFall(float deltaTime);
void DrawFreeFall();
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
