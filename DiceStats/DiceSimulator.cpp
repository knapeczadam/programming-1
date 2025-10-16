// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "DiceSimulator.h"

DiceSimulator::DiceSimulator(const Point2f& bottomLeft, const Color4f& color, int numOfRow, int numOfDice)
	: m_BottomLeft{bottomLeft}
	  , m_Color{color}
	  , m_NumOfRow{numOfRow} 
	  , m_NumOfDice{numOfDice}
	  , m_Spacing{5.0f}
	  , m_MaxSimulation{2000}
	  , m_SimulationCounter{}
	  , m_Height{20.0f}
	  , m_MaxValueOfDice{6}
	  , m_Stats{}
{
	m_Stats = new int[numOfRow]{};
}

DiceSimulator::~DiceSimulator()
{
	delete[] m_Stats;
}

void DiceSimulator::Draw() const
{
	utils::SetColor(m_Color);
	for (int i{}; i < m_NumOfRow; ++i)
	{
		utils::FillRect(m_BottomLeft.x, m_BottomLeft.y + m_Height * i + m_Spacing * i, float(m_Stats[i]), m_Height);
	}
}

void DiceSimulator::Simulate()
{
	if (m_SimulationCounter < m_MaxSimulation)
	{
		int result{};
		for (int i{}; i < m_NumOfDice; ++i)
		{
			result += rand() % m_MaxValueOfDice + 1;
		}
		++m_Stats[result - 1 * m_NumOfDice];
		++m_SimulationCounter;
	}
}

float DiceSimulator::GetHeight() const
{
	return m_BottomLeft.y + m_NumOfRow * (m_Height + m_Spacing);
}

