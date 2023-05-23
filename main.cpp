#include <QApplication>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create QLineEdit widget
    QLineEdit *lineEdit = new QLineEdit("Test", nullptr);

    // Create QPushButton widgets
    QPushButton *widthBtn = new QPushButton("Width", nullptr);
    QPushButton *heightBtn = new QPushButton("Height", nullptr);

    // Create layout and add widgets
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lineEdit);
    layout->addWidget(widthBtn);
    layout->addWidget(heightBtn);

    // Set layout for the main window
    QWidget *window = new QWidget(nullptr);
    window->setLayout(layout);

    // Create QTimer for width increase
    QTimer *widthTimer = new QTimer(nullptr);
    widthTimer->setInterval(1000);  // 1 second interval

    // Create QTimer for height increase
    QTimer *heightTimer = new QTimer(nullptr);
    heightTimer->setInterval(1000);  // 1 second interval

    // Connect width timer to slot
    QObject::connect(widthTimer, &QTimer::timeout, [=]() {
        int newWidth = lineEdit->width() + 10;
        lineEdit->setFixedWidth(newWidth);
    });

    // Connect height timer to slot
    QObject::connect(heightTimer, &QTimer::timeout, [=]() {
        int newHeight = lineEdit->height() + 10;
        lineEdit->setFixedHeight(newHeight);
    });

    // Connect button clicks to timers
    QObject::connect(widthBtn, &QPushButton::clicked, [=]() {
        widthTimer->start();
    });
    QObject::connect(heightBtn, &QPushButton::clicked, [=]() {
        heightTimer->start();
    });

    // Show main window
    window->show();

    return app.exec();
}
