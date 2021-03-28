#pragma once

#include <QDialog>
#include "ui_LayoutDlg.h"

class LayoutDlg : public QDialog
{
	Q_OBJECT

public:
	LayoutDlg(QWidget *parent = Q_NULLPTR);
	~LayoutDlg();

private:
	Ui::LayoutDlg ui;
};
