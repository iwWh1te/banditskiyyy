#include <QApplication>
#include <QtWidgets>

int leftButton1 = 150;
int topButton1 = 220;
int widthButton1 = 100;
int heightButton1 = 50;
int flags1 = 0;
int xMouse = 0;
int yMouse = 0;
int xGlobal = 0;
int yGlobal = 0;

class MainWindow : public QMainWindow {
    public:
        MainWindow ();
        void mousePressEvent (QMouseEvent *event);
        void paintEvent (QPaintEvent *event);
    private:
        QLabel      *xLabel;
        QLabel      *yLabel;
        QLabel      *flag1Label;
};

MainWindow::MainWindow () {
    setWindowTitle ("Mouse v0.2");
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

    flag1Label = new QLabel (this);
    flag1Label -> setGeometry (150, 245, 850, 120);
    flag1Label -> setFont (labelFont);
    flag1Label -> setText ("Flag: ");
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

    QString strFlag1;
    if ((xMouse > leftButton1) && (xMouse < leftButton1 + widthButton1) && (yMouse > topButton1) && (yMouse < topButton1 + heightButton1)) {       
        flags1 = 1;
    }
    else {
        flags1 = 0;
    }
    strFlag1 = QString::number (flags1);
    flag1Label -> setText ("flag1: " + strFlag1);
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter1 (this);
    painter1.setPen (QPen (Qt::green, 4, Qt::SolidLine, Qt::RoundCap));
    painter1.setBrush (QBrush(Qt::white, Qt::NoBrush));
    painter1.drawRect (leftButton1, topButton1, widthButton1, heightButton1);
}

int main (int argc, char *argv[]) {
    QApplication app (argc, argv);
    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
