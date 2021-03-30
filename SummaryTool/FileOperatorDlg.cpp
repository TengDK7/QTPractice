#include "FileOperatorDlg.h"

FileOperatorDlg::FileOperatorDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButtonNew, SIGNAL(clicked()), this, SLOT(newFile()));
	connect(ui.pushButtonOpen, SIGNAL(clicked()), this, SLOT(openFile()));
	connect(ui.pushButtonSave, SIGNAL(clicked()), this, SLOT(saveFile()));
	connect(ui.pushButtonSaveAs, SIGNAL(clicked()), this, SLOT(saveFileAs()));
	connect(ui.pushButtonRename, SIGNAL(clicked()), this, SLOT(renameFile()));
	connect(ui.pushButtonCopy, SIGNAL(clicked()), this, SLOT(copyFile()));
	connect(ui.pushButtonDelete, SIGNAL(clicked()), this, SLOT(deleteFile()));
}

FileOperatorDlg::~FileOperatorDlg()
{
}

void FileOperatorDlg::newFile()
{

}
void FileOperatorDlg::openFile()
{
}

void FileOperatorDlg::saveFile()
{
}

void FileOperatorDlg::saveFileAs()
{
}

void FileOperatorDlg::renameFile()
{
}

void FileOperatorDlg::copyFile()
{
}

void FileOperatorDlg::deleteFile()
{
}
