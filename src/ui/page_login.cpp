#include "page_login.h"
#include <QDebug>
#include <QMessageBox>
#include "../core/contact_service.h"
#include "ui_page_login.h"

page_login::page_login(QWidget* parent) : QWidget(parent),
                                          ui(new Ui::page_login) {
    ui->setupUi(this);

    // 按钮连接
    connect(ui->pushButton, &QPushButton::clicked, this, &page_login::onLoginClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &page_login::onExitClicked);
}

// 槽函数声明请确保已在 page_login.h 中添加：
// void onLoginClicked();
// void onExitClicked();



page_login::~page_login() {
    delete ui;
}

// 登录按钮槽函数
void page_login::onLoginClicked() {
    QString username = ui->lineEdit->text().trimmed();
    QString password = ui->lineEdit_2->text().trimmed();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "警告", "用户名或密码不能为空！");
        return;
    }

    // 调用 ContactService 登录接口
    int result = ContactService::login(username, password);

    if (result == 1) {
        QMessageBox::information(this, "提示", "登录成功！");

        // 跳转到主页面
        MainWindow *mainWindow = new MainWindow();
        mainWindow->show();

        this->close();  // 关闭当前登录窗口
    } else {
        QMessageBox::critical(this, "错误", "用户名或密码错误！");
    }
}

// 退出按钮槽函数
void page_login::onExitClicked() {
    QApplication::quit();
}
