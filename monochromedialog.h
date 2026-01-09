#ifndef MONOCHROMEDIALOG_H
#define MONOCHROMEDIALOG_H
#include <QDialog>
class MonochromeDialog : public QDialog {
    Q_OBJECT
public:
    explicit MonochromeDialog(QWidget *parent = nullptr);
signals:
    void colorSetSelected(int index);
};
#endif
