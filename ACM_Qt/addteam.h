#ifndef ADDTEAM_H
#define ADDTEAM_H

#include <QDialog>

namespace Ui {
class AddTeam;
}

class AddTeam : public QDialog
{
	Q_OBJECT

public:
	explicit AddTeam(QWidget *parent = 0);
	~AddTeam();

private:
	Ui::AddTeam *ui;
};

#endif // ADDTEAM_H
