#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Tastatursperre.h"

class Tastatursperre : public QMainWindow
{
    Q_OBJECT

public:
    Tastatursperre(QWidget *parent = nullptr);
    ~Tastatursperre();

private:
    Ui::TastatursperreClass ui;
};

