#include <QApplication>
#include "mainwindow.h"
int main(int argc, char *argv[]) {
    qputenv("QSG_RENDER_LOOP", "basic");
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}
