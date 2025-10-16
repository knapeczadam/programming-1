// Knapecz, Adam - 1DAE11

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <numbers>

int main()
{
	std::string userInput{}; 
	std::stringstream ss{};

	/*
	 * RGBA
	 */
	constexpr  unsigned char MAX_COLOR = 255;
	float r{}, g{}, b{}, a{};
	std::cout << "RGBA in [0, 255]? ";
	std::getline(std::cin, userInput);
	ss << userInput;
	ss >> r >> g >> b >> a;
	std::cout << "RGBA in [0.0f, 1.0f]:" << '\n';
	r /= MAX_COLOR; 
	g /= MAX_COLOR;
	b /= MAX_COLOR;
	a /= MAX_COLOR;
	std::cout << r << '\n' << g << '\n' << b << '\n' << a << '\n';

	/*
	 * DISTANCE
	 */
	float distance{};
	std::cout << '\n';
	std::cout << "Distance in km? ";
	std::cin >> distance;
	std::cout << distance * 1000 << " meters, " << distance * 100000 << " cm" << '\n';

	/*
	 * R2D
	 */
	float radians{};
	std::cout << '\n';
	std::cout << "Angle in radians? ";
	std::cin >> radians;
	std::cout << radians * 180 / std::numbers::pi << " degrees" << '\n';

	/*
	 * D2R
	 */
	float degrees{};
	std::cout << '\n';
	std::cout << "Angle in degrees? ";
	std::cin >> degrees;
	std::cout << degrees * std::numbers::pi / 180 << " radians" << '\n';

	/*
	 * ROTATION
	 */
	float rotationInSecond{};
	std::cout << '\n';
	std::cout << "Seconds of one rotation? ";
	std::cin >> rotationInSecond;
	std::cout << 360 / rotationInSecond << " degrees/second" << '\n';

	/*
	 * SPEED
	 */
	float speed{};
	float elapsedTimeInMinutes{};
	std::cout << '\n';
	std::cout << "Speed (km/h)? ";
	std::cin >> speed;
	std::cout << "Elapsed time (minutes)? ";
	std::cin >> elapsedTimeInMinutes;
	std::cout << speed / 60 * elapsedTimeInMinutes * 1000 << " meters" << '\n';

	/*
	 * VELOCITY
	 */
	float seconds{};
	constexpr  float GRAVITY{ 9.8f };
	std::cout << '\n';
	std::cout << "Seconds? ";
	std::cin >> seconds;
	std::cout << "Velocity " << seconds * GRAVITY << " m/sec" << '\n';

	/*
	 * CIRCLE
	 */
	float radius{};
	std::cout << '\n';
	std::cout << "Radius of circle? ";
	std::cin >> radius;
	std::cout << "Circumference: " << radius * 2 * std::numbers::pi << '\n';
	std::cout << "Area: " << radius * radius * std::numbers::pi << '\n';

	/*
	 * RECTANGLE
	 */
	float width{}, height{};
	std::cout << '\n';
	std::cout << "Width and height? ";
	std::cin.ignore();
	std::getline(std::cin, userInput);
	ss.str("");
	ss.clear();
	ss << userInput;
	ss >> width >> height;
	std::cout << "Circumference: " << 2 * width + 2 * height << '\n';
	std::cout << "Area: " << width * height << '\n';

	/*
	 * TRIANGLE
	 */
	float base{};
	std::cout << '\n';
	std::cout << "Base and height? ";
	std::getline(std::cin, userInput);
	ss.str("");
	ss.clear();
	ss << userInput;
	ss >> base >> height;
	std::cout << "Area: " << base * height / 2 << '\n';
}

