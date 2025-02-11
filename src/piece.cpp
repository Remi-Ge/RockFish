#include "piece.h"
#include <iostream>

const std::map<PieceType, PieceInfo> Piece::pieceRepresentations = {
    {PieceType::empty, {' ', ' ', ""}},
    {PieceType::rook, {'R', 'r', "rook"}},
    {PieceType::knight, {'N', 'n', "knight"}},
    {PieceType::bishop, {'B', 'b', "bishop"}},
    {PieceType::queen, {'Q', 'q', "queen"}},
    {PieceType::king, {'K', 'k', "king"}},
    {PieceType::pawn, {'P', 'p', "pawn"}},
};

Piece::Piece(char notation) {
    for (const auto& [type, info] : pieceRepresentations) {
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
    PieceInfo info = pieceRepresentations.at(this->type);
    return this->isWhite ? info.whiteNotation : info.blackNotation;
}
