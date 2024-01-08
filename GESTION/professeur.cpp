// professeur.cpp
#include "professeur.h"

Professeur::Professeur(const QString& cni, const QString& nom, const QString& prenom, const QString& telephone)
    : cni(cni), nom(nom), prenom(prenom), telephone(telephone) {}

QString Professeur::getCNI() const {
    return cni;
}

QString Professeur::getNom() const {
    return nom;
}

QString Professeur::getPrenom() const {
    return prenom;
}

QString Professeur::getTelephone() const {
    return telephone;
}
