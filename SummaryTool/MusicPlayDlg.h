#pragma once

#include <QDialog>
#include<QtMultimedia/qmediaplayer.h>
#include<qstringlistmodel.h>
#include "ui_MusicPlayDlg.h"

class MusicPlayDlg : public QDialog
{
	Q_OBJECT

public:
	MusicPlayDlg(QWidget *parent = Q_NULLPTR);
	~MusicPlayDlg();

private:
	Ui::MusicPlayDlg ui;
	QMediaPlayer* player;
	QStringListModel* listModel;
	QStringList strlist;
private:
	void InitCtrlStatus();

protected:
	void closeEvent(QCloseEvent*) override;
	
private slots:
	void buttonBrowserClick();
	void buttonStartClick();
	void buttonStopClick();
	void buttonNextClick();
	void buttonPreClick();
	void playerPositonChange(qint64 position);
	void playerDurationChange(qint64 len);
	void columnSliderValueChange(int value);
	void combCurIndexChange(int index);
	void playerStateChange(QMediaPlayer::State state);
	void listViewDoubleClick(const QModelIndex& index);
};
