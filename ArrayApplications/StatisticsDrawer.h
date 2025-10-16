// Knapecz, Adam - 1DAE11
#pragma once

class StatisticsDrawer
{
public:
	explicit StatisticsDrawer();
	void DrawRandStats() const;
	void UpdateRandStats(float deltaTime);
	~StatisticsDrawer();
private:
	void InitTexts();
	int* m_Rows;
	utils::Texture* m_Textures;
	const int m_NrRows;
	const Color4f m_RectColor;
	const Color4f m_TexColor;
	const int m_TexSize;
	const float m_Spacing;
	const float m_PaddingLeft;
	const Point2f m_BottomLeft;
	const float m_Height;
	bool m_OutOfWindow;
};
