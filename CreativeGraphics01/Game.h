#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
constexpr  float cubeSize{ 150.f };
constexpr float pointOffset{ 30.f };
const Point2f g_WindowCenter{ g_WindowWidth / 2, g_WindowHeight / 2 };
Point2f a{ g_WindowCenter.x - cubeSize / 2,g_WindowCenter.y - cubeSize / 2 };
Point2f b{ g_WindowCenter.x + cubeSize / 2,g_WindowCenter.y - cubeSize / 2 };
Point2f c{ g_WindowCenter.x + cubeSize / 2,g_WindowCenter.y + cubeSize / 2 };
Point2f d{ g_WindowCenter.x - cubeSize / 2,g_WindowCenter.y + cubeSize / 2 };

Point2f aa{ g_WindowCenter.x - cubeSize / 2 + pointOffset,g_WindowCenter.y - cubeSize / 2 + pointOffset};
Point2f bb{ g_WindowCenter.x + cubeSize / 2 + pointOffset,g_WindowCenter.y - cubeSize / 2 + pointOffset };
Point2f cc{ g_WindowCenter.x + cubeSize / 2 + pointOffset,g_WindowCenter.y + cubeSize / 2 + pointOffset };
Point2f dd{ g_WindowCenter.x - cubeSize / 2 + pointOffset,g_WindowCenter.y + cubeSize / 2 + pointOffset };

// Declare your own functions here
void RotatePoint(Point2f& point, float deltaTime)
{
	double s = sin(deltaTime);
	double c = cos(deltaTime);

	point.x -= g_WindowCenter.x;
	point.y -= g_WindowCenter.y;

	double newX = point.x * c - point.y * s;
	double newY = point.x * s + point.y * c;

	point.x = static_cast<float>(newX) + g_WindowCenter.x;
	point.y = static_cast<float>(newY) + g_WindowCenter.y;
}

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
