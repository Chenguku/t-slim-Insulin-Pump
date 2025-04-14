#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>

class DBManager{
    public:
        DBManager();

    private:
        QSqlDatabase tslimDB;
};

#endif // DBMANAGER_H
