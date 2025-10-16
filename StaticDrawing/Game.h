// Knapecz, Adam - 1DAE11
#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "StaticDrawing - Knapecz, Adam - 1DAE11" };

// Change the window dimensions here
float g_WindowWidth{ 1024 };
float g_WindowHeight{ 768 };
Point2f g_WindowCenter{ g_WindowWidth / 2, g_WindowHeight / 2 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
// COLORS
std::vector<Point2f> starPoints;
struct Colors
{
	static const Color4f BACKGROUND_COLOR;
	static const Color4f RED;
	static const Color4f GREEN;
	static const Color4f BLUE;
	static const Color4f BLACK;
	static const Color4f WHITE;
	static const Color4f CYAN; 
	static const Color4f MAGENTA;
	static const Color4f YELLOW;
};

const Color4f Colors::BACKGROUND_COLOR{ 50 / 255.0f, 20 / 255.0f, 50 / 255.0f, 1.0f };
const Color4f Colors::RED{ 1.0f, 0, 0, 1.0f };
const Color4f Colors::GREEN{ 0, 1.0f, 0, 1.0f };
const Color4f Colors::BLUE{ 0, 0, 1.0f, 1.0f };
const Color4f Colors::BLACK{ 0, 0, 0, 1.0f };
const Color4f Colors::WHITE{ 1.0f, 1.0f, 1.0f, 1.0f };
const Color4f Colors::CYAN{ 0, 1.0f, 1.0f, 1.0f };
const Color4f Colors::MAGENTA{ 1.0f, 0, 1.0f, 1.0f };
const Color4f Colors::YELLOW{ 1.0f, 1.0f, 0, 1.0f };

float percentage[4]{};

// Declare your own functions here
void DrawHouse();
void DrawFlag();
void DrawCheckerPattern();
void DrawColorBand();
void DrawPentagram();
void DrawColumnChar();
void CreateStarPoints();
void RotatePoint(Point2f& point, float deltaTime);
void test();
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
