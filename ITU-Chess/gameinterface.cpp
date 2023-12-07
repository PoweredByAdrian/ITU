#include "gameinterface.h"

#include <QDebug>

GameInterface::GameInterface()
{
    // Constructor initialization if needed
}

char GameInterface::getPieceAtPosition(const std::string& board, int row, int col) {
    // Calculate the index in the flattened string

    int index = row * (8 + 1) + col;

    // Check if the index is within the bounds of the flattened string
    if (index >= 0 && index < static_cast<int>(board.size())) {
        return board[index];
    } else {
        // Return a default value (e.g., '.' for out-of-bounds)
        return '.';
    }
}


void GameInterface::pieceSelected(const std::pair<int, int>& gridCoordinates)
{

    std::string chessboard =
        "rnbqkbnr\n"
        "pppppppp\n"
        "........\n"
        "........\n"
        "........\n"
        "........\n"
        "PPPPPPPP\n"
        "RNBQKBNR\n";

    char piece = getPieceAtPosition(chessboard, gridCoordinates.first, gridCoordinates.second);

    // Implement the rest of your GameInterface logic here
    qDebug() << "Piece: " << piece << " selected at grid coordinates: (" << gridCoordinates.first << ", " << gridCoordinates.second << ")";
    // Emit signals or perform actions as needed
}
