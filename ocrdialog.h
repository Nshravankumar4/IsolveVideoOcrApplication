#ifndef OCRDIALOG_H
#define OCRDIALOG_H
#include <QDialog>
class OcrDialog : public QDialog {
public:
    OcrDialog(const QString &text, QWidget *parent = nullptr);
};
#endif
