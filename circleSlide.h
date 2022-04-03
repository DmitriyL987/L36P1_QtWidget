//
// Created by Lopatin Dmitriy on 02.04.2022.
//
#pragma once
#include <QPaintEvent>
#include <QWidget>
#include <QVBoxLayout>
#include <QPixmap>
#include <QSlider>
#include <QPainter>

class CircleImg: public QWidget
{
    QPixmap *redC = new QPixmap("C:\\Users\\LDm\\CLionProjects\\L36P1-QtWidget\\redCircle.png");
    QPixmap *greenC = new QPixmap("C:\\Users\\LDm\\CLionProjects\\L36P1-QtWidget\\greenCircle.png");
    QPixmap *yellowC = new QPixmap("C:\\Users\\LDm\\CLionProjects\\L36P1-QtWidget\\yellowCircle.png");
    QPixmap *currImg = greenC;
    Q_OBJECT
public:
    CircleImg(QWidget* parent= nullptr): QWidget(parent){
        setParent(parent);
    }
    void paintEvent(QPaintEvent* e) override;
public slots:
    void setYellow(){currImg = yellowC; update();};
    void setGreen(){currImg = greenC; update();};
    void setRed(){currImg = redC; update();};
};
//-------------------------------------
class mainframeWidget : public QWidget
{
    Q_OBJECT
public:
    QVBoxLayout *box = nullptr;
    QSlider *slider = nullptr;
    CircleImg * circleImg = nullptr;

    mainframeWidget(QWidget *parent = nullptr): QWidget(parent){
        setParent(parent);
        circleImg = new CircleImg(this);
        slider = new QSlider(this);
        box = new QVBoxLayout(this);
        slider->setOrientation(Qt::Horizontal);
        slider->rangeChanged(0,100);
        box->addWidget(circleImg);
        box->addWidget(slider);

        connect(slider, &QSlider::valueChanged, [this](int newVal){
                    if(newVal <= 33) circleImg->setGreen();
                    else if(newVal <= 66) circleImg->setYellow();
                    else circleImg->setRed();
                    update();
                });
    }
    void paintEvent(QPaintEvent *event) override;
};