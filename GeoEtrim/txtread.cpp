#include "txtread.h"

#include <QFile>
#include <QTextStream>
#include "QDebug"

txtRead::txtRead()
{
}

QList<QStringList> txtRead::Read(QString roaD)
{
    QList<QStringList> list;

    QFile inputFile(roaD);

    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();

            QStringList listOrder = line.split("\t");

            list.append(listOrder);
        }
        inputFile.close();
    }
    return list;
}


