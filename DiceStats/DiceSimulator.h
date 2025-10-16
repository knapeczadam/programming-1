// Knapecz, Adam - 1DAE11
#pragma once

class DiceSimulator
{
public:
	explicit DiceSimulator(const Point2f& bottomLeft, const Color4f& color, int numOfRow, int numOfDice);
	~DiceSimulator();
	void Simulate();
	void Draw() const;
	float GetHeight() const;
private:
	Point2f m_BottomLeft;
	const Color4f m_Color;
	const int m_NumOfRow;
	int m_NumOfDice;

	const float m_Spacing;
	const int m_MaxSimulation;
	int m_SimulationCounter;
	float m_Height;
	const int m_MaxValueOfDice;
	int* m_Stats;
};

