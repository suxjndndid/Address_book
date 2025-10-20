QT += core gui widgets
CONFIG += c++11

TARGET = Address_book
TEMPLATE = app

# === 包含路径 ===
INCLUDEPATH += src \
               src/ui

# === 源文件 ===
SOURCES += \
    src/main.cpp \
    src/ui/mainwindow.cpp \
    src/ui/page_login.cpp \
    src/ui/page_edit.cpp \
    src/core/contact_service.cpp

# === 头文件 ===
HEADERS += \
    src/ui/mainwindow.h \
    src/ui/page_login.h \
    src/ui/page_edit.h \
    src/core/contact_service.h

# === UI 文件 ===
FORMS += \
    $$PWD/ui/mainwindow.ui \
    $$PWD/ui/page_login.ui \
    $$PWD/ui/page_edit.ui

# === 资源文件 ===
RESOURCES += \
    $$PWD/resources/res.qrc

# === 输出路径设置 ===
# 所有生成文件都放到 build 目录下
DESTDIR = $$PWD/build           # 可执行文件输出目录
OBJECTS_DIR = $$PWD/build/obj   # 编译生成的 .o 文件目录
MOC_DIR = $$PWD/build/moc       # 自动生成的 moc_ 文件目录
RCC_DIR = $$PWD/build/rcc       # 自动生成的 qrc_ 文件目录
UI_DIR = $$PWD/build/ui         # 自动生成的 ui_ 文件目录

# === 编译选项 ===
CONFIG += warn_on release

# === 跨平台兼容输出文件名 ===
# Windows 会生成 Address_book.exe
# Linux 会生成 Address_book（无后缀）
win32:TARGET_EXT = .exe
