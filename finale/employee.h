#ifndef EMPLOYEE_H
#define EMPLOYEE_H
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
#include <QString>


class Employee
{
    QString nom;
    QString prenom;
    QString email;
    QString salaire;

public:
    Employee(){}
    Employee(QString nom, QString prenom,QString email,QString salaire);

    // Getters
    QString getNom() const;
    QString getPrenom() const;
    QString getEmail() const;
    QString getSalaire() const;

    // Setters
    void setNom(const QString &nom);
    void setPrenom(const QString &prenom);
    void setEmail(const QString &email);
    void setSalaire(QString salaire);


//partie crud

bool ajouter();
  bool supprimer(const QString &nom);
};

#endif // EMPLOYEE_H
