#ifndef ENGINE_PIECE_H
#define ENGINE_PIECE_H
#include <string>

enum class Team {
	WHITE,
	BLACK
};

/*
Translate python code into C++ here:
points = {
	"King": 0,
	"Queen": 9,
	...
	"Pawn": 1
}

For piece class init:
self.points = points[name]
*/

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
};

#endif
