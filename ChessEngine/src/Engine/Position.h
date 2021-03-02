#ifndef ENGINE_POSITION_H
#define ENGINE_POSITION_H
#include "Piece.h"
#include "./Errors.h"
#include <string>
#include <regex>

std::string rows = "abcdefgh";
constexpr int totalColumns = 8;

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

	std::string getPosition() const {
		return this->position;
	}

	bool occupied() const {
		return this->isOccupied;
	}

	Position f_left() const {
		if (this->position[0] == 'a')
			throw MoveNotAllowed{};
		for (int i = 0; i < rows.size(); ++i) {
			if (rows[i] == this->position[0]) {
				if (!this->isOccupied) {
					return Position{ std::string{rows[i-1]} + this->position[1] };
				}
				else {
					return Position{ std::string{rows[i-1]} + this->position[1], this->piece };
				}
			}
		}
	}

	Position f_right() const {
		if (this->position[0] == 'h')
			throw MoveNotAllowed{};
		for (int i = 0; i < rows.size(); ++i) {
			if (rows[i] == this->position[0]) {
				if (!this->isOccupied) {
					return Position{ std::string{rows[i + 1]} + this->position[1] };
				}
				else {
					return Position{ std::string{rows[i + 1]} + this->position[1], this->piece };
				}
			}
		}
	}

	Position f_up() const {
		if (this->position[1] == '8')
			throw MoveNotAllowed{};
		int posup = std::stoi(std::string{ this->position[1] }) + 1;
		if (!this->isOccupied) {
			return Position{ std::string{this->position[0]} + std::to_string(posup) };
		}
		else {
			return Position{ std::string{this->position[0]} + std::to_string(posup), this->piece };
		}
	}

	Position f_down() const {
		if (this->position[1] == '1')
			throw MoveNotAllowed{};
		int posup = std::stoi(std::string{ this->position[1] }) - 1;
		if (!this->isOccupied) {
			return Position{ std::string{this->position[0]} + std::to_string(posup) };
		}
		else {
			return Position{ std::string{this->position[0]} + std::to_string(posup), this->piece };
		}
	}

	Position diagonal_upright() const { return this->up.right; }
	Position diagonal_downright() const { return this->down.right; }
	Position diagonal_upleft() const { return this->up.left; }
	Position diagonal_downleft() const { return this->down.left; }

	__declspec(property(get=f_left)) Position left;
	__declspec(property(get=f_right)) Position right;
	__declspec(property(get=f_up)) Position up;
	__declspec(property(get=f_down)) Position down;
};

#endif