#ifndef ENGINE_MOVES_H
#define ENGINE_MOVES_H
#include <vector>
#include "./Board.h"
#include "./Position.h"


using Positions = std::vector<std::string>;

bool isValid(std::string n) {
	return (n[0] >= 'a' && n[0] <= 'h') && (n[1] >= '1' && n[1] <= '8');
}

Positions getPawnPositions(const Board& board, const Position& currentPosition) {
	Positions availablePositions;
	if (currentPosition.pos[1] == '8')
		return availablePositions;
	std::map<std::string, Position> rawBoard = board.getBoard();
	availablePositions.push_back(currentPosition.up.pos);
	if (currentPosition.pos[1] == '2') {
		if (!rawBoard[currentPosition.up.pos].occupied() && !rawBoard[currentPosition.up.up.pos].occupied()) {
			availablePositions.push_back(currentPosition.up.up.pos);
		}
	}
	if (rawBoard[currentPosition.upleft().pos].occupied()) {
		if (!(rawBoard[currentPosition.upleft().pos].getPiece().team() == currentPosition.getPiece().team())) {
			availablePositions.push_back(currentPosition.upleft().pos);
		}
	}
	if (rawBoard[currentPosition.upright().pos].occupied()) {
		if (!(rawBoard[currentPosition.upright().pos].getPiece().team() == currentPosition.getPiece().team())) {
			availablePositions.push_back(currentPosition.upright().pos);
		}
	}
	return availablePositions;
}

Positions getKnightPositions(const Board& board, const Position& currentPosition) {
	Positions availablePositions;
	return std::vector<std::string>{};
}

#endif