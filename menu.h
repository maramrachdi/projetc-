#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QtGui>
#include <QStackedWidget>
#include <QMainWindow>
#include"equipement.h"

QT_BEGIN_NAMESPACE
namespace Ui { class menu; }
QT_END_NAMESPACE

class menu : public QMainWindow
{
    Q_OBJECT

public:
    menu(QWidget *parent = nullptr);
     void setequipement(Equipement e);
    ~menu();

private slots:
    void on_perosonelle_2_clicked();

    void on_programe_2_clicked();

    void on_invite_2_clicked();

    void on_equipment_2_clicked();

    void on_sponsor_2_clicked();

    void on_perosonelle_clicked();

    void on_programe_clicked();

    void on_invite_clicked();

    void on_equipment_clicked();

    void on_sponsor_clicked();

    void on_quitter_2_clicked();

    void on_quitter_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();




    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::menu *ui;
    Equipement tmpequipement;
};
#endif // MENU_H
