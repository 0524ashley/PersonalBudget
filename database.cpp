#include "database.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

Database::Database() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("budget.db");
}

Database::~Database() {
    close();
}

bool Database::open() {
    if (!db.open()) {
        qDebug() << "Error: Unable to open the database" << db.lastError().text();
        return false;
    }
    return true;
}

void Database::close() {
    if (db.isOpen()) {
        db.close();
    }
}

bool Database::createTables() {
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS budget (id INTEGER PRIMARY KEY, amount REAL)")) {
        qDebug() << "Error creating budget table:" << query.lastError();
        return false;
    }
    if (!query.exec("CREATE TABLE IF NOT EXISTS expenses (id INTEGER PRIMARY KEY, amount REAL, category TEXT)")) {
        qDebug() << "Error creating expenses table:" << query.lastError();
        return false;
    }
    return true;
}

bool Database::setBudget(double budget) {
    QSqlQuery query;
    query.prepare("INSERT OR REPLACE INTO budget (id, amount) VALUES (1, :amount)");
    query.bindValue(":amount", budget);
    return query.exec();
}

double Database::getBudget() const {
    QSqlQuery query;
    query.prepare("SELECT amount FROM budget WHERE id = 1");
    if (!query.exec() || !query.next()) {
        qDebug() << "Error getting budget:" << query.lastError();
        return 0.0;
    }
    return query.value(0).toDouble();
}

bool Database::addExpense(double amount, const QString& category) {
    QSqlQuery query;
    query.prepare("INSERT INTO expenses (amount, category) VALUES (:amount, :category)");
    query.bindValue(":amount", amount);
    query.bindValue(":category", category);
    return query.exec();
}

QList<QPair<QString, double>> Database::getExpenses() const {
    QList<QPair<QString, double>> expenses;
    QSqlQuery query("SELECT amount, category FROM expenses");
    while (query.next()) {
        QString category = query.value(1).toString();
        double amount = query.value(0).toDouble();
        expenses.append(qMakePair(category, amount));
    }
    return expenses;
}
