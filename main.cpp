#include <QTWidgets>
class MainWindow : public QMainWindow{
public:
    MainWindow();
    void openButtonClick();
protected:
    void paintEvent(QPaintEvent *event);
private:
    QLabel *pathLabel;
    QPushButton *openButton;
    QLineEdit *pathEdit;
    QPainter *painter;
    QPixmap pixmap;
    QString imgPath;
};
MainWindow::MainWindow(){
    resize(1000,600);
    setWindowTitle("gallery01");
    QFont buttonFont("Time", 10, QFont::Bold);

    pathLabel = new QLabel(this);
    pathLabel->setGeometry(30, 10, 850, 35);
    pathLabel->setText("Image path");
    pathLabel->setFont(QFont("Time",20,QFont::Bold));

    pathEdit=new QLineEdit(this);
    pathEdit->setText("...");
    pathEdit->setGeometry(30, 50, 850, 20);

    openButton = new QPushButton("Open Picture",this);
    openButton->setGeometry(30, 80, 100, 40);
    openButton->setFont(buttonFont);

    connect (openButton, &QPushButton::clicked,this, &MainWindow::openButtonClick);}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    pixmap.load(imgPath);
    painter.drawPixmap(50,150,pixmap);
    painter.restore();}

void MainWindow::openButtonClick(){
    imgPath = pathEdit->text();
    update();}

int main(int argc,char *argv[]){
    QApplication app(argc,argv);
    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
