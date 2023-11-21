#include "game.h"
#include "display.h"
#include <QMainWindow>
#include <QString>
#include <QTime>
#include <QTimer>
#include <QObject>
#include <stdlib.h>



int main(int argc,char*argv[]){

    Ui::MainWindow ui;
    QApplication app(argc,argv);
    QMainWindow window;

    ui.setupUi(&window);

    Game g(ui);

    window.show();
    return app.exec();

}

