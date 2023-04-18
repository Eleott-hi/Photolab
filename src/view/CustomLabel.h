#ifndef SRC_VIEW_CUSTOM_LABEL_H_
#define SRC_VIEW_CUSTOM_LABEL_H_

#include <QLabel>

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

#endif  // SRC_VIEW_CUSTOM_LABEL_H_
