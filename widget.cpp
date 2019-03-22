#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    backgroundImage = QImage(qApp->applicationDirPath()+"/background.png").scaled(680,880);

    scene = new QGraphicsScene(this);
    backgroundPixmap = scene->addPixmap(QPixmap::fromImage(backgroundImage));
    name = scene->addText("");
    flavor = scene->addText("");

    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &Widget::updateTextItems);
    connect(ui->textEdit, &QTextEdit::textChanged, this, &Widget::updateTextItems);
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::openArt);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateTextItems() {
    QRectF boundingRect;

    name->setPlainText(ui->lineEdit->text());
    name->setFont(QFont("Arial", 20));
    boundingRect = name->boundingRect();
    while(boundingRect.width()>280) {
        name->setFont(QFont("Arial", name->font().pointSize()-1));
        boundingRect = name->boundingRect();
    }
    name->setPos(340-boundingRect.width()/2, 60-boundingRect.height()/2);

    flavor->setPlainText(ui->textEdit->toPlainText());
    flavor->setTextWidth(-1);
    flavor->setFont(QFont("Arial", 40));
    boundingRect = flavor->boundingRect();
    if(boundingRect.width()>480) {
        flavor->setTextWidth(480);
        boundingRect = flavor->boundingRect();
        while(boundingRect.height()>190) {
            flavor->setFont(QFont("Arial", flavor->font().pointSize()-1));
            boundingRect = flavor->boundingRect();
        }
    }
    flavor->setPos(340-boundingRect.width()/2, 688-boundingRect.height()/2);
}

void Widget::openArt() {

    QString artFileName = QFileDialog::getOpenFileName(this, "Open Art", QDir::homePath(), "Images (*.png *.jpg *.jpeg *.bmp *.gif)");
    if(!artFileName.isEmpty()) {
        artImage = QImage(artFileName).scaled(520,368);
        artPixMap = scene->addPixmap(QPixmap::fromImage(artImage));
        artPixMap->setPos(80, 152);
    }
}
