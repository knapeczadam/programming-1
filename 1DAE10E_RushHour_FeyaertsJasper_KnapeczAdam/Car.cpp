#include "pch.h"
#include "Car.h"

Car::Car()
	: id{-1}
	  , colorCode{ColorCode::X}
	  , color{utils::Color::white}
	  , dir{Direction::horizontal}
	  , length{2}
	  , back{Point2{0, 0}}
	  , isActive{false}
	  , isSelected{false}
	  , texture{}
{
}
