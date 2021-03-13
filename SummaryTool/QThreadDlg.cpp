#include "QThreadDlg.h"
#include"pthread.h"
#include<thread>

pthread_t sid1;
pthread_t sid2;
pthread_t sid3;

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
		pthread_testcancel();
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
		pthread_testcancel();
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
		pthread_testcancel();
	}
	return 0;
}

void QThreadDlg::startone()
{
	pthread_create(&sid1, NULL, threadone, (void*)&ui);
}
void QThreadDlg::starttwo()
{
	pthread_create(&sid2, NULL, threadtwo, (void*)&ui);
}

void QThreadDlg::startthree()
{
	pthread_create(&sid3, NULL, threadthree, (void*)&ui);
}

void QThreadDlg::endone()
{
	pthread_cancel(sid1);
}

void QThreadDlg::endtwo()
{
	pthread_cancel(sid2);
}

void QThreadDlg::endthree()
{
	pthread_cancel(sid3);
}
