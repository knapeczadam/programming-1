// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Game.h"
#include "myutils.h"

#include <cmath>

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

	// SQUARES
	const float border{10.0f};
	const float squareWidth1{100.0f};
	const float squareWidth2{100.0f};
	const float squareWidth3{50.0f};
	myutils::DrawSquares(border, g_WindowHeight - border - squareWidth1, squareWidth1, 10);
	myutils::DrawSquares(border + squareWidth1 + border, g_WindowHeight - border - squareWidth1, squareWidth2, 5);
	myutils::DrawSquares(border + squareWidth1 + border + squareWidth2 + border, g_WindowHeight - border - squareWidth1,
	                     squareWidth3, 3);

	// TRIANGLES
	const float offset{10.0f};
	const float offsetX{std::cosf(60 / 2 * (g_Pi / 180)) * offset};
	const float offsetY{std::sinf(60 / 2 * (g_Pi / 180)) * offset};
	const float triangeWidth{100.0f};
	const float triangleX{g_WindowWidth / 2 + 50.0f};
	const float triangleY{g_WindowHeight - border - triangeWidth};
	myutils::DrawEquilateralTriangle(triangleX, triangleY, triangeWidth, false, true, {}, myutils::red);
	myutils::DrawEquilateralTriangle(triangleX + 1 * offsetX, triangleY + 1 * offsetY, triangeWidth - 2 * offsetX,
	                                 false, true, {}, myutils::green);
	myutils::DrawEquilateralTriangle(triangleX + 2 * offsetX, triangleY + 2 * offsetY, triangeWidth - 4 * offsetX,
	                                 false, true, {}, myutils::blue);


	const float smallTriangleX{triangleX + triangeWidth + border};
	const float smallTriangleY{triangleY};
	const float smallTriangleWidth{triangeWidth / 2};
	const float altitude{std::sqrtf(std::powf(smallTriangleWidth, 2) - std::powf(smallTriangleWidth / 2, 2))};
	myutils::DrawEquilateralTriangle(smallTriangleX, smallTriangleY, smallTriangleWidth, true, true, {}, myutils::cyan);
	myutils::DrawEquilateralTriangle(smallTriangleX + smallTriangleWidth, smallTriangleY, smallTriangleWidth, true,
	                                 true, {}, myutils::yellow);
	myutils::DrawEquilateralTriangle(smallTriangleX + smallTriangleWidth / 2, smallTriangleY + altitude,
	                                 smallTriangleWidth, true, true, {}, myutils::magenta);

	// PENTAGRAM
	const float radius1{50.0f};
	const float pentagramX{triangleX + radius1};
	const float pentagramY{triangleY - 100.0f};
	myutils::DrawPentagram(pentagramX, pentagramY, radius1, myutils::red);
	myutils::DrawPentagram(pentagramX + radius1 + border + radius1 / 3, pentagramY, radius1 / 3, myutils::blue);

	// LINEAR GRADIENT
	const float width{100.0f};
	const float height{50.0f};
	const float baseHeight{ 130.0f };
	myutils::DrawLinearGradient(border, border + baseHeight + 3 * border + 3 * height, width, height);
	myutils::DrawLinearGradient(border, border + baseHeight + 2 * border + 2 * height, width * 2, height, myutils::red, myutils::magenta);
	myutils::DrawLinearGradient(border, border + baseHeight + 1 * border + 1 * height, width * 3, height, myutils::yellow, myutils::green);
	myutils::DrawLinearGradient(border, border + baseHeight, width * 4, height, myutils::blue, myutils::cyan);

	// DotGrid
	myutils::DrawDotGrid(border, border, 3, 5, 20, 2, myutils::red);
	const float bigGridLeft{ border + 450.0f };
	const float bigGridBottom{ border + 50.0f };
	const float bigRadius{ 20.0f };
	const float bigSpacing{ 2.0f };
	const float smallGridLeft{ bigGridLeft + bigRadius / 2 };
	const float smallGridBottom{ bigGridBottom + bigRadius / 2 };
	const float smallRadius{ bigRadius / 2 };
	const float smallSpacing{ bigRadius + bigSpacing };
	myutils::DrawDotGrid(bigGridLeft, bigGridBottom, 2, 7, bigRadius, bigSpacing, myutils::green);
	myutils::DrawDotGrid(smallGridLeft, smallGridBottom, 2, 7, smallRadius, smallSpacing, myutils::blue);
}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
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

#pragma endregion ownDefinitions
