// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Game.h"
#include "Tile.h"

#include <string>
#include <set>
#include <iostream>

//Basic game functions
#pragma region gameFunctions
void Start()
{
	// initialize game resources here
	CreateTiles();
	RandomizeTiles();
	LoadNames();
}

void Draw()
{
	ClearBackground();
	// Put your own draw statements here
	DrawTiles();
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
	DeleteTiles();
	DeleteNames();
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling
void OnKeyDownEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_r:
		if (!g_Puzzle.m_Solved)
		{
			RandomizeTiles();
		}
		break;
	}
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
	if (!g_Puzzle.m_Solved)
	{
		for (Tile* tile : g_Puzzle.m_tiles)
		{
			tile->CheckActivation(Point2f{float(e.x), float(g_WindowHeight - e.y)});
		}
	}
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		if (!g_Puzzle.m_Solved)
		{
			for (Tile* tile : g_Puzzle.m_tiles)
			{
				if (tile->CheckHit(Point2f{float(e.x), float(g_WindowHeight - e.y)}))
				{
					if (IsPuzzleSolved())
					{
						g_Puzzle.m_Solved = true;
						DeactivateTiles();
					}
				}
			}
		}
	}
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
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
void CreateTiles()
{
	Rectf dstRect{g_Puzzle.m_center.x, g_Puzzle.m_center.y, g_Puzzle.m_tileWidth, g_Puzzle.m_tileHeight};

	const Point2f positions[g_Puzzle.m_nrTiles]
	{
		Point2f{g_Puzzle.m_center.x - g_Puzzle.m_tileWidth, g_Puzzle.m_center.y},
		Point2f{g_Puzzle.m_center.x, g_Puzzle.m_center.y},
		Point2f{g_Puzzle.m_center.x - g_Puzzle.m_tileWidth, g_Puzzle.m_center.y - g_Puzzle.m_tileHeight},
		Point2f{g_Puzzle.m_center.x, g_Puzzle.m_center.y - g_Puzzle.m_tileHeight}
	};

	for (int i{}; i < g_Puzzle.m_nrRow; i++)
	{
		for (int j{}; j < g_Puzzle.m_nrCol; ++j)
		{
			const std::string path{"Resources/Tiles" + std::to_string(i) + std::to_string(j) + ".png"};

			dstRect.left = positions[g_Puzzle.m_nrCol * i + j].x;
			dstRect.bottom = positions[g_Puzzle.m_nrCol * i + j].y;
			g_Puzzle.m_tiles[g_Puzzle.m_nrCol * i + j] = new Tile{dstRect, path, g_Puzzle.m_nrAnimals};
		}
	}
}

void DeleteTiles()
{
	for (int i{}; i < g_Puzzle.m_nrTiles; ++i)
	{
		delete g_Puzzle.m_tiles[i];
	}
}

void DrawTiles()
{
	for (int i{}; i < g_Puzzle.m_nrTiles; ++i)
	{
		g_Puzzle.m_tiles[i]->Draw();
	}
	if (g_Puzzle.m_Solved)
	{
		SetColor(0, 1.0f, 0, 1.0f);
		DrawName();
	}
	else
	{
		SetColor(1.0f, 0, 0, 1.0f);
	}
	DrawRect(g_Puzzle.m_center.x - g_Puzzle.m_tileWidth, g_Puzzle.m_center.y - g_Puzzle.m_tileHeight,
	         g_Puzzle.m_tileWidth * 2, g_Puzzle.m_tileHeight * 2, 2.0f);
}

void DeactivateTiles()
{
	for (Tile* tile : g_Puzzle.m_tiles)
	{
		tile->Deactivate();
	}
}


void RandomizeTiles()
{
	std::set<int> s{};
	while (s.size() != g_Puzzle.m_nrTiles)
	{
		s.clear();
		for (Tile* tile : g_Puzzle.m_tiles)
		{
			tile->Randomize();
			s.insert(tile->GetCurrentAnimal());
		}
	}
}

bool IsPuzzleSolved()
{
	g_Puzzle.m_winningAnimal = g_Puzzle.m_tiles[0]->GetCurrentAnimal();
	for (int i{1}; i < g_Puzzle.m_nrTiles; ++i)
	{
		if (g_Puzzle.m_tiles[i]->GetCurrentAnimal() != g_Puzzle.m_winningAnimal)
		{
			return false;
		}
	}
	return true;
}

void LoadNames()
{
	TextureFromFile("Resources/Names.png", g_Puzzle.m_names);
}

void DeleteNames()
{
	DeleteTexture(g_Puzzle.m_names);
}

void DrawName()
{
	Rectf src;
	src.width = g_Puzzle.m_names.width;
	src.height = g_Puzzle.m_names.height / g_Puzzle.m_nrAnimals;
	src.left = 0;
	src.bottom = g_Puzzle.m_names.height / g_Puzzle.m_nrAnimals * (g_Puzzle.m_winningAnimal + 1);

	Rectf dst;
	dst.width = src.width;
	dst.height = src.height;
	dst.left = g_Puzzle.m_center.x - dst.width / 2;
	dst.bottom = g_Puzzle.m_center.y - g_Puzzle.m_tileHeight - dst.height;
	DrawTexture(g_Puzzle.m_names, dst, src);
}


#pragma endregion ownDefinitions
