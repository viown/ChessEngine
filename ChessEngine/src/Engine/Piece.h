#ifndef ENGINE_PIECE_H
#define ENGINE_PIECE_H
#include <string>
#include <map>

enum class Team {
	WHITE,
	BLACK
};

std::map<std::string, int> points = {
	{"King", 0},
	{"Queen", 9},
	{"Rook", 5},
	{"Bishop", 3},
	{"Knight", 3},
	{"Pawn", 1}
	
};

class Piece {
	std::string m_name;
	Team m_team = Team::WHITE;
	
	int points = 0;
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
