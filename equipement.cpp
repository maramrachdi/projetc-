#include "equipement.h"
#include<QSqlQueryModel>

Equipement::Equipement()
{
  id=0;
  nom="";
  type="";
  prix=0;
  etat="";
  caracteristique="";
  id_p=0;

}



bool ajouter();
Equipement::Equipement(int id, QString nom, QString type, int prix, QString etat, QString caracteristique,int id_p)
    : id(id), nom(nom), type(type), prix(prix), etat(etat), caracteristique(caracteristique),id_p(id_p) {}

QSqlQueryModel afficher();
bool supprimer(int idd);

bool modifier(int idd, const QString &newNom, const QString &newType, const QString &newPrix, const QString &newEtat, const QString &newCaracteristique,const QString &newId_p);

