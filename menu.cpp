#include "menu.h"
#include "ui_menu.h"
#include<QPixmap>
#include"equipement.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QMessageBox>
#include<QString>
#include <QObject>
#include<QSqlQueryModel>
menu::menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));
   ui->tableequipement->setModel(tmpequipement.afficher());
   ui->lineEdit_id->setValidator(new QIntValidator(0,999999999,this));
   ui->lineEdit_prix->setValidator(new QIntValidator(0,99999999,this));
   ui->lineEdit_id_p->setValidator(new QIntValidator(0,99999999,this));

   QPixmap pix("C:/Users/Admin/Downloads/photo.png");

    ui->back->setPixmap(pix.scaled(950,950,Qt::KeepAspectRatio));


}

menu::~menu()
{
    delete ui;
}


void menu::on_perosonelle_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menu::on_programe_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void menu::on_invite_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void menu::on_equipment_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void menu::on_sponsor_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}
void menu::on_perosonelle_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void menu::on_programe_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void menu::on_invite_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void menu::on_equipment_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void menu::on_sponsor_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void menu::on_quitter_2_clicked()
{
    close();
}

void menu::on_quitter_clicked()
{
    close();
}

void menu::on_pushButton_3_clicked()
{

    on_pushButton_2_clicked();
       ui->stackedWidget_2->setCurrentWidget(ui->page);


}

void menu::on_pushButton_4_clicked()
{   QSqlQuery query;
    ui->stackedWidget_2->setCurrentWidget(ui->page_4);
    ui->tableequipement_2->setModel(tmpequipement.afficher());


}
void menu::on_pushButton_5_clicked()
{

 ui->stackedWidget_2->setCurrentWidget(ui->page_3);
}
void menu::on_pushButton_6_clicked()
{
    ui->stackedWidget_2->setCurrentWidget(ui->page_2);
    ui->tableequipement->setModel(tmpequipement.afficher());
}


void menu::on_pushButton_2_clicked()
{

    int idE = ui->lineEdit_id->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString type = ui->lineEdit_type->text();
    int prix = ui->lineEdit_prix->text().toInt();
    QString etat = ui->lineEdit_etat->text();
    QString caracteristique = ui->lineEdit_caracteristique->text();
     int id_p = ui->lineEdit_id_p->text().toInt();

     if (prix < 0) {
          QMessageBox::warning(nullptr, tr("Erreur"), tr("Le prix ne peut pas être négatif."));
          return;
      }

     if (etat != "en bon état" && etat != "en très bon état" && etat != "en mauvais état") {
          QMessageBox::warning(nullptr, tr("Erreur"), tr("L'état de l'équipement doit être 'en bon état', 'en très bon état' ou 'en mauvais état'."));
          return;
      }



    Equipement e(idE, nom, type, prix, etat, caracteristique,id_p);
    bool test = e.ajouter();


    if (test)
    {
        ui->stackedWidget_2->setCurrentWidget(ui->page_2);
        ui->tableequipement->setModel(tmpequipement.afficher());
        QMessageBox::information(nullptr, tr("Information"), tr("Ajout d'un equipement avec succès."));
    }
}

bool Equipement::ajouter()
{

    QSqlQuery query;
    QString res = QString::number(id);


    query.prepare("INSERT INTO equipement (id,nom,type,prix,etat,caracteristique,id_p)VALUES (:id, :nom, :type, :prix, :etat, :caracteristique, :id_p)");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);
    query.bindValue(":prix",prix);
    query.bindValue(":etat",etat);
    query.bindValue(":caracteristique",caracteristique);
     query.bindValue(":id_p",id_p);
    return query.exec();


}


QSqlQueryModel * Equipement::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();


    model->setQuery("select * from equipement");
    model->setHeaderData(0, Qt::Horizontal ,QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal ,QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal ,QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal ,QObject::tr("prix"));
    model->setHeaderData(4, Qt::Horizontal ,QObject::tr("etat"));
    model->setHeaderData(5, Qt::Horizontal ,QObject::tr("caracteristique"));
    model->setHeaderData(6, Qt::Horizontal ,QObject::tr("id_p"));
    return model;
}



bool Equipement::supprimer(int idd)
{

   QSqlQuery query;
   QString res= QString::number(idd);
   query.prepare("delete from equipement where id= :id");
   query.bindValue(":id",res);
   return query.exec();
}

bool Equipement::existe(int id)
{
    QSqlQuery query;
    query.prepare("SELECT count(*) FROM equipement WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();
    query.next();
    int count = query.value(0).toInt();
    return count > 0;
}

void menu::on_pushButton_7_clicked()
{
    QString idText = ui->lineEdit_id_2->text();



    int id = idText.toInt();


    if(!tmpequipement.existe(id)) {
        QMessageBox::warning(this, tr("Erreur"), tr("Aucun equipement trouvé avec cet id"));
        return;
    }


    bool test = tmpequipement.supprimer(id);

    if(test) {
        ui->tableequipement->setModel(tmpequipement.afficher());
        QMessageBox::information(nullptr, tr("Supprimer"), tr("equipement supprimé avec succès"));
    } else {
        QMessageBox::information(nullptr, tr("Supprimer"), tr("Erreur lors de la suppression de l'equipement"));
    }
}



void menu::on_pushButton_8_clicked()
{
    QString id = ui->lineEdit_i->text();


    if(id.isEmpty()) {
        QMessageBox::warning(nullptr, tr("Erreur"), tr("Veuillez entrer l'id)."));
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM equipement WHERE id = :id");
    query.bindValue(":id", id);

    if(query.exec() && query.next()) {

        QString nom = query.value("nom").toString();
        QString type = query.value("type").toString();
        QString prix = query.value("prix").toString();
        QString etat = query.value("etat").toString();
        QString caracteristique = query.value("caracteristique").toString();
         QString id_p = query.value("id_p").toString();


        ui->lineEdit_n_2->setText(nom);
        ui->lineEdit_t_2->setText(type);
        ui->lineEdit_p->setText(prix);
        ui->lineEdit_e->setText(etat);
        ui->lineEdit_ca->setText(caracteristique);
         ui->lineEdit_idp->setText(id_p);


    } else {
        QMessageBox::warning(nullptr, tr("Erreur"), tr("Aucun equipement trouvé avec cet id"));
    }
}




void menu::on_pushButton_9_clicked()
{
     QSqlQuery query;
      QString nouvelEtat = ui->lineEdit_e->text();
      if (nouvelEtat != "en bon état" && nouvelEtat != "en très bon état" && nouvelEtat != "en mauvais état") {
          QMessageBox::warning(nullptr, tr("Erreur"), tr("Le nouvel état de l'équipement doit être 'en bon état', 'en très bon état' ou 'en mauvais état'."));
          return;
      }
    query.prepare("UPDATE equipement SET nom = :nom, type = :type, prix = :prix, etat = :etat, caracteristique = :caracteristique, id_p = :id_p WHERE id =" + ui->lineEdit_i->text() +"");
    query.bindValue(":nom",ui->lineEdit_n_2->text());
    query.bindValue(":type",ui->lineEdit_t_2->text());
    query.bindValue(":prix",ui->lineEdit_p->text());
    query.bindValue(":etat",ui->lineEdit_e->text());
    query.bindValue(":caracteristique",ui->lineEdit_ca->text());
   query.bindValue(":id_p",ui->lineEdit_idp->text());


    query.exec();
    ui->stackedWidget_2->setCurrentWidget(ui->page_4);
    ui->tableequipement_2->setModel(tmpequipement.afficher());
}
