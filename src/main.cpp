#include "mainwindow.h"
#include "page_login.h"
#include "page_edit.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
//    w.show();

//    page_login p;
//    p.show();

    page_edit m;
//    m.show();
    return a.exec();
}
