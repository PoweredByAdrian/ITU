// ConnectionManager.cpp
#include "ConnectionManager.h"
#include "MainWindow.h"


ConnectionManager::ConnectionManager(QObject *parent) : QObject(parent)
{
    gi = new GameInterface;

}

void ConnectionManager::connectMainWindow(MainWindow *mainWindow)
{
    connect(mainWindow, &MainWindow::mousePressed, this, &ConnectionManager::handlePieceSelection);
}

// Conversion function
std::pair<int, int> convertQPointToPair(const QPoint& point) {
    return std::make_pair(point.x(), point.y());
}

void ConnectionManager::handlePieceSelection(const QPoint &gridCoordinates)
{
    // Convert QPoint to std::pair<int, int>
    const std::pair<int, int>& convertedCoordinates = convertQPointToPair(gridCoordinates);


    gi->pieceSelected(convertedCoordinates);
}
