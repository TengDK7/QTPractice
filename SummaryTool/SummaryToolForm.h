#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SummaryTool.h"

class SummaryToolForm : public QMainWindow
{
    Q_OBJECT

public:
    SummaryToolForm(QWidget *parent = Q_NULLPTR);
private:
    void InitMenu();
    void InitStatusBar();
    void InitToolBar();

private:
    Ui::SummaryToolClass ui;


private slots:
    void trigerMenu(QAction* action);
    void openFile();
    void closeFIle();
    void statusBtnClick();
    void openthreaddlg();
    void opendrawfundlg();
    void openmusicplayldg();
    void openvidioplaydlg();
};
