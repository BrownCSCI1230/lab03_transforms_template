#include "mainwindow.h"
#include "parsing/sceneparser.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMenu>
#include <QMessageBox>

using namespace Parsing;

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QMenu* fileMenu = new QMenu(this);
    fileMenu->addAction(ui->actionOpen);

    ui->fileButton->setMenu(fileMenu);

    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::fileOpen);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::fileOpen() {
    QString file =
        QFileDialog::getOpenFileName(this, QString(), "./scenefiles");
    if (file.isNull()) {
        return;
    }

    if (!file.endsWith(".json")) {
        QMessageBox::warning(this, "Error", "Unsupported file format");
        return;
    }

    RenderData renderData;
    bool success = SceneParser::parse(file.toStdString(), renderData);
    if (!success) {
        QMessageBox::critical(this, "Error", "Parse JSON fail");
        return;
    }

    // load the scene
    ui->glwidget->loadScene(renderData);
}
