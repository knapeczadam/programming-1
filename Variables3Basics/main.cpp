// Knapecz, Adam - 1DAE11

#include "pch.h"
#include <iostream>

int main()
{
	// 3.2.1. Sizeof operator
	const bool b{true};
	const int i{42};
	const float f{3.14f};
	const double d{2.718281};
	std::cout << "Size of bool: " << sizeof(b) << std::endl;
	std::cout << "Size of int: " << sizeof(i) << std::endl;
	std::cout << "Size of float: " << sizeof(f) << std::endl;
	std::cout << "Size of double: " << sizeof(d) << std::endl;
	std::cout << std::endl;

	// 3.2.2. Hexadecimal and binary number presentation
	const int i1{12};
	const int i2{0xC};
	const int i3{0b1100};
	std::cout << "12 as base ten: " << i1 << std::endl;
	std::cout << "12 as hexadecimal: " << i2 << std::endl;
	std::cout << "12 as binary: " << i3 << std::endl;
	std::cout << std::endl;

	// 3.2.3. Range of – signed vs unsigned types
	unsigned int ui1{0};
	unsigned int ui2{UINT32_MAX};
	int si1{INT32_MIN};
	int si2{INT32_MAX};

	std::cout << "MIN unsigned int: " << ui1 << std::endl;
	std::cout << "MIN unsigned int - 1: " << --ui1 << std::endl;
	std::cout << "MAX unsigned int: " << ui2 << std::endl;
	std::cout << "MAX unsigned int + 1: " << ++ui2 << std::endl;
	std::cout << "MIN signed int: " << si1 << std::endl;
	std::cout << "MIN signed int - 1: " << --si1 << std::endl;
	std::cout << "MAX signed int: " << si2 << std::endl;
	std::cout << "MAX signed int + 1: " << ++si2 << std::endl;
	std::cout << std::endl;

	// 3.2.4. Binary bitwise | and & operator
	const unsigned int x{0b0011};
	const unsigned int y{0b0101};
	unsigned int result{x & y};
	std::cout << "Result of 0011 & 0101: " << result << std::endl;
	result = x | y;
	std::cout << "Result of 0011 | 0101: " << result << std::endl;
	std::cout << std::endl;

	// Applying the bitwise &: is a bit 0 or 1?
	unsigned int userInput{};
	std::cout << "Number to check which bits are set? ";
	std::cin >> userInput;
	std::cout << "1st bit " << (userInput & 1) << std::endl;
	std::cout << "2st bit " << (userInput & 2) << std::endl;
	std::cout << "3st bit " << (userInput & 4) << std::endl;
	std::cout << "4st bit " << (userInput & 8) << std::endl;
	std::cout << std::endl;

	// d. Applying the bitwise |: set a bit in a number
	std::cout << "Number to set 3rd bit in? ";
	std::cin >> userInput;
	std::cout << "This number with 3rd bit set " << (userInput | 0b0100) << std::endl;
	std::cout << std::endl;

	// f. Right shift (divide unsigned integer by 2)
	unsigned int val{2048};
	std::cout << "Using right shift operator: 2048 >> 2 = " << (val >> 2) << std::endl;
	std::cout << std::endl;

	int A{0b0000'0001'0000'0000};
	const int B{0b0001'0001'0110'0000};
	std::cout << "The bit representing 256 is set in the value 4448: " << std::endl;
	std::cout << std::endl;

	// g. Left shift (multiply unsigned integer by 2)
	val = 2048;
	std::cout << "Using left shift operator: 2048 << 2 = " << (val << 2) << std::endl;
	std::cout << std::endl;

	// h. General bitwise operator exercise.
	unsigned int bitMagic{};
	bitMagic |= (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 7) | (1 << 8) | (1 << 9) | (1 <<
		11) | (1 << 13) | (1 << 14) | (1 << 16) | (1 << 17) | (1 << 19) | (1 << 21);;
	std::cout << bitMagic << std::endl;
}

