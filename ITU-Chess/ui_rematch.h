/**
 * @file ui_rematch.h
 *
 * @brief Header file for the ui_rematch class
 *
 * The ui_Rematch class represents the UI for the rematch dialog.
 * It is part of the user interface generated by Qt Designer.
 *
 * @author Adrian Horvath (xhorva14)
 */

#ifndef UI_REMATCH_H
#define UI_REMATCH_H

#include <QWidget>

namespace Ui {
class ui_Rematch;
}

class ui_Rematch : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a ui_Rematch instance.
     * @param parent The parent QWidget.
     */
    explicit ui_Rematch(QWidget *parent = nullptr);

    /**
     * @brief Destroys the ui_Rematch instance.
     */
    ~ui_Rematch();

private:
    Ui::ui_Rematch *ui;
};

#endif // UI_REMATCH_H