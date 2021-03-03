#ifndef ENGINE_BOARD_H
#define ENGINE_BOARD_H
#include <map>
#include <string>
#include "./Position.h"
#include "./Piece.h"

class Board {
private:
	std::map<std::string, Position> m_board;

	void setupBoard() {
		m_board["a1"].setPiece("Rook", Team::WHITE);
		m_board["b1"].setPiece("Knight", Team::WHITE);
		m_board["c1"].setPiece("Bishop", Team::WHITE);
		m_board["d1"].setPiece("Queen", Team::WHITE);
		m_board["e1"].setPiece("King", Team::WHITE);
		m_board["f1"].setPiece("Bishop", Team::WHITE);
		m_board["g1"].setPiece("Knight", Team::WHITE);
		m_board["h1"].setPiece("Rook", Team::WHITE);
		for (int i = 1; i <= columnAmount; ++i) {
			m_board[(std::string{ rows[i] } + "2")].setPiece("Pawn", Team::WHITE);
		}
		m_board["a8"].setPiece("Rook", Team::BLACK);
		m_board["b8"].setPiece("Knight", Team::BLACK);
		m_board["c8"].setPiece("Bishop", Team::BLACK);
		m_board["d8"].setPiece("Queen", Team::BLACK);
		m_board["e8"].setPiece("King", Team::BLACK);
		m_board["f8"].setPiece("Bishop", Team::BLACK);
		m_board["g8"].setPiece("Knight", Team::BLACK);
		m_board["h8"].setPiece("Rook", Team::BLACK);
		for (int i = 1; i <= columnAmount; ++i) {
			m_board[(std::string{rows[i]} + "7")].setPiece("Pawn", Team::BLACK);
		}
	}
public:
	Board(bool default_setup=true) {
		for (char c : rows) {
			for (int i = 1; i <= columnAmount; ++i) {
				std::string pos = c + std::to_string(i);
				m_board[pos] = Position{pos};
			}
		}
		if (default_setup) {
			this->setupBoard();
		}
	}

	std::map<std::string, Position> getBoard() const {
		return this->m_board;
	}

	Position operator[](std::string location) {
		return this->m_board[location];
	}

	void move(std::string pos, std::string to) {

	}
};

#endif