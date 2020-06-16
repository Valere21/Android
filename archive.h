#ifndef ARCHIVE_H
#define ARCHIVE_H
#include <QFile>

class Archive
{
public:
    Archive();

    void newFile();




protected:

    QFile *m_fileArchive;

    QString getTime();





};

#endif // ARCHIVE_H
