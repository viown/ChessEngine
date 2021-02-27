#ifndef ENGINE_PIECE_H
#define ENGINE_PIECE_H
#include <string>
#include <vector>
#include "Board.h"
#include "Position.h"

class Piece {
	std::string m_name;
	Board m_board;
	Position m_position;
public:
	Piece(std::string name) {
		this->m_name = name;
	}

	std::vector<Position> getPossiblePositions() {

	}

	void move(const Position& newPosition) {

	}
};

#endif