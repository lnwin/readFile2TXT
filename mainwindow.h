#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <readthread.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QStringList file_list;
    readThread  *RT;

signals:
    void sendFileNames2T(QStringList);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void receiveFileNameFromT(QString);
private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
