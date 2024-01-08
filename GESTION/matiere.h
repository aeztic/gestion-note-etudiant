// matiere.h
#ifndef MATIERE_H
#define MATIERE_H

#include <QString>

class Matiere {
public:
    Matiere(int id, const QString& libelle, const QString& coeff, const QString& cni);

    int getId() const;
    QString getLibelle() const;
    QString getCoeff() const;
    QString getCNI() const;

private:
    int id;
    QString libelle;
    QString coeff;
    QString cni;
};

#endif // MATIERE_H
