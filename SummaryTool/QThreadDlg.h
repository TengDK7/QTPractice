#pragma once

#include <QDialog>
#include "ui_QThreadDlg.h"

class QThreadDlg : public QDialog
{
	Q_OBJECT

public:
	QThreadDlg(QDialog*parent = Q_NULLPTR);
	~QThreadDlg();

private:
	Ui::QThreadDlg ui;
private slots:
	void startone();
	void starttwo();
	void startthree();

	void endone();
	void endtwo();
	void endthree();
};
