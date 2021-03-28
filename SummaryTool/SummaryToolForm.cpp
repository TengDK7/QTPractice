#include "SummaryToolForm.h"
#include"qmessagebox.h"
#include"qlabel.h"
#include"qpushbutton.h"
#include"qfiledialog.h"
#include"qcolordialog.h"
#include"qfontdialog.h"
#include"QThreadDlg.h"
#include"DrawFunctionDlg.h"
#include"MusicPlayDlg.h"
#include"VidioPalyDlg.h"
#include"LayoutDlg.h"
#include"FileOperatorDlg.h"

#define z QString::fromLocal8Bit//ͨ�ú�

SummaryToolForm::SummaryToolForm(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    InitMenu();
    InitToolBar();
    InitStatusBar();
}
#pragma region �˵���
void  SummaryToolForm::InitMenu()
{
    QMenu* commondlgitem = new QMenu(z("ͨ�öԻ���"));//�˵���
    commondlgitem->addAction(z("�ļ��Ի���"));//�Ӳ˵�
    commondlgitem->addAction(z("����Ի���"));
    commondlgitem->addAction(z("��ɫ�Ի���"));

    QMenu* msgboxitem = new QMenu(z("��Ϣ�Ի���"));//�Ӳ˵�
    msgboxitem->addAction(z("��Ϣ��Ϣ��"));
    msgboxitem->addAction(z("ѯ����Ϣ��"));
    msgboxitem->addAction(z("������Ϣ��"));
    msgboxitem->addAction(z("������Ϣ��"));

    commondlgitem->addMenu(msgboxitem);

    QMenu* appitem = new QMenu(z("����"));
    appitem->addAction(z("�ر�"));

    this->menuBar()->addMenu(commondlgitem);//ϵͳ�˵�
    this->menuBar()->addMenu(appitem);

    connect(menuBar(), SIGNAL(triggered(QAction*)), this, SLOT(trigerMenu(QAction*)));//��action
}
void SummaryToolForm::trigerMenu(QAction* action)
{
    if (action == NULL)
        return;

    auto text = action->text();

    if (text == z("�ļ��Ի���"))
    {
        QFileDialog::getOpenFileName(this, z("ѡ��һ��ͼƬ"),".","Image File(*.jpg *.png)");

        QFileDialog::getOpenFileNames(this, z("ѡ����ͼƬ"), ".", "Image File(*.jpg *.png)");

        QFileDialog::getSaveFileName(this, z("�����ļ�"), ".", "Image File(*.jpg *.png)");
    }
    else if (text == z("����Ի���"))
    {
        bool ok;
        QFontDialog::getFont(&ok);
        if(ok)
            QMessageBox::information(this, z("��ʾ"), z("ѡ������ɹ�"));
        else
            QMessageBox::information(this, z("��ʾ"), z("ѡ������ʧ��"));
    }
    else if (text == z("��ɫ�Ի���"))
    {
        QColor color = QColorDialog::getColor();
        if (color.isValid())
            QMessageBox::information(this, z("��ʾ"), z("ѡ����ɫ�ɹ�"));
        else
            QMessageBox::information(this, z("��ʾ"), z("ѡ����ɫʧ��"));

    }
    else if (text == z("��Ϣ��Ϣ��"))
    {
        this->statusBar()->showMessage(z("��Ϣ��Ϣ��"), 5000);

        QMessageBox::information(this, z("��ʾ"), z("������Ϣ��Ϣ��_1"));
        QMessageBox::information(this, z("��ʾ"), z("������Ϣ��Ϣ��_2"), QMessageBox::Ok);
    }
    else if (text == z("ѯ����Ϣ��"))
    {
        this->statusBar()->showMessage(z("ѯ����Ϣ��"), 5000);

        QMessageBox::question(this, z("ȷ��"), z("����ѯ����Ϣ��_1"), QMessageBox::Yes | QMessageBox::No);
        QMessageBox::question(this, z("ȷ��"), z("����ѯ����Ϣ��_2"), QMessageBox::Abort | QMessageBox::Retry | QMessageBox::Ignore);
    }
    else if (text == z("������Ϣ��"))
    {
        this->statusBar()->showMessage(z("������Ϣ��"), 5000);

        QMessageBox::critical(this, z("����"), z("���ǽ�����Ϣ��"), QMessageBox::Ok);
    }
    else if (text == z("������Ϣ��"))
    {
        this->statusBar()->showMessage(z("������Ϣ��"), 5000);

        QMessageBox::warning(this, z("����"), z("���Ǿ�����Ϣ��"), QMessageBox::Ok | QMessageBox::Cancel);
    }
    else if (text == z("�ر�"))
    {
        this->close();//�رնԻ���
    }
}
#pragma endregion


