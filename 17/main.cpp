#include <QApplication>
#include <QtWidgets>

int xMouse = 0;
int yMouse = 0;
int xGlobal = 0;
int yGlobal = 0;

class MainWindow : public QMainWindow {
    public:
        MainWindow ();
        void mousePressEvent (QMouseEvent *event);
    private:
        QLabel      *xLabel;
        QLabel      *yLabel;
};

MainWindow::MainWindow () {
    setWindowTitle ("Mouse v01");
    setFixedSize (900, 500);
    QFont labelFont ("Courier", 32, QFont::Bold);
    xLabel = new QLabel (this);
    xLabel -> setGeometry (150, 5, 850, 120);
    xLabel -> setFont (labelFont);
    xLabel -> setText ("Mouse x: ");

    yLabel = new QLabel (this);
    yLabel -> setGeometry (150, 125, 850, 120);
    yLabel -> setFont (labelFont);
    yLabel -> setText ("Mouse y: ");
}

void MainWindow::mousePressEvent (QMouseEvent *event) {
    QString strGlobalX, strX;
    xMouse = event -> x();
    xGlobal = event -> globalX();
    strX = QString::number (xMouse);
    strGlobalX = QString::number (xGlobal);
    xLabel -> setText ("MouseX: " + strX + " [" + strGlobalX + " ]");

    QString strGlobalY, strY;
    yMouse = event -> y();
    yGlobal = event -> globalY();
    strY = QString::number (yMouse);
    strGlobalY = QString::number (yGlobal);
    yLabel -> setText ("MouseY: " + strY + " [" + strGlobalY + " ]");

}

int main (int argc, char *argv[]) {
    QApplication app (argc, argv);
    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
