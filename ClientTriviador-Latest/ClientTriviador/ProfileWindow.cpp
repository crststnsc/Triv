#include "ProfileWindow.h"

ProfileWindow::ProfileWindow(QWidget *menu,QWidget *parent)
	: QMainWindow(parent)
{
	profileUi.setupUi(this);
	this->menu = menu;
}

ProfileWindow::~ProfileWindow()
{}

void ProfileWindow::history()
{
	auto response = cpr::Get(
		cpr::Url{ "http://localhost:8080/historyGames" }
		
	);
	if (response.status_code == 200) {
		profileUi.historyTable->setRowCount(0);
		
	/*	for (int i = 0; i < array.size(); i++) {
			profileUi.historyTable->insertRow(i);
			profileUi.historyTable->setItem(i, 1, new QTableWidgetItem(obj["score"].toString()));
			profileUi.historyTable->setItem(i, 2, new QTableWidgetItem(obj["win/lose"].toString()));
		}*/
	}
	else {
		QMessageBox::information(this, "Error", "Cannot open history");
	}
}

void ProfileWindow::on_backToMenu_clicked()
{
	this->close();
	menu->showMaximized();
}



