#include "login.h"
#include "dash.h"
#include "ui_widget.h"
#include <QPixmap>

#include <QtSql>
#include <QDebug>
#include <QFileInfo>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPixmap pix(":/Ressourses/Picture/Login.png");
    ui->label_Picture2->setPixmap(pix);
    if (!connOpen())
        ui->label->setText("Failed to open the database");
    else
        ui->label->setText("Conneted...");


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString username = ui  -> lineEdit_Username -> text();
    QString password = ui  ->  lineEdit_Password -> text();

    if (!connOpen()){
        qDebug() <<"Failed to open database";
        return;}

    connOpen();
    QSqlQuery query;

    query.prepare("SELECT * FROM ADMIN WHERE Username = '"+username+"' AND Password = "+password );
    qDebug() << query.lastQuery();
    qDebug() << query.exec();


    if (sqlSize(std::move(query)) != 0) {
        qDebug() <<"PASSWORD IS CORRECT";
        mydb.close();
        this->hide();
        Menu menu;
        menu.setModal(true);
        menu.exec();}
    else
        ui->label_Login->setText("Le username ou password sont incorrecte !");








}

//"SELECT * FROM ADMIN WHERE Username = ''aa'' AND password = ''"
//"SELECT * FROM ADMIN WHERE Username = 'admin' AND password = 123456789"
//"SELECT * FROM ADMIN WHERE Username = 'admin' AND password = 123456789"
//"SELECT * FROM ADMIN WHERE Username = 'admin' AND password = '123456789'"
