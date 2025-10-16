#pragma once
#include "Car.h"

struct CarData
{
	ColorCode colorCode;
	Point2 pos;
	Direction dir;
};

namespace levels
{
	std::vector<std::vector<CarData>> levelData
	{
		// 1
		{
			CarData{ColorCode::X, Point2{2, 1}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 0}, Direction::horizontal},
			CarData{ColorCode::O, Point2{0, 5}, Direction::vertical},
			CarData{ColorCode::P, Point2{1, 0}, Direction::vertical},
			CarData{ColorCode::Q, Point2{1, 3}, Direction::vertical},
			CarData{ColorCode::B, Point2{4, 0}, Direction::vertical},
			CarData{ColorCode::C, Point2{4, 4}, Direction::horizontal},
			CarData{ColorCode::R, Point2{5, 2}, Direction::horizontal}
		},
		// 2
		{
			CarData{ColorCode::X, Point2{2, 0}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 0}, Direction::vertical},
			CarData{ColorCode::O, Point2{0, 3}, Direction::horizontal},
			CarData{ColorCode::B, Point2{1, 3}, Direction::vertical},
			CarData{ColorCode::P, Point2{1, 5}, Direction::vertical},
			CarData{ColorCode::C, Point2{2, 4}, Direction::vertical},
			CarData{ColorCode::Q, Point2{3, 0}, Direction::horizontal},
			CarData{ColorCode::D, Point2{4, 2}, Direction::vertical},
			CarData{ColorCode::E, Point2{4, 4}, Direction::horizontal},
			CarData{ColorCode::F, Point2{5, 0}, Direction::horizontal},
			CarData{ColorCode::G, Point2{5, 3}, Direction::horizontal}
		},
		// 3
		{
			CarData{ColorCode::X, Point2{2, 1}, Direction::horizontal},
			CarData{ColorCode::O, Point2{2, 3}, Direction::vertical},
			CarData{ColorCode::A, Point2{3, 1}, Direction::horizontal},
			CarData{ColorCode::P, Point2{3, 5}, Direction::vertical},
			CarData{ColorCode::B, Point2{4, 1}, Direction::vertical},
			CarData{ColorCode::C, Point2{5, 2}, Direction::horizontal}
		},
		// 4
		{
			CarData{ColorCode::X, Point2{2, 1}, Direction::horizontal},
			CarData{ColorCode::O, Point2{0, 0}, Direction::vertical},
			CarData{ColorCode::P, Point2{0, 3}, Direction::vertical},
			CarData{ColorCode::A, Point2{3, 2}, Direction::vertical},
			CarData{ColorCode::Q, Point2{3, 3}, Direction::horizontal},
			CarData{ColorCode::B, Point2{4, 5}, Direction::vertical},
			CarData{ColorCode::R, Point2{5, 2}, Direction::horizontal}
		},
		// 5
		{
			CarData{ColorCode::X, Point2{2, 1}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 0}, Direction::horizontal},
			CarData{ColorCode::O, Point2{0, 3}, Direction::vertical},
			CarData{ColorCode::B, Point2{0, 5}, Direction::vertical},
			CarData{ColorCode::P, Point2{1, 0}, Direction::vertical},
			CarData{ColorCode::Q, Point2{1, 4}, Direction::vertical},
			CarData{ColorCode::G, Point2{2, 5}, Direction::vertical},
			CarData{ColorCode::R, Point2{3, 1}, Direction::horizontal},
			CarData{ColorCode::D, Point2{4, 0}, Direction::vertical},
			CarData{ColorCode::E, Point2{4, 4}, Direction::horizontal},
			CarData{ColorCode::F, Point2{5, 4}, Direction::horizontal}
		},
		// 6
		{
			CarData{ColorCode::X, Point2{2, 1}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 0}, Direction::horizontal},
			CarData{ColorCode::B, Point2{0, 3}, Direction::vertical},
			CarData{ColorCode::C, Point2{1, 0}, Direction::horizontal},
			CarData{ColorCode::O, Point2{1, 4}, Direction::vertical},
			CarData{ColorCode::P, Point2{1, 5}, Direction::vertical},
			CarData{ColorCode::Q, Point2{2, 3}, Direction::vertical},
			CarData{ColorCode::D, Point2{3, 0}, Direction::horizontal},
			CarData{ColorCode::E, Point2{3, 2}, Direction::vertical},
			CarData{ColorCode::F, Point2{4, 0}, Direction::vertical},
			CarData{ColorCode::R, Point2{5, 3}, Direction::horizontal}
		},
		// 7
		{
			CarData{ColorCode::X, Point2{2, 1}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 1}, Direction::vertical},
			CarData{ColorCode::B, Point2{0, 2}, Direction::horizontal},
			CarData{ColorCode::C, Point2{0, 4}, Direction::vertical},
			CarData{ColorCode::D, Point2{0, 5}, Direction::vertical},
			CarData{ColorCode::E, Point2{1, 3}, Direction::vertical},
			CarData{ColorCode::F, Point2{2, 5}, Direction::vertical},
			CarData{ColorCode::I, Point2{3, 2}, Direction::horizontal},
			CarData{ColorCode::H, Point2{4, 3}, Direction::vertical}
		},
		// 8
		{
			CarData{ColorCode::X, Point2{2, 0}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 3}, Direction::horizontal},
			CarData{ColorCode::O, Point2{0, 5}, Direction::vertical},
			CarData{ColorCode::B, Point2{1, 2}, Direction::horizontal},
			CarData{ColorCode::C, Point2{1, 4}, Direction::vertical},
			CarData{ColorCode::D, Point2{2, 2}, Direction::vertical},
			CarData{ColorCode::E, Point2{2, 3}, Direction::vertical},
			CarData{ColorCode::F, Point2{3, 0}, Direction::horizontal},
			CarData{ColorCode::G, Point2{3, 4}, Direction::horizontal},
			CarData{ColorCode::H, Point2{4, 0}, Direction::horizontal},
			CarData{ColorCode::I, Point2{4, 2}, Direction::vertical},
			CarData{ColorCode::P, Point2{4, 3}, Direction::horizontal},
			CarData{ColorCode::K, Point2{5, 0}, Direction::horizontal},
			CarData{ColorCode::Q, Point2{5, 3}, Direction::horizontal}
		},
		// 9
		{
			CarData{ColorCode::X, Point2{2, 0}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 1}, Direction::vertical},
			CarData{ColorCode::B, Point2{0, 2}, Direction::horizontal},
			CarData{ColorCode::C, Point2{0, 4}, Direction::horizontal},
			CarData{ColorCode::D, Point2{1, 3}, Direction::vertical},
			CarData{ColorCode::E, Point2{1, 4}, Direction::horizontal},
			CarData{ColorCode::O, Point2{2, 4}, Direction::vertical},
			CarData{ColorCode::F, Point2{2, 5}, Direction::vertical},
			CarData{ColorCode::P, Point2{3, 0}, Direction::vertical},
			CarData{ColorCode::Q, Point2{3, 1}, Direction::horizontal},
			CarData{ColorCode::G, Point2{4, 2}, Direction::vertical},
			CarData{ColorCode::H, Point2{4, 5}, Direction::vertical}
		},
		// 10
		{
			CarData{ColorCode::X, Point2{2, 1}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 0}, Direction::horizontal},
			CarData{ColorCode::B, Point2{0, 2}, Direction::vertical},
			CarData{ColorCode::C, Point2{0, 4}, Direction::horizontal},
			CarData{ColorCode::D, Point2{1, 0}, Direction::horizontal},
			CarData{ColorCode::O, Point2{1, 5}, Direction::vertical},
			CarData{ColorCode::P, Point2{2, 0}, Direction::vertical},
			CarData{ColorCode::Q, Point2{3, 1}, Direction::horizontal},
			CarData{ColorCode::E, Point2{4, 3}, Direction::vertical},
			CarData{ColorCode::F, Point2{4, 4}, Direction::horizontal},
			CarData{ColorCode::G, Point2{5, 0}, Direction::horizontal},
			CarData{ColorCode::H, Point2{5, 4}, Direction::horizontal}
		},
		// 11
		{
			CarData{ColorCode::X, Point2{2, 1}, Direction::horizontal},
			CarData{ColorCode::O, Point2{0, 0}, Direction::vertical},
			CarData{ColorCode::A, Point2{0, 1}, Direction::horizontal},
			CarData{ColorCode::P, Point2{0, 3}, Direction::vertical},
			CarData{ColorCode::B, Point2{3, 2}, Direction::vertical},
			CarData{ColorCode::Q, Point2{3, 3}, Direction::horizontal},
			CarData{ColorCode::E, Point2{4, 5}, Direction::vertical},
			CarData{ColorCode::R, Point2{5, 2}, Direction::horizontal}
		},
		// 12
		{
			CarData{ColorCode::X, Point2{2, 0}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 0}, Direction::vertical},
			CarData{ColorCode::B, Point2{0, 1}, Direction::horizontal},
			CarData{ColorCode::O, Point2{0, 5}, Direction::vertical},
			CarData{ColorCode::P, Point2{1, 2}, Direction::vertical},
			CarData{ColorCode::Q, Point2{3, 3}, Direction::horizontal},
			CarData{ColorCode::C, Point2{4, 4}, Direction::horizontal},
			CarData{ColorCode::R, Point2{5, 0}, Direction::horizontal}
		},
		// 13
		{
			CarData{ColorCode::X, Point2{2, 3}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 0}, Direction::horizontal},
			CarData{ColorCode::B, Point2{0, 2}, Direction::horizontal},
			CarData{ColorCode::C, Point2{0, 4}, Direction::vertical},
			CarData{ColorCode::D, Point2{1, 2}, Direction::vertical},
			CarData{ColorCode::O, Point2{1, 5}, Direction::vertical},
			CarData{ColorCode::E, Point2{2, 1}, Direction::vertical},
			CarData{ColorCode::P, Point2{3, 0}, Direction::vertical},
			CarData{ColorCode::F, Point2{3, 3}, Direction::horizontal},
			CarData{ColorCode::G, Point2{4, 3}, Direction::horizontal},
			CarData{ColorCode::H, Point2{4, 4}, Direction::horizontal},
			CarData{ColorCode::I, Point2{5, 1}, Direction::horizontal},
			CarData{ColorCode::K, Point2{5, 4}, Direction::horizontal}
		},
		// 14
		{
			CarData{ColorCode::X, Point2{2, 2}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 0}, Direction::horizontal},
			CarData{ColorCode::B, Point2{0, 2}, Direction::vertical},
			CarData{ColorCode::C, Point2{1, 4}, Direction::horizontal},
			CarData{ColorCode::D, Point2{2, 0}, Direction::vertical},
			CarData{ColorCode::E, Point2{2, 1}, Direction::vertical},
			CarData{ColorCode::F, Point2{2, 4}, Direction::vertical},
			CarData{ColorCode::G, Point2{2, 5}, Direction::vertical},
			CarData{ColorCode::H, Point2{3, 2}, Direction::horizontal},
			CarData{ColorCode::I, Point2{4, 2}, Direction::vertical},
			CarData{ColorCode::J, Point2{4, 4}, Direction::horizontal},
			CarData{ColorCode::K, Point2{5, 0}, Direction::horizontal}
		},
		// 15
		{
			CarData{ColorCode::X, Point2{2, 2}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 1}, Direction::horizontal},
			CarData{ColorCode::B, Point2{0, 3}, Direction::horizontal},
			CarData{ColorCode::C, Point2{1, 0}, Direction::horizontal},
			CarData{ColorCode::D, Point2{1, 2}, Direction::horizontal},
			CarData{ColorCode::O, Point2{1, 4}, Direction::vertical},
			CarData{ColorCode::P, Point2{1, 5}, Direction::vertical},
			CarData{ColorCode::Q, Point2{2, 0}, Direction::vertical},
			CarData{ColorCode::R, Point2{2, 1}, Direction::vertical},
			CarData{ColorCode::E, Point2{3, 2}, Direction::vertical},
			CarData{ColorCode::F, Point2{3, 3}, Direction::vertical},
			CarData{ColorCode::G, Point2{4, 4}, Direction::horizontal},
			CarData{ColorCode::H, Point2{5, 1}, Direction::horizontal},
			CarData{ColorCode::I, Point2{5, 3}, Direction::horizontal}
		},
		// 16
		{
			CarData{ColorCode::X, Point2{2, 3}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 0}, Direction::horizontal},
			CarData{ColorCode::B, Point2{0, 2}, Direction::horizontal},
			CarData{ColorCode::C, Point2{0, 4}, Direction::vertical},
			CarData{ColorCode::O, Point2{0, 5}, Direction::vertical},
			CarData{ColorCode::D, Point2{1, 0}, Direction::vertical},
			CarData{ColorCode::E, Point2{1, 2}, Direction::horizontal},
			CarData{ColorCode::F, Point2{2, 1}, Direction::vertical},
			CarData{ColorCode::P, Point2{2, 2}, Direction::vertical},
			CarData{ColorCode::Q, Point2{3, 3}, Direction::horizontal},
			CarData{ColorCode::G, Point2{5, 0}, Direction::horizontal}
		},
		// 17
		{
			CarData{ColorCode::X, Point2{2, 0}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 0}, Direction::vertical},
			CarData{ColorCode::O, Point2{0, 1}, Direction::horizontal},
			CarData{ColorCode::B, Point2{1, 2}, Direction::horizontal},
			CarData{ColorCode::C, Point2{1, 4}, Direction::horizontal},
			CarData{ColorCode::D, Point2{2, 2}, Direction::vertical},
			CarData{ColorCode::E, Point2{3, 0}, Direction::horizontal},
			CarData{ColorCode::P, Point2{3, 3}, Direction::vertical},
			CarData{ColorCode::Q, Point2{4, 0}, Direction::horizontal},
			CarData{ColorCode::F, Point2{4, 4}, Direction::vertical},
			CarData{ColorCode::G, Point2{4, 5}, Direction::vertical},
			CarData{ColorCode::R, Point2{5, 0}, Direction::horizontal}
		},
		// 18
		{
			CarData{ColorCode::X, Point2{2, 1}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 0}, Direction::horizontal},
			CarData{ColorCode::B, Point2{0, 2}, Direction::vertical},
			CarData{ColorCode::O, Point2{0, 3}, Direction::vertical},
			CarData{ColorCode::C, Point2{1, 0}, Direction::horizontal},
			CarData{ColorCode::P, Point2{2, 0}, Direction::vertical},
			CarData{ColorCode::Q, Point2{3, 1}, Direction::horizontal},
			CarData{ColorCode::D, Point2{4, 1}, Direction::horizontal},
			CarData{ColorCode::R, Point2{5, 0}, Direction::horizontal}
		},
		// 19
		{
			CarData{ColorCode::X, Point2{2, 2}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 2}, Direction::vertical},
			CarData{ColorCode::B, Point2{0, 3}, Direction::horizontal},
			CarData{ColorCode::J, Point2{1, 4}, Direction::vertical},
			CarData{ColorCode::D, Point2{2, 1}, Direction::vertical},
			CarData{ColorCode::E, Point2{3, 2}, Direction::horizontal},
			CarData{ColorCode::F, Point2{3, 4}, Direction::vertical},
			CarData{ColorCode::O, Point2{4, 1}, Direction::horizontal}
		},
		// 20
		{
			CarData{ColorCode::X, Point2{2, 0}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 0}, Direction::vertical},
			CarData{ColorCode::O, Point2{0, 3}, Direction::horizontal},
			CarData{ColorCode::B, Point2{1, 1}, Direction::horizontal},
			CarData{ColorCode::C, Point2{1, 3}, Direction::vertical},
			CarData{ColorCode::D, Point2{2, 2}, Direction::vertical},
			CarData{ColorCode::P, Point2{2, 5}, Direction::vertical},
			CarData{ColorCode::E, Point2{4, 2}, Direction::vertical},
			CarData{ColorCode::F, Point2{4, 3}, Direction::horizontal},
			CarData{ColorCode::Q, Point2{5, 3}, Direction::horizontal}
		},
		// 21
		{
			CarData{ColorCode::X, Point2{2, 1}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 0}, Direction::horizontal},
			CarData{ColorCode::B, Point2{0, 2}, Direction::vertical},
			CarData{ColorCode::O, Point2{0, 3}, Direction::vertical},
			CarData{ColorCode::P, Point2{1, 0}, Direction::vertical},
			CarData{ColorCode::Q, Point2{3, 1}, Direction::horizontal},
			CarData{ColorCode::R, Point2{5, 3}, Direction::horizontal}
		},
		// 22
		{
			CarData{ColorCode::X, Point2{2, 1}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 2}, Direction::vertical},
			CarData{ColorCode::O, Point2{0, 3}, Direction::horizontal},
			CarData{ColorCode::B, Point2{1, 0}, Direction::vertical},
			CarData{ColorCode::P, Point2{1, 3}, Direction::vertical},
			CarData{ColorCode::C, Point2{1, 4}, Direction::horizontal},
			CarData{ColorCode::D, Point2{3, 1}, Direction::vertical},
			CarData{ColorCode::E, Point2{3, 4}, Direction::horizontal},
			CarData{ColorCode::F, Point2{4, 0}, Direction::vertical},
			CarData{ColorCode::G, Point2{4, 2}, Direction::horizontal},
			CarData{ColorCode::H, Point2{4, 5}, Direction::vertical},
			CarData{ColorCode::Q, Point2{5, 1}, Direction::horizontal}
		},
		// 23
		{
			CarData{ColorCode::X, Point2{2, 3}, Direction::horizontal},
			CarData{ColorCode::O, Point2{0, 2}, Direction::horizontal},
			CarData{ColorCode::P, Point2{0, 5}, Direction::vertical},
			CarData{ColorCode::A, Point2{1, 2}, Direction::vertical},
			CarData{ColorCode::B, Point2{1, 3}, Direction::horizontal},
			CarData{ColorCode::C, Point2{3, 2}, Direction::vertical},
			CarData{ColorCode::D, Point2{3, 3}, Direction::vertical},
			CarData{ColorCode::E, Point2{3, 4}, Direction::horizontal},
			CarData{ColorCode::F, Point2{4, 4}, Direction::horizontal},
			CarData{ColorCode::Q, Point2{5, 2}, Direction::horizontal}
		},
		// 24
		{
			CarData{ColorCode::X, Point2{2, 2}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 2}, Direction::vertical},
			CarData{ColorCode::B, Point2{0, 3}, Direction::horizontal},
			CarData{ColorCode::C, Point2{1, 1}, Direction::vertical},
			CarData{ColorCode::D, Point2{2, 0}, Direction::vertical},
			CarData{ColorCode::E, Point2{2, 4}, Direction::vertical},
			CarData{ColorCode::F, Point2{3, 1}, Direction::horizontal},
			CarData{ColorCode::O, Point2{4, 0}, Direction::horizontal},
			CarData{ColorCode::G, Point2{4, 4}, Direction::vertical},
			CarData{ColorCode::H, Point2{5, 0}, Direction::horizontal}
		},
		// 25
		{
			CarData{ColorCode::X, Point2{2, 1}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 0}, Direction::horizontal},
			CarData{ColorCode::B, Point2{0, 2}, Direction::vertical},
			CarData{ColorCode::C, Point2{0, 4}, Direction::horizontal},
			CarData{ColorCode::D, Point2{1, 0}, Direction::horizontal},
			CarData{ColorCode::O, Point2{1, 5}, Direction::vertical},
			CarData{ColorCode::P, Point2{2, 0}, Direction::vertical},
			CarData{ColorCode::E, Point2{2, 4}, Direction::vertical},
			CarData{ColorCode::Q, Point2{3, 1}, Direction::horizontal},
			CarData{ColorCode::F, Point2{4, 1}, Direction::vertical},
			CarData{ColorCode::G, Point2{4, 3}, Direction::vertical},
			CarData{ColorCode::H, Point2{4, 4}, Direction::horizontal},
			CarData{ColorCode::I, Point2{5, 4}, Direction::horizontal}
		},
		// 26
		{
			CarData{ColorCode::X, Point2{2, 1}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 1}, Direction::vertical},
			CarData{ColorCode::O, Point2{0, 3}, Direction::horizontal},
			CarData{ColorCode::B, Point2{1, 0}, Direction::vertical},
			CarData{ColorCode::C, Point2{1, 3}, Direction::vertical},
			CarData{ColorCode::P, Point2{1, 4}, Direction::vertical},
			CarData{ColorCode::D, Point2{2, 5}, Direction::vertical},
			CarData{ColorCode::E, Point2{3, 0}, Direction::vertical},
			CarData{ColorCode::R, Point2{3, 1}, Direction::horizontal},
			CarData{ColorCode::F, Point2{4, 2}, Direction::vertical},
			CarData{ColorCode::G, Point2{4, 5}, Direction::vertical},
			CarData{ColorCode::H, Point2{5, 3}, Direction::horizontal}
		},
		// 27
		{
			CarData{ColorCode::X, Point2{2, 0}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 0}, Direction::vertical},
			CarData{ColorCode::B, Point2{0, 1}, Direction::horizontal},
			CarData{ColorCode::O, Point2{0, 3}, Direction::vertical},
			CarData{ColorCode::C, Point2{1, 1}, Direction::horizontal},
			CarData{ColorCode::D, Point2{2, 2}, Direction::vertical},
			CarData{ColorCode::P, Point2{2, 5}, Direction::vertical},
			CarData{ColorCode::E, Point2{3, 3}, Direction::horizontal},
			CarData{ColorCode::F, Point2{4, 2}, Direction::vertical},
			CarData{ColorCode::R, Point2{5, 3}, Direction::horizontal}
		},
		// 28
		{
			CarData{ColorCode::X, Point2{2, 0}, Direction::horizontal},
			CarData{ColorCode::O, Point2{0, 0}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 3}, Direction::vertical},
			CarData{ColorCode::P, Point2{1, 2}, Direction::vertical},
			CarData{ColorCode::B, Point2{1, 4}, Direction::horizontal},
			CarData{ColorCode::C, Point2{3, 0}, Direction::vertical},
			CarData{ColorCode::D, Point2{3, 1}, Direction::vertical},
			CarData{ColorCode::E, Point2{3, 3}, Direction::horizontal},
			CarData{ColorCode::Q, Point2{3, 5}, Direction::vertical},
			CarData{ColorCode::R, Point2{4, 2}, Direction::horizontal},
			CarData{ColorCode::F, Point2{5, 0}, Direction::horizontal},
			CarData{ColorCode::G, Point2{5, 2}, Direction::horizontal}
		},
		// 29
		{
			CarData{ColorCode::X, Point2{2, 0}, Direction::horizontal},
			CarData{ColorCode::O, Point2{0, 0}, Direction::horizontal},
			CarData{ColorCode::P, Point2{0, 4}, Direction::vertical},
			CarData{ColorCode::A, Point2{1, 2}, Direction::vertical},
			CarData{ColorCode::B, Point2{2, 5}, Direction::vertical},
			CarData{ColorCode::C, Point2{3, 0}, Direction::vertical},
			CarData{ColorCode::D, Point2{3, 1}, Direction::horizontal},
			CarData{ColorCode::E, Point2{3, 3}, Direction::horizontal},
			CarData{ColorCode::F, Point2{4, 1}, Direction::horizontal},
			CarData{ColorCode::G, Point2{4, 3}, Direction::vertical},
			CarData{ColorCode::H, Point2{4, 5}, Direction::vertical},
			CarData{ColorCode::R, Point2{5, 0}, Direction::horizontal}
		},
		// 30
		{
			CarData{ColorCode::X, Point2{2, 1}, Direction::horizontal},
			CarData{ColorCode::O, Point2{0, 0}, Direction::vertical},
			CarData{ColorCode::A, Point2{0, 2}, Direction::vertical},
			CarData{ColorCode::P, Point2{0, 3}, Direction::horizontal},
			CarData{ColorCode::B, Point2{1, 3}, Direction::vertical},
			CarData{ColorCode::C, Point2{3, 0}, Direction::horizontal},
			CarData{ColorCode::D, Point2{3, 2}, Direction::horizontal},
			CarData{ColorCode::Q, Point2{3, 5}, Direction::vertical},
			CarData{ColorCode::E, Point2{5, 0}, Direction::horizontal},
			CarData{ColorCode::F, Point2{5, 2}, Direction::horizontal}
		},
		// 31
		{
			CarData{ColorCode::X, Point2{2, 1}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 0}, Direction::horizontal},
			CarData{ColorCode::O, Point2{0, 3}, Direction::horizontal},
			CarData{ColorCode::B, Point2{1, 3}, Direction::vertical},
			CarData{ColorCode::C, Point2{1, 4}, Direction::horizontal},
			CarData{ColorCode::D, Point2{2, 0}, Direction::vertical},
			CarData{ColorCode::P, Point2{2, 5}, Direction::vertical},
			CarData{ColorCode::Q, Point2{3, 2}, Direction::vertical},
			CarData{ColorCode::E, Point2{3, 3}, Direction::horizontal},
			CarData{ColorCode::F, Point2{4, 0}, Direction::horizontal},
			CarData{ColorCode::R, Point2{5, 3}, Direction::horizontal}
		},
		// 32
		{
			CarData{ColorCode::X, Point2{2, 0}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 0}, Direction::horizontal},
			CarData{ColorCode::O, Point2{0, 2}, Direction::vertical},
			CarData{ColorCode::B, Point2{0, 3}, Direction::vertical},
			CarData{ColorCode::C, Point2{0, 4}, Direction::horizontal},
			CarData{ColorCode::D, Point2{3, 0}, Direction::vertical},
			CarData{ColorCode::E, Point2{3, 1}, Direction::horizontal},
			CarData{ColorCode::F, Point2{3, 3}, Direction::horizontal},
			CarData{ColorCode::P, Point2{3, 5}, Direction::vertical},
			CarData{ColorCode::K, Point2{4, 3}, Direction::vertical},
			CarData{ColorCode::H, Point2{5, 0}, Direction::horizontal}
		},
		// 33
		{
			CarData{ColorCode::X, Point2{2, 0}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 1}, Direction::vertical},
			CarData{ColorCode::R, Point2{0, 2}, Direction::vertical},
			CarData{ColorCode::B, Point2{0, 4}, Direction::horizontal},
			CarData{ColorCode::I, Point2{3, 0}, Direction::vertical},
			CarData{ColorCode::D, Point2{3, 1}, Direction::horizontal},
			CarData{ColorCode::E, Point2{3, 3}, Direction::horizontal},
			CarData{ColorCode::P, Point2{3, 5}, Direction::vertical},
			CarData{ColorCode::F, Point2{4, 1}, Direction::horizontal},
			CarData{ColorCode::G, Point2{4, 3}, Direction::vertical},
			CarData{ColorCode::H, Point2{4, 4}, Direction::vertical},
			CarData{ColorCode::Q, Point2{5, 0}, Direction::horizontal}
		},
		// 34
		{
			CarData{ColorCode::X, Point2{2, 0}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 0}, Direction::vertical},
			CarData{ColorCode::R, Point2{0, 3}, Direction::horizontal},
			CarData{ColorCode::B, Point2{1, 3}, Direction::vertical},
			CarData{ColorCode::P, Point2{1, 5}, Direction::vertical},
			CarData{ColorCode::C, Point2{2, 4}, Direction::vertical},
			CarData{ColorCode::Q, Point2{3, 0}, Direction::horizontal},
			CarData{ColorCode::D, Point2{3, 3}, Direction::vertical},
			CarData{ColorCode::E, Point2{4, 2}, Direction::vertical},
			CarData{ColorCode::F, Point2{4, 4}, Direction::horizontal},
			CarData{ColorCode::I, Point2{5, 0}, Direction::horizontal},
			CarData{ColorCode::H, Point2{5, 3}, Direction::horizontal}
		},
		// 35
		{
			CarData{ColorCode::X, Point2{2, 0}, Direction::horizontal},
			CarData{ColorCode::O, Point2{0, 2}, Direction::vertical},
			CarData{ColorCode::A, Point2{0, 3}, Direction::horizontal},
			CarData{ColorCode::P, Point2{0, 5}, Direction::vertical},
			CarData{ColorCode::B, Point2{1, 3}, Direction::vertical},
			CarData{ColorCode::K, Point2{3, 0}, Direction::vertical},
			CarData{ColorCode::Q, Point2{3, 1}, Direction::horizontal},
			CarData{ColorCode::D, Point2{4, 1}, Direction::horizontal},
			CarData{ColorCode::E, Point2{4, 3}, Direction::vertical},
			CarData{ColorCode::F, Point2{4, 4}, Direction::vertical},
			CarData{ColorCode::G, Point2{5, 0}, Direction::horizontal}
		},
		// 36
		{
			CarData{ColorCode::X, Point2{2, 2}, Direction::horizontal},
			CarData{ColorCode::O, Point2{0, 0}, Direction::vertical},
			CarData{ColorCode::P, Point2{0, 1}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 4}, Direction::horizontal},
			CarData{ColorCode::B, Point2{1, 1}, Direction::vertical},
			CarData{ColorCode::C, Point2{1, 2}, Direction::horizontal},
			CarData{ColorCode::Q, Point2{1, 5}, Direction::vertical},
			CarData{ColorCode::R, Point2{3, 0}, Direction::horizontal},
			CarData{ColorCode::D, Point2{3, 3}, Direction::vertical},
			CarData{ColorCode::E, Point2{4, 2}, Direction::vertical},
			CarData{ColorCode::F, Point2{4, 4}, Direction::horizontal},
			CarData{ColorCode::G, Point2{5, 0}, Direction::horizontal}
		},
		// 37
		{
			CarData{ColorCode::X, Point2{2, 1}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 0}, Direction::horizontal},
			CarData{ColorCode::B, Point2{0, 2}, Direction::vertical},
			CarData{ColorCode::C, Point2{0, 4}, Direction::horizontal},
			CarData{ColorCode::D, Point2{1, 0}, Direction::horizontal},
			CarData{ColorCode::O, Point2{1, 4}, Direction::vertical},
			CarData{ColorCode::P, Point2{1, 5}, Direction::vertical},
			CarData{ColorCode::Q, Point2{2, 0}, Direction::vertical},
			CarData{ColorCode::R, Point2{3, 1}, Direction::horizontal},
			CarData{ColorCode::E, Point2{4, 3}, Direction::vertical},
			CarData{ColorCode::F, Point2{4, 4}, Direction::horizontal},
			CarData{ColorCode::G, Point2{5, 0}, Direction::horizontal},
			CarData{ColorCode::H, Point2{5, 4}, Direction::horizontal}
		},
		// 38
		{
			CarData{ColorCode::X, Point2{2, 0}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 0}, Direction::vertical},
			CarData{ColorCode::O, Point2{0, 3}, Direction::horizontal},
			CarData{ColorCode::B, Point2{1, 1}, Direction::horizontal},
			CarData{ColorCode::C, Point2{1, 3}, Direction::vertical},
			CarData{ColorCode::D, Point2{2, 2}, Direction::vertical},
			CarData{ColorCode::R, Point2{2, 5}, Direction::vertical},
			CarData{ColorCode::E, Point2{3, 3}, Direction::horizontal},
			CarData{ColorCode::F, Point2{4, 2}, Direction::vertical},
			CarData{ColorCode::G, Point2{4, 3}, Direction::horizontal},
			CarData{ColorCode::Q, Point2{5, 3}, Direction::horizontal}
		},
		// 39
		{
			CarData{ColorCode::X, Point2{2, 0}, Direction::horizontal},
			CarData{ColorCode::A, Point2{0, 2}, Direction::vertical},
			CarData{ColorCode::O, Point2{0, 3}, Direction::horizontal},
			CarData{ColorCode::B, Point2{1, 3}, Direction::vertical},
			CarData{ColorCode::C, Point2{2, 2}, Direction::vertical},
			CarData{ColorCode::R, Point2{2, 5}, Direction::vertical},
			CarData{ColorCode::D, Point2{3, 0}, Direction::horizontal},
			CarData{ColorCode::E, Point2{3, 3}, Direction::horizontal},
			CarData{ColorCode::F, Point2{4, 0}, Direction::vertical},
			CarData{ColorCode::G, Point2{4, 1}, Direction::vertical},
			CarData{ColorCode::H, Point2{4, 2}, Direction::horizontal},
			CarData{ColorCode::I, Point2{5, 2}, Direction::horizontal}
		},
		// 40
		{
			CarData{ColorCode::X, Point2{2, 3}, Direction::horizontal},
			CarData{ColorCode::O, Point2{0, 0}, Direction::vertical},
			CarData{ColorCode::A, Point2{0, 1}, Direction::horizontal},
			CarData{ColorCode::B, Point2{0, 4}, Direction::vertical},
			CarData{ColorCode::C, Point2{1, 1}, Direction::vertical},
			CarData{ColorCode::D, Point2{1, 2}, Direction::vertical},
			CarData{ColorCode::P, Point2{1, 5}, Direction::vertical},
			CarData{ColorCode::Q, Point2{3, 0}, Direction::horizontal},
			CarData{ColorCode::E, Point2{3, 3}, Direction::vertical},
			CarData{ColorCode::F, Point2{4, 2}, Direction::vertical},
			CarData{ColorCode::G, Point2{4, 4}, Direction::horizontal},
			CarData{ColorCode::H, Point2{5, 0}, Direction::horizontal},
			CarData{ColorCode::I, Point2{5, 3}, Direction::horizontal}
		},
	};
}
