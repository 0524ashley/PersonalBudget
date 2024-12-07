#include "budgetmanager.h"

BudgetManager::BudgetManager() {
    db.open();
    db.createTables();
}

BudgetManager::~BudgetManager() {
    db.close();
}

bool BudgetManager::setBudget(double budget) {
    return db.setBudget(budget);
}

double BudgetManager::getBudget() const {
    return db.getBudget();
}

bool BudgetManager::addExpense(double amount, const QString& category) {
    return db.addExpense(amount, category);
}

QList<QPair<QString, double>> BudgetManager::getExpenses() const {
    return db.getExpenses();
}
