#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GUILearn.h"

class GUILearn : public QMainWindow
{
    Q_OBJECT

public:
    GUILearn(QWidget *parent = Q_NULLPTR);

private:
    Ui::GUILearnClass ui;

public slots:
    void okClick();
    void closeClick();
};
