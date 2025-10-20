#include <QApplication>

#include "ui/mainwindow.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    MainWindow w;  // 主窗口对象
    w.hide();      // 启动时先隐藏主窗口

    w.showLogin();  // 显示登录页面

    return a.exec();
}
