#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QCloseEvent>
#include <QGridLayout>
#include <QMainWindow>
#include <QObject>
#include <QPoint>
#include <QSize>
#include <QSizeGrip>

#include "appcontroller.h"

class LoginWidget;
class LibraryWidget;

namespace Ui
{
class AppWindow;
}

class AppWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppWindow(AppController* controller, QWidget* parent = 0);
    ~AppWindow();

    LoginWidget* loginWidget;
    LibraryWidget* libraryWidget;

    void setupSizeGrip();
    void setupLogin();
    void setupLibrary();

private:
    void closeEvent(QCloseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

    void setStatus(QString status, bool disable);

    void close();
    void maximize();
    void restore();

    Ui::AppWindow* ui;
    AppController* controller;

    QSize oldSize;
    QPoint oldPosition;
    int dragClickX;
    int dragClickY;
    QObject* firstClicked = NULL;

    QSize loginToLibrarySizeDiference;

    QSizeGrip* sizeGrip;
    QWidget* topBar;
    QGridLayout* appWindowLayout;
    QGridLayout* widgetsLayout;

signals:

public slots:

private slots:
    void on_topBarCloseButton_clicked();

};

#endif // APPWINDOW_H