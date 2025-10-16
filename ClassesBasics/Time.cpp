// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Time.h"

#include <iomanip>
#include <iostream>

Time::Time(int seconds) : m_Seconds{seconds}
{
}

Time::Time(int minutes, int seconds)
{
	m_Seconds = seconds + minutes * 60;
}

Time::Time(int hours, int minutes, int seconds)
{
	minutes += hours * 60;
	seconds += minutes * 60;
	m_Seconds = seconds;
}

void Time::AddSeconds(int deltaSeconds)
{
	m_Seconds += deltaSeconds;
}

void Time::AddMinutes(int deltaMinutes)
{
	m_Seconds += deltaMinutes * 60;
}

void Time::AddHours(int deltaHours)
{
	m_Seconds += deltaHours * 3600;
}

int Time::GetSeconds() const
{
	const int minSec{m_Seconds % 3600};
	return minSec % 60;
}

int Time::GetMinutes() const
{
	const int minSec{m_Seconds % 3600};
	return minSec / 60;
}

int Time::GetHours() const
{
	return m_Seconds / 3600;
}

void Time::Print() const
{
	std::cout << "Time ";
	std::cout << std::setw(2) << std::setfill('0');
	std::cout << GetHours() << ':';
	std::cout << std::setw(2) << std::setfill('0');
	std::cout << GetMinutes() << ':';
	std::cout << std::setw(2) << std::setfill('0');
	std::cout << GetSeconds() << std::endl;
}

