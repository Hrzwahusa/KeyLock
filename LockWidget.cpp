#include "LockWidget.h"
#include <QSize>
#include <QDebug>
#include <QFile>
#include <QApplication>

bool LockWidget::locked = false;
HHOOK LockWidget::hHook = NULL;

LRESULT CALLBACK LockWidget::KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0 && locked) {
        return 1; // block the key
    }
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

LockWidget::LockWidget(QWidget* parent) : QWidget(parent) {
    QPixmap lockPix("icons/lock.png");
    QPixmap unlockPix("icons/unlock.png");
    lockIcon = QIcon(lockPix);
    unlockIcon = QIcon(unlockPix);
    qDebug() << "QFile exists icons/lock.png =" << QFile::exists("icons/lock.png");
    qDebug() << "lockIcon.isNull() =" << lockIcon.isNull() << " unlockIcon.isNull() =" << unlockIcon.isNull();
    qDebug() << "lockPix.isNull() =" << lockPix.isNull() << " unlockPix.isNull() =" << unlockPix.isNull();
    button = new QPushButton;
    button->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    button->setIcon(unlockIcon);
    button->setIconSize(QSize(600, 600));
    button->setFixedSize(640, 640);
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(button, 0, Qt::AlignCenter);
    setLayout(layout);
    setWindowTitle("KeyLock");
    resize(200, 200);
    connect(button, &QPushButton::clicked, this, &LockWidget::toggleLock);
    // Remove qApp eventFilter, use global hook instead
}

LockWidget::~LockWidget() {
    if (hHook) {
        UnhookWindowsHookEx(hHook);
        hHook = NULL;
    }
}

bool LockWidget::eventFilter(QObject* obj, QEvent* event) {
    if (locked && (event->type() == QEvent::KeyPress || event->type() == QEvent::KeyRelease)) {
        event->accept();
        return true;
    }
    return QWidget::eventFilter(obj, event);
}

void LockWidget::keyPressEvent(QKeyEvent* event) {
    if (locked) {
        event->accept();
        return;
    }
    QWidget::keyPressEvent(event);
}

void LockWidget::keyReleaseEvent(QKeyEvent* event) {
    if (locked) {
        event->accept();
        return;
    }
    QWidget::keyReleaseEvent(event);
}

void LockWidget::toggleLock() {
    qDebug() << "toggleLock called, locked =" << locked;
    locked = !locked;
    if (locked) {
        hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, GetModuleHandle(NULL), 0);
    } else {
        if (hHook) {
            UnhookWindowsHookEx(hHook);
            hHook = NULL;
        }
    }
    button->setIcon(locked ? lockIcon : unlockIcon);
}
