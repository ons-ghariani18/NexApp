#include "ajout.h"
#include "ui_ajout.h"
#include"employee.h"
#include <QMessageBox>


ajout::ajout(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ajout)
{
    ui->setupUi(this);
}

ajout::~ajout()
{
    delete ui;
}
void ajout::on_pushButton_clicked()
{
    // Récupérer les données depuis les champs de saisie de l'interface utilisateur
    QString nom = ui->lineEdit_Nom->text();
    QString prenom = ui->lineEdit_Prenom->text();
    QString email = ui->lineEdit_Email->text();
    QString salaire = ui->lineEdit_Salaire->text(); // Convertir la valeur du salaire en double

    // Créer un nouvel objet Employee avec les données récupérées

Employee employee(nom, prenom, email, salaire);
    // Appeler la méthode ajouter() pour insérer le nouvel employé dans la base de données
    bool insertionReussie = employee.ajouter();

    // Afficher un message en fonction du résultat de l'insertion
    if (insertionReussie) {
        QMessageBox::information(this, "Succès", "Nouvel employé ajouté avec succès !");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'ajout du nouvel employé.");
    }
}
