#ifndef ENGINE_PIECE_H
#define ENGINE_PIECE_H
#include <string>

enum class Team {
	WHITE,
	BLACK
};

class Piece {
	std::string m_name;
	Team m_team = Team::WHITE;
public:
	Piece() = default;
	Piece(std::string name, Team team) {
		this->m_name = name;
		this->m_team = team;
	}

	std::string name() {
		return this->m_name;
	}

	Team team() const {
		return this->m_team;
	}
};

#endif