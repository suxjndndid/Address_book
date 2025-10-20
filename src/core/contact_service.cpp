#include "contact_service.h"
#include "contact_convert.h"
#include <QDebug>


#define DEBUG 1   // ← 控制是否启用调试模式

#if !DEBUG
extern "C" {
#include "contact_backend.h"
}
#endif

bool ContactService::addContact(const Contact &contact) {
#if DEBUG
    qDebug() << "[DEBUG] addContact:" << contact.name << contact.phone;
    return true; // 模拟成功
#else
    ContactC c = toCStruct(contact);
    return backend_add_contact(&c) == 0;
#endif
}

bool ContactService::updateContact(const Contact &contact) {
#if DEBUG
    qDebug() << "[DEBUG] updateContact:" << contact.id << contact.name;
    return true; // 模拟成功
#else
    ContactC c = toCStruct(contact);
    return backend_update_contact(&c) == 0;
#endif
}

bool ContactService::deleteContact(int id) {
#if DEBUG
    qDebug() << "[DEBUG] deleteContact:" << id;
    return true;
#else
    return backend_delete_contact(id) == 0;
#endif
}

QList<Contact> ContactService::getAllContacts() {
    QList<Contact> result;
#if DEBUG
    qDebug() << "[DEBUG] getAllContacts called";
    // 模拟 2 条联系人数据
    Contact a;
    a.id = 1;
    a.name = "Alice";
    a.phone = "123456";
    a.email = "alice@example.com";
    a.address = "Debug Street 1";
    a.notes = "测试数据";
    a.group_name = "Family";
    a.created_time = QDateTime::currentDateTime();

    Contact b = a;
    b.id = 2;
    b.name = "Bob";
    b.phone = "654321";
    b.group_name = "Work";

    result << a << b;
#else
    ContactC list[200];
    int count = backend_query_all(list, 200);
    for (int i = 0; i < count; ++i)
        result.append(fromCStruct(list[i]));
#endif
    return result;
}

QList<Contact> ContactService::searchByName(const QString &name) {
    QList<Contact> result;
#if DEBUG
    qDebug() << "[DEBUG] searchByName:" << name;
    // 模拟结果
    if (name.contains("Alice", Qt::CaseInsensitive)) {
        Contact a;
        a.id = 1;
        a.name = "Alice";
        a.phone = "123456";
        a.email = "alice@example.com";
        a.address = "Debug Street 1";
        a.notes = "搜索模拟结果";
        a.group_name = "Family";
        a.created_time = QDateTime::currentDateTime();
        result << a;
    }
#else
    ContactC list[200];
    QByteArray utf8 = name.toUtf8();
    int count = backend_query_by_name(utf8.constData(), list, 200);
    for (int i = 0; i < count; ++i)
        result.append(fromCStruct(list[i]));
#endif
    return result;
}

int ContactService::login(const QString &username, const QString &password) {
#if DEBUG
    qDebug() << "[DEBUG] login called:" << username << password;
    if (username == "admin" && password == "123456")
        return 0; // 模拟成功
    if (username != "admin")
        return 1; // 模拟用户名不存在
    return 2;     // 模拟密码错误
#else
    QByteArray u = username.toUtf8();
    QByteArray p = password.toUtf8();
    return backend_login(u.constData(), p.constData());
#endif
}
