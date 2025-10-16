// Knapecz, Adam - 1DAE11
#pragma once

#include "RandomPoint.h"
#include "RandomRect.h"

class RandomLine
{
public:
	explicit RandomLine();
	void Draw() const;
	void Update(float deltaTime);
	void ToggleMotion();

private:
	void Init();
	void SetColor();
	
	RandomPoint m_P1;
	RandomPoint m_P2;

	Color4f m_Color;
	const Color4f m_ColorYellow;
	const Color4f m_Transparent;

	MotionState m_State;
};

