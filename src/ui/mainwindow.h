#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include "page_login.h"
#include "page_edit.h"
#include "../core/contact.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void login();

    void onQueryClicked();
    void onAddClicked();
    void onEditClicked();
    void onDeleteClicked();

    // 接收编辑页面保存成功信号，刷新表格
    void onEditPageSaveFinished();

private:
    void loadAllContacts();
    void updateTable(const QList<Contact>& contacts);

    Ui::MainWindow* ui;
    page_login my_login;
    page_edit editPage; // 👈 新增，编辑页面

public:
    void showLogin();  // 显示登录页面

};

#endif // MAINWINDOW_H
