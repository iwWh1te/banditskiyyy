#include <QtWidgets>

class MainWindow : public QMainWindow {
public:
    MainWindow();
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
    int         xSpot;
};

MainWindow::MainWindow() {
    resize(900, 500);
    setWindowTitle("Main v9");
    QFont labelFont("Courier", 24, QFont::Bold);
    startButton = new QPushButton("Start", this);
    startButton->setGeometry(100, 300, 150, 50);
    startButton->setFont(QFont("Time", 20, QFont::Bold));

    stopButton = new QPushButton("Stop", this);
    stopButton->setGeometry(300, 300, 150, 50);
    stopButton->setFont(QFont("Time", 20, QFont::Bold));

    textLabel = new QLabel (this);
    textLabel->setGeometry(100, 20, 350, 180);
    textLabel->setFont(labelFont);

    connect(startButton, &QPushButton::clicked, this, &MainWindow::startButtonClick);
    connect(stopButton, &QPushButton::clicked, this, &MainWindow::stopButtonClick);

    timer = new QTimer (this);
    connect (timer, &QTimer::timeout, this, &MainWindow::runClock);
    seconds = 0;
    timerInterval = 10;

    xSpot = 0;
}

void MainWindow::paintEvent(QPaintEvent *) {
    QPainter painter (this);
    QPen darkGreenPen(Qt::darkGreen, 4, Qt::SolidLine, Qt::RoundCap);
    QBrush greenBrush (Qt::green, Qt::SolidPattern);
    painter.setPen (darkGreenPen);
    painter.setBrush (greenBrush);
    painter.drawEllipse(xSpot, 200, 80, 60);
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

    xSpot++;
    update();
}



int main (int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
