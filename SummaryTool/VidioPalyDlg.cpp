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
	player = new QMediaPlayer();
	vw = new QVideoWidget();
	layout = new QVBoxLayout();

	layout->addWidget(vw);
	ui.vidiowidget->setLayout(layout);
	player->setVideoOutput(vw);


	connect(ui.comboBoxSpeed, SIGNAL(currentIndexChanged(int)), this, SLOT(speedCombChange(int)));

	connect(ui.volumnSlider, SIGNAL(valueChanged(int)), this, SLOT(volumnSlidChange(int)));

	connect(ui.playSlider, SIGNAL(sliderReleased()), this, SLOT(playSlidChange()));

	connect(ui.pushButtonAddDir, SIGNAL(clicked()), this, SLOT(addDirClick()));

	connect(ui.pushButtonAddFile, SIGNAL(clicked()), this, SLOT(addFileClick()));

	connect(ui.pushButtonStart, SIGNAL(clicked()), this, SLOT(playClick()));

	connect(ui.pushButtonStop, SIGNAL(clicked()), this, SLOT(stopClick()));

	connect(ui.pushButtonNext, SIGNAL(clicked()), this, SLOT(nextClick()));
}

#pragma region 响应槽
void VidioPalyDlg::addFileClick()
{
	auto filepath = QFileDialog::getOpenFileName(this, z("选择文件"), ".", z("mp4文件(*.mp4)"));
	if (QFile::exists(filepath))
	{
		player->setMedia(QUrl::fromLocalFile(filepath));
	}
}

void VidioPalyDlg::addDirClick()
{

}

void VidioPalyDlg::playClick()
{
	player->play();
	ui.vidiowidget->show();
}

void VidioPalyDlg::stopClick()
{

}

void VidioPalyDlg::nextClick()
{

}

void VidioPalyDlg::volumnSlidChange(int)
{

}

void VidioPalyDlg::playSlidChange()
{

}

void VidioPalyDlg::speedCombChange(int value)
{

}
#pragma endregion

