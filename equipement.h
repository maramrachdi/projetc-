
#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include<QString>
#include<QSqlQueryModel>
#include <QTableWidget>
class Equipement
{
public:


    bool ajouter();
     QSqlQueryModel* afficher();
    bool supprimer(int idd);
    Equipement(int id, QString nom, QString type, int prix, QString etat, QString caracteristique,int id_p);

    void setid_pi(int n);
    bool existe(int id);



    bool modifier(int idd, const QString &newNom, const QString &newType, int &newPrix, const QString &newEtat ,const QString &newCaracteristique , int &newid_p);




    Equipement();

private:
    int id, prix,id_p;
     QString nom,type,etat,caracteristique;

};

#endif // EQUIPEMENT_H
