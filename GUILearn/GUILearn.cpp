#include "GUILearn.h"
#include"qmessagebox.h"

GUILearn::GUILearn(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(okClick()));
    connect(ui.pushButton_1, SIGNAL(clicked()), this, SLOT(closeClick()));
}

void GUILearn::closeClick()
{
    QMessageBox::information(this, "Tip", "click close button", QMessageBox::Ok);
}
void GUILearn::okClick()
{
    QMessageBox::information(this, "Tip", "click ok button", QMessageBox::Ok);
}
