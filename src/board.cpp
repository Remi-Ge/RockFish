#include "board.h"
#include <sstream>
#include <iostream>

Board::Board(std::string fen) {
    std::istringstream fenStream(fen);
    std::string boardPart;
    std::string turnPart;
    std::string castlePart;
    std::string enPassantPart;
    std::string halfMovesPart;
    std::string totalMovesPart;

    fenStream >> boardPart >> turnPart >> castlePart >> enPassantPart >> halfMovesPart >> totalMovesPart;

    int index = 0;
    for (char c: boardPart) {
        if (c == '/') {
            continue;
        } else if (std::isdigit(c)) {
            index += c - '0';
        } else {
            this->position.insert({index, Piece(c)});
            index++;
        }
    }
}


void Board::show() {
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            int index = rank * 8 + file;
            if (position.find(index) != position.end()) {
                std::cout << position.at(index).getNotation() << " ";
            } else {
                std::cout << ". "; // empty
            }
        }
        std::cout << std::endl;
    }
}

