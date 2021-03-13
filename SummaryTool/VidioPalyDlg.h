#pragma once

#include <QDialog>
#include "ui_VidioPalyDlg.h"

class VidioPalyDlg : public QDialog
{
	Q_OBJECT

public:
	VidioPalyDlg(QWidget *parent = Q_NULLPTR);
	~VidioPalyDlg();

private:
	Ui::VidioPalyDlg ui;
};
