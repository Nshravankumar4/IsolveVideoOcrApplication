#include "ocrdialog.h"
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
OcrDialog::OcrDialog(const QString &text, QWidget *parent)
    : QDialog(parent) {

    setWindowTitle("✅ OCR Recognition Result");
    setFixedSize(500, 400);

    QTextEdit *resultText = new QTextEdit(text, this);
    resultText->setReadOnly(true);
    resultText->setStyleSheet("background: #f0f8ff; font-family: monospace;");

    QPushButton *closeBtn = new QPushButton("Close", this);
    connect(closeBtn, &QPushButton::clicked, this, &QDialog::accept);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(resultText);
    layout->addWidget(closeBtn, 0, Qt::AlignCenter);
}
