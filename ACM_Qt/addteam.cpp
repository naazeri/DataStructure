#include "addteam.h"
#include "ui_addteam.h"

AddTeam::AddTeam(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::AddTeam)
{
	ui->setupUi(this);
}

AddTeam::~AddTeam()
{
	delete ui;
}
