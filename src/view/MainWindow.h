#ifndef CPP8_SRC_VIEW_MAIN_WINDOW_H_
#define CPP8_SRC_VIEW_MAIN_WINDOW_H_

#include <QImage>
#include <QMainWindow>
#include <QVector>

#include "Controller.h"
#include "HistoryWidget.h"

namespace Ui {
class MainWindow;
}

namespace s21 {
class MainWindow : public QMainWindow, public Observer {
  Q_OBJECT

 public:
  MainWindow() = delete;
  MainWindow(MainWindow &&) = delete;
  MainWindow(MainWindow const &) = delete;
  MainWindow &operator=(MainWindow &&) = delete;
  MainWindow &operator=(MainWindow const &) = delete;
  explicit MainWindow(Controller *controller, QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_actionOpen_triggered();
  void on_actionSave_triggered();
  void on_actionReverse_triggered();
  void LabelSelected(QMouseEvent *event);
  void ShowContextMenu(QLabel *label, QPoint const &pos);

 private:
  QImage preview_;
  Ui::MainWindow *ui_;
  QVector<QImage> imgs_;
  Controller *controller_;

  void ConnectSignals();
  void PreviewChanging();
  void SetSlidersToZero();
  void AddToHistory(QImage const &img);
  void resizeEvent(QResizeEvent *event) final;
  void NotifyPhotoPreview(QImage const &img) final;
  void NotifyPhotoFiltered(QImage const &img) final;
};

}  // namespace s21
#endif  // CPP8_SRC_VIEW_MAIN_WINDOW_H_
