#ifndef PIECE_H
#define PIECE_H

#include <map>
#include <string>
#include <vector>

using Direction = std::pair<int, int>;

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
    static const std::map<PieceType, PieceInfo> PIECE_REPRESENTATIONS;
    static const std::vector<Direction> DIRECTIONS;
    static const std::vector<Direction> KNIGHT_DIRECTIONS;
public:
    Piece(char notation);
    PieceType type = PieceType::empty;
    bool isWhite = true;
    char getNotation();
};

#endif
