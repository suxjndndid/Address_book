#include "page_login.h"
#include "ui_page_login.h"

#include <QDebug>

page_login::page_login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page_login)
{
    ui->setupUi(this);
}

page_login::~page_login()
{
    delete ui;
}

void page_login::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text(); // 假设UI有用户名输入框
    QString password = ui->lineEdit_password->text(); // 假设UI有密码输入框
    // 模拟数据库验证（后续可替换为真实数据库查询）
    if (username == "admin" && password == "123456") {
        emit sendLoginSuccess(); // 验证通过发送信号
    } else {
        QMessageBox::warning(this, "错误", "用户名或密码错误");
    }
    qDebug() << "点击登录";

    emit page_login::sendLoginSuccess();
}
