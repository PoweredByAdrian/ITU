#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QVector>
#include <QPoint>
#include <QMouseEvent>
#include <QPainter>
#include "connectionmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void mousePressed(const QPoint &gridCoordinates);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::MainWindow *ui;

    ConnectionManager* cm;

    //movePiece(QLabel *pieceLabel, const QPoint &newPosition);

    QLabel *backgroundLabel;

    // Define grid parameters
    int gridSize = 79;
    int numRows = 8;
    int numCols = 8;

    int boardSize = 700;
    int figureSize = 78;

    // 2D vector to represent the grid
    QVector<QVector<QRect>> grid;

    // Function to initialize the grid
    void initializeGrid();

    // Function to get the grid coordinates for a given position
    QPoint getGridCoordinates(const QPoint &position);

    // Function to set up pieces on the chessboard
    void setupWhitePieces();
    void setupBlackPieces();

    // Function to draw borders for each square on the chessboard
    void drawGridBorders();

    // Declare a 2D array of QLabel pointers
    QLabel* gridLabels[8][8];

    void movePiece(int x, int y, int xDest, int yDest);


};
#endif // MAINWINDOW_H
