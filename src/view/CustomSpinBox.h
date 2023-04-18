#ifndef SRC_VIEW_CUSTOM_SPIN_BOX_H_
#define SRC_VIEW_CUSTOM_SPIN_BOX_H_

#include <QKeyEvent>
#include <QSpinBox>

class CustomSpinBox : public QSpinBox {
 public:
  CustomSpinBox(CustomSpinBox &&) = delete;
  CustomSpinBox(CustomSpinBox const &) = delete;
  CustomSpinBox &operator=(CustomSpinBox &&) = delete;
  CustomSpinBox &operator=(CustomSpinBox const &) = delete;
  ~CustomSpinBox() = default;

  CustomSpinBox(QWidget *parent = nullptr) : QSpinBox(parent) {}

 protected:
  virtual void keyPressEvent(QKeyEvent *event) override { event->ignore(); }
};

#endif  // SRC_VIEW_CUSTOM_SPIN_BOX_H_
