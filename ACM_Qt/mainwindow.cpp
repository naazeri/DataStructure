#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addteam.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	list = new List<Team>();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_main_button_exit_clicked()
{
	this->close();
}

void MainWindow::on_main_button_addTeam_clicked()
{
	AddTeam *addTeam = new AddTeam();
	addTeam->exec();
}

void MainWindow::on_main_button_showData_clicked()
{
//	list->printData();
	QFile *file = new QFile("/home/reza/team.txt", this);
	QTextStream *in = new QTextStream(file);
	in->setCodec("UTF-8");

	if( file->open(QFile::ReadOnly | QFile::Text)) {
		while(!in->atEnd()) {
			QString data = in->readLine();

			if (data == "----") {
				continue;
			}
			qDebug() << "Name:" << data;

			data = in->readLine();
			if (data == "----") {
				continue;
			}
			qDebug() << "Family:" << data << "\n";
		}
	}

	else {
		QMessageBox *message = new QMessageBox(this);
		message->setWindowTitle("خطا");
		message->setText("متاسفانه فایل باز نشد");
		message->setIcon(QMessageBox::Critical);
		message->exec();
	}
}
