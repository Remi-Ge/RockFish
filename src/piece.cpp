#include "piece.h"
#include <iostream>

const std::map<PieceType, PieceInfo> Piece::PIECE_REPRESENTATIONS = {
    {PieceType::empty, {' ', ' ', ""}},
    {PieceType::rook, {'R', 'r', "rook"}},
    {PieceType::knight, {'N', 'n', "knight"}},
    {PieceType::bishop, {'B', 'b', "bishop"}},
    {PieceType::queen, {'Q', 'q', "queen"}},
    {PieceType::king, {'K', 'k', "king"}},
    {PieceType::pawn, {'P', 'p', "pawn"}},
};

const std::vector<Direction> Piece::DIRECTIONS = {
    {-1, 0}, {0, +1}, {0, -1}, {0, +1}, // left, right, up, down
    {-1, -1}, {-1, +1}, {+1, +1}, {+1, -1} // diagonales
};

const std::vector<Direction> Piece::KNIGHT_DIRECTIONS = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

Piece::Piece(char notation) {
    for (const auto& [type, info] : PIECE_REPRESENTATIONS) {
        if (notation == info.whiteNotation) {
            this->isWhite = true;
            this->type = type;
            break;
        }
        if (notation == info.blackNotation) {
            this->isWhite = false;
            this->type = type;
            break;
        }
    }
}

char Piece::getNotation() {
    PieceInfo info = PIECE_REPRESENTATIONS.at(this->type);
    return this->isWhite ? info.whiteNotation : info.blackNotation;
}
