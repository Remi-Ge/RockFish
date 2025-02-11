#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include <string>
#include <map>

class Board {
private:
    std::map<u_int8_t, Piece> position;
public:
    Board(std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    void show();
};

#endif