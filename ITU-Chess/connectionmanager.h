// ConnectionManager.h
#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <QObject>
#include <QPoint>
#include "GameInterface.h"

class GameInterface;
class MainWindow;

class ConnectionManager : public QObject
{
    Q_OBJECT

public:
    explicit ConnectionManager(QObject *parent = nullptr);

    void connectGameInterface(GameInterface *gameInterface);
    void connectMainWindow(MainWindow *mainWindow);

private slots:
    void handlePieceSelection(const QPoint &gridCoordinates);
private:
    GameInterface* gi;
};

#endif // CONNECTIONMANAGER_H
