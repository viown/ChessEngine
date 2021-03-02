#ifndef ENGINE_PIECE_H
#define ENGINE_PIECE_H
#include <string>

class Piece {
	std::string m_name;
public:
	Piece() = default;
	Piece(std::string name) {
		this->m_name = name;
	}
};

#endif