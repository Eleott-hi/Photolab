#ifndef SRC_COMMON_OBSERVABLE_H_
#define SRC_COMMON_OBSERVABLE_H_

#include <QImage>
#include <vector>

#include "Observer.h"

class Observable {
 public:
  virtual ~Observable() = default;

  virtual void AddObserver(Observer* observer) {
    observers_.push_back(observer);
  }

 protected:
  std::vector<Observer*> observers_;

  virtual void NotifyPhotoFiltered(QImage const& img) {
    for (auto i : observers_) i->NotifyPhotoFiltered(img);
  }

  virtual void NotifyPhotoPreview(QImage const& img) {
    for (auto i : observers_) i->NotifyPhotoPreview(img);
  }
};

#endif  // SRC_COMMON_OBSERVABLE_H_
