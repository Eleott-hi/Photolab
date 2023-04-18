#include <QApplication>

#include "MainWindow.h"
#include "Model.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  Model model;
  Controller controller(&model);
  MainWindow window(&controller);

  window.show();

  return app.exec();
}
