#include <iostream>
#include <vector>
#include "Engine.h"

int main() {
	char p1Token = 'X';
	char p2Token = 'O';
	bool isGameOver = false;
	bool isValidInput = false;

	Engine engine(p1Token, p2Token);

	while (!isGameOver) {
		int playerChoice;

		engine.drawBoard(false);
		std::cout << (engine.getIsP1Turn() ? "Player 1:" : "Player 2:") << "\n" <<  std::endl;
		std::cout << ((isValidInput) ? "Enter a number (1-9)" : "Invalid Input.\nEnter a number (1-9)") << ": " << std::flush;

		if (std::cin >> playerChoice) {
			// subtract 1 from the player choice due to the player choice range starting at 1
			playerChoice -= 1;

			bool isLegalMove = engine.validateMove(playerChoice);
			if (isLegalMove) {
				engine.playToken(playerChoice);
				isValidInput = true;
			}
			else {
				isValidInput = false;
			}
		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			isValidInput = true;
			continue;
		}

		const bool hasWinner = engine.hasWinner();
		const bool isDraw = engine.isDraw();
		if (hasWinner) {
			isGameOver = true;
			engine.drawBoard();
			const std::string winner = engine.getWinner();
			std::cout << "Game Over!\n" << (winner == "p1" ? "\033[31;1mPlayer 1 Won!\033[0m" : "\033[36;1mPlayer 2 Won!\033[0m") << std::endl;
		}
		else if (isDraw) {
			isGameOver = true;
			engine.drawBoard();
			std::cout << "Game Over! \033[33;1mIt was a Draw!\033[0m" << std::endl;
		}
	}

	return 0;
}