#pragma region ������
void SummaryToolForm::InitToolBar()
{
    QAction* openfile = new QAction(z("��"), this);
    QAction* closefile = new QAction(z("�ر�"), this);
    QAction* threadtest = new QAction(z("�߳�"), this);
    QAction* drawfun = new QAction(z("��ͼ"), this);
    QAction* musicplay = new QAction(z("����"), this);
    QAction* vidioplay = new QAction(z("��Ƶ"),this);
    QAction* layouttest = new QAction(z("����"), this);
    QAction* fileoperator = new QAction(z("�ļ�"), this);

    connect(openfile, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(closefile, SIGNAL(triggered()), this, SLOT(closeFIle()));
    connect(threadtest, SIGNAL(triggered()), this, SLOT(openthreaddlg()));
    connect(drawfun, SIGNAL(triggered()), this, SLOT(opendrawfundlg()));
    connect(musicplay, SIGNAL(triggered()), this, SLOT(openmusicplayldg()));
    connect(vidioplay, SIGNAL(triggered()), this, SLOT(openvidioplaydlg()));
    connect(layouttest, SIGNAL(triggered()), this, SLOT(openlayouttestdlg()));
    connect(fileoperator, SIGNAL(triggered()), this, SLOT(openfileoperatordlg()));

    ui.mainToolBar->addAction(openfile);
    ui.mainToolBar->addAction(closefile);
    ui.mainToolBar->addAction(threadtest);
    ui.mainToolBar->addAction(drawfun);
    ui.mainToolBar->addAction(musicplay);
    ui.mainToolBar->addAction(vidioplay);
    ui.mainToolBar->addAction(layouttest);
    ui.mainToolBar->addAction(fileoperator);
}

void SummaryToolForm::openFile()
{
    QMessageBox::information(this, z("��ʾ"), z("���ļ�"));
}

void SummaryToolForm::closeFIle()
{
    QMessageBox::information(this, z("��ʾ"), z("�ر��ļ�"));
}
void SummaryToolForm::openthreaddlg()
{
    QThreadDlg* dlg = new QThreadDlg();//�Ի���
    dlg->setModal(true);
    dlg->show();
}
void SummaryToolForm::opendrawfundlg()
{
    DrawFunctionDlg* dlg = new DrawFunctionDlg();
    dlg->setModal(true);
    dlg->show();
}
void SummaryToolForm::openmusicplayldg()
{
    MusicPlayDlg dlg(this);
    dlg.exec();
}
void SummaryToolForm::openvidioplaydlg()
{
    VidioPalyDlg* dlg = new VidioPalyDlg(this);
    dlg->setModal(true);
    dlg->show();
}
void SummaryToolForm::openlayouttestdlg()
{
    LayoutDlg* dlg = new LayoutDlg(this);
    dlg->setModal(true);
    dlg->show();
}
void SummaryToolForm::openfileoperatordlg()
{
    FileOperatorDlg* dlg = new FileOperatorDlg();
    dlg->setModal(true);
    dlg->show();
}
#pragma endregion

#pragma region ״̬��
void SummaryToolForm::InitStatusBar()
{
    QLabel* infolabel1 = new QLabel(z("һ����Ϣ1"));
    QLabel* infolabel2 = new QLabel(z("һ����Ϣ2"));

    QPushButton* btnMsg = new QPushButton(z("һ����ť"));
    connect(btnMsg, SIGNAL(clicked()), this, SLOT(statusBtnClick()));

    QLabel* still1 = new QLabel(z("������Ϣ1"));
    QLabel* still2 = new QLabel(z("������Ϣ2"));

    this->statusBar()->addWidget(infolabel1);
    this->statusBar()->addWidget(infolabel2);

    this->statusBar()->addWidget(btnMsg);

    this->statusBar()->addPermanentWidget(still1);
    this->statusBar()->addPermanentWidget(still2);
}
void SummaryToolForm::statusBtnClick()
{
    QMessageBox::information(this, z("��ʾ"), z("״̬����ť���"));
}
#pragma endregion
