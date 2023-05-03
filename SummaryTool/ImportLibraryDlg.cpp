#include "ImportLibraryDlg.h"
#include"qmessagebox.h"
#define z QString::fromUtf8

//载入库MyDll_D1(方法一)
#include"../MyDll_D1/Math.h"
#pragma comment(lib,"MyDll_D1.lib")//项目属性附加库目录添加lib所在目录

//载入库MyDll_D2(方法二)
#include"../MyDll_D2/Math.h" //在项目中直接添加MyDll_D2.lib
extern int renamereduce(int, int);//reduce_d2在def中被重命名了，要使用重命名的函数需要外部申明


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


	result = reduce_d1(2.5, 4.732);//重载double 函数无效
	QMessageBox::information(this, z("reduce_d1"), "2.5 - 4.732 =" + QString::number(result));


	//multiply_d1未导出，以下是无法解析的外部命令
	//result = multiply_d1(1, 2);
	//QMessageBox::information(this, z("multiply_d1"), "1*2=" + QString::number(result));
}
void ImportLibraryDlg::loadlibrary2()
{
	auto result = add_d2(2, 3);
	QMessageBox::information(this, z("add_d2"), "2 + 3 = " + QString::number(result));


	result = renamereduce(2, 3);//reduce_d2在def中被重命名了，要使用重命名的函数需要外部申明
    QMessageBox::information(this, z("renamereduce"), "2 - 3 = " + QString::number(result));


	//reduce_d2在def中被重命名了，无法直接使用，报错无法解析的外部命令
	//result = reduce_d2(2, 3);
	//QMessageBox::information(this, z("reduce_d2"), "2 - 3 = " + QString::number(result));
 

	//multiply_d2未导出，以下是无法解析的外部命令
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
