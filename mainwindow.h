#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QTableWidget>
#include <QtCharts/QLineSeries>
#include <QTableWidgetItem>
#include <QMessageBox>
#include "./ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_setBudgetButton_clicked();
    void on_addExpenseButton_clicked();
    void on_viewReportButton_clicked();

private:
    Ui::MainWindow *ui;

    double budget = 0.0;
    double currentSpent = 0.0;
    QTableWidgetItem *createItem(const QString &text);

    // Helper to update budget status label
    void updateBudgetStatus();

    // Helper to generate pie chart based on expenses
    void generateReport();
};

#endif // MAINWINDOW_H

