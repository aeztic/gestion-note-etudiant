// professeur.h
#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include <QString>

class Professeur {
public:
    Professeur(const QString& cni, const QString& nom, const QString& prenom, const QString& telephone);

    QString getCNI() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getTelephone() const;

private:
    QString cni;
    QString nom;
    QString prenom;
    QString telephone;
};

#endif // PROFESSEUR_H
