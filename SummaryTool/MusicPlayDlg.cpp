#include "MusicPlayDlg.h"
#include"qfiledialog.h"


#define z QString::fromLocal8Bit

MusicPlayDlg::MusicPlayDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this); 
	InitCtrlStatus();
}

MusicPlayDlg::~MusicPlayDlg()
{
}
#pragma region 初始化元素
/// <summary>
/// 初始化
/// </summary>
void MusicPlayDlg::InitCtrlStatus()
{
	//cur dlg init
	this->setFixedHeight(this->height());
	this->setFixedWidth(this->width());

	//listModel init
	listModel = new QStringListModel(this);
	listModel->setStringList(strlist);

	//listview init
	ui.musicListView->setModel(listModel);
	ui.musicListView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
	ui.musicListView->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
	ui.musicListView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
	connect(ui.musicListView, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(listViewDoubleClick(const QModelIndex&)));

	//music player init
	player = new QMediaPlayer();
	player->setVolume(30);
	player->setPlaybackRate(1);
	connect(player, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(playerStateChange(QMediaPlayer::State)));
	connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(playerPositonChange(qint64)));
	connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(playerDurationChange(qint64)));

	//play rate init
	ui.comboBox->setCurrentIndex(0);
	connect(ui.comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(combCurIndexChange(int)));

	//columnslider init
	ui.columnSlider->setRange(0, 100);
	ui.columnSlider->setValue(30);
	connect(ui.columnSlider, SIGNAL(valueChanged(int)), this, SLOT(columnSliderValueChange(int)));

	//buttons init
	connect(ui.pushButtonbrowser, SIGNAL(clicked()), this, SLOT(buttonBrowserClick()));
	connect(ui.pushButtonpausestart, SIGNAL(clicked()), this, SLOT(buttonStartClick()));
	connect(ui.pushButtonstop, SIGNAL(clicked()), this, SLOT(buttonStopClick()));
	connect(ui.pushButtonNext, SIGNAL(clicked()), this, SLOT(buttonNextClick()));
	connect(ui.pushButtonPre, SIGNAL(clicked()), this, SLOT(buttonPreClick()));
}
#pragma endregion

#pragma region 按钮响应
/// <summary>
/// 播放按钮点击
/// </summary>
void MusicPlayDlg::buttonStartClick()
{
	if (ui.pushButtonpausestart->text() == z("播放"))
	{
		player->play();
		ui.pushButtonpausestart->setText(z("暂停"));
	}
	else if (ui.pushButtonpausestart->text() == z("暂停"))
	{
		player->pause();
		ui.pushButtonpausestart->setText(z("播放"));
	}
}
/// <summary>
/// 响应停止按钮点击
/// </summary>
void MusicPlayDlg::buttonStopClick()
{
	player->stop();
}
/// <summary>
/// 下一首
/// </summary>
void MusicPlayDlg::buttonNextClick()
{
	auto len = listModel->rowCount();//和listview的children数量不一致
	if (len == 0)
		return;
	auto cur = ui.musicListView->currentIndex().row();
	if (cur < len - 1)
	{
		cur += 1;
	}
	else if (cur == len - 1)
	{
		cur = 0;
	}
	auto index = listModel->index(cur);
	ui.musicListView->setCurrentIndex(index);
	auto data = listModel->data(index);
	player->setMedia(QUrl::fromLocalFile(data.toString()));
	player->play();
}
/// <summary>
/// 上一首
/// </summary>
void MusicPlayDlg::buttonPreClick()
{
	auto len = listModel->rowCount();
	if (len == 0)
		return;
	auto cur = ui.musicListView->currentIndex().row();
	if (cur > 0)
	{
		cur -= 1;
	}
	else if (cur == 0)
	{
		cur = len - 1;
	}
	auto index = listModel->index(cur);
	ui.musicListView->setCurrentIndex(index);
	auto data = listModel->data(index);
	player->setMedia(QUrl::fromLocalFile(data.toString()));
	player->play();
}
/// <summary>
/// 获取目录下所有文件
/// </summary>
/// <param name="path"></param>
/// <returns></returns>
QFileInfoList GetFileList(QString path)
{
	QDir dir(path);
	QFileInfoList file_list = dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
	QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);

	for (int i = 0; i != folder_list.size(); i++)
	{
		QString name = folder_list.at(i).absoluteFilePath();
		QFileInfoList child_file_list = GetFileList(name);
		file_list.append(child_file_list);
	}

	return file_list;
}
/// <summary>
/// 选择目录按钮点击
/// </summary>
void MusicPlayDlg::buttonBrowserClick()
{
	auto dlg = new QFileDialog(this);
	dlg->setFileMode(QFileDialog::FileMode::DirectoryOnly);
	dlg->setDirectory(".");
	auto res = dlg->exec();
	if (res == QFileDialog::Accepted)
	{
		auto path = dlg->selectedFiles()[0];
		auto files = GetFileList(path);

		strlist.clear();

		for each (auto file in files)
		{
			auto fullpath = file.fileName();
			if (!fullpath.endsWith(".mp3") && !fullpath.endsWith(".wav"))
				continue;
			strlist << file.fileName();
		}
		listModel->setStringList(strlist);//需要重新设置，因为此函数是复制后set

		int index = 0;
		for each (auto file in files)
		{
			auto fullpath = file.fileName();
			if (!fullpath.endsWith(".mp3") && !fullpath.endsWith(".wav"))
				continue;

			auto sel = listModel->index(index);
			listModel->setData(sel, file.filePath());
			index++;
		}
	}
}
#pragma endregion

