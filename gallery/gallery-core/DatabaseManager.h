#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "AlbumDao.h"
#include "PictureDao.h"
#include <memory>
#include <QString>

class QSqlQuery;
class QSqlDatabase;

const QString DATABASE_FILENAME = "gallery.db";

class DatabaseManager {
public:
    static DatabaseManager &instance();
    ~DatabaseManager();

    static void debugQuery(const QSqlQuery &query);

protected:
    DatabaseManager(const QString &path = DATABASE_FILENAME);
    DatabaseManager &operator=(const DatabaseManager &rhs);

private:
    std::unique_ptr<QSqlDatabase> mDatabase;

public:
    const AlbumDao albumDao;
    const PictureDao pictureDao;
};

#endif // DATABASEMANAGER_H
