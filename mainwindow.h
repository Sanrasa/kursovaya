#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QImage>
#include <QPixmap>
#include "fileget.h"
#include "filesave.h"
#include "fileconvert.h"
#include <QFileInfo>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_OpenF_clicked();

    void on_SaveF_clicked();

    void on_ConvertF_clicked();

private:
    Ui::MainWindow *ui;
    double k;
    QImage view;
    QImage pic;
    QPixmap orig;
    QString pho;
    int labelwidth;
    int labelheight;
    QString file_name;
};
#endif // MAINWINDOW_H
