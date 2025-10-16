// Knapecz, Adam - 1DAE11
#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{"Ex50 - Knapecz, Adam - 1DAE11"};

// Change the window dimensions here
float g_WindowWidth{500};
float g_WindowHeight{500};
#pragma endregion gameInformation


#pragma region ownDeclarations
// Declare your own global variables here
class Tile;

struct Puzzle
{
	static const int m_nrTiles{4};
	const int m_nrRow{2};
	const int m_nrCol{2};
	const int m_nrAnimals{6};
	const float m_tileWidth{128.0f};
	const float m_tileHeight{128.0f};
	const Point2f m_center{g_WindowWidth / 2, g_WindowHeight / 2};
	Tile* m_tiles[m_nrTiles]{};
	bool m_Solved{};
	int m_winningAnimal{};
	Texture m_names;
} g_Puzzle;

// Declare your own functions here
void CreateTiles();
void DeleteTiles();
void DeactivateTiles();
void DrawTiles();
void RandomizeTiles();
bool IsPuzzleSolved();
void LoadNames();
void DeleteNames();
void DrawName();
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
