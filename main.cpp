#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    // Crear y mostrar la ventana principal
    MainWindow window;
    window.show();
    
    return app.exec();
}