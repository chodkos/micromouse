#include "fileutils.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <iostream>

FileUtils::FileUtils() {}

QVector<QString> FileUtils::readFile()
{
    QFile file(PATH);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream inputStream(&file);
    QVector<QString> rows;
    while(!inputStream.atEnd()) {
        QString row = inputStream.readLine();
        rows.append(row);
    }
    file.close();
    return rows;
}


