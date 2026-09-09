#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// #include "parsing_ui/glwidget.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace Parsing {

class MainWindow : public QWidget {
    Q_OBJECT

   public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

   public slots:
    void fileOpen();
    void exportRenderedScenes();

   private:
    Ui::MainWindow* ui;
};

}  // namespace Parsing
#endif  // MAINWINDOW_H
