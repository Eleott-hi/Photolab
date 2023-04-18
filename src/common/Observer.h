#ifndef SRC_COMMON_OBSERVER_H_
#define SRC_COMMON_OBSERVER_H_

#include <QImage>

class Observer {
 public:
  virtual void NotifyPhotoFiltered(QImage const &img) = 0;
  virtual void NotifyPhotoPreview(QImage const &img) = 0;
};

#endif  // SRC_COMMON_OBSERVER_H_