#pragma region 信号响应
/// <summary>
/// 响应播放时长变化
/// </summary>
/// <param name="position"></param>
void MusicPlayDlg::playerPositonChange(qint64 position)
{
	ui.musicprogress->setValue(position / 1000);
}
/// <summary>
/// 资源时长变化（响应切换播放资源）
/// </summary>
/// <param name="len"></param>
void MusicPlayDlg::playerDurationChange(qint64 len)
{
	ui.musicprogress->setRange(0, len / 1000);//转化为秒
	ui.musicprogress->setValue(0);
}
/// <summary>
/// 响应音量变化
/// </summary>
/// <param name="value"></param>
void MusicPlayDlg::columnSliderValueChange(int value)
{
	player->setVolume(value);
}
/// <summary>
/// 响应播放速度变化
/// </summary>
/// <param name="index"></param>
void MusicPlayDlg::combCurIndexChange(int index)
{
	switch (index)
	{
	case 0:
		player->setPlaybackRate(1);
		break;
	case 1:
		player->setPlaybackRate(1.25);
		break;
	case 2:
		player->setPlaybackRate(1.5);
		break;
	default:
		break;
	}
}
/// <summary>
/// 响应播放状态变化
/// </summary>
/// <param name="state"></param>
void MusicPlayDlg::playerStateChange(QMediaPlayer::State state)
{
	switch (state)
	{
	case QMediaPlayer::StoppedState:
		ui.pushButtonpausestart->setText(z("播放"));
		break;
	case QMediaPlayer::PlayingState:
		ui.pushButtonpausestart->setText(z("暂停"));
		break;
	case QMediaPlayer::PausedState:
		ui.pushButtonpausestart->setText(z("播放"));
		break;
	default:
		break;
	}
}
/// <summary>
/// 手动选择歌曲
/// </summary>
/// <param name="index"></param>
void MusicPlayDlg::listViewDoubleClick(const QModelIndex& index)
{
	auto date = listModel->data(index);
	player->setMedia(QUrl::fromLocalFile(date.toString()));
	player->play();
}
#pragma endregion

/// <summary>
/// 重写窗口关闭事件
/// </summary>
/// <param name=""></param>
void MusicPlayDlg::closeEvent(QCloseEvent*)
{
	player->stop();
}
