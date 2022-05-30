#include "filesave.h"

FileSave::FileSave(QObject *parent)
    : QObject{parent}
{

}

QString FileSave::saveFileName(QString pho)
{
    QFileInfo pholocation(pho);
    QString tempFileName = pholocation.fileName();
    QString File_Name = pholocation.absolutePath().replace(tempFileName.lastIndexOf(".png"), 4," (negative).png")
                                                  .replace(tempFileName.lastIndexOf(".jpeg"), 5," (negative).png")
                                                  .replace(tempFileName.lastIndexOf(".jpg"), 4," (negative).png");
    return (File_Name);
};
