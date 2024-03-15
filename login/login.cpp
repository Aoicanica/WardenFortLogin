#include "login.h"
#include "ui_login.h"
#include <QMessageBox> // Include the header for QMessageBox
#include <QSqlQuery> // Include the header for QSqlQuery

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);

    // Connect the clicked() signal of the loginButton to the on_loginButton_clicked() slot
    connect(ui->loginButton, &QPushButton::clicked, this, &login::on_loginButton_clicked);
}

login::~login()
{
    delete ui;
}

void login::on_loginButton_clicked()
{
    QString username = ui->typeUN_box->text(); // Assuming QLineEdit for username input
    QString password = ui->typePASS_box->text(); // Assuming QLineEdit for password input

    // Query the database to check if the entered credentials are valid
    QSqlQuery query;
    query.prepare("SELECT * FROM Login WHERE user_id = :username AND pass_id = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        // Credentials are valid, proceed with login
        qDebug() << "Login successful for username:" << username;
        // Close the login window
        this->close();
        // Proceed with main application logic
        // For example, open another window or perform other actions
    } else {
        // Invalid credentials, display an error message
        qDebug() << "Invalid username or password.";
        QMessageBox::warning(this, "Login Error", "Invalid username or password.");
    }
}
