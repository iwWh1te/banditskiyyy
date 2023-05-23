#include <QtWidgets>

class MainWindow : public QMainWindow {
public:
    MainWindow(Road *_road);
    void startButtonClick();
    void stopButtonClick();
    void runClock();
protected:
    void paintEvent(QPaintEvent *event);
private:
    QPushButton *startButton;
    QPushButton *stopButton;
    QLabel      *textLabel;
    QTimer      *timer;
    int         seconds;
    int         timerInterval;
    int         xSpot1;
    int         xSpot2;
    int         xSpot3;
    int         xStep1;
    int         xStep2;
    int         xStep3;
    int         widthWindow = 1400;
};

class Road {
public:
    double      length;
    int         width;
};

MainWindow::MainWindow(Road *_road) {
    resize(900, 500);
    setWindowTitle("Main v9");
    QFont labelFont("Courier", 24, QFont::Bold);
    startButton = new QPushButton("Start", this);
    startButton->setGeometry(50, 410, 150, 50);
    startButton->setFont(QFont("Time", 20, QFont::Bold));

    stopButton = new QPushButton("Stop", this);
    stopButton->setGeometry(250, 410, 150, 50);
    stopButton->setFont(QFont("Time", 20, QFont::Bold));

    textLabel = new QLabel (this);
    textLabel->setGeometry(50, 380, 350, 20);
    textLabel->setFont(labelFont);

    connect(startButton, &QPushButton::clicked, this, &MainWindow::startButtonClick);
    connect(stopButton, &QPushButton::clicked, this, &MainWindow::stopButtonClick);

    timer = new QTimer (this);
    connect (timer, &QTimer::timeout, this, &MainWindow::runClock);
    seconds = 0;
    timerInterval = 10;

    xSpot1 = 0;
    xSpot2 = 0;
    xSpot3 = 0;

    xStep1 = 2;
    xStep2 = 6;
    xStep3 = 4;
}

void MainWindow::paintEvent(QPaintEvent *) {
    QPainter painter (this);
    QPen darkGreenPen(Qt::darkGreen, 4, Qt::SolidLine, Qt::RoundCap);
    QPen darkRedPen(Qt::darkRed, 4, Qt::SolidLine, Qt::RoundCap);
    QPen darkBluePen(Qt::darkBlue, 4, Qt::SolidLine, Qt::RoundCap);
    QBrush greenBrush (Qt::green, Qt::SolidPattern);
    QBrush redBrush (Qt::red, Qt::SolidPattern);
    QBrush blueBrush (Qt::blue, Qt::SolidPattern);
    painter.setPen (darkGreenPen);
    painter.setBrush (greenBrush);
    painter.drawEllipse(xSpot1, 50, 80, 40);
    painter.setPen (darkRedPen);
    painter.setBrush (redBrush);
    painter.drawEllipse(xSpot2, 100, 80, 40);
    painter.setPen (darkBluePen);
    painter.setBrush (blueBrush);
    painter.drawEllipse(xSpot3, 150, 80, 40);

    QPen blackPen2(Qt::black, 4, Qt::SolidLine, Qt::RoundCap);
    painter.setPen2 (blackPen);
    painter.drawRect(40, 0, road.length, 40)
}

void MainWindow::startButtonClick() {
    textLabel->setText ("Start1");
    timer->setInterval (timerInterval);
    timer->start();
}

void MainWindow::stopButtonClick() {
    textLabel->setText ("Stop2");
    timer->stop();
    seconds = 0;
}

void MainWindow::runClock() {
    QString strSeconds = QString::number (seconds);
    textLabel->setText (strSeconds);
    seconds++;

    xSpot1 += xStep1;
    xSpot2 += xStep2;
    xSpot3 += xStep3;
    if (xSpot1 > widthWindow) {
        xSpot1 = 0;
    }

    if (xSpot2 > widthWindow) {
        xSpot2 = 0;
    }

    if (xSpot3 > widthWindow) {
        xSpot3 = 0;
    }
    update();
}



int main (int argc, char *argv[]) {
    QApplication app(argc, argv);
    Road road;
    road.length = 1100;
    road.width = 3;
    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
