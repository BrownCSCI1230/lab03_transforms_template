#include <parsing_ui/mainwindow.h>
#include <transforms_ui/mainwindow.h>
#include <QApplication>
#include <QMainWindow>
#include <QScreen>
#include <QTabWidget>

int main(int argc, char* argv[]) {
    QSurfaceFormat fmt;
    fmt.setVersion(4, 1);
    fmt.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(fmt);

    QApplication app(argc, argv);

    QCoreApplication::setApplicationName("lab03");
    QCoreApplication::setOrganizationName("BrownCSCI1230");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    auto* tabs = new QTabWidget;
    tabs->addTab(new TransformDemo::MainWindow(), "Transforms");
    tabs->addTab(new Parsing::MainWindow(), "Parsing");

    QMainWindow window;
    window.setCentralWidget(tabs);

    window.resize(600, 400);
    int desktopArea = QGuiApplication::primaryScreen()->size().width() *
                      QGuiApplication::primaryScreen()->size().height();
    int widgetArea = window.width() * window.height();
    if (((float)widgetArea / (float)desktopArea) < 0.75f)
        window.show();
    else
        window.showMaximized();

    return app.exec();
}