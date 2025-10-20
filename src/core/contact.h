#ifndef CONTACT_H
#define CONTACT_H

#include <QDateTime>
#include <QString>

struct Contact {
    int id;
    QString name;
    QString phone;
    QString email;
    QString address;
    QString notes;
    QString group_name;
    QDateTime created_time;
};

#endif  // CONTACT_H
