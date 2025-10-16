// Knapecz, Adam - 1DAE11
#pragma once
#include <string>

class Sprite
{
public:
	Sprite(const std::string& fileName, int nrCols, int nrRows, float frameSec, float scale);
	~Sprite();
	void Update(float elapsedSec);
	void Draw(const Point2f& pos) const;
	float GetFrameWidth() const;
	float GetFrameHeight() const;
private:
	utils::Texture m_Texture;
	int m_Cols;
	int m_Rows;
	float m_FrameSec;
	float m_AccuSec;
	int m_ActFrame;
	float m_Scale;
};

