#include <QApplication>

#include "MainWindow.h"
#include "Model.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  s21::Model model;
  s21::Controller controller(&model);
  s21::MainWindow window(&controller);

  window.show();

  return app.exec();
}
