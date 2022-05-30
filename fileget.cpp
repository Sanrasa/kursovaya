#include "fileget.h"
#include <QFileDialog>

FileGet::FileGet(QObject *parent)
    : QObject{parent}
{

}

QString FileGet::getFileName()
{
    File_Name = QFileDialog::getOpenFileName(0, "Open Dialog","C:/" , "Image Files ;*.png; *.jpg; *.jpeg");
    return File_Name;
}

double FileGet::Resize(QPixmap pic, int width, int height)
{
    int picwidth = pic.width();
    int picheight = pic.height();
    double factorw = (width + 0.0)/picwidth;
    double factorh = (height + 0.0)/picheight;
    double k = 0;
    if (factorw > 1 && factorh > 1)
    {
        if (factorh < factorw)
            k = factorh;
        else
            k = factorw;
    }
    else
    {
        if (factorh < factorw)
            k = factorh;
        else
            k = factorw;
    }
    return (k);
}
