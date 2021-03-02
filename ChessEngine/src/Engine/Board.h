#ifndef ENGINE_BOARD_H
#define ENGINE_BOARD_H
#include <map>
#include <string>
#include "./Position.h"

class Board {
private:
	std::map<std::string, Position> m_board;
public:
	Board(bool default_setup=true) {
		std::string rows = "abcdefgh";
		int columnAmount = 8;
		for (char c : rows) {
			for (int i = 1; i <= columnAmount; ++i) {
				std::string pos = c + std::to_string(i);
				m_board[pos] = Position{pos};
			}
		}
	}

	std::map<std::string, Position> getBoard() {
		return this->m_board;
	}
};

#endif