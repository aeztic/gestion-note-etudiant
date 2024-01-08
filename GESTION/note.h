#ifndef NOTE_H
#define NOTE_H


#include <QDialog>
#include <login.h>

namespace Ui {
class Note_Abs;
}

class Note_Abs : public QDialog
{
    Q_OBJECT

public:
    explicit Note_Abs(QWidget *parent = nullptr);
    ~Note_Abs();

private slots:
    void on_pushButton_afficher_3_clicked();
    void on_pushButton_ajouter_3_clicked();
    void on_pushButton_modifier_3_clicked();
    void on_pushButton_supprimer_3_clicked();
    void on_pushButton_ajouter_4_clicked();
    void on_pushButton_afficher_4_clicked();
    void on_pushButton_modifier_4_clicked();
    void on_pushButton_supprimer_4_clicked();

private:
    Ui::Note_Abs *ui;
    Widget conn;
};

#endif //NOTE_H

