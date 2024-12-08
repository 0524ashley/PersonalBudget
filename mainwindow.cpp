#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateBudgetStatus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_setBudgetButton_clicked()
{
    bool ok;
    double budgetAmount = ui->budgetLineEdit->text().toDouble(&ok);

    if (ok && budgetAmount > 0) {
        budget = budgetAmount;
        currentSpent = 0.0;
        updateBudgetStatus();
    } else {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid budget amount.");
    }
}

void MainWindow::on_addExpenseButton_clicked()
{
    bool ok;
    double expenseAmount = ui->expenseLineEdit->text().toDouble(&ok);

    if (ok && expenseAmount > 0) {
        QString category = ui->categoryComboBox->currentText();

        int row = ui->expenseTableWidget->rowCount();
        ui->expenseTableWidget->insertRow(row);

        ui->expenseTableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(expenseAmount)));
        ui->expenseTableWidget->setItem(row, 1, new QTableWidgetItem(category));

        currentSpent += expenseAmount;
        updateBudgetStatus();
    } else {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid expense amount.");
    }
}

void MainWindow::on_viewReportButton_clicked()
{
    generateReport();
}

void MainWindow::updateBudgetStatus()
{
    double remaining = budget - currentSpent;
    ui->label_4->setText(QString("Budget Status: $%1").arg(remaining, 0, 'f', 2));
}

void MainWindow::generateReport()
{
    // Create Pie Chart
    QPieSeries *series = new QPieSeries();
    QMap<QString, double> categoryTotals;

    // Calculate total expenses per category
    for (int row = 0; row < ui->expenseTableWidget->rowCount(); ++row) {
        QString category = ui->expenseTableWidget->item(row, 1)->text();
        double amount = ui->expenseTableWidget->item(row, 0)->text().toDouble(); //bug fixed

        categoryTotals[category] += amount;
    }

    // Add series items based on categories
    for (auto it = categoryTotals.begin(); it != categoryTotals.end(); ++it) {
        series->append(it.key(), it.value());
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Expense Breakdown");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Set the chart view as the central widget (optional: can add to layout)
    ui->verticalLayout->addWidget(chartView);
}
