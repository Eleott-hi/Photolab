#ifndef CPP8_SRC_MODEL_MODEL_H_
#define CPP8_SRC_MODEL_MODEL_H_

#include <QImage>
#include <functional>
#include <map>

#include "Filter.h"
#include "Observable.h"

namespace s21 {
class Model : public Observable {
 public:
  Model() = default;
  ~Model() = default;
  Model(Model &&) = delete;
  Model(Model const &) = delete;
  Model &operator=(Model &&) = delete;
  Model &operator=(Model const &) = delete;

  void Contrast(QImage const &img, int contrast);
  void Filter(QImage const &img, FilterName filter);
  void Brightness(QImage const &img, int brightness);
  void Toning(QImage const &img, QColor const &color);
  void CustomFilter(QImage const &img, Matrix<double> const &matrix);
  void HSL(QImage const &img, int hue, int saturation, int light);
  void HSV(QImage const &img, int hue, int saturation, int value);

 private:
  std::map<FilterName, std::function<QImage(QImage const &)> > filters_ = {
      {FilterName::Emboss, Filter::Emboss},
      {FilterName::Sharpen, Filter::Sharpen},
      {FilterName::BoxBlur, Filter::BoxBlur},
      {FilterName::Prewitt, Filter::Prewitt},
      {FilterName::Negative, Filter::Negative},
      {FilterName::Grayscale, Filter::Grayscale},
      {FilterName::Laplacian, Filter::Laplacian},
      {FilterName::SobelFull, Filter::SobelFull},
      {FilterName::SobelLeft, Filter::SobelLeft},
      {FilterName::SobelRight, Filter::SobelRight},
      {FilterName::GaussianBlur, Filter::GaussianBlur}};
};
}  // namespace s21

#endif  // CPP8_SRC_MODEL_MODEL_H_
