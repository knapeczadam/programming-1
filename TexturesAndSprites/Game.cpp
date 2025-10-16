// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Game.h"
#include "Sprite.h"

//Basic game functions
#pragma region gameFunctions
void Start()
{
	// initialize game resources here
	CreateTextures();
	CreateSprites();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawTextures();
	DrawSprites();
}

void Update(float elapsedSec)
{
	// process input, do physics 
	UpdateSprites(elapsedSec);
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
	DeleteTextures();
	DeleteSprites();
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
void CreateTextures()
{
	for (int i{}; i < 6; ++i)
	{
		textures[i] = new Texture;
	}
	for (int i{}; i < 3; ++i)
	{
		TextureFromFile("Resources/DAE.png", *textures[i]);
	}
	for (int i{3}; i < 6; ++i)
	{
		TextureFromString("HELLO", "Resources/DIN-Light.otf", 20 - 2 * i, {}, *textures[i]);
	}
}

void DrawTextures()
{
	for (int i{}; i < 3; ++i)
	{
		Rectf src;
		src.width = textures[i]->width;
		src.height = textures[i]->height;
		src.left = 0;
		src.bottom = src.height;

		Rectf dst;
		dst.width = src.width * (1.0f - 0.4f * i);
		dst.height = src.height * (1.0f - 0.4f * i);
		dst.left = 20.0f + 220.0f * i;
		dst.bottom = 50.0f;
		DrawTexture(*textures[i], dst, src);
	}
	float left{20.0f};
	const float bottom{20.0f};
	const float offset{50.0f};
	for (int i{3}; i < 6; ++i)
	{
		DrawTexture(*textures[i], Point2f{left, bottom});
		left += offset;
	}
}

void DeleteTextures()
{
	for (int i{}; i < 6; ++i)
	{
		DeleteTexture(*textures[i]);
		delete textures[i];
	}
}

void CreateSprites()
{
	for (int i{}; i < 3; ++i)
	{
		sprites[i] = new Sprite{"Resources/Sprites/RunningKnight.png", 8, 1, 1.0f / 10, 4.0f - 0.3f * i};
	}
	for (int i{3}; i < 5; ++i)
	{
		sprites[i] = new Sprite{"Resources/Sprites/Tibo.png", 5, 5, 1.0f / 15, 1.0f - 0.2f * i};
	}
}

void DrawSprites()
{
	Point2f pos{20.0f, g_WindowHeight / 2};
	const float offset{90.0f};
	for (int i{}; i < 5; ++i)
	{
		sprites[i]->Draw(pos);
		pos.x += offset;
	}
}

void UpdateSprites(float deltaTime)
{
	for (int i{}; i < 5; ++i)
	{
		sprites[i]->Update(deltaTime);
	}
}

void DeleteSprites()
{
	for (int i{}; i < 5; ++i)
	{
		delete sprites[i];
	}
}
#pragma endregion ownDefinitions
