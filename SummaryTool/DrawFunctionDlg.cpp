#include<qpainter.h>
#include "DrawFunctionDlg.h"
#include <Qt>

#define z QString::fromLocal8Bit

DrawFunctionDlg::DrawFunctionDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	InitControl();
}

DrawFunctionDlg::~DrawFunctionDlg()
{
}

void DrawFunctionDlg::InitControl()
{
	auto actionline = toolBar->addAction(z("ֱ��"));
	auto actionRect = toolBar->addAction(z("����"));
	auto actionCircle = toolBar->addAction(z("Բ"));
	auto actionPic = toolBar->addAction(z("ͼƬ"));
	auto actiontext = toolBar->addAction(z("�ı�"));
	auto actionClear = toolBar->addAction(z("���"));

	connect(toolBar, SIGNAL(actionTriggered(QAction *)), this, SLOT(actionTriggered(QAction *)));
}

void DrawFunctionDlg::paintEvent(QPaintEvent* info)
{
	QPainter painter;
	painter.begin(this);

	auto wh = this->height();
	auto ww = this->width();

	QPen pen;
	QBrush brush;


	switch (curAction)
	{
	case ActionType::NONE:
		break;
	case ActionType::LINE:		
	{
		QLinearGradient linearGradient(0, 0, ww, wh);
		linearGradient.setColorAt(0.2, Qt::white);
		linearGradient.setColorAt(0.5, Qt::green);
		linearGradient.setColorAt(0.8, Qt::yellow);

		pen.setStyle(Qt::PenStyle::DashDotLine);
		pen.setBrush(QBrush(linearGradient));
		pen.setWidth(20);
		painter.setPen(pen);
		painter.drawLine(0, 0, ww, wh);
		break;
	}
	case ActionType::RECT:
	{
		brush.setStyle(Qt::BrushStyle::Dense4Pattern);
		brush.setColor(QColor(255, 0, 0));
		pen.setColor(QColor(0, 255, 0));
		pen.setWidth(10);
		painter.setPen(pen);
		painter.setBrush(brush);
		painter.drawRect(30, 30, ww - 100, wh - 100);
		break;
	}
	case ActionType::CIRCLE:
	{
		QRadialGradient patter(ww / 2, wh / 2, ww / 2);
		patter.setColorAt(0.2, Qt::white);
		patter.setColorAt(0.5, Qt::green);
		patter.setColorAt(0.8 , Qt::yellow);

		QBrush curbursh(patter);
		curbursh.setStyle(Qt::BrushStyle::RadialGradientPattern);
		pen.setColor(QColor(0, 255, 0));
		pen.setWidth(10);
		painter.setPen(pen);
		painter.setBrush(QBrush(patter));
		painter.drawEllipse(0, 0, ww, wh);
		break;
	}
	case ActionType::PICTURE:
	{
		QPixmap pixmap("./res/Image/pic7.jpg");
		int w = pixmap.width();
		int h = pixmap.height();
		pixmap.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		brush.setTexture(pixmap);
		painter.setBrush(brush);
		painter.drawRect(0, 0, w, h);
		break;
	}
	case ActionType::TEXT:
	{
		pen.setColor(Qt::darkGreen);
		pen.setWidth(5);
		painter.setPen(pen);
		painter.drawText(QPoint(50,50), z("�����ı������ı�"));
	}
	}
	painter.end();
}

void DrawFunctionDlg::actionTriggered(QAction* action)
{
	if (action == nullptr)
		return;
	auto text = action->text();
	if (text == z("ֱ��"))
	{
		curAction = ActionType::LINE;
	}
	else if (text == z("����"))
	{
		curAction = ActionType::RECT;
	}
	else if (text == z("Բ"))
	{
		curAction = ActionType::CIRCLE;
	}
	else if (text == z("ͼƬ"))
	{
		curAction = ActionType::PICTURE;
	}
	else if (text == z("�ı�"))
	{
		curAction = ActionType::TEXT;
	}
	else if (text == z("���"))
	{
		curAction = ActionType::NONE;
	}
	this->repaint();
	//this->update();//����
}
