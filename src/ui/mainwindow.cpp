#include "mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include "../core/contact.h"
#include "../core/contact_service.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    my_login.show();
    connect(&my_login, &page_login::sendLoginSuccess, this, &MainWindow::login);

    // 按钮连接
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onQueryClicked);     // 查询
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onAddClicked);     // 添加
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::onEditClicked);    // 修改
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::onDeleteClicked);  // 删除

    // 编辑页面保存信号连接
    connect(&editPage, &page_edit::saveFinished, this, &MainWindow::onEditPageSaveFinished);
}


MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::login() {
    my_login.hide();
    this->show();
}

void MainWindow::loadAllContacts() {
    QList<Contact> list = ContactService::getAllContacts();
    updateTable(list);
}

void MainWindow::onQueryClicked() {
    QString name = ui->lineEdit->text().trimmed();

    QList<Contact> result;
    if (name.isEmpty()) {
        result = ContactService::getAllContacts();
    } else {
        result = ContactService::searchByName(name);
    }

    updateTable(result);
}
void MainWindow::onDeleteClicked() {
    int row = ui->tableWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请先选择要删除的联系人！");
        return;
    }

    int id = ui->tableWidget->item(row, 0)->text().toInt();
    if (QMessageBox::question(this, "确认", "确定要删除该联系人吗？") == QMessageBox::Yes) {
        if (ContactService::deleteContact(id)) {
            QMessageBox::information(this, "成功", "删除成功！");
            loadAllContacts();
        } else {
            QMessageBox::critical(this, "失败", "删除失败！");
        }
    }
}

// 添加联系人
void MainWindow::onAddClicked() {
    editPage.setAddMode();  // 调用 page_edit 清空模式
}

// 修改联系人
void MainWindow::onEditClicked() {
    int row = ui->tableWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请先选择要修改的联系人！");
        return;
    }

    Contact contact;
    contact.id = ui->tableWidget->item(row, 0)->text().toInt();
    contact.name = ui->tableWidget->item(row, 1)->text();
    contact.phone = ui->tableWidget->item(row, 2)->text();
    contact.email = ui->tableWidget->item(row, 3)->text();
    contact.address = ui->tableWidget->item(row, 4)->text();
    contact.notes = ui->tableWidget->item(row, 5)->text();
    contact.group_name = ui->tableWidget->item(row, 6)->text();

    editPage.setEditMode(contact);  // 编辑模式
}

// 编辑完成后刷新联系人表
void MainWindow::onEditPageSaveFinished() {
    loadAllContacts(); // 重新加载数据库内容
}
