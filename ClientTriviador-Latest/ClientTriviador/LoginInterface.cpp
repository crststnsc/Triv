#include "LoginInterface.h"
#include "PlayerInfo.h"


LoginInterface::LoginInterface(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	LoginInterface::setFixedSize(1600, 900);
}

LoginInterface::~LoginInterface() { /*empty*/ }

//void LoginInterface::resizeEvent(QResizeEvent* event)
//{  
//	QPixmap background(":/newPrefix/images/Imagine_mare_buna_3.png");
//	background = background.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
//	
//	QPalette palette = this->palette();
//	palette.setBrush(QPalette::Window, background);
//	this->setPalette(palette);
//
//	QMainWindow::resizeEvent(event);
//}

//QPixmap background("harta3playersBunaMatr.png");
//background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
//QPalette palette;
//palette.setBrush(QPalette::Background, background);
//this->setPalette(palette);

void LoginInterface::on_RegisterButton_clicked()
{	
	std::string username = ui.lineEdit_username->text().toUtf8().constData();
	std::string password = ui.lineEdit_password->text().toUtf8().constData();
	auto response = cpr::Get(
		cpr::Url{ "http://localhost:18080/register/" + username },
		cpr::Parameters{ {"password", password} }
	);
	if (response.status_code == 200) {
		QMessageBox::information(nullptr, "Succes", "Register successful, please login");
	}
	else {
		QMessageBox::information(nullptr, "Error", "Register unsuccessful");
	}	 
}

void LoginInterface::on_LoginButton_clicked()
{
	std::string username = ui.lineEdit_username->text().toUtf8().constData();
	std::string password = ui.lineEdit_password->text().toUtf8().constData();
	auto response = cpr::Get(
		cpr::Url{"http://localhost:18080/login/" + username },
		cpr::Parameters{{"password", password} }
	);
	if (response.status_code != 400) {
		hide();
		ui2 = new SecondWindow(this);
		ui2->showMaximized();
		PlayerInfo::id = std::stoi(response.text);
		PlayerInfo::username = username;
	}
	else {
		QMessageBox::warning(this, "Error", "Username or password is incorrect");
	}
}