#include "dash.h"
#include "ui_menu.h"
#include "login.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QDebug>
#include "note.h"

Menu::Menu(QWidget *parent) : QDialog(parent), ui(new Ui::Menu) {
    ui->setupUi(this);

    // Initialize other parts of your UI
    QPixmap pix(":/Ressourses/Picture/Plan.png");
    ui->label_Picture->setPixmap(pix);

    Widget conn;
    if (!conn.connOpen())
        ui->label_menu->setText("Failed to open the database");
    else
        ui->label_menu->setText("Connected...");
}

Menu::~Menu() {
    delete ui;
}

void Menu::on_pushButton_ajouter_clicked() {
    Widget conn;
    QString CNE = ui->texte_CNE->text();
    QString Nom = ui->texte_Nom->text();
    QString Prenom = ui->texte_prenom->text();
    QDate DN = ui->DN->date();
    QString Birthday = DN.toString();

    if (!conn.connOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery query;
    query.exec("create table Etudiant(CNE Varchar(20) primary key, "
               "Nom varchar(20), Prénom varchar(20),Date_de_naissance int)");

    query.prepare("insert into Etudiant values('" + CNE + "','" + Nom + "','" + Prenom + "','" + Birthday + "');");
    qDebug() << query.lastQuery();

    if (query.exec()) {
        QMessageBox msgBox;
        msgBox.setText("L'étudiant a été enregistré avec succès !");
        msgBox.exec();
        conn.connClose();
    } else {
        QMessageBox::critical(this, tr("ERROR::"), tr("L'étudiant n'a pas été enregistré !"));
    }
}

void Menu::on_pushButton_modifier_clicked() {
    Widget conn;
    QString CNE = ui->texte_CNE->text();
    QString Nom = ui->texte_Nom->text();
    QString Prenom = ui->texte_prenom->text();
    QDate DN = ui->DN->date();
    QString Birthday = DN.toString();

    if (!conn.connOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery query;
    query.prepare("UPDATE Etudiant SET CNE ='" + CNE + "',Nom='" + Nom + "',Prénom='" + Prenom + "',Date_de_naissance='" + Birthday + "' WHERE CNE ='" + CNE + "';");
    qDebug() << query.lastQuery();

    if (query.exec()) {
        QMessageBox msgBox;
        msgBox.setText("L'étudiant a été modifié avec succès !");
        msgBox.exec();
        conn.connClose();
    } else {
        QMessageBox::critical(this, tr("ERROR::"), tr("L'étudiant n'a pas été modifié !"));
    }
}

void Menu::on_pushButton_supprimer_clicked() {
    Widget conn;
    QString CNE = ui->texte_CNE->text();

    if (!conn.connOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery query;
    query.prepare("DELETE FROM Etudiant WHERE CNE ='" + CNE + "';");
    qDebug() << query.lastQuery();

    if (query.exec()) {
        QMessageBox msgBox;
        msgBox.setText("L'étudiant a été supprimé avec succès !");
        msgBox.exec();
        conn.connClose();
    } else {
        QMessageBox::critical(this, tr("ERROR::"), tr("L'étudiant n'a pas été supprimé !"));
    }
}

void Menu::on_pushButton_afficher_clicked() {
    Widget conn;
    QSqlQueryModel *Modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *query = new QSqlQuery(conn.mydb);
    query->prepare("SELECT * FROM Etudiant");
    query->exec();
    Modal->setQuery(std::move(*query));
    ui->tableView->setModel(Modal);
}

void Menu::on_pushButton_ajouter_2_clicked() {
    Widget conn;
    QString CNI = ui->texte_CIN_2->text();
    QString Nom = ui->texte_Nom_2->text();
    QString Prenom = ui->texte_prenom_2->text();
    QString Telephone = ui->texte_Telephone_2->text();

    if (!conn.connOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery query;
    query.prepare("insert into Professeur values(" + CNI + ",'" + Nom + "','" + Prenom + "'," + Telephone + ");");
    qDebug() << query.lastQuery();

    if (query.exec()) {
        QMessageBox msgBox;
        msgBox.setText("Le professeur a été enregistré avec succès !");
        msgBox.exec();
        conn.connClose();
    } else {
        QMessageBox::critical(this, tr("ERROR::"), tr("Le professeur n'a pas été enregistré"));
    }
}

void Menu::on_pushButton_modifier_2_clicked() {
    Widget conn;
    QString CNI = ui->texte_CIN_2->text();
    QString Nom = ui->texte_Nom_2->text();
    QString Prenom = ui->texte_prenom_2->text();
    QString Telephone = ui->texte_Telephone_2->text();

    if (!conn.connOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery query;
    query.prepare("UPDATE Professeur SET CNE =" + CNI + ",Nom='" + Nom + "',Prénom='" + Prenom + "',Date_de_naissance=" + Telephone + " WHERE CNE =" + CNI + ";");
    qDebug() << query.lastQuery();

    if (query.exec()) {
        QMessageBox msgBox;
        msgBox.setText("Le professeur a été modifié avec succès !");
        msgBox.exec();
        conn.connClose();
    } else {
        QMessageBox::critical(this, tr("ERROR::"), tr("Le professeur n'a pas été modifié !"));
    }
}

void Menu::on_pushButton_supprimer_2_clicked() {
    Widget conn;
    QString CNI = ui->texte_CIN_2->text();

    if (!conn.connOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery query;
    query.prepare("DELETE FROM Professeur WHERE CNE =" + CNI + ";");
    qDebug() << query.lastQuery();

    if (query.exec()) {
        QMessageBox msgBox;
        msgBox.setText("Le professeur a été supprimé avec succès !");
        msgBox.exec();
        conn.connClose();
    } else {
        QMessageBox::critical(this, tr("ERROR::"), tr("Le professeur n'a pas été supprimé !"));
    }
}

void Menu::on_pushButton_afficher_2_clicked() {
    Widget conn;
    QSqlQueryModel *Modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *query = new QSqlQuery(conn.mydb);
    query->prepare("SELECT * FROM Professeur");
    query->exec();
    Modal->setQuery(std::move(*query));
    ui->tableView->setModel(Modal);
}

void Menu::on_pushButton_ajouter_3_clicked() {
    Widget conn;
    QString ID = ui->texte_ID->text();
    QString Libelle = ui->texte_Libelle->text();
    QString Coeff = ui->texte_Coeff->text();
    QString CIN = ui->texte_CIN_3->text();

    if (!conn.connOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery query;

    // Convert ID to integer if it's an integer
    bool isIdInt;
    int idInt = ID.toInt(&isIdInt);

    if (isIdInt) {
        query.prepare("insert into Matiere values(" + QString::number(idInt) + ",'" + Libelle + "','" + Coeff + "','" + CIN + "');");
        qDebug() << query.lastQuery();
    } else {
        // Handle the case where ID is not an integer
        QMessageBox::critical(this, tr("ERROR"), tr("Le ID doit être un entier !"));
        conn.connClose();
        return;
    }

    if (query.exec()) {
        QMessageBox msgBox;
        msgBox.setText("La matière a été enregistré avec succès !");
        msgBox.exec();
        conn.connClose();
    } else {
        QMessageBox::critical(this, tr("ERROR::"), tr("La matière n'a pas été enregistré !"));
    }
}

void Menu::on_pushButton_modifier_3_clicked() {
    Widget conn;
    QString ID = ui->texte_ID->text();
    QString Libelle = ui->texte_Libelle->text();
    QString Coeff = ui->texte_Coeff->text();
    QString CIN = ui->texte_CIN_3->text();

    if (!conn.connOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery query;
    query.prepare("UPDATE Matiere SET Id_matiere =" + ID + ", Libelle='" + Libelle + "', Coeff='" + Coeff + "', CIN='" + CIN + "' WHERE Id_matiere =" + ID + ";");
    qDebug() << query.lastQuery();

    if (query.exec()) {
        QMessageBox msgBox;
        msgBox.setText("La matière a été modifié avec succès !");
        msgBox.exec();
        conn.connClose();
    } else {
        QMessageBox::critical(this, tr("ERROR::"), tr("La matière n'a pas été modifié !"));
    }
}

void Menu::on_pushButton_supprimer_3_clicked() {
    Widget conn;
    QString ID = ui->texte_ID->text();

    if (!conn.connOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery query;
    query.prepare("DELETE FROM Matiere WHERE Id_matiere =" + ID + ";");
    qDebug() << query.lastQuery();

    if (query.exec()) {
        QMessageBox msgBox;
        msgBox.setText("La matière a été supprimé avec succès !");
        msgBox.exec();
        conn.connClose();
    } else {
        QMessageBox::critical(this, tr("ERROR::"), tr("La matière n'a pas été supprimé !"));
    }
}

void Menu::on_pushButton_afficher_3_clicked() {
    Widget conn;
    QSqlQueryModel *Modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *query = new QSqlQuery(conn.mydb);
    query->prepare("SELECT * FROM Matiere");
    query->exec();
    Modal->setQuery(std::move(*query));
    ui->tableView->setModel(Modal);
}

void Menu::on_pushButton_clicked() {
    Note_Abs NoteAbs;
    NoteAbs.setModal(true);
    NoteAbs.exec();
}
