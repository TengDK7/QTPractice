#pragma once

#include <QDialog>
#include<qmediaplayer.h>
#include<qvideowidget.h>
#include<QBoxLayout.h>
#include<qstandarditemmodel.h>
#include "ui_VidioPalyDlg.h"

class VidioPalyDlg : public QDialog
{
	Q_OBJECT

public:
	VidioPalyDlg(QWidget *parent = Q_NULLPTR);
	~VidioPalyDlg();

private:
	Ui::VidioPalyDlg ui;

	QMediaPlayer* player = new QMediaPlayer();
	QVBoxLayout* layout = new QVBoxLayout();
	QVideoWidget* vw = new QVideoWidget();

	QStandardItemModel* playListModel = new QStandardItemModel(this);

private:
	void InitControls();

protected:
	void closeEvent(QCloseEvent*) override;

private slots:
	void addFileClick();
	void addDirClick();
	void playClick();
	void stopClick();
	void nextClick();
	void volumnSlidChange(int value);
	void playSlidChange();
	void speedCombChange(int value);

	void playerStateChange(QMediaPlayer::State state);
	void playerPositonChange(qint64 value);
	void playerDurationChange(qint64 value);

	void videoListPressed(const QModelIndex& index);
};
