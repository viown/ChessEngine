#ifndef ENGINE_POSITION_H
#define ENGINE_POSITION_H
#include "./Piece.h"
#include "./Errors.h"
#include <string>
#include <regex>

std::string rows = "abcdefgh";
constexpr int columnAmount = 8;

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

	Piece getPiece() const {
		if (this->isOccupied)
			return this->piece;
		else
			throw -1;
	}

	void setPiece(const Piece& p) {
		this->piece = p;
		this->isOccupied = true;
	}
	void setPiece(std::string p, Team team) {
		setPiece(Piece{ p, team });
	}

	bool occupied() const {
		return this->isOccupied;
	}

	std::string f_pos() const {
		return this->position;
	}

	Position f_left() const {
		if (this->position[0] == 'a')
			throw MoveNotAllowed{};
		for (int i = 0; i < rows.size(); ++i) {
			if (rows[i] == this->position[0]) {
				return Position{ std::string{rows[i-1]} + this->position[1] };
			}
		}
	}

	Position f_right() const {
		if (this->position[0] == 'h')
			throw MoveNotAllowed{};
		for (int i = 0; i < rows.size(); ++i) {
			if (rows[i] == this->position[0]) {
				return Position{ std::string{rows[i + 1]} + this->position[1] };
			}
		}
	}

	Position f_up() const {
		if (this->position[1] == '8')
			throw MoveNotAllowed{};
		int posup = std::stoi(std::string{ this->position[1] }) + 1;
		return Position{ std::string{this->position[0]} + std::to_string(posup) };
	}

	Position f_down() const {
		if (this->position[1] == '1')
			throw MoveNotAllowed{};
		int posup = std::stoi(std::string{ this->position[1] }) - 1;
		return Position{ std::string{this->position[0]} + std::to_string(posup) };
	}

	Position upright() const { return this->up.right; }
	Position downright() const { return this->down.right; }
	Position upleft() const { return this->up.left; }
	Position downleft() const { return this->down.left; }

	__declspec(property(get=f_left)) Position left;
	__declspec(property(get=f_right)) Position right;
	__declspec(property(get=f_up)) Position up;
	__declspec(property(get=f_down)) Position down;
	__declspec(property(get=f_pos)) std::string pos;
};

#endif