#include "page_edit.h"
#include "ui_page_edit.h"

#include <QMessageBox>
#include "../core/contact_service.h"

page_edit::page_edit(QWidget* parent)
    : QWidget(parent), ui(new Ui::page_edit) {
    ui->setupUi(this);

    // 按钮连接
    connect(ui->pushButton, &QPushButton::clicked, this, &page_edit::onConfirmClicked);   // 确认
    connect(ui->pushButton_2, &QPushButton::clicked, this, &page_edit::onCancelClicked);  // 取消
}

page_edit::~page_edit() {
    delete ui;
}

// 设置为添加模式
void page_edit::setAddMode() {
    isEditMode = false;
    currentId = -1;

    ui->label_7->setText("新建联系人");
    ui->lineEdit->clear();     // 姓名
    ui->lineEdit_2->clear();   // 电话
    ui->lineEdit_3->clear();   // 邮箱
    ui->lineEdit_4->clear();   // 地址
    ui->lineEdit_5->clear();   // 备注
    ui->lineEdit_6->clear();   // 分组

    show();
}

// 设置为编辑模式
void page_edit::setEditMode(const Contact& contact) {
    isEditMode = true;
    currentId = contact.id;

    ui->label_7->setText("编辑联系人");
    ui->lineEdit->setText(contact.name);
    ui->lineEdit_2->setText(contact.phone);
    ui->lineEdit_3->setText(contact.email);
    ui->lineEdit_4->setText(contact.address);
    ui->lineEdit_5->setText(contact.notes);
    ui->lineEdit_6->setText(contact.group_name);

    show();
}

// 确认按钮槽函数
void page_edit::onConfirmClicked() {
    Contact contact;
    contact.id = currentId;
    contact.name = ui->lineEdit->text();
    contact.phone = ui->lineEdit_2->text();
    contact.email = ui->lineEdit_3->text();
    contact.address = ui->lineEdit_4->text();
    contact.notes = ui->lineEdit_5->text();
    contact.group_name = ui->lineEdit_6->text();

    bool success = false;

    if (isEditMode) {
        success = ContactService::updateContact(contact);
    } else {
        success = ContactService::addContact(contact);
    }

    if (success) {
        QMessageBox::information(this, "成功", "联系人已保存！");
        emit saveFinished();  // 通知主窗口刷新
        this->hide();
    } else {
        QMessageBox::warning(this, "失败", "保存失败，请检查输入。");
    }
}

// 取消按钮槽函数
void page_edit::onCancelClicked() {
    this->hide();
}
