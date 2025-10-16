// Knapecz, Adam - 1DAE11
#pragma once
class Time
{
public:
	Time(int seconds);
	Time(int minutes, int seconds);
	Time(int hours, int minutes, int seconds);

	void Print() const;

	int GetSeconds() const;
	int GetMinutes() const;
	int GetHours() const;

	void AddSeconds(int deltaSeconds);
	void AddMinutes(int deltaMinutes);
	void AddHours(int deltaHours);
private:
	int m_Seconds;
};

