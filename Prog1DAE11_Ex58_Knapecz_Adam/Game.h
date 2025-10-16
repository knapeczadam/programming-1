// Knapecz, Adam - 1DAE11
#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{"Ex58 - Knapecz, Adam - 1DAE11"};

// Change the window dimensions here
float g_WindowWidth{500};
float g_WindowHeight{300};
#pragma endregion gameInformation


#pragma region ownDeclarations
// Declare your own global variables here
enum class GameState
{
	play,
	pause,
	win,
	lose,
	reset
};

class Vehicle;

struct ChickenGame
{
	GameState m_Sate{GameState::reset};
	static const int s_NrCars{5};
	Vehicle* m_Cars[s_NrCars]{};
	const char* m_MessageWin{"The chicken survived!"};
	const char* m_MessageLose{"The chicken died!"};
	const char* m_MessagePause{"Pause"};
	Texture m_TexWin{};
	Texture m_TexLose{};
	Texture m_TexPause{};
	const int m_FontSize{40};
	const char* m_FontPath{"Resources/consola.ttf"};
	const Color4f m_ColorFont{1.0f, 1.0f, 1.0f, 1.0f};
	const Color4f m_ColorBackground{0, 0, 0, 0.5f};
	const Point2f m_Center{g_WindowWidth / 2, g_WindowHeight / 2};
	Point2f m_PosLose{};
	Point2f m_PosWin{};
	Point2f m_PosPause{};
} g_Game;

enum class ChickenDir
{
	idle,
	left,
	right,
	down
};

struct Dir
{
	static constexpr Vector2f LEFT{-1, 0};
	static constexpr Vector2f RIGHT{1, 0};
	static constexpr Vector2f UP{0, 1};
	static constexpr Vector2f DOWN{0, -1};
};

struct Chicken
{
	float m_Speed{100.0f};
	const Point2f m_StarPos{g_WindowWidth / 2, g_WindowHeight - 20};
	Point2f m_Pos{};
	Vector2f m_Dir{};
	const char* path{"Resources/Chicken.bmp"};
	Texture m_Tex{};
	const float m_Scale{0.5f};
	ChickenDir m_HorizonatlDir{ChickenDir::down};
	ChickenDir m_VerticalDir{ChickenDir::idle};
} g_Chicken;

struct Street
{
	Point2f m_Pos{};
	const char* path{"Resources/street.png"};
	Texture m_Tex{};
	const float m_PavementHeight{43.0f};
	const float m_LaneHeight{45.0f};
} g_Street;

// Declare your own functions here

#pragma endregion ownDeclarations
void ResetGame();
void PauseGame();

void CreateChicken();
void CreateStreet();
void CreateCars();
void LoadTexts();
void ShuffleCars();

void DrawChicken();
void DrawStreet();
void DrawCars();
void PrintText();
void PrintStartMessage();

void UpdateChicken(float deltaTime);
void UpdateCars(float deltaTime);

void DestroyChicken();
void DestroyStreet();
void DestroyCars();
void DestroyTexts();
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
