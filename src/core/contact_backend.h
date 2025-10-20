#ifndef CONTACT_BACKEND_H
#define CONTACT_BACKEND_H

#include "contact_c.h"

#ifdef __cplusplus
extern "C" {
#endif

// 初始化数据库（创建表）
int backend_init_db(const char* db_path);

// 新增联系人
int backend_add_contact(const ContactC* contact);

// 更新联系人
int backend_update_contact(const ContactC* contact);

// 删除联系人
int backend_delete_contact(int id);

// 查询所有联系人
int backend_query_all(ContactC* list, int max_count);

// 按姓名搜索联系人
int backend_query_by_name(const char* name, ContactC* list, int max_count);

//登录
int backend_login(const char* username, const char* password);

#ifdef __cplusplus
}
#endif

#endif  // CONTACT_BACKEND_H
