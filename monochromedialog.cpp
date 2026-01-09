#include "monochromedialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QColor>
MonochromeDialog::MonochromeDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("🎨 Select Monochrome Color Set");
    setFixedSize(400, 280);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(new QLabel("<b>Choose Color Mapping:</b>"));

    struct ColorSet {
        QString name;
        QColor from, to;
    };

    ColorSet sets[4] = {
        {"Colors First", QColor("#ffffff"), QColor("#000000")},
        {"Colors Second", QColor("#000000"), QColor("#ffffff")},
        {"Colors Third", QColor("#000000"), QColor("#11c70e")},
        {"Colors Fourth", QColor("#000000"), QColor("#f4d81e")}
    };

    for (int i = 0; i < 4; ++i) {
        QWidget *row = new QWidget;
        QHBoxLayout *rowLayout = new QHBoxLayout(row);

        QPushButton *btn = new QPushButton(sets[i].name);
        btn->setStyleSheet(QString(
                               "QPushButton { background: qlineargradient(x1:0, y1:0, x2:1, y2:1, "
                               "stop:0 %1, stop:1 %2); border: 2px solid gray; font-weight: bold; }"
                               "QPushButton:hover { border: 3px solid blue; }"
                               ).arg(sets[i].from.name()).arg(sets[i].to.name()));

        connect(btn, &QPushButton::clicked, this, [this, i]{
            emit colorSetSelected(i + 1);
            accept();
        });

        rowLayout->addWidget(btn);
        mainLayout->addWidget(row);
    }
}
