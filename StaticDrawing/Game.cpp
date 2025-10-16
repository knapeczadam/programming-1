// Knapecz, Adam - 1DAE11
#include "pch.h"
#include <cmath>
#include <vector>
#include <iostream>
#include "Game.h"

//Basic game functions
#pragma region gameFunctions
void Start()
{
	// initialize game resources here
	std::cout << "% people playing games" << std::endl;
	std::cout << "In the range [0, 20]? ";
	std::cin >> percentage[0];
	std::cout << "In the range [21, 40]? ";
	std::cin >> percentage[1];
	std::cout << "In the range [41, 60]? ";
	std::cin >> percentage[2];
	std::cout << "Older than 60 ?";
	std::cin >> percentage[3];

	for (float& e : percentage)
	{
		e = std::min(e, 100.0f);
		e /= 100;
	}

	CreateStarPoints();
}

void Draw()
{
	// Put your own draw statements here
	ClearBackground(Colors::BACKGROUND_COLOR.r, Colors::BACKGROUND_COLOR.g, Colors::BACKGROUND_COLOR.b);
	//DrawHouse();
	//DrawFlag();
	//DrawCheckerPattern();
	//DrawColorBand();
	//DrawPentagram();
	//DrawColumnChar();
	test();
}

void Update(float elapsedSec)
{
	// process input, do physics 
	for (auto& point : starPoints)
	{
		RotatePoint(point, elapsedSec);
	}
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
void DrawHouse()
{
	float houseWidth = 400.0f;
	float houseHeight = 100.0f;
	Point2f houseBottomLeft{20.0f, 500.0f};

	float rootHeight = 100.0f;
	Point2f roofLeftCorner{houseBottomLeft.x, houseBottomLeft.y + houseHeight};
	Point2f roofRightCorner{roofLeftCorner.x + houseWidth, roofLeftCorner.y};
	Point2f roofApex{roofLeftCorner.x + houseWidth / 2, roofLeftCorner.y + rootHeight};

	SetColor(Colors::RED);
	FillRect(houseBottomLeft.x, houseBottomLeft.y, houseWidth, houseHeight);
	FillTriangle(roofLeftCorner, roofRightCorner, roofApex);

	SetColor(Colors::WHITE);
	DrawRect(houseBottomLeft.x, houseBottomLeft.y, houseWidth, houseHeight);
	DrawTriangle(roofLeftCorner, roofRightCorner, roofApex);
}

void DrawFlag()
{
	float flagWidth = 400.0f;
	float flagHeight = 150.0f;
	Point2f flagBottomLeft{20.0f, 300.0f};

	SetColor(Colors::BLACK);
	FillRect(flagBottomLeft.x, flagBottomLeft.y, flagWidth / 3, flagHeight);
	SetColor(Colors::YELLOW);
	FillRect(flagBottomLeft.x + flagWidth / 3, flagBottomLeft.y, flagWidth / 3, flagHeight);
	SetColor(Colors::RED);
	FillRect(flagBottomLeft.x + flagWidth * 2 / 3, flagBottomLeft.y, flagWidth / 3, flagHeight);

	SetColor(Colors::WHITE);
	DrawRect(flagBottomLeft.x, flagBottomLeft.y, flagWidth, flagHeight);
}

void DrawCheckerPattern()
{
	float checkerWidth = 200.0f;
	float checkerHeight = 200.0f;
	Point2f checkerBottomLeft{20.0f, 20.0f};
	int rowTileNum = 3;
	int colTileNum = 3;

	Color4f startColor = Colors::BLACK;
	Color4f secondaryColor = Colors::WHITE;
	for (int r = 0; r < rowTileNum; ++r)
	{
		for (int c = 0; c < colTileNum; ++c)
		{
			if (c % 2 == 0)
			{
				SetColor(startColor);
			}
			else
			{
				SetColor(secondaryColor);
			}
			float left = checkerBottomLeft.x + checkerWidth / colTileNum * c;
			float bottom = checkerBottomLeft.y + checkerHeight / rowTileNum * r;
			FillRect(left, bottom, checkerWidth / colTileNum, checkerHeight / rowTileNum);
		}
		Color4f temp = startColor;
		startColor = secondaryColor;
		secondaryColor = temp;
	}
	DrawRect(checkerBottomLeft.x, checkerBottomLeft.y, checkerWidth, checkerHeight);
}

void DrawColorBand()
{
	float width = 400.0f;
	int bandCount = 9;
	float bandWidth = width / bandCount;
	float height = bandWidth * 4;

	Point2f leftBottom{600.0f, 500.0f};

	float lightY = leftBottom.y + height / 2;
	float halfBandHeight = height / 2;

	const int colorNum = 9;

	Color4f colors[colorNum]
	{
		Colors::BLACK,
		Colors::RED,
		Colors::GREEN,
		Colors::BLUE,
		Colors::MAGENTA,
		Colors::YELLOW,
		Colors::GREEN,
		Colors::CYAN,
		Colors::WHITE
	};

	for (int i = 0; i < bandCount; ++i)
	{
		float darkX = leftBottom.x + bandWidth * i;
		Color4f currentColor = colors[i % colorNum];
		SetColor(currentColor.r, currentColor.g, currentColor.b, 0.5f);
		FillRect(darkX, leftBottom.y, bandWidth, halfBandHeight);
		SetColor(currentColor);
		FillRect(darkX, lightY, bandWidth, halfBandHeight);
	}

	SetColor(Colors::YELLOW);
	DrawRect(leftBottom.x, leftBottom.y, width, height, 3);
}


void CreateStarPoints()
{
	// CONSTANTS
	const float fullCircle = 360.0f;
	const float pi = 3.14f;

	int numberOfPoints = 5;
	Point2f leftBottomCenter{700.0f, 300.0f};
	float radius = 150.0f;

	// DEGREE
	float angleDeg = fullCircle / numberOfPoints;

	// RADIAN
	float angleRad = angleDeg * pi / (fullCircle / 2);

	starPoints.reserve(numberOfPoints);

	for (int i = 0; i < numberOfPoints; i++)
	{
		float x = std::cosf(angleRad * i) * radius + leftBottomCenter.x;
		float y = std::sinf(angleRad * i) * radius + leftBottomCenter.y;
		starPoints.push_back(Point2f{x, y});
	}
}

void DrawPentagram()
{
	SetColor(Colors::RED);
	for (int i = 0; i < starPoints.size(); ++i)
	{
		DrawLine(starPoints[i], starPoints[(i + 2) % starPoints.size()], 3);
	}
}


void DrawColumnChar()
{
	float width = 200.0f;
	float height = 100.0f;
	int numOfCol = 4;
	Point2f leftBottom{700.0f, 20.0f};
	for (int i = 0; i < numOfCol; ++i)
	{
		SetColor(Colors::BLUE.r, Colors::BLUE.g, Colors::BLUE.b, 1.0f * percentage[i]);
		FillRect(leftBottom.x + width / numOfCol * i, leftBottom.y, width / numOfCol, height * percentage[i]);
	}
}

void RotatePoint(Point2f& point, float deltaTime)
{
	float speed = 1.0f;
	Point2f leftBottomCenter{700.0f, 300.0f};
	double s = sin(deltaTime * speed);
	double c = cos(deltaTime * speed);

	point.x -= leftBottomCenter.x;
	point.y -= leftBottomCenter.y;

	double newX = point.x * c - point.y * s;
	double newY = point.x * s + point.y * c;

	point.x = static_cast<float>(newX) + leftBottomCenter.x;
	point.y = static_cast<float>(newY) + leftBottomCenter.y;
}

void test()
{
	// CONSTANTS
	const float downAngle = 270;
	const float rightAngle = 90;

	// HOUSE
	Point2f bottomLeft{500.0f, 300.0f};
	float houseWidth{250.0f};
	float houseHeight{125.0f};

	// ROOF
	float roofWidth{houseWidth};
	float roofHalfWidth{roofWidth / 2};
	float roofHeight{125.0f};

	float totalHeight{houseHeight + roofHeight};


	// ANGLES - 225/315
	const float D2R = float(M_PI) / 180;
	float arcAngleLeftDeg = (downAngle - rightAngle / 2); // 225 degrees
	float arcAngleLefRad = arcAngleLeftDeg * D2R;
	float arcAngleRightDeg = (downAngle + rightAngle / 2); // 315 degrees
	float arcAngleRightRad = arcAngleRightDeg * D2R;

	// ROOF APEX
	float apexX{bottomLeft.x + roofHalfWidth};
	float apexY{bottomLeft.y + houseHeight + roofHeight};

	// ROOF TOP RIGHT CORNER
	float roofRightCornerX = (apexX - (bottomLeft.x + roofWidth));
	float roofRightCornerY = (apexY - (bottomLeft.y + houseHeight));

	// CALCULATING SAGITTA
	// https://www.liutaiomottola.com/formulae/sag.htm
	float r = std::sqrt(roofRightCornerX * roofRightCornerX + roofRightCornerY * roofRightCornerY);
	float l = roofHalfWidth;
	float s = r - std::sqrt(r * r - l * l);

	// SAGITTA CORRECTION
	roofRightCornerX = (apexX - (bottomLeft.x + roofWidth + s));
	roofRightCornerY = (apexY - (bottomLeft.y + houseHeight - s));


	SetColor(1.0f, 0.0f, 0.0f, 1.0f);
	FillArc(apexX, apexY, roofRightCornerX, roofRightCornerY, arcAngleLefRad, arcAngleRightRad);
	FillRect(bottomLeft.x, bottomLeft.y, houseWidth, houseHeight);

	SetColor(0.2f, 0.0f, 0.0f, 1.0f);
	float lineWidth = 5.0f;
	DrawRect(bottomLeft.x, bottomLeft.y, houseWidth, houseHeight, lineWidth);
	DrawLine(bottomLeft.x, bottomLeft.y + houseHeight, apexX, apexY, lineWidth);
	DrawLine(bottomLeft.x + houseWidth, bottomLeft.y + houseHeight, apexX, apexY, lineWidth);
}

#pragma endregion ownDefinitions
