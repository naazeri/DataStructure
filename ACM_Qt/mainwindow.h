#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "list.h"
#include "team.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_main_button_exit_clicked();

	void on_main_button_addTeam_clicked();

	void on_main_button_showData_clicked();

private:
	Ui::MainWindow *ui;
	List<Team> *list;
};

#endif // MAINWINDOW_H
