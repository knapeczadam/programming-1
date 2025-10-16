// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Game.h"
#include "Fraction.h"
#include "Light.h"
#include "DaeEllipse.h"

#include <iostream>

//Basic game functions
#pragma region gameFunctions
void Start()
{
	// initialize game resources here
	CreateFractions();
	PrintFractionsSum();
	CreateLights();
	CreateEllipses();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawFractions();
	DrawLights();
	DrawEllipses();
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
	DeleteFractions();
	DeleteLights();
	DeleteEllipses();
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
	ActivateEllipses(Point2f{float(e.x), float(g_WindowHeight - e.y)});
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		const Point2f pos{float(e.x), float(g_WindowHeight - e.y)};
		HitLights(pos);
		break;
	}
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
void CreateFractions()
{
	g_pFraction1 = new Fraction{9, 10};
	g_pFraction2 = new Fraction{9, 3};
	g_pFraction3 = new Fraction{4, 6};
	g_pFraction4 = new Fraction{6, 4};
	g_pFraction5 = new Fraction{1, 10};
	g_pFraction6 = new Fraction{0, 2};
}

void DeleteFractions()
{
	delete g_pFraction1;
	delete g_pFraction2;
	delete g_pFraction3;
	delete g_pFraction4;
	delete g_pFraction5;
	delete g_pFraction6;
}

void PrintFractionsSum()
{
	float total{};
	total += g_pFraction1->GetValue();
	total += g_pFraction2->GetValue();
	total += g_pFraction3->GetValue();
	total += g_pFraction4->GetValue();
	total += g_pFraction5->GetValue();
	total += g_pFraction6->GetValue();
	std::cout << "Total value of created Fraction objects: " << total << std::endl;
}

void DrawFractions()
{
	const float size{20.0f};
	const float spacing{10.0f};
	const float border{20.0f};
	Point2f pos{border, border};
	g_pFraction1->Draw(pos, size);
	pos.y += size + spacing;
	g_pFraction2->Draw(pos, size);
	pos.y += size + spacing;
	g_pFraction3->Draw(pos, size);
	pos.y += size + spacing;
	g_pFraction4->Draw(pos, size);
	pos.y += size + spacing;
	g_pFraction5->Draw(pos, size);
	pos.y += size + spacing;
	g_pFraction6->Draw(pos, size);
}

void CreateLights()
{
	const int row{4};
	const int col{2};
	Light** lights[]
	{
		&g_pLight1, &g_pLight2, &g_pLight3, &g_pLight4, &g_pLight5, &g_pLight6, &g_pLight7, &g_pLight8
	};

	const float left{g_WindowWidth / 2};
	float bottom{20.0f};
	const float height{20.0f};
	const float minWidth{10.0f};
	const float maxWidht{30.0f};
	const float spacing{5.0f};
	for (int iRow{}; iRow < row; ++iRow)
	{
		for (int iCol{}; iCol < col - 1; ++iCol)
		{
			Rectf r1;
			r1.left = left;
			r1.bottom = bottom;
			r1.height = height;
			r1.width = GetRand(minWidth, maxWidht);
			Color4f c1;
			c1.r = GetRand(0.0, 1.0f);
			c1.g = GetRand(0.0, 1.0f);
			c1.b = GetRand(0.0, 1.0f);
			c1.a = 1.0f;
			*lights[utils::GetIndex(iRow, iCol, col)] = new Light{r1, c1};

			Rectf r2;
			r2.left = r1.left + r1.width + spacing;
			r2.bottom = bottom;
			r2.height = height;
			r2.width = GetRand(minWidth, maxWidht);
			Color4f c2;
			c2.r = GetRand(0.0, 1.0f);
			c2.g = GetRand(0.0, 1.0f);
			c2.b = GetRand(0.0, 1.0f);
			c2.a = 1.0f;
			*lights[utils::GetIndex(iRow, iCol + 1, col)] = new Light{r2, c2};
			bottom += height + spacing;
		}
	}
}

void DeleteLights()
{
	delete g_pLight1;
	delete g_pLight2;
	delete g_pLight3;
	delete g_pLight4;
	delete g_pLight5;
	delete g_pLight6;
	delete g_pLight7;
	delete g_pLight8;
}

void DrawLights()
{
	g_pLight1->Draw();
	g_pLight2->Draw();
	g_pLight3->Draw();
	g_pLight4->Draw();
	g_pLight5->Draw();
	g_pLight6->Draw();
	g_pLight7->Draw();
	g_pLight8->Draw();
}

void HitLights(const Point2f& pos)
{
	bool isHit{};
	isHit |= g_pLight1->IsHit(pos);
	isHit |= g_pLight2->IsHit(pos);
	isHit |= g_pLight3->IsHit(pos);
	isHit |= g_pLight4->IsHit(pos);
	isHit |= g_pLight5->IsHit(pos);
	isHit |= g_pLight6->IsHit(pos);
	isHit |= g_pLight7->IsHit(pos);
	isHit |= g_pLight8->IsHit(pos);
	if (isHit)
	{
		int count{};
		count += g_pLight1->IsOn();
		count += g_pLight2->IsOn();
		count += g_pLight3->IsOn();
		count += g_pLight4->IsOn();
		count += g_pLight5->IsOn();
		count += g_pLight6->IsOn();
		count += g_pLight7->IsOn();
		count += g_pLight8->IsOn();
		std::cout << count << " lights are on" << std::endl;
	}
}

void CreateEllipses()
{
	Point2f center1{50.0f, g_WindowHeight - 50.0f};
	Point2f center2{200, g_WindowHeight - 50.0f};
	Point2f center3{g_WindowWidth / 2 + 150.0f, g_WindowHeight / 2};
	Color4f color1{0, 1.0f, 0, 1.0f};
	Color4f color2{1.0f, 0, 0, 1.0f};
	Color4f color3{0, 0, 1.0f, 1.0f};
	g_pEllipse1 = new DaeEllipse{center1, 20.0f, 20.0f, color1};
	g_pEllipse2 = new DaeEllipse{center2, 50.0f, 20.0f, color2};
	g_pEllipse3 = new DaeEllipse{center3, 100.0f, 100.0f, color3};
}

void DeleteEllipses()
{
	delete g_pEllipse1;
	delete g_pEllipse2;
	delete g_pEllipse3;
}

void DrawEllipses()
{
	g_pEllipse1->Draw();
	g_pEllipse2->Draw();
	g_pEllipse3->Draw();
}

void ActivateEllipses(const Point2f& pos)
{
	g_pEllipse1->ActivateTest(pos);
	g_pEllipse2->ActivateTest(pos);
	g_pEllipse3->ActivateTest(pos);
}
#pragma endregion ownDefinitions

