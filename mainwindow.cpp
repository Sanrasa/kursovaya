#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QImage>
#include <QColor>
#include "mainwindow.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    labelwidth = ui->label->width();
    labelheight = ui -> label -> height();

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_OpenF_clicked()
{
    FileGet FGet;
    pho = FGet.getFileName(); // реализация того же что и работает, только через класс
    // pho = QFileDialog::getOpenFileName(0, "Open Dialog","D://" , "Image Files ;*.png; *.jpg; *.jpeg"); // рабочий вариант загрузки фотографии
    orig.load(pho); // фоточка (QPixmap)
    pic.load(pho); // фоточка (QImage)
    k = FGet.Resize(orig, labelwidth, labelheight);
    view = QImage (pic);
    ui -> label -> setPixmap(orig);
    ui -> label -> setScaledContents(true);
    ui->label->setFixedWidth(k * ui->label->pixmap()->width());
    ui->label->setFixedHeight(k * ui->label->pixmap()->height());
    ui->label->setPixmap(QPixmap::fromImage(view));
}
void MainWindow::on_SaveF_clicked()
{

/*
    QFileInfo pholocation(pho);
    //QString file_name = pholocation.absolutePath() + "/" + pholocation.baseName() + "_(negative).png"; // v1.4
    QString tempFileName = pholocation.fileName();
    QString tempFileName = pholocation.absolutePath().replace(pholocation.lastIndexOf(""), subStr.size(), newStr)
                                                     .replace(".png","_(negative).png")
                                                     .replace(".jpg","_(negative).png")
                                                     .replace(".jpeg","_(negative).png"); v2.0
*/

     //file_name = pholocation.absolutePath() + "/" + tempFileName.replace(tempFileName.lastIndexOf(".png"), 4," (negative).png")
       //                                                                   .replace(tempFileName.lastIndexOf(".jpeg"), 5," (negative).png")
         //                                                                 .replace(tempFileName.lastIndexOf(".jpg"), 4," (negative).png"); // v2.1

    FileSave FSave;
    file_name = FSave.saveFileName(pho);
    std::cout<<file_name.toStdString();
  view.save(file_name);
}


void MainWindow::on_ConvertF_clicked()
{
    FileConvert FConvert;
    view = FConvert.Convert(QImage(pho));
    ui->label->setPixmap(QPixmap::fromImage(view));

    /*
    view = QImage(pho);
        for (int w = 0; w<view.rect().right();w++)
            for (int h = 0; h<view.rect().bottom();h++)
            {
                QColor col(view.pixel(w,h));
                int r = col.red();
                int g = col.green();
                int b = col.blue();
                r = 255 - r;
                g = 255 - g;
                b = 255 - b;
                col.setRgb(r,g,b, 0);
                view.setPixel(w,h,col.rgb());
            }
     */

}

