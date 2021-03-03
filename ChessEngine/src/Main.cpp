#include <iostream>
#include "Engine/Board.h"
#include "Engine/Position.h"

int main() {
    Board b{};
    std::map<std::string, Position> n = b.getBoard();
    for (auto obj = n.begin(); obj != n.end(); ++obj) {
        if (obj->second.occupied())
            std::cout << obj->first << "  |  " << obj->second.getPiece().name() << '\n';
    }
    return 0;
}