#include <QFile>
#include <QString>
#include <QDir>
#include <QDebug>
#include <QStandardPaths>
#include <QDateTime>
#include "archive.h"

Archive::Archive()
{

    newFile();

}


void Archive::newFile()
{
    QString pathDesktop =  QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString nameFile = "/archiveRaspberry";
    QDir filePath(pathDesktop);                                              //La classe QDir fournit un accès au fichier, il est lié à un string Path pour lui indiquer quel fichier..

    bool creationState = false;

    if(!filePath.exists())                                                    //Si le chemin "d" n'existe pas ..
    {
        creationState = filePath.mkpath(pathDesktop);                                         //La fct mkpth permet de crée des fichiers si il en manque
        if (!creationState)
            qWarning()<<"Erreur de creation du fichier";
    }



   QString pathFile = QString(pathDesktop).append(nameFile).append(".txt");
   //QString pathFile = QString(pathDesktop).append(nameFile).append(".txt");               //Définit le nom du fichier




   QString fichier = QString(pathFile);

   m_fileArchive = new QFile(fichier);
   qWarning()<<" ouverture du fichier";
   m_fileArchive->open(QIODevice::ReadWrite | QIODevice::Append);

   if (!m_fileArchive->isOpen())
   {
       qWarning()<<"Erreur d'ouverture du fichier";
   }

qDebug() << "Test de fichier ok";
   m_fileArchive->write("test");
   m_fileArchive->close();
   delete m_fileArchive;

}


