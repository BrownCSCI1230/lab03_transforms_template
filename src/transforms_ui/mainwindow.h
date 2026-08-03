#pragma once

#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include "glrenderer.h"

namespace TransformDemo {

class MainWindow : public QWidget {
    Q_OBJECT

   public:
    MainWindow();

   private:
    GLRenderer* glRenderer;

    QPushButton* buttonA;
    QPushButton* buttonB;
    QPushButton* buttonC;
    QPushButton* buttonD;
    QPushButton* buttonView;

    QPushButton* buttonAInv;
    QPushButton* buttonBInv;
    QPushButton* buttonCInv;
    QPushButton* buttonDInv;
    QPushButton* buttonViewInv;

    QPushButton* buttonReset;
    QPushButton* buttonRotation;
    QPushButton* buttonRotationInv;

    QLabel* transformLabel;
    QString transformStr;

   private slots:
    void pressA();
    void pressB();
    void pressC();
    void pressD();
    void pressView();

    void pressAInv();
    void pressBInv();
    void pressCInv();
    void pressDInv();
    void pressRotation();
    void pressRotationInv();
    void pressViewInv();

    void pressReset();

    void addTransformLabel(QString matrix);
};
};  // namespace TransformDemo