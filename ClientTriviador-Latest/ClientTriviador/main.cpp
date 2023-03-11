#include "LoginInterface.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginInterface w;
	w.setWindowState(Qt::WindowMaximized);
    w.show();
    return a.exec();
}
