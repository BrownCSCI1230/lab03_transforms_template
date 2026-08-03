#include "mainwindow.h"

#include <QHBoxLayout>
#include <iostream>

using namespace TransformDemo;

MainWindow::MainWindow() {
    /* Set up the layouts (parent-child diagram):
     *
     *                 hLayout
     *                 /     \
     *           vLayout      glWidget (canvas)
     *          |
     * labels,buttons
     *
     */

    setWindowTitle("Lab 4: Transforms");

    QHBoxLayout* hLayout = new QHBoxLayout;

    QGridLayout* gridLayout = new QGridLayout;
    gridLayout->setAlignment(Qt::AlignTop);
    hLayout->addLayout(gridLayout);

    glRenderer = new GLRenderer;
    glRenderer->setEnabled(true);
    hLayout->addWidget(glRenderer, 1);

    this->setLayout(hLayout);

    buttonA = new QPushButton("A");
    buttonB = new QPushButton("B");
    buttonC = new QPushButton("C");
    buttonD = new QPushButton("D");
    buttonView = new QPushButton("View");
    buttonAInv = new QPushButton("A⁻¹");
    buttonBInv = new QPushButton("B⁻¹");
    buttonCInv = new QPushButton("C⁻¹");
    buttonDInv = new QPushButton("D⁻¹");
    buttonViewInv = new QPushButton("View⁻¹");
    buttonRotation = new QPushButton("Rotation");
    buttonRotationInv = new QPushButton("Rotation⁻¹");
    buttonReset = new QPushButton("Reset");

    gridLayout->addWidget(buttonA, 0, 0);
    gridLayout->addWidget(buttonB, 1, 0);
    gridLayout->addWidget(buttonC, 2, 0);
    gridLayout->addWidget(buttonD, 3, 0);
    gridLayout->addWidget(buttonView, 4, 0);
    gridLayout->addWidget(buttonAInv, 0, 1);
    gridLayout->addWidget(buttonBInv, 1, 1);
    gridLayout->addWidget(buttonCInv, 2, 1);
    gridLayout->addWidget(buttonDInv, 3, 1);
    gridLayout->addWidget(buttonViewInv, 4, 1);
    gridLayout->addWidget(buttonRotation, 5, 0);
    gridLayout->addWidget(buttonRotationInv, 5, 1);
    gridLayout->addWidget(buttonReset, 6, 0, 1, 2);

    connect(buttonA, &QPushButton::released, this, &MainWindow::pressA);
    connect(buttonB, &QPushButton::released, this, &MainWindow::pressB);
    connect(buttonC, &QPushButton::released, this, &MainWindow::pressC);
    connect(buttonD, &QPushButton::released, this, &MainWindow::pressD);
    connect(buttonView, &QPushButton::released, this, &MainWindow::pressView);
    connect(buttonAInv, &QPushButton::released, this, &MainWindow::pressAInv);
    connect(buttonBInv, &QPushButton::released, this, &MainWindow::pressBInv);
    connect(buttonCInv, &QPushButton::released, this, &MainWindow::pressCInv);
    connect(buttonDInv, &QPushButton::released, this, &MainWindow::pressDInv);
    connect(buttonViewInv, &QPushButton::released, this,
            &MainWindow::pressViewInv);
    connect(buttonRotation, &QPushButton::released, this,
            &MainWindow::pressRotation);
    connect(buttonRotationInv, &QPushButton::released, this,
            &MainWindow::pressRotationInv);
    connect(buttonReset, &QPushButton::released, this, &MainWindow::pressReset);

    transformStr = "you";
    transformLabel = new QLabel();
    QFont font;
    font.setPointSize(16);
    font.setBold(true);
    transformLabel->setFont(font);
    transformLabel->setText(transformStr);
    gridLayout->addWidget(transformLabel, 7, 0, 1, 2);
}

void MainWindow::pressA() {
    glRenderer->buttonPressed(A);
    this->addTransformLabel("A");
}

void MainWindow::pressB() {
    glRenderer->buttonPressed(B);
    this->addTransformLabel("B");
}

void MainWindow::pressC() {
    glRenderer->buttonPressed(C);
    this->addTransformLabel("C");
}

void MainWindow::pressD() {
    glRenderer->buttonPressed(D);
    this->addTransformLabel("D");
}

void MainWindow::pressView() {
    glRenderer->buttonPressed(VIEW);
    this->addTransformLabel("V");
}

void MainWindow::pressAInv() {
    glRenderer->buttonPressed(A_INV);
    this->addTransformLabel("A⁻¹");
}

void MainWindow::pressBInv() {
    glRenderer->buttonPressed(B_INV);
    this->addTransformLabel("B⁻¹");
}

void MainWindow::pressCInv() {
    glRenderer->buttonPressed(C_INV);
    this->addTransformLabel("C⁻¹");
}

void MainWindow::pressDInv() {
    glRenderer->buttonPressed(D_INV);
    this->addTransformLabel("D⁻¹");
}

void MainWindow::pressViewInv() {
    glRenderer->buttonPressed(VIEW_INV);
    this->addTransformLabel("V⁻¹");
}

void MainWindow::pressRotation() {
    glRenderer->buttonPressed(ROTATION);
    this->addTransformLabel("R");
}

void MainWindow::pressRotationInv() {
    glRenderer->buttonPressed(ROTATION_INV);
    this->addTransformLabel("R⁻¹");
}

void MainWindow::pressReset() {
    glRenderer->buttonPressed(RESET);
    transformStr = "you";
    transformLabel->setText(transformStr);
}

void MainWindow::addTransformLabel(QString matrix) {
    transformStr.prepend("(");
    transformStr.prepend(matrix);
    transformStr.append(")");
    transformLabel->setText(transformStr);
}
