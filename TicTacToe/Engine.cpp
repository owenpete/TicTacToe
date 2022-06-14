#include "Engine.h"
#include <iostream>
#include <vector>
#include <sstream>

std::vector<char> board;
int boardCellCount;
bool isP1Turn;
char p1Token;
char p2Token;
std::string winner;

Engine::Engine(char p1Token, char p2Token) {
	board = {
		'1', '2', '3',
		'4', '5', '6',
		'7', '8', '9',
	};
	boardCellCount = board.size();
	this->p1Token = p1Token;
	this->p2Token = p2Token;
	isP1Turn = true;
}

const void Engine::clearConsole() {
	system("CLS");
}

const void Engine::drawBoard(bool shouldClear) {
	if (shouldClear) { clearConsole(); }
	std::string row = "";
	for (int i = 0; i < boardCellCount; i++) {
		std::string token = std::string(1, board[i]);
		std::stringstream ss;
		if (board[i] == p1Token) {
			ss << "\033[31;1m" << board[i] << "\033[0m";
			token = ss.str();
		}
		else if (board[i] == p2Token) {
			ss << "\033[36;1m" << board[i] << "\033[0m";
			token = ss.str();
		}
		if ((i - 1) % 3 == 0) {
			row+= " | " + token + " | ";
		}
		else {
			row+=token;
		}
		if ((i+1) % 3 == 0) {
			std::cout << row << std::endl;
			if (i + 1 != boardCellCount) {
				std::cout << "---------" << std::endl;
			}
			else {
				std::cout << std::endl;
			}
			row = "";
		}
	}
}

const bool Engine::validateMove(int pos) {
	return pos <= boardCellCount && (board[pos] != p1Token && board[pos] != p2Token);
}

const bool Engine::hasWinner() {
	// check rows
	if (board[0] == board[1] && board[1] == board[2]) {
		if (board[0] == p1Token) {
			winner = "p1";
		}
		else {
			winner = "p2";
		}
		return true;
	}
	else if (board[3] == board[4] && board[4] == board[5]) {
		if (board[3] == p1Token) {
			winner = "p1";
		}
		else {
			winner = "p2";
		}
		return true;
	}
	else if (board[6] == board[7] && board[7] == board[8]) {
		if (board[6] == p1Token) {
			winner = "p1";
		}
		else {
			winner = "p2";
		}
		return true;
	}

	// check columns
	else if (board[0] == board[3] && board[3] == board[6]) {
		if (board[0] == p1Token) {
			winner = "p1";
		}
		else {
			winner = "p2";
		}
		return true;
	}
	else if (board[1] == board[4] && board[4] == board[7]) {
		if (board[1] == p1Token) {
			winner = "p1";
		}
		else {
			winner = "p2";
		}
		return true;
	}
	else if (board[2] == board[5] && board[5] == board[8]) {
		if (board[2] == p1Token) {
			winner = "p1";
		}
		else {
			winner = "p2";
		}
		return true;
	}

	// check diagonals 
	else if (board[0] == board[5] && board[5] == board[9]) {
		if (board[0] == p1Token) {
			winner = "p1";
		}
		else {
			winner = "p2";
		}
		return true;
	}
	else if (board[2] == board[5] && board[5] == board[7]) {
		if (board[2] == p1Token) {
			winner = "p1";
		}
		else {
			winner = "p2";
		}
		return true;
	}
	else {
		return false;
	}
}

const std::string Engine::getWinner() {
	return winner;
}

const bool Engine::isDraw() {
	for (int i = 0; i < boardCellCount; i++) {
		if (board[i] != p1Token && board[i] != p2Token) { return false; }
	}
	return true;
}

const void Engine::playToken(int pos) {
	board[pos] = (isP1Turn) ? p1Token : p2Token;
	switchTurns();
}

const void Engine::switchTurns() {
	isP1Turn = !isP1Turn;
}

const bool Engine::getIsP1Turn() {
	return isP1Turn;
}

