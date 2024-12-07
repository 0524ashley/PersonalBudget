#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    // Connect signals to slots
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginDialog::onLogin);
    connect(ui->cancelButton, &QPushButton::clicked, this, &LoginDialog::onCancel);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::onLogin()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both username and password.");
        return;
    }

    // Hardcoded username and password check
    if (username == "admin" && password == "admin") {
        QMessageBox::information(this, "Login Successful", "You are logged in.");
        accept();  // Close the dialog if login is successful
    } else {
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password.");
    }
}

void LoginDialog::onCancel()
{
    reject();  // Close the dialog if "Cancel" is clicked
}
