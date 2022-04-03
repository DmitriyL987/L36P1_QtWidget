#include <QApplication>
#include "circleSlide.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    mainframeWidget sliderWt(nullptr);
    sliderWt.move(900,500);
    sliderWt.resize(156,228);
    sliderWt.show();
    return QApplication::exec();
}
