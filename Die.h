#pragma once
#include <string>

enum class State
{
	idle,
	rolling,
	rolled
};

class Die
{
public:
	Die(const Point2f& pos, float scale);
	Die(const Point2f& pos, float scale, const std::string& path);
	~Die();
	int GetDots();
	void SetScale(float scale);
	void Draw();
	void Update(float deltaTime);
	void CheckHit(const Point2f& pos);
	void CheckHit(float mouseX, float mouseY);
	int Randomize(bool isRolling);
	State GetState();
	void ResetState();
	float GetDieWidth();
	void SetPosition(const Point2f& pos);
private:
	float GetDieHeight();

private:
	Point2f m_Pos;
	float m_Scale;
	std::string m_SpritePath;
	utils::Texture m_SpriteSheet;
	int m_ColorIdx;
	int m_DieIdx;
	const int m_NrRows;
	const int m_NrCols;
	float m_AccuSec;
	const float m_FrameSec;
	State m_State;
};
