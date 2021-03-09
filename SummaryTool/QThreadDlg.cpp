#include "QThreadDlg.h"
#include"pthread.h"
#include<thread>

QThreadDlg::QThreadDlg(QDialog*parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton11, SIGNAL(clicked()), this, SLOT(startone()));
	connect(ui.pushButton12, SIGNAL(clicked()), this, SLOT(endone()));
	connect(ui.pushButton21, SIGNAL(clicked()), this, SLOT(starttwo()));
	connect(ui.pushButton22, SIGNAL(clicked()), this, SLOT(endtwo()));
	connect(ui.pushButton31, SIGNAL(clicked()), this, SLOT(startthree()));
	connect(ui.pushButton32, SIGNAL(clicked()), this, SLOT(endthree()));
}

QThreadDlg::~QThreadDlg()
{
}
void* threadone(void* arg)
{
	auto mui = (Ui::QThreadDlg*)arg;
	int i = 0;
	while (i<20)
	{
		mui->label12->setText(QString::number(i));
		i++;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	return 0;
}
void* threadtwo(void* arg)
{
	auto mui = (Ui::QThreadDlg*)arg;
	int i = 0;
	while (i < 20)
	{
		mui->label22->setText(QString::number(i));
		i++;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	return 0;
}
void* threadthree(void* arg)
{
	auto mui = (Ui::QThreadDlg*)arg;
	int i = 0;
	while (i < 20)
	{
		mui->label32->setText(QString::number(i));
		i++;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	return 0;
}
void QThreadDlg::startone()
{
	pthread_t sid;
	pthread_create(&sid, NULL, threadone, (void*)&ui);
}
void QThreadDlg::starttwo()
{
	pthread_t sid;
	pthread_create(&sid, NULL, threadtwo, (void*)&ui);
}

void QThreadDlg::startthree()
{
	pthread_t sid;
	pthread_create(&sid, NULL, threadthree, (void*)&ui);
}

void QThreadDlg::endone()
{
}

void QThreadDlg::endtwo()
{
}

void QThreadDlg::endthree()
{
}
