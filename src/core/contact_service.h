#ifndef CONTACT_SERVICE_H
#define CONTACT_SERVICE_H

#include "contact.h"
#include <QList>

class ContactService {
public:
    static bool addContact(const Contact &contact);
    static bool updateContact(const Contact &contact);
    static bool deleteContact(int id);
    static QList<Contact> getAllContacts();
    static QList<Contact> searchByName(const QString &name);
    static int login(const QString &username, const QString &password);

};

#endif // CONTACT_SERVICE_H
