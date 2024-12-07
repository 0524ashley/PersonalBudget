#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

class Database {
public:
    Database();
    ~Database();

    bool open();
    void close();
    bool createTables();

    bool setBudget(double budget);
    double getBudget() const; //fixed to const

    bool addExpense(double amount, const QString& category);
    QList<QPair<QString, double>> getExpenses() const; //fixed to const

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
