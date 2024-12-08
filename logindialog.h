#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog(); // dialog null

private slots:
    void onLogin();     // Slot for login button click
    void onCancel();    // Slot for cancel button click

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
