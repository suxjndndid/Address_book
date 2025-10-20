#ifndef CONTACT_CONVERT_H
#define CONTACT_CONVERT_H

#include "contact.h"
#include "contact_c.h"
#include <cstring>

// Qt → C
inline ContactC toCStruct(const Contact &qtContact) {
    ContactC c{};
    c.id = qtContact.id;
    strncpy(c.name, qtContact.name.toUtf8().constData(), MAX_LEN - 1);
    strncpy(c.phone, qtContact.phone.toUtf8().constData(), MAX_LEN - 1);
    strncpy(c.email, qtContact.email.toUtf8().constData(), MAX_LEN - 1);
    strncpy(c.address, qtContact.address.toUtf8().constData(), MAX_LEN - 1);
    strncpy(c.notes, qtContact.notes.toUtf8().constData(), MAX_LEN - 1);
    strncpy(c.group_name, qtContact.group_name.toUtf8().constData(), MAX_LEN - 1);
    c.created_time = qtContact.created_time.toSecsSinceEpoch();
    return c;
}

// C → Qt
inline Contact fromCStruct(const ContactC &c) {
    Contact qt{};
    qt.id = c.id;
    qt.name = QString::fromUtf8(c.name);
    qt.phone = QString::fromUtf8(c.phone);
    qt.email = QString::fromUtf8(c.email);
    qt.address = QString::fromUtf8(c.address);
    qt.notes = QString::fromUtf8(c.notes);
    qt.group_name = QString::fromUtf8(c.group_name);
    qt.created_time = QDateTime::fromSecsSinceEpoch(c.created_time);
    return qt;
}

#endif // CONTACT_CONVERT_H
