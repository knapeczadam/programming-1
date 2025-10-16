// Knapecz, Adam - 1DAE11
#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{"Clock Pointers- Knapecz, Adam - 1DAE11"};

// Change the window dimensions here
float g_WindowWidth{500};
float g_WindowHeight{500};
#pragma endregion gameInformation


#pragma region ownDeclarations
// Declare your own global variables here
int g_NrFrames{};

struct ClockPointers
{
	Point2f center{g_WindowWidth / 2, g_WindowHeight / 2};
	const float largeRadius{150.0f};
	const float smallRadius{100.0f};
	const float fullCircleDeg{360};
	const float fullCircleRad{2 * g_Pi};
	const float halfCircleDeg{fullCircleDeg / 2};
	const float halfCircleRad{g_Pi};
	const float t{240.0f};
	const float f{fullCircleRad / t};
	const float largePointerThickness{10.0f};
	const float largePointerHalfThickness{largePointerThickness / 2};
	const float smallPointerThickness{7.0f};
	const float smallPointerHalfThickness{smallPointerThickness / 2};
	const float largeOpposite{largePointerHalfThickness};
	const float smallOpposite{smallPointerHalfThickness};
	const float largeAdjacent{largeRadius / 3};
	const float smallAdjacent{smallRadius / 3};
	const float largePointerSpeed{1.0f};
	const float smallPointerSpeed{largePointerSpeed / 12};
	const float clockwise{-1};
	const float counterClockwise{1};
	float largeAngle{};
	float smallAngle{};
} clockPointers;

// Declare your own functions here
void DrawSmallPointer();
void DrawLargePointer();
Point2f CreatePointerPoint(float speed, float radius, float angleOffset = 0, bool clockwise = true);
Point2f AddPoints(const Point2f& a, const Point2f& b);
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
