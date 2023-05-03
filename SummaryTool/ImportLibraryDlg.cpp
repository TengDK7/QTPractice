#include "ImportLibraryDlg.h"
#include"qmessagebox.h"
#define z QString::fromUtf8

//�����MyDll_D1(����һ)
#include"../MyDll_D1/Math.h"
#pragma comment(lib,"MyDll_D1.lib")//��Ŀ���Ը��ӿ�Ŀ¼���lib����Ŀ¼

//�����MyDll_D2(������)
#include"../MyDll_D2/Math.h" //����Ŀ��ֱ�����MyDll_D2.lib
extern int renamereduce(int, int);//reduce_d2��def�б��������ˣ�Ҫʹ���������ĺ�����Ҫ�ⲿ����


ImportLibraryDlg::ImportLibraryDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton1, SIGNAL(clicked()), this, SLOT(loadlibrary1()));
	connect(ui.pushButton2, SIGNAL(clicked()), this, SLOT(loadlibrary2()));
	connect(ui.pushButton3, SIGNAL(clicked()), this, SLOT(loadlibrary3()));
	connect(ui.pushButton4, SIGNAL(clicked()), this, SLOT(loadlibrary4()));
	connect(ui.pushButton5, SIGNAL(clicked()), this, SLOT(loadlibrary5()));
	connect(ui.pushButton6, SIGNAL(clicked()), this, SLOT(loadlibrary6()));
	connect(ui.pushButton7, SIGNAL(clicked()), this, SLOT(loadlibrary7()));
	connect(ui.pushButton8, SIGNAL(clicked()), this, SLOT(loadlibrary8()));
	connect(ui.pushButton9, SIGNAL(clicked()), this, SLOT(loadlibrary9()));
}

ImportLibraryDlg::~ImportLibraryDlg()
{

}

void ImportLibraryDlg::loadlibrary1()
{
	auto result = add_d1(1, 2);
	QMessageBox::information(this, z("add_d1"), "1 + 2 = " + QString::number(result));


	result = reduce_d1(1, 2);
    QMessageBox::information(this, z("reduce_d1"), "1 - 2 = " + QString::number(result));


	result = reduce_d1(2.5, 4.732);//����double ������Ч
	QMessageBox::information(this, z("reduce_d1"), "2.5 - 4.732 =" + QString::number(result));


	//multiply_d1δ�������������޷��������ⲿ����
	//result = multiply_d1(1, 2);
	//QMessageBox::information(this, z("multiply_d1"), "1*2=" + QString::number(result));
}
void ImportLibraryDlg::loadlibrary2()
{
	auto result = add_d2(2, 3);
	QMessageBox::information(this, z("add_d2"), "2 + 3 = " + QString::number(result));


	result = renamereduce(2, 3);//reduce_d2��def�б��������ˣ�Ҫʹ���������ĺ�����Ҫ�ⲿ����
    QMessageBox::information(this, z("renamereduce"), "2 - 3 = " + QString::number(result));


	//reduce_d2��def�б��������ˣ��޷�ֱ��ʹ�ã������޷��������ⲿ����
	//result = reduce_d2(2, 3);
	//QMessageBox::information(this, z("reduce_d2"), "2 - 3 = " + QString::number(result));
 

	//multiply_d2δ�������������޷��������ⲿ����
	//result = multiply_d2(2, 3);
    //QMessageBox::information(this, z("multiply_d2"), "2 * 3 = " + QString::number(result));
}

void ImportLibraryDlg::loadlibrary3()
{
}

void ImportLibraryDlg::loadlibrary4()
{
}

void ImportLibraryDlg::loadlibrary5()
{
}

void ImportLibraryDlg::loadlibrary6()
{
}

void ImportLibraryDlg::loadlibrary7()
{
}

void ImportLibraryDlg::loadlibrary8()
{
}

void ImportLibraryDlg::loadlibrary9()
{
}
