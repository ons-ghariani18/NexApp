#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajout.h"
#include "partenaire.h"
#include"suppression.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->listEmployetableView->setModel(p.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ajout a;
    a.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    suppression s;
    s.exec();

}


void MainWindow::on_pushButton_3_clicked()
{
    partenaire p("","","","","","","");

       ui->listEmployetableView->setModel(p.afficher());
}

bool MainWindow::modifiercontrat(const QString& dureeContrat, const QString& nouveaudureeContrat)
{
    partenaire p;
    return p.modifiercontrat(dureeContrat, nouveaudureeContrat);
}

void MainWindow::on_pushButton_4_clicked()
{
    // Récupérer le nom et le nouveau prénom depuis l'interface utilisateur
    QString contrat = ui->contrat_LE->text(); // Rename the variable to avoid shadowing
    QString nouveaudureeContrat = ui->nouveaucontrat_LE->text();

    // Appeler la fonction de modification du prénom du partenaire en utilisant le nom comme critère de sélection
    bool success =  modifiercontrat(contrat, nouveaudureeContrat);

    // Vérifier si la modification a réussi et afficher un message en conséquence
    if (success) {
        QMessageBox::information(this, "Succès", "Modification de la durée du contrat réussie !");
    } else {
        QMessageBox::warning(this, "Erreur", "La modification du contrat  n'a pas pu être effectuée.");
    }
}
