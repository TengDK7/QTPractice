#pragma once

#include <QDialog>
#include<qmediaplayer.h>
#include<qvideowidget.h>
#include<QBoxLayout.h>
#include "ui_VidioPalyDlg.h"

class VidioPalyDlg : public QDialog
{
	Q_OBJECT

public:
	VidioPalyDlg(QWidget *parent = Q_NULLPTR);
	~VidioPalyDlg();

private:
	Ui::VidioPalyDlg ui;

	QMediaPlayer* player = nullptr;
	QVBoxLayout* layout = nullptr;
	QVideoWidget* vw = nullptr;

private:
	void InitControls();

private slots:
	void addFileClick();
	void addDirClick();
	void playClick();
	void stopClick();
	void nextClick();
	void volumnSlidChange(int);
	void playSlidChange();
	void speedCombChange(int value);
};
