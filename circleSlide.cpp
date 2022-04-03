#include "circleSlide.h"

void mainframeWidget::paintEvent(QPaintEvent *e){
    update();
}

void CircleImg::paintEvent(QPaintEvent *e){
    QPainter p(this);
    p.drawPixmap(this->rect(), *currImg);
}