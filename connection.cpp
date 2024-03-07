#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test");
db.setUserName("maram");//inserer nom de l'utilisateur
db.setPassword("abc");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
void::Connection::fermerconnexion(){db.close();}
