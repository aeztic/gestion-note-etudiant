#include "note.h"
#include "ui_note_abs.h"
#include <QMessageBox>
#include <QPixmap>
#include <QDebug>

Note_Abs::Note_Abs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Note_Abs)
{
    ui->setupUi(this);
    QPixmap pix("/Users/aeztic/Documents/GESTION/Picture/Note.png");
    ui->label_Picture5->setPixmap(pix);
}

Note_Abs::~Note_Abs()
{
    delete ui;
}

void Note_Abs::on_pushButton_ajouter_3_clicked()
{
    QString CNE = ui->texte_CNE_Abs->text();
    QString Id_matiere = ui->texte_Id_Abs->text();
    QString Nbr_h = ui->texte_Nbr_Abs->text();

    if (!conn.connOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery query;

    query.exec("CREATE TABLE Abs (CNE VARCHAR(20) NOT NULL, "
               "Id_matiere INTEGER NOT NULL, nbr_h INTEGER, PRIMARY KEY (CNE, Id_matiere));");
    query.prepare("insert into Abs values('" + CNE + "'," + Id_matiere + "," + Nbr_h + ");");
    qDebug() << query.lastQuery();

    if (query.exec()) {
        QMessageBox msgBox;
        msgBox.setText("L'étudiant a été ajouté avec succès !");
        msgBox.exec();
        conn.connClose();
    } else {
        QMessageBox::critical(this, tr("ERROR::"), tr("L'étudiant n'a pas été ajouté !"));
    }
}

void Note_Abs::on_pushButton_afficher_3_clicked()
{
    QSqlQueryModel *Modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *query = new QSqlQuery(conn.mydb);
    query->prepare("SELECT * FROM Abs");
    query->exec();
    Modal->setQuery(std::move(*query));
    ui->tableView->setModel(Modal);
}

void Note_Abs::on_pushButton_modifier_3_clicked()
{
    QString CNE = ui->texte_CNE_Abs->text();
    QString Id_matiere = ui->texte_Id_Abs->text();
    QString Nbr_h = ui->texte_Nbr_Abs->text();

    if (!conn.connOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery query;

    query.prepare("UPDATE Abs SET CNE ='" + CNE + "', Id_matiere=" + Id_matiere + ", nbr_h=" + Nbr_h + " WHERE CNE ='" + CNE + "' AND Id_matiere=" + Id_matiere + ";");
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

void Note_Abs::on_pushButton_supprimer_3_clicked()
{
    QString CNE = ui->texte_CNE_Abs->text();
    QString Id_matiere = ui->texte_Id_Abs->text();
    QString Nbr_h = ui->texte_Nbr_Abs->text();

    if (!conn.connOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery query;

    query.prepare("DELETE FROM Abs WHERE CNE ='" + CNE + "';");
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

void Note_Abs::on_pushButton_ajouter_4_clicked()
{
    QString CNE = ui->texte_CNE_Note->text();
    QString Id_matiere = ui->texte_Id_Note->text();
    QString Note = ui->texte_Note->text();

    if (!conn.connOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery query;

    query.exec("CREATE TABLE Evaluation (CNE VARCHAR(20) NOT NULL, "
               "Id_matiere INTEGER NOT NULL, Note INTEGER, PRIMARY KEY (CNE, Id_matiere));");
    query.prepare("insert into Evaluation values('" + CNE + "'," + Id_matiere + "," + Note + ");");
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

void Note_Abs::on_pushButton_afficher_4_clicked()
{
    QSqlQueryModel *Modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *query = new QSqlQuery(conn.mydb);
    query->prepare("SELECT * FROM Evaluation");
    query->exec();
    Modal->setQuery(std::move(*query));
    ui->tableView->setModel(Modal);
}

void Note_Abs::on_pushButton_modifier_4_clicked()
{
    QString CNE = ui->texte_CNE_Note->text();
    QString Id_matiere = ui->texte_Id_Note->text();
    QString Note = ui->texte_Note->text();

    if (!conn.connOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery query;

    query.prepare("UPDATE Evaluation SET CNE ='" + CNE + "', Id_matiere=" + Id_matiere + ", Note=" + Note + " WHERE CNE ='"
                  + CNE + "' AND Id_matiere=" + Id_matiere + ";");
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

void Note_Abs::on_pushButton_supprimer_4_clicked()
{
    QString CNE = ui->texte_CNE_Note->text();
    QString Id_matiere = ui->texte_Id_Note->text();
    QString Note = ui->texte_Note->text();

    if (!conn.connOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery query;

    query.prepare("DELETE FROM Evaluation WHERE CNE ='" + CNE + "';");
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
