#ifndef CPP8_SRC_VIEW_CUSTOM_LABEL_H_
#define CPP8_SRC_VIEW_CUSTOM_LABEL_H_

#include <QLabel>

namespace s21 {
class CustomLabel : public QLabel {
  Q_OBJECT
 public:
  CustomLabel(CustomLabel &&) = delete;
  CustomLabel(CustomLabel const &) = delete;
  CustomLabel &operator=(CustomLabel &&) = delete;
  CustomLabel &operator=(CustomLabel const &) = delete;
  ~CustomLabel() = default;

  CustomLabel(QWidget *parent = nullptr) : QLabel(parent) {
    setContextMenuPolicy(Qt::CustomContextMenu);
  }

 signals:
  void mousePressEvent(QMouseEvent *event) override;
};

}  // namespace s21

#endif  // CPP8_SRC_VIEW_CUSTOM_LABEL_H_
