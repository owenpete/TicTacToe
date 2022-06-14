#pragma once
#include <iostream>
#include <vector>

class Engine
{
	private:
		std::vector<char> board;
		int boardCellCount;
		bool isP1Turn;
		char p1Token;
		char p2Token;
	public: 
		Engine(char p1, char p2);
		const void drawBoard(bool shouldClear = true);
		const bool validateMove(int pos);
		const bool hasWinner();
		const bool isDraw();
		const void playToken(int pos);
		const void switchTurns();
		const bool getIsP1Turn();
		const std::string getWinner();
		const void clearConsole();
};
