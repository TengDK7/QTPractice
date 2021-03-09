#pragma once

#include <QWidget>
#include "ui_DrawFunctionDlg.h"

class DrawFunctionDlg : public QWidget
{
	Q_OBJECT

public:
	DrawFunctionDlg(QWidget *parent = Q_NULLPTR);
	~DrawFunctionDlg();

private:
	Ui::DrawFunctionDlg ui;
};
