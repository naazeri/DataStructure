#include "database.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QApplication>
//#include <iostream>

DataBase::DataBase(QObject *parent) : QObject(parent)
{
	list = new List<Team>();

	reloadData();

//	QStringList foo = {"12", "2", "3"};
//	setTeamNumber(foo);
//	_teamNumber.append(foo);
//	_teamNumber.append("masoud");

	_teamName.append("reza");
	_teamName.append("ali");
//	_teamName.append("init3");
}

void DataBase::reloadData() {
	QFile *file = new QFile("/home/reza/team.txt", this);  // ToDo: ba qrc benevisam

	if( file->open(QFile::ReadOnly | QFile::Text)) {
		QTextStream *in = new QTextStream(file);
		in->setCodec("UTF-8");
		qDebug() << "teamNumber:";

		while(!in->atEnd()) {
			QStringList data;
			data.append(in->readLine());

			if (data.back() == "----") {
				continue;
			}

			Team team;
			team.setTeamNumber(data.back().toInt());
			qDebug() << "teamNumber:" << team.getTeamNumber();
//			std::cout << "teamNumber: " << team.getTeamNumber() << "\n";

			data.append(in->readLine());
			qDebug() << "teamName:" << data.back();
			team.setTeamName(data.back());

			data.append(in->readLine());
			qDebug() << "team have" << data.back() << "member:";

			const int members = data.back().toInt();
			if (members <= 0) {
				qDebug() << "Invalid team member number!";
				file->close();
				return;
			}

			for (int i = 0; i < members; ++i) {
				qDebug() << "\n" << QString("Member %1:").arg(i+1);

				Person person;

				data.append(in->readLine());
				qDebug() << "    name:" << data.back();
				person.setName(data.back());

				data.append(in->readLine());
				qDebug() << "    family:" << data.back();
				person.setFamily(data.back());

				data.append(in->readLine());
				const QString y = data.back();

				data.append(in->readLine());
				const QString m = data.back();

				data.append(in->readLine());
				const QString d = data.back();

				qDebug() << "    birthday:" << QString("%1/%2/%3").arg(y).arg(m).arg(d);
				person.setBirthDay(y, m, d);

				data.append(in->readLine());
				if (data.back() == "male") {
					qDebug() << "    gender: male";
					person.setGender(Person::MALE);
				} else if (data.back() == "female") {
					person.setGender(Person::FEMALE);
					qDebug() << "    gender: female";
				} else {
					qDebug() << "Invalid gender!";
					file->close();
					return;
				}

				team.setMember(person, i);
			}

			// ToDo: az inja monde
			data.append(in->readLine());
			qDebug() << "uniName:" << data.back();
			team.setUniversityName(data.back());

			data.append(in->readLine());
			qDebug() << "Accepted question:" << data.back();
			team.setAcceptedQuestion(data.back().toInt());

			data.append(in->readLine());
			QString h = data.back();
			data.append(in->readLine());
			QString m = data.back();
			qDebug() << "Enter time:" << QString("%1:%2").arg(h).arg(m);
//			std::cout << QString("Enter time: %1:%2\n").arg(h).arg(m).toStdString();
			team.setEnterTime(h, m);

			data.append(in->readLine());
			h = data.back();
			data.append(in->readLine());
			m = data.back();
			qDebug() << "Exit time:" << QString("%1:%2").arg(h).arg(m);
//			std::cout << QString("Exit time: %1:%2\n").arg(h).arg(m).toStdString();
			team.setEnterTime(h, m);

			list->addLast(team);
		}
		file->close();
        qDebug() << "End\n\n\n";
	}

	else {
		QMessageBox *message = new QMessageBox();
		message->setWindowTitle("خطا");
		message->setText("فایل پیدا نشد!");
		message->setIcon(QMessageBox::Critical);
		message->exec();
		exit(0);
	}
}

void DataBase::setTeamNumber(const QStringList s)
{
	this->_teamNumber = s;
	emit teamNumberChanged();
}

void DataBase::setTeamName(const QStringList s)
{
	this->_teamName = s;
	emit teamNameChanged();
}

QStringList DataBase::teamNumber()
{
	return _teamNumber;
}

QStringList DataBase::teamName()
{
	return _teamName;
}

void DataBase::changeTeamNumber() {
	Team team;
//	list->showAllTeam();
	list->get(team, 1);
	QStringList l;
	l.append(QString::number(team.getTeamNumber()));
	setTeamNumber(l);
}

void DataBase::changeTeamName() {
    list->showAllTeam();
//	Team team;
//	list->showAllTeam();
//	list->get(team, 1);
//	QStringList l;
//	l.append(team.getTeamName());
	//	setTeamName(l);
}

void DataBase::sortList()
{
	qDebug() << "Before Sort:";
	list->showAllTeam();



	qDebug() << "Before Sort:";
	list->showAllTeam();
}
