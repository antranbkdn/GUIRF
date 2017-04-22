#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mainAk = new ak();
    connect(this,SIGNAL(destroyed()),mainAk,SLOT(deleteLater()));
    mainAk->start(QThread::TimeCriticalPriority);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    ak.sendData();//lien ket toi code phan cung
}

void MainWindow::on_pushButton_2_clicked()
{
   qDebug()<<"chao ban";
}

void MainWindow::on_pushButton_3_clicked()
{
//    pm = new Thread();
//    pm->start();
}
