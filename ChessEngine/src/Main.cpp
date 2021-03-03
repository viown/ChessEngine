#include <iostream>
#include "Engine/Board.h"
#include "Engine/Position.h"
#include "Engine/Moves.h"

int main() {
    Board b{};
    std::map<std::string, Position> n = b.getBoard();
    auto pawn = n["e2"];
    auto available = getPawnPositions(b, pawn);
    for (auto lol : available) {
        std::cout << lol << ' ';
    }
    return 0;
}