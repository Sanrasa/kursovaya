#ifndef FILESAVE_H
#define FILESAVE_H

#include <QObject>
#include <QFileInfo>
#include <QString>
#include <QImage>

class FileSave : public QObject
{
    Q_OBJECT
public:
    explicit FileSave(QObject *parent = nullptr);

    QString saveFileName(QString pho);

private:
    QString File_Name;
};

#endif // FILESAVE_H
