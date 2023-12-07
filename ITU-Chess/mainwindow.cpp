#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , backgroundLabel(new QLabel(this))

{
    ui->setupUi(this);

    cm = new ConnectionManager(this);
    cm->connectMainWindow(this);

    // Set the fixed size of the MainWindow
    setFixedSize(boardSize, boardSize);

    // Load the board image as the background
    QPixmap boardPixmap("D:/School/Chess/ITU-Chess/Resources/board.png");

    // Set the background pixmap to the label
    backgroundLabel->setPixmap(boardPixmap);

    // Set the geometry of the background label to cover the entire window
    backgroundLabel->setGeometry(0, 0, width(), height());

    // Make the background label a child of the central widget
    backgroundLabel->setParent(centralWidget());

    // Ensure the background label is behind other widgets
    backgroundLabel->lower();

    // Initialize the grid
    initializeGrid();

    // Set up pieces on the chessboard
    setupWhitePieces();
    setupBlackPieces();


}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeGrid()
{
    // Resize the gridLabels array
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            QLabel* label = new QLabel(this);
            int x = 35 + col * gridSize;
            int y = 36 + row * gridSize;
            label->setGeometry(x, y, gridSize, gridSize);
            label->setAlignment(Qt::AlignCenter);  // Optional: Center text in QLabel
            label->setFrameStyle(QFrame::Box);    // Optional: Add a border to the QLabel
            gridLabels[row][col] = label;
        }
    }


}


QPoint MainWindow::getGridCoordinates(const QPoint &position)
{
    // Find the grid coordinates for a given position
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            if (gridLabels[row][col]->geometry().contains(position)) {
                return QPoint(row, col);
            }
        }
    }
    return QPoint(-1, -1);  // Invalid coordinates
}

void MainWindow::setupWhitePieces()
{
    // Loop through each square on the chessboard and set up white pieces
    for (int row = 6; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            QLabel *pieceLabel = gridLabels[row][col];
            QPixmap piecePixmap;

            // Example: Set up white pawn on the second row
            if (row == 6) {
                piecePixmap.load("D:/School/Chess/ITU-Chess/Resources/White/pawn.png");
            }
            // Example: Set up white rook on the first row
            else if (row == 7 && (col == 0 || col == numCols - 1)) {
                piecePixmap.load("D:/School/Chess/ITU-Chess/Resources/White/rook.png");
            }
            // Example: Set up white knight on the first row
            else if (row == 7 && (col == 1 || col == numCols - 2)) {
                piecePixmap.load("D:/School/Chess/ITU-Chess/Resources/White/knight.png");
            }
            // Example: Set up white bishop on the first row
            else if (row == 7 && (col == 2 || col == numCols - 3)) {
                piecePixmap.load("D:/School/Chess/ITU-Chess/Resources/White/bishop.png");
            }
            // Example: Set up white queen on the first row
            else if (row == 7 && col == numCols - 4) {
                piecePixmap.load("D:/School/Chess/ITU-Chess/Resources/White/queen.png");
            }
            // Example: Set up white king on the first row
            else if (row == 7 && col == numCols - 5) {
                piecePixmap.load("D:/School/Chess/ITU-Chess/Resources/White/king.png");
            }

            // Resize the piece
            piecePixmap = piecePixmap.scaled(figureSize, figureSize, Qt::KeepAspectRatio);
            pieceLabel->setPixmap(piecePixmap);
        }
    }
}

void MainWindow::setupBlackPieces()
{
    // Loop through each square on the chessboard and set up black pieces
    for (int row = 0; row < 2; ++row) {
        for (int col = 0; col < numCols; ++col) {

            QLabel *pieceLabel = gridLabels[row][col];
            QPixmap piecePixmap;

            // Example: Set up black pawn on the second to last row
            if (row == 1) {
                piecePixmap.load("D:/School/Chess/ITU-Chess/Resources/Black/pawn.png");
            }
            // Example: Set up black rook on the last row
            else if (row == 0 && (col == 0 || col == numCols - 1)) {
                piecePixmap.load("D:/School/Chess/ITU-Chess/Resources/Black/rook.png");
            }
            // Example: Set up black knight on the last row
            else if (row == 0 && (col == 1 || col == numCols - 2)) {
                piecePixmap.load("D:/School/Chess/ITU-Chess/Resources/Black/knight.png");
            }
            // Example: Set up black bishop on the last row
            else if (row == 0 && (col == 2 || col == numCols - 3)) {
                piecePixmap.load("D:/School/Chess/ITU-Chess/Resources/Black/bishop.png");
            }
            // Example: Set up black queen on the last row
            else if (row == 0 && col == numCols - 4) {
                piecePixmap.load("D:/School/Chess/ITU-Chess/Resources/Black/queen.png");
            }
            // Example: Set up black king on the last row
            else if (row == 0 && col == numCols - 5) {
                piecePixmap.load("D:/School/Chess/ITU-Chess/Resources/Black/king.png");
            }

            // Resize the piece
            piecePixmap = piecePixmap.scaled(figureSize, figureSize, Qt::KeepAspectRatio);

            pieceLabel->setPixmap(piecePixmap);
        }
            // TODO: Add more conditions to set up other black pieces as needed
    }
}

void MainWindow::movePiece(int x, int y, int xDest, int yDest)
{
    // Assuming you have a 2D array of QLabel pointers representing the chessboard
    QLabel *selectedPiece = gridLabels[x][y];

    // Check if the destination coordinates are within bounds
    if (xDest >= 0 && xDest < numRows && yDest >= 0 && yDest < numCols) {
        // Move the piece to the destination coordinates
        gridLabels[xDest][yDest]->setPixmap(selectedPiece->pixmap());
        // Optionally, clear the pixmap at the source coordinates to remove the original piece
        selectedPiece->clear();
    } else {
        qDebug() << "Invalid destination coordinates.";
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    QPoint gridCoordinates = getGridCoordinates(event->pos());

    qDebug() << "Clicked on grid coordinates:" << gridCoordinates;

    // Emit a signal to notify the ConnectionManager about the mouse press event
    emit mousePressed(gridCoordinates);

}

