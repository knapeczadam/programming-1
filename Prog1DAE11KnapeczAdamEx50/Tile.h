// Knapecz, Adam - 1DAE11
#pragma once

#include <string>

class Tile
{
public:
	Tile(const Rectf& dstRect, const std::string& texPath, int nrAnimals);

	void Draw() const;
	void CheckActivation(const Point2f& pos);
	bool CheckHit(const Point2f& pos);
	int GetCurrentAnimal() const;
	void Deactivate();
	void Randomize();
private:
	utils::Texture m_Texture;
	const std::string m_TexPath;
	const int m_NrAnimals;
	int m_CurrAnimal;
	Rectf m_DstRect;
	bool m_Active;
	const Color4f m_ColorGrey;
	const Color4f m_ColorRed;
	const int m_SmallRectRatio;
};
