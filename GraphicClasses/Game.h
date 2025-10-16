// Knapecz, Adam - 1DAE11
#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{"GraphicClasses- Knapecz, Adam - 1DAE11"};

// Change the window dimensions here
float g_WindowWidth{500};
float g_WindowHeight{300};
#pragma endregion gameInformation


#pragma region ownDeclarations
// Declare your own global variables here
class Fraction;
Fraction* g_pFraction1{nullptr};
Fraction* g_pFraction2{nullptr};
Fraction* g_pFraction3{nullptr};
Fraction* g_pFraction4{nullptr};
Fraction* g_pFraction5{nullptr};
Fraction* g_pFraction6{nullptr};

class Light;
Light* g_pLight1{nullptr};
Light* g_pLight2{nullptr};
Light* g_pLight3{nullptr};
Light* g_pLight4{nullptr};
Light* g_pLight5{nullptr};
Light* g_pLight6{nullptr};
Light* g_pLight7{nullptr};
Light* g_pLight8{nullptr};

class DaeEllipse;
DaeEllipse* g_pEllipse1{nullptr};
DaeEllipse* g_pEllipse2{nullptr};
DaeEllipse* g_pEllipse3{nullptr};
// Declare your own functions here
void CreateFractions();
void DeleteFractions();
void PrintFractionsSum();
void DrawFractions();

void CreateLights();
void DeleteLights();
void DrawLights();
void HitLights(const Point2f& pos);

void CreateEllipses();
void DeleteEllipses();
void DrawEllipses();
void ActivateEllipses(const Point2f& pos);

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
