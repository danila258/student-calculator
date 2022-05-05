#ifndef DATABASE_H
#define DATABASE_H

#include "Student.h"
#include <vector>
#include <exception>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QDebug>

typedef QVector<QStringList> fileData;

class Database {
public:
    Database() = default;
    explicit Database(int n);

    void storeFile(QString& filePath, int fileNum);
    void restoreFile(int fileNum);

    fileData& operator[](int i);

    void clearData(int fileNum);

private:
    std::vector<fileData> _filesData;
    std::vector<QString> _filesPathes;
};

#endif //DATABASE_H

// GET HEADER
// FIND