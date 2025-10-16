#pragma once

enum class Direction
{
	horizontal,
	vertical,
};

// Color codes according to the official instruction manual
enum class ColorCode : char
{
	// cars
	X = 'X', // red
	A = 'A', // green
	B = 'B', // orange
	C = 'C', // turquoise
	D = 'D', // rose
	E = 'E', // purple
	F = 'F', // dark green
	G = 'G', // light gray
	H = 'H', // light yellow
	I = 'I', // yellow
	J = 'J', // brown
	K = 'K', // dark yellow
	// trucks
	O = 'O', // gold
	P = 'P', // lavender
	Q = 'Q', // blue
	R = 'R'  // dark teal	
};

struct CarTexture
{
	utils::Texture horizontal;
	utils::Texture vertical;
};

struct Car
{
	Car();

	int id;
	ColorCode colorCode;
	Color4f color;
	Direction dir;
	int length;
	Point2 back;
	bool isActive;
	bool isSelected;
	CarTexture texture;
};
