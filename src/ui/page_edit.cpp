#include "page_edit.h"
#include "ui_page_edit.h"

page_edit::page_edit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page_edit)
{
    ui->setupUi(this);

//    this->show();

    my_edit.show();
}

page_edit::~page_edit()
{
    delete ui;
}
