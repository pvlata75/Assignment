#pragma once
#include <string>

class Game {
public:
	void Run();

	void PrintCurrentInfo();

	bool HandleCommand();

private:
	int m_currentDay = 1;
	int m_m = 0;
	int m_b = 5000;
	int m_quota = 150;
	std::string m_planet = "Corporation";
};
