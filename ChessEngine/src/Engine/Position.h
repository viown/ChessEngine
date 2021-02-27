#ifndef ENGINE_POSITION_H
#define ENGINE_POSITION_H
#include <string>

class Position {
private:
	std::string position;
public:
	Position() = default;
	Position(std::string pos) : position{position} {}

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