QT += core gui widgets
CONFIG += c++11

TARGET = Address_book
TEMPLATE = app
INCLUDEPATH += src src/ui

# 源文件
SOURCES += \
    src/main.cpp \
    src/ui/mainwindow.cpp \
    src/ui/page_login.cpp \
    src/ui/page_edit.cpp

# 头文件
HEADERS += \
    src/ui/mainwindow.h \
    src/ui/page_login.h \
    src/ui/page_edit.h

# UI 文件
FORMS += \
    ui/mainwindow.ui \
    ui/page_login.ui \
    ui/page_edit.ui

# 资源文件
RESOURCES += resources/res.qrc

# 包含路径（重要）
INCLUDEPATH += src
