#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    RT = new readThread();

    connect(this,SIGNAL(sendFileNames2T(QStringList)),RT,SLOT(receiveFileNames(QStringList)));
    connect(RT,SIGNAL(sendChangeFile2M(QString)),this,SLOT(receiveFileNameFromT(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
        QStringList str_path_list = QFileDialog::getOpenFileNames(this, tr("选择转码文件"), tr("/home"));
        for (int i = 0; i < str_path_list.size(); i++)
        {
            QString str_path = str_path_list[i];
            //单个文件路径
            ui->textBrowser->append(str_path+"\t\n");
            QFileInfo file = QFileInfo(str_path);
            file_list.append(str_path);
        }
        emit sendFileNames2T(file_list);
}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_pushButton_3_clicked()//
{

       RT->start();

}
void MainWindow::receiveFileNameFromT(QString filename)
 {
     ui->textBrowser_2->append(filename+"\t\n");
 }
