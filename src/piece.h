#ifndef PIECE_H
#define PIECE_H

#include <map>
#include <string>

enum class PieceType {
    empty,
    rook,
    knight,
    bishop,
    queen,
    king,
    pawn
};

struct PieceInfo {
    char whiteNotation;
    char blackNotation;
    std::string name;
};

class Piece {
private:
    static const std::map<PieceType, PieceInfo> pieceRepresentations;
public:
    Piece(char notation);
    PieceType type = PieceType::empty;
    bool isWhite = true;
    char getNotation();
};

#endif
