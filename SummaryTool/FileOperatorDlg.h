#pragma once

#include <QDialog>
#include "ui_FileOperatorDlg.h"

class FileOperatorDlg : public QDialog
{
	Q_OBJECT

public:
	FileOperatorDlg(QWidget *parent = Q_NULLPTR);
	~FileOperatorDlg();

private:
	Ui::FileOperatorDlg ui;

private slots:
	void newFile();
	void openFile();
	void saveFile();
	void saveFileAs();
	void renameFile();
	void copyFile();
	void deleteFile();
};
