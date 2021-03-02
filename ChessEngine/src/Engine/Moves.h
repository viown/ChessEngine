#ifndef ENGINE_MOVES_H
#define ENGINE_MOVES_H
#include <vector>
#include "./Board.h"
#include "./Position.h"

/*
	TODO: organize this stuff jesus
*/

using Positions = std::vector<std::string>;

Positions getPawnPositions(const Board& board, const Position& currentPosition) {
	// pretend this mess doesn't exist
	// the pawn is tricky, okay?
	Positions possiblePositions;
	if (currentPosition.getPosition()[1] == '2') {
		if (!currentPosition.up.occupied()) {
			possiblePositions.push_back(currentPosition.up.getPosition());
			possiblePositions.push_back(currentPosition.up.up.getPosition());
		}
	}
	else {
		if (!currentPosition.up.occupied()) {
			possiblePositions.push_back(currentPosition.up.getPosition());
		}
	}
	if (board.getBoard()[currentPosition.diagonal_upleft().getPosition()].occupied()) {
		possiblePositions.push_back(currentPosition.diagonal_upleft().getPosition());
	}
	if (board.getBoard()[currentPosition.diagonal_upright().getPosition()].occupied()) {
		possiblePositions.push_back(currentPosition.diagonal_upright().getPosition());
	}
	return possiblePositions;
}

Positions getKnightPositions(const Board& board, const Position& currentPosition) {
	return std::vector<std::string>{};
}

#endif