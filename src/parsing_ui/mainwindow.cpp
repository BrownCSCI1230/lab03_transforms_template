#include "mainwindow.h"
#include "parsing/sceneparser.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QDirIterator>
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
    connect(ui->exportButton, &QPushButton::clicked, this,
            &MainWindow::exportRenderedScenes);
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

void MainWindow::exportRenderedScenes() {
    // Create output directory if it doesn't exist
    QDir outputDir(STUDENT_OUTPUTS_DIR);
    if (!outputDir.exists()) {
        QDir().mkdir(outputDir.absolutePath());
    }

    // Get all JSON files from scenefiles directory
    QDir sceneDir(":resources/scenefiles");
    QStringList jsonFiles =
        sceneDir.entryList(QStringList() << "*.json", QDir::Files);

    if (jsonFiles.isEmpty()) {
        QMessageBox::warning(this, "Warning",
                             "No scene files found in :resources/scenefiles");
        return;
    }

    int successCount = 0;
    int failureCount = 0;

    for (const QString& fileName : jsonFiles) {
        QString filePath = sceneDir.filePath(fileName);
        QString baseName = fileName;
        baseName.remove(".json");
        QString outputPath = outputDir.filePath(baseName + ".png");

        RenderData renderData;
        bool success = SceneParser::parse(filePath.toStdString(), renderData);
        if (!success) {
            failureCount++;
            continue;
        }

        // Load the scene
        ui->glwidget->loadScene(renderData);
        ui->glwidget->update();
        QApplication::processEvents();

        // Save the rendered image
        ui->glwidget->saveRenderedImage(outputPath);
        successCount++;
    }

    QString message =
        QString(
            "Export completed!\nSuccessfully exported: %1\nFailed: %2\nSaved "
            "images are located in the %3 directory.")
            .arg(successCount)
            .arg(failureCount)
            .arg(outputDir.absolutePath());
    QMessageBox::information(this, "Export Complete", message);
}
