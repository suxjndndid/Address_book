#ifndef PAGE_EDIT_H
#define PAGE_EDIT_H

#include <QWidget>
#include "../core/contact.h"

namespace Ui {
class page_edit;
}

class page_edit : public QWidget {
    Q_OBJECT

public:
    explicit page_edit(QWidget* parent = nullptr);
    ~page_edit();

    // 设置编辑页面为“添加模式”（清空输入框）
    void setAddMode();

    // 设置编辑页面为“编辑模式”，并加载已有数据
    void setEditMode(const Contact& contact);

signals:
    // 编辑完成后通知主界面刷新（无论添加或修改）
    void saveFinished();

private slots:
    void onConfirmClicked();
    void onCancelClicked();

private:
    Ui::page_edit* ui;
    bool isEditMode = false;  // true 表示编辑模式
    int currentId = -1;       // 当前联系人ID
};

#endif  // PAGE_EDIT_H
