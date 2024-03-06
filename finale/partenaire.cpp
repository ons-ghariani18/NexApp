#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
#include <QMessageBox>
#include "partenaire.h"

partenaire::partenaire( QString matriculeFiscale, QString nomEntreprise, QString adresse, QString numeroTelephone, QString dureeContrat, QString secteurActivite, QString interet)
{

    this->matriculeFiscale = matriculeFiscale;
    this->nomEntreprise = nomEntreprise;
    this->adresse = adresse;
    this->numeroTelephone = numeroTelephone;
    this->dureeContrat = dureeContrat;
    this->secteurActivite = secteurActivite;
    this->interet = interet;
}

bool partenaire::ajouter()
{
    // Vérifier la longueur de la matricule fiscale
    if (matriculeFiscale.length() > 10)
    {
        QMessageBox::critical(nullptr, "Erreur", "La matricule fiscale ne peut pas dépasser 10 caractères.");
        return false;
    }

    // Vérifier la longueur du numéro de téléphone
    if (numeroTelephone.length() < 8 || numeroTelephone.length() > 15) // Limite de 8 à 15 chiffres pour le numéro de téléphone
    {
        QMessageBox::critical(nullptr, "Erreur", "Le numéro de téléphone doit contenir entre 8 et 15 chiffres.");
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO FOOL(MATRICULE_FISCALE, NOM_ENTREPRISE, ADRESSE, NUMERO_TELEPHONE, DUREE_CONTRAT, SECTEUR_ACTIVITE, INTERET) "
                  "VALUES (:matriculeFiscale, :nomEntreprise, :adresse, :numeroTelephone, :dureeContrat, :secteurActivite, :interet)");

    // Liage des valeurs aux paramètres

    query.bindValue(":matriculeFiscale", matriculeFiscale);
    query.bindValue(":nomEntreprise", nomEntreprise);
    query.bindValue(":adresse", adresse);
    query.bindValue(":numeroTelephone", numeroTelephone);
    query.bindValue(":dureeContrat", dureeContrat);
    query.bindValue(":secteurActivite", secteurActivite);
    query.bindValue(":interet", interet);

    if (!query.exec())
    {
        qDebug() << "Échec de l'exécution de la requête:" << query.lastError().text();
        qDebug() << "Erreur Oracle:" << query.lastError().databaseText();
        return false;
    }
    else
    {
        qDebug() << "Insertion réussie.";
        return true;
    }
}




bool partenaire::supprimer(const QString& matriculeFiscale)
{
    QSqlQuery query;
    query.prepare("DELETE FROM FOOL WHERE MATRICULE_FISCALE = :matriculeFiscale");
    query.bindValue(":matriculeFiscale", matriculeFiscale);

    if (!query.exec())
    {
        qDebug() << "Échec de l'exécution de la requête:" << query.lastError().text();
        qDebug() << "Erreur Oracle:" << query.lastError().databaseText();
        return false;
    }
    else
    {
        qDebug() << "Suppression réussie.";
        return true;
    }
}

bool partenaire::modifiercontrat(const QString& dureeContrat, const QString& nouveaudureeContrat)
{
    QSqlQuery query;
    query.prepare("UPDATE FOOL SET DUREE_CONTRAT = :nouveauDureeContrat WHERE DUREE_CONTRAT = :ancienneDureeContrat");
    query.bindValue(":nouveauDureeContrat", nouveaudureeContrat);
    query.bindValue(":ancienneDureeContrat", dureeContrat);

    if (!query.exec())
    {
        qDebug() << "Échec de l'exécution de la requête:" << query.lastError().text();
        qDebug() << "Erreur Oracle:" << query.lastError().databaseText();
        return false;
    }
    else
    {
        qDebug() << "Modification de la durée du contrat réussie.";
        return true;
    }
}


QSqlQueryModel* partenaire::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT MATRICULE_FISCALE, NOM_ENTREPRISE, ADRESSE, NUMERO_TELEPHONE, DUREE_CONTRAT, SECTEUR_ACTIVITE, INTERET FROM FOOL");

    // Définir les en-têtes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matriculeFiscale"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr(" nomEntreprise"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("numeroTelephone"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("dureeContrat"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("secteurActivite"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("interet"));

    return model;
};
