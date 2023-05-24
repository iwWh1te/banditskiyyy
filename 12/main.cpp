#include <QTWidgets>
class MainWindow : public QMainWindow{
	public:
		MainWindow();
		void openButtonClick();
		void openImage(const QString & path=QString() );
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
	resize(900,500);
	setWindowTitle("Main gallery v2");
	QFont buttonFont("Time", 10, QFont::Bold);
	
	pathLabel = new QLabel(this);
	pathLabel->setGeometry(30,0,850,20);
	pathLabel->setText(imgPath);
	pathLabel->setFont(QFont("Time",10,QFont::Bold));
	
	pathEdit=new QLineEdit(this);
	pathEdit->setText(imgPath);
	pathEdit->setGeometry(30,30,850,20);
	
	openButton = new QPushButton("Open Image",this);
	openButton->setGeometry(30,60,100,40);
	openButton->setFont(buttonFont);
	
connect (openButton, &QPushButton::clicked,this, &MainWindow::openButtonClick);}
	
void MainWindow::openImage(const QString & path){
	imgPath=path;
	if (imgPath.isNull()){
		imgPath=QFileDialog::getOpenFileName(this,"Open Image"," ","Image Files(*.png *.jpg *.bmp) ");
        }
	if (!imgPath.isEmpty()){
		if (!pixmap.load(imgPath)){
			QMessageBox::warning(this,"Open Image","The img file could not be loaded.", QMessageBox::Cancel);
	return;
    }
}
	pathEdit->setText(imgPath);}
		
void MainWindow::paintEvent(QPaintEvent *){
	QPainter painter(this);
	pixmap.load(imgPath);
	painter.drawPixmap(300,150,pixmap);
	painter.restore();}
	
void MainWindow::openButtonClick(){
	imgPath = pathEdit->text();
	openImage();
	update();}

int main(int argc,char *argv[]){
	QApplication app(argc,argv);
	MainWindow mainWin;
	mainWin.show();
	return app.exec();
}
