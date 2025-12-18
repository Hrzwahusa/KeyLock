#pragma once
#include <QWidget>
#include <QPushButton>
#include <QIcon>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <windows.h>

class LockWidget : public QWidget {
    Q_OBJECT
    static bool locked;
    QPushButton* button;
    QIcon lockIcon, unlockIcon;
    static HHOOK hHook;
public:
    explicit LockWidget(QWidget* parent = nullptr);
    ~LockWidget();
protected:
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    bool eventFilter(QObject* obj, QEvent* event) override;
private slots:
    void toggleLock();
private:
    static LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
};
