#ifndef GAME
#define GAME

#include <string>
#include "ItemManager.h"
#include "Choice.h"

class Game {
public:
	void Run();

	void RegisterItems();
	void PrintCurrentInfo();

	bool HandleCommand();

private:
	ItemManager m_itemManager;
	int m_balance = 5000;
	int m_currentDay = 1;
	int m_total = 0;
	int m_quota = 150;
	std::string m_planet = "Corporation";
	Choice m_currentChoice;
};

#endif