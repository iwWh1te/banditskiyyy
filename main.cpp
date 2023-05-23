#include <QApplication>
#include <QFont>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    window->setWindowTitle("Change Font Size");

    QLabel *label = new QLabel("Hello World!");
    QFont font = label->font();
    font.setPointSize(20);
    label->setFont(font);

    QPushButton *plusButton = new QPushButton("+");
    QPushButton *minusButton = new QPushButton("-");

    QObject::connect(plusButton, &QPushButton::clicked, [&label]() {
        QFont font = label->font();
        font.setPointSize(font.pointSize() + 1);
        label->setFont(font);
    });

    QObject::connect(minusButton, &QPushButton::clicked, [&label]() {
        QFont font = label->font();
        font.setPointSize(font.pointSize() - 1);
        label->setFont(font);
    });

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(plusButton);
    layout->addWidget(minusButton);

    window->setLayout(layout);
    window->show();

    return app.exec();
}
