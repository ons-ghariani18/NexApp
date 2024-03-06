#include "suppression.h"
#include "ui_suppression.h"
#include"employee.h"
#include <QMessageBox>

suppression::suppression(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::suppression)
{
    ui->setupUi(this);
}

suppression::~suppression()
{
    delete ui;
}

void suppression::on_supprimer_LE_clicked()
{
    // Get the name of the employee to be deleted
    QString nom = ui->supprimer_LE->text();
  QSqlQuery query;
    // Create a QSqlQuery object
    Employee employee;
    bool test =employee.supprimer(nom);
    // Prepare the SQL query to delete the employee with the given name

    // Execute the query
    if (test) {
        QMessageBox::information(this, "Success", "Employee deleted successfully.");
    } else {
        QMessageBox::warning(this, "Error", "Failed to delete employee:" + query.lastError().text());
    }
}

