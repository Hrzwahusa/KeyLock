#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_KeyLock.h"

class KeyLock : public QMainWindow
{
    Q_OBJECT

public:
    KeyLock(QWidget *parent = nullptr);
    ~KeyLock();

private:
    Ui::KeyLockClass ui;
};


