#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <QString>

/*!
 * \brief The FileUtils class
 * Klasa uzytkowa, do wczytywania danych z pliku
 */
class FileUtils
{
private:
    FileUtils();
    inline static const QString PATH = "C:\\Users\\lukasz\\Documents\\maze\\bigmaze.txt";
public:
    /*!
     * \brief readFile
     * \return QVector<QString>
     * metoda wczytujaca dane z pliku, zwraca QVector zawierajacy wiersz danych
     */
    static QVector<QString> readFile();
};

#endif // FILEUTILS_H
