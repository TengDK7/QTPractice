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
#include"ImportLibraryDlg.h"

#define z QString::fromUtf8//通用宏

SummaryToolForm::SummaryToolForm(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    InitMenu();
    InitToolBar();
    InitStatusBar();
}
#pragma region 菜单栏
void  SummaryToolForm::InitMenu()
{
    QMenu* commondlgitem = new QMenu(z("通用对话框"));//菜单栏
    commondlgitem->addAction(z("文件对话框"));//子菜单
    commondlgitem->addAction(z("字体对话框"));
    commondlgitem->addAction(z("颜色对话框"));

    QMenu* msgboxitem = new QMenu(z("消息对话框"));//子菜单
    msgboxitem->addAction(z("信息消息框"));
    msgboxitem->addAction(z("询问消息框"));
    msgboxitem->addAction(z("紧急消息框"));
    msgboxitem->addAction(z("警告消息框"));

    commondlgitem->addMenu(msgboxitem);

    QMenu* appitem = new QMenu(z("程序"));
    appitem->addAction(z("关闭"));

    this->menuBar()->addMenu(commondlgitem);//系统菜单
    this->menuBar()->addMenu(appitem);

    connect(menuBar(), SIGNAL(triggered(QAction*)), this, SLOT(trigerMenu(QAction*)));//绑定action
}
void SummaryToolForm::trigerMenu(QAction* action)
{
    if (action == NULL)
        return;

    auto text = action->text();

    if (text == z("文件对话框"))
    {
        QFileDialog::getOpenFileName(this, z("选择一个图片"),".","Image File(*.jpg *.png)");

        QFileDialog::getOpenFileNames(this, z("选择多个图片"), ".", "Image File(*.jpg *.png)");

        QFileDialog::getSaveFileName(this, z("保存文件"), ".", "Image File(*.jpg *.png)");
    }
    else if (text == z("字体对话框"))
    {
        bool ok;
        QFontDialog::getFont(&ok);
        if(ok)
            QMessageBox::information(this, z("提示"), z("选择字体成功"));
        else
            QMessageBox::information(this, z("提示"), z("选择字体失败"));
    }
    else if (text == z("颜色对话框"))
    {
        QColor color = QColorDialog::getColor();
        if (color.isValid())
            QMessageBox::information(this, z("提示"), z("选择颜色成功"));
        else
            QMessageBox::information(this, z("提示"), z("选择颜色失败"));

    }
    else if (text == z("信息消息框"))
    {
        this->statusBar()->showMessage(z("信息消息框"), 5000);

        QMessageBox::information(this, z("提示"), z("这是信息消息框_1"));
        QMessageBox::information(this, z("提示"), z("这是信息消息框_2"), QMessageBox::Ok);
    }
    else if (text == z("询问消息框"))
    {
        this->statusBar()->showMessage(z("询问消息框"), 5000);

        QMessageBox::question(this, z("确认"), z("这是询问消息框_1"), QMessageBox::Yes | QMessageBox::No);
        QMessageBox::question(this, z("确认"), z("这是询问消息框_2"), QMessageBox::Abort | QMessageBox::Retry | QMessageBox::Ignore);
    }
    else if (text == z("紧急消息框"))
    {
        this->statusBar()->showMessage(z("紧急消息框"), 5000);

        QMessageBox::critical(this, z("紧急"), z("这是紧急消息框"), QMessageBox::Ok);
    }
    else if (text == z("警告消息框"))
    {
        this->statusBar()->showMessage(z("警告消息框"), 5000);

        QMessageBox::warning(this, z("警告"), z("这是警告消息框"), QMessageBox::Ok | QMessageBox::Cancel);
    }
    else if (text == z("关闭"))
    {
        this->close();//关闭对话框
    }
}
#pragma endregion


#pragma region 工具栏
void SummaryToolForm::InitToolBar()
{
    QAction* openfile = new QAction(z("打开"), this);
    QAction* closefile = new QAction(z("关闭"), this);
    QAction* threadtest = new QAction(z("线程"), this);
    QAction* drawfun = new QAction(z("绘图"), this);
    QAction* musicplay = new QAction(z("音乐"), this);
    QAction* vidioplay = new QAction(z("视频"),this);
    QAction* layouttest = new QAction(z("布局"), this);
    QAction* fileoperator = new QAction(z("文件"), this);
    QAction* loadlibrary = new QAction(z("加载库"), this);

    connect(openfile, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(closefile, SIGNAL(triggered()), this, SLOT(closeFIle()));
    connect(threadtest, SIGNAL(triggered()), this, SLOT(openthreaddlg()));
    connect(drawfun, SIGNAL(triggered()), this, SLOT(opendrawfundlg()));
    connect(musicplay, SIGNAL(triggered()), this, SLOT(openmusicplayldg()));
    connect(vidioplay, SIGNAL(triggered()), this, SLOT(openvidioplaydlg()));
    connect(layouttest, SIGNAL(triggered()), this, SLOT(openlayouttestdlg()));
    connect(fileoperator, SIGNAL(triggered()), this, SLOT(openfileoperatordlg()));
    connect(loadlibrary, SIGNAL(triggered()), this, SLOT(openloadlibrarydlg()));

    ui.mainToolBar->addAction(openfile);
    ui.mainToolBar->addAction(closefile);
    ui.mainToolBar->addAction(threadtest);
    ui.mainToolBar->addAction(drawfun);
    ui.mainToolBar->addAction(musicplay);
    ui.mainToolBar->addAction(vidioplay);
    ui.mainToolBar->addAction(layouttest);
    ui.mainToolBar->addAction(fileoperator);
    ui.mainToolBar->addAction(loadlibrary);
}

void SummaryToolForm::openFile()
{
    QMessageBox::information(this, z("提示"), z("打开文件"));
}

void SummaryToolForm::closeFIle()
{
    QMessageBox::information(this, z("提示"), z("关闭文件"));
}
void SummaryToolForm::openthreaddlg()
{
    QThreadDlg* dlg = new QThreadDlg();//对话框
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
void SummaryToolForm::openloadlibrarydlg()
{
    ImportLibraryDlg* dlg = new ImportLibraryDlg();
    dlg->setModal(true);
    dlg->show();
}
#pragma endregion

#pragma region 状态栏
void SummaryToolForm::InitStatusBar()
{
    QLabel* infolabel1 = new QLabel(z("一般信息1"));
    QLabel* infolabel2 = new QLabel(z("一般信息2"));

    QPushButton* btnMsg = new QPushButton(z("一个按钮"));
    connect(btnMsg, SIGNAL(clicked()), this, SLOT(statusBtnClick()));

    QLabel* still1 = new QLabel(z("永久信息1"));
    QLabel* still2 = new QLabel(z("永久信息2"));

    this->statusBar()->addWidget(infolabel1);
    this->statusBar()->addWidget(infolabel2);

    this->statusBar()->addWidget(btnMsg);

    this->statusBar()->addPermanentWidget(still1);
    this->statusBar()->addPermanentWidget(still2);
}
void SummaryToolForm::statusBtnClick()
{
    QMessageBox::information(this, z("提示"), z("状态栏按钮点击"));
}
#pragma endregion
