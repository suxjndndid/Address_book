#ifndef PAGE_EDIT_H
#define PAGE_EDIT_H

#include <QWidget>

#include "page_edit.h"

namespace Ui {
class page_edit;
}

class page_edit : public QWidget
{
    Q_OBJECT

public:
    explicit page_edit(QWidget *parent = nullptr);
    ~page_edit();

private:
    Ui::page_edit *ui;

    page_edit my_edit;
};

#endif // PAGE_EDIT_H
