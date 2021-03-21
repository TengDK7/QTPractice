#pragma once

#include <QDialog>
#include<qtoolbar.h>
#include "ui_DrawFunctionDlg.h"

enum ActionType
{
	NONE=0,
	LINE,
	RECT,
	CIRCLE,
	PICTURE,
	TEXT
};
class DrawFunctionDlg : public QDialog
{
	Q_OBJECT

public:
	DrawFunctionDlg(QWidget *parent = Q_NULLPTR);
	~DrawFunctionDlg();
private:
	void InitControl();

private:
	Ui::DrawFunctionDlg ui;
	ActionType curAction = ActionType::NONE;
	QToolBar* toolBar = new QToolBar(this);

protected:
	void paintEvent(QPaintEvent* info);

private slots:
	void actionTriggered(QAction* action);
};
