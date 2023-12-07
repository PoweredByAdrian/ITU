#ifndef GAMEINTERFACE_H
#include <vector>
#include <iostream>

class GameInterface
{

public:
    explicit GameInterface();

    void pieceSelected(const std::pair<int, int>& gridCoordinates);

private:
    char getPieceAtPosition(const std::string& board, int row, int col);

};

#endif // GAMEINTERFACE_H
