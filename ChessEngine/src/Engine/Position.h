#ifndef ENGINE_POSITION_H
#define ENGINE_POSITION_H
#include "Piece.h"
#include "./Errors.h"
#include <string>
#include <regex>


bool validatePosition(std::string pos) {
	if (pos.size() > 2) {
		return false;
	}
	std::regex validator("[a-h][1-8]");
	return std::regex_match(pos, validator);
}

class Position {
private:
	std::string position;
	Piece piece;
	bool isOccupied = false;
public:
	Position() = default;
	Position(std::string pos) : position{ pos } {
		if (!validatePosition(pos))
			throw InvalidPosition{};
	}
	Position(std::string pos, Piece objPiece) : position{ position }, piece{ objPiece } {
		if (!validatePosition(pos))
			throw InvalidPosition{};
		isOccupied = true;
	}

	void setPiece(const Piece& p) {
		this->piece = p;
		this->isOccupied = true;
	}

	std::string getPosition() {
		return this->position;
	}

	Position f_left() {
		return Position{ "test" };
	}

	Position f_right() {
		return Position{ "test" };
	}

	Position f_up() {
		return Position{ "test" };
	}

	Position f_down() {
		return Position{ "test" };
	}

	Position diagonal_upright() { return this->up.right; }
	Position diagonal_downright() { return this->down.right; }
	Position diagonal_upleft() { return this->up.left; }
	Position diagonal_downleft() { return this->down.left; }

	__declspec(property(get=f_left)) Position left;
	__declspec(property(get=f_right)) Position right;
	__declspec(property(get=f_up)) Position up;
	__declspec(property(get=f_down)) Position down;
};

#endif