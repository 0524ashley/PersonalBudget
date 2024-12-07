#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <QString>
#include <QList>
#include <QPair>
#include "database.h"

class BudgetManager {
public:
    BudgetManager();
    ~BudgetManager();

    bool setBudget(double budget);
    double getBudget() const;

    bool addExpense(double amount, const QString& category);
    QList<QPair<QString, double>> getExpenses() const;

private:
    Database db;
};

#endif // BUDGETMANAGER_H
