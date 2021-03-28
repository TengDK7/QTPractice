#pragma once

#include <QDialog>
#include "ui_ImportLibraryDlg.h"

class ImportLibraryDlg : public QDialog
{
	Q_OBJECT

public:
	ImportLibraryDlg(QWidget *parent = Q_NULLPTR);
	~ImportLibraryDlg();

private:
	Ui::ImportLibraryDlg ui;

private	slots:
	void loadlibrary1();
	void loadlibrary2();
	void loadlibrary3();
	void loadlibrary4();
	void loadlibrary5();
	void loadlibrary6();
	void loadlibrary7();
	void loadlibrary8();
	void loadlibrary9();
	
};
