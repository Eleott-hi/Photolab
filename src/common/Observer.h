#ifndef CPP8_SRC_COMMON_OBSERVER_H_
#define CPP8_SRC_COMMON_OBSERVER_H_

#include <QImage>

namespace s21 {

class Observer {
 public:
  virtual void NotifyPhotoFiltered(QImage const &img) = 0;
  virtual void NotifyPhotoPreview(QImage const &img) = 0;
};

}  // namespace s21

#endif  // CPP8_SRC_COMMON_OBSERVER_H_