#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery> // Include the header for QSqlQuery
#include <QDebug>
#include "login.h" // Include your login header file here

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    // Set up the database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/login/login/login/login.db"); // Set the full path to your database file here

    // Open the database connection
    if (!db.open()) {
        qWarning() << "Failed to open database:" << db.lastError().text();
        return 1;
    }

    qDebug() << "Database connected successfully";

    // Now that the database connection is established, you can show your login window
    login login; // Assuming you have a login window defined
    login.show();

    // Debugging the data inside the database
    QSqlQuery query("SELECT user_id, pass_id FROM Login"); // Assuming 'Login' is the table name
    if(query.exec()) {
        qDebug() << "Query executed successfully.";
        if(query.size() == 0) {
            qDebug() << "No records found in the database.";
        }
        else {
            while(query.next()) {
                QString user_id = query.value("user_id").toString();
                QString pass_id = query.value("pass_id").toString();
                qDebug() << "Username:" << user_id << "Password:" << pass_id;
            }
        }
    }
    else {
        qWarning() << "Query failed:" << query.lastError().text();
    }

    return a.exec();
}
