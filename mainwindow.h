#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QVideoWidget>
#include <QMediaCaptureSession>
#include <QCamera>
#include <QShortcut>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include "monochromedialog.h"
#include "ocrdialog.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void openColorDialog();
    void triggerOcr();
private:
    QMediaCaptureSession *m_session;
    QCamera *m_camera;
    QVideoWidget *m_videoWidget;
    QPushButton *m_colorBtn;
    QLabel *m_statusLabel;
    QShortcut *m_f4Shortcut;
    MonochromeDialog *m_colorDialog;
    OcrDialog *m_ocrDialog;
    int m_currentColorSet = 1;
};
#endif
