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
	std::map<std::string, Position> rawBoard = board.getBoard();
	if (currentPosition.pos[1] == '2') {
		if (!currentPosition.up.occupied()) {
			possiblePositions.push_back(currentPosition.up.pos);
			possiblePositions.push_back(currentPosition.up.up.pos);
		}
	}
	else {
		if (!currentPosition.up.occupied()) {
			possiblePositions.push_back(currentPosition.up.pos);
		}
	}
	if (rawBoard[currentPosition.upleft().pos].occupied()) {
		if (!(rawBoard[currentPosition.upleft().pos].getPiece().getTeam() == currentPosition.getPiece().getTeam())) {
			possiblePositions.push_back(currentPosition.upleft().pos);
		}
	}
	if (rawBoard[currentPosition.upright().pos].occupied()) {
		if (!(rawBoard[currentPosition.upright().pos].getPiece().getTeam() == currentPosition.getPiece().getTeam())) {
			possiblePositions.push_back(currentPosition.upright().pos);
		}
	}
	return possiblePositions;
}

Positions getKnightPositions(const Board& board, const Position& currentPosition) {
	return std::vector<std::string>{};
}

#endif