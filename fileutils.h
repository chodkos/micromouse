#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <QString>


class FileUtils
{
private:
    FileUtils();
    inline static const QString PATH = "C:\\Users\\lukasz\\Documents\\maze\\bigmaze.txt";
public:
    static QVector<QString> readFile();
};

#endif // FILEUTILS_H
