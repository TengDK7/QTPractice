#pragma once

#include <QDialog>
#include "ui_DrawFunctionDlg.h"

class DrawFunctionDlg : public QDialog
{
	Q_OBJECT

public:
	DrawFunctionDlg(QWidget *parent = Q_NULLPTR);
	~DrawFunctionDlg();

private:
	Ui::DrawFunctionDlg ui;
};
