#ifndef CPP8_SRC_VIEW_CUSTOM_SPIN_BOX_H_
#define CPP8_SRC_VIEW_CUSTOM_SPIN_BOX_H_

#include <QKeyEvent>
#include <QSpinBox>

namespace s21 {
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

}  // namespace s21

#endif  // CPP8_SRC_VIEW_CUSTOM_SPIN_BOX_H_
