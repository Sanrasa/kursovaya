#ifndef FILECONVERT_H
#define FILECONVERT_H

#include <QObject>
#include <QImage>

class FileConvert : public QObject
{
    Q_OBJECT
public:
    explicit FileConvert(QObject *parent = nullptr);

QImage Convert(QImage view);

};

#endif // FILECONVERT_H
