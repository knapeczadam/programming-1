// Knapecz, Adam - 1DAE11
#pragma once

class Texture;

class Game
{
public:
	explicit Game(const Window& window);

	Game(const Game& other) = delete;

	Game& operator=(const Game& other) = delete;

	Game(Game&& other) = delete;

	Game& operator=(Game&& other) = delete;

	~Game();

	void Update(float elapsedSec);

	void Draw() const;

	// Event handling
	void ProcessKeyDownEvent(const SDL_KeyboardEvent& key);

	void ProcessKeyUpEvent(const SDL_KeyboardEvent& key);

	void ProcessMouseMotionEvent(const SDL_MouseMotionEvent& e);

	void ProcessMouseDownEvent(const SDL_MouseButtonEvent& e);

	void ProcessMouseUpEvent(const SDL_MouseButtonEvent& e);

private:
	// DATA MEMBERS
	const Window m_Window;


	// FUNCTIONS
	void Initialize();

	void Cleanup();

	void ClearBackground() const;
};
