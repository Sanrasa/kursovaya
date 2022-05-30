#ifndef FILEGET_H
#define FILEGET_H

#include <QObject>
#include <QImage>
#include <QPixmap>
#include <QFileDialog>

class FileGet : public QObject
{
    Q_OBJECT
public:
    explicit FileGet(QObject *parent = nullptr);

    QString Photo;
    QString getFileName();
    QString load();

    double Resize(QPixmap pho, int width, int height);

private:

    QString File_Name;
    double k;
};

#endif // FILEGET_H
