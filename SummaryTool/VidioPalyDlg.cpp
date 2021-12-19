#include "VidioPalyDlg.h"
#include"qfiledialog.h"

#define z QString::fromLocal8Bit

VidioPalyDlg::VidioPalyDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	InitControls();
}

VidioPalyDlg::~VidioPalyDlg()
{
}

void VidioPalyDlg::InitControls()
{
	this->setFixedHeight(this->height());
	this->setFixedWidth(this->width());

	ui.vidioListView->setModel(playListModel);
	ui.vidioListView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
	ui.vidioListView->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
	ui.vidioListView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
	connect(ui.vidioListView, SIGNAL(pressed(const QModelIndex&)), this, SLOT(videoListPressed(const QModelIndex&)));

	layout->addWidget(vw);
	ui.vidiowidget->setLayout(layout);
	player->setVideoOutput(vw);
	ao->setVolume(30);
	player->setAudioOutput(ao);
	player->setPlaybackRate(1);
	connect(player, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(playerStateChange(QMediaPlayer::State)));
	connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(playerPositonChange(qint64)));
	connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(playerDurationChange(qint64)));

	connect(ui.comboBoxSpeed, SIGNAL(currentIndexChanged(int)), this, SLOT(speedCombChange(int)));

	ui.volumnSlider->setRange(0, 100);
	ui.volumnSlider->setValue(30);
	connect(ui.volumnSlider, SIGNAL(valueChanged(int)), this, SLOT(volumnSlidChange(int)));

	ui.playSlider->setRange(0, 100);
	ui.playSlider->setValue(0);
	connect(ui.playSlider, SIGNAL(sliderReleased()), this, SLOT(playSlidChange()));

	connect(ui.pushButtonAddDir, SIGNAL(clicked()), this, SLOT(addDirClick()));
	connect(ui.pushButtonAddFile, SIGNAL(clicked()), this, SLOT(addFileClick()));
	connect(ui.pushButtonStart, SIGNAL(clicked()), this, SLOT(playClick()));
	connect(ui.pushButtonStop, SIGNAL(clicked()), this, SLOT(stopClick()));
	connect(ui.pushButtonNext, SIGNAL(clicked()), this, SLOT(nextClick()));
}
void VidioPalyDlg::closeEvent(QCloseEvent*)
{
	player->stop();
}
void VidioPalyDlg::videoListPressed(const QModelIndex& index)
{
	auto item = playListModel->item(index.row());//从数据模型中取数据
	auto filepath = item->data().toString();
	player->setSource(QUrl::fromLocalFile(filepath));
	player->play();
}
#pragma region 播放槽
void VidioPalyDlg::playerStateChange(QMediaPlayer::PlaybackState state)
{
	switch (state)
	{
	case QMediaPlayer::StoppedState:
		ui.pushButtonStart->setText(z("播放"));
		break;
	case QMediaPlayer::PlayingState:
		ui.pushButtonStart->setText(z("暂停"));
		break;
	case QMediaPlayer::PausedState:
		ui.pushButtonStart->setText(z("播放"));
		break;
	default:
		break;
	}
}
void VidioPalyDlg::playerPositonChange(qint64 value)
{
	ui.playSlider->setValue(value / 1000);
}
void VidioPalyDlg::playerDurationChange(qint64 value)
{
	ui.playSlider->setRange(0, value / 1000);//秒
	ui.playSlider->setValue(0);
}
#pragma endregion


#pragma region 响应槽
void VidioPalyDlg::addFileClick()
{
	auto filepath = QFileDialog::getOpenFileName(this, z("选择文件"), ".", z("mp4文件(*.mp4)"));
	if (QFile::exists(filepath))
	{
		QFileInfo file(filepath);
		auto filename = file.fileName();
		
		auto item = new QStandardItem(filename);
		item->setData(filepath);//向数据模型中存数据
		playListModel->appendRow(item);
	}
}
QFileInfoList GetFileLists(QString path)
{
	QDir dir(path);
	QFileInfoList file_list = dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
	QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);

	for (int i = 0; i != folder_list.size(); i++)
	{
		QString name = folder_list.at(i).absoluteFilePath();
		QFileInfoList child_file_list = GetFileLists(name);
		file_list.append(child_file_list);
	}

	return file_list;
}
void VidioPalyDlg::addDirClick()
{
	QFileDialog* dlg = new QFileDialog();
	dlg->setModal(true);
	dlg->setFileMode(QFileDialog::FileMode::Directory);
	if (dlg->exec() == QFileDialog::Accepted)
	{
		auto path = dlg->selectedFiles()[0];
		auto files = GetFileLists(path);

		playListModel->clear();
		for each (auto file in files)
		{
			auto filename = file.fileName();
			if (!filename.endsWith(".mp4"))
				continue;
			
			auto item = new QStandardItem(filename);
			item->setData(file.filePath()); 
			playListModel->appendRow(item);
		}
	}
}

void VidioPalyDlg::playClick()
{
	auto text = ui.pushButtonStart->text();
	if (text == z("播放"))
	{
		player->play();
		ui.pushButtonStart->setText(z("暂停"));
	}
	else if (text == z("暂停"))
	{
		player->pause();
		ui.pushButtonStart->setText(z("播放"));
	}
}

void VidioPalyDlg::stopClick()
{
	player->stop();
}

void VidioPalyDlg::nextClick()
{
	auto len = playListModel->rowCount();
	if (len == 0)
		return;
	auto index = ui.vidioListView->currentIndex().row();
	if (index < len - 1)
	{
		index += 1;
	}
	else if (index == len - 1)
	{
		index = 0;
	}
	auto qindex = playListModel->index(index, 0);
	ui.vidioListView->setCurrentIndex(qindex);
	auto itemdata = playListModel->item(index);
	auto path = itemdata->data().toString();
	player->setSource(QUrl::fromLocalFile(path));
	player->play();
}

void VidioPalyDlg::volumnSlidChange(int value)
{
	ao->setVolume(value);
}

void VidioPalyDlg::playSlidChange()
{
	auto value = ui.playSlider->value() * 1000;
	player->setPosition(value);
}

void VidioPalyDlg::speedCombChange(int value)
{
	if (value == 0)
	{
		player->setPlaybackRate(1);
	}
	else if (value == 1)
	{
		player->setPlaybackRate(1.25);
	}
	else if (value == 2)
	{
		player->setPlaybackRate(1.5);
	}
}
#pragma endregion

