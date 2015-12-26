#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addteam.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
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
