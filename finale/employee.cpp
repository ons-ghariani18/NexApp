#include "employee.h"
#include <QTableView>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
#include <QMessageBox>


Employee::Employee(QString nom, QString prenom, QString email, QString salaire) {
    this->nom = nom;
    this->prenom = prenom;
    this->email = email;
    this->salaire = salaire;
}

bool Employee::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYE (NOM, PRENOM, EMAIL, SALAIRE) "
                  "VALUES (:nom, :prenom, :email, :salaire)");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":salaire", salaire);

    if (query.exec()) {
        qDebug() << "Employee added successfully.";
        return true;
    } else {
        qDebug() << "Failed to add employee:" << query.lastError().text();
        return false;
    }
}

bool Employee::supprimer(const QString &nom)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYE WHERE NOM = :nom");
    query.bindValue(":nom", nom);

    if (query.exec()) {
        qDebug() << "Employee deleted successfully.";
        return true;
    } else {
        qDebug() << "Failed to delete employee:" << query.lastError().text();
        return false;
    }
}
