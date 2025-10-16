// Knapecz, Adam - 1DAE11
#pragma once
namespace myutils
{
	const Color4f red{ 1.0f, 0, 0, 1.0f };
	const Color4f green(0, 1.0f, 0, 1.0f);
	const Color4f blue{ 0, 0, 1.0f, 1.0f };
	const Color4f cyan{ 0, 1.0f, 1.0f, 1.0f };
	const Color4f magenta{ 1.0f, 0, 1.0f, 1.0f };
	const Color4f yellow{ 1.0f, 1.0f, 0, 1.0f };
	const Color4f black{ 0, 0, 0, 1.0f };
	const Color4f white{ 1.0f, 1.0f, 1.0f, 1.0f };
	void DrawSquares(float left, float bottom, float width, int division, Color4f color=black);
	void DrawEquilateralTriangle(float left, float bottom, float width, bool outline=true, bool fill=false, Color4f outlineColor=black, Color4f fillColor=white);
	void DrawPentagram(float centerX, float centerY, float radius, Color4f color=black);
	void DrawLinearGradient(float left, float bottom, float width, float height, Color4f colorFrom=black, Color4f colorTo=white);
	void DrawDotGrid(float left, float bottom, int row, int col, float radius, float spacing, Color4f color=black);
}

