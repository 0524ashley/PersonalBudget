#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Show the login dialog first
    LoginDialog loginDialog;
    if (loginDialog.exec() == QDialog::Accepted) {
        // If login is successful, show the main window
        MainWindow w;
        w.show();
        return a.exec();
    } else {
        // If login is unsuccessful, close the application
        return 0;
    }
}
