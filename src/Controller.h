#ifndef CPP8_SRC_CONTROLLER_H_
#define CPP8_SRC_CONTROLLER_H_

#include "Model.h"

namespace s21 {

class Controller {
 public:
  Controller() = default;
  ~Controller() = default;
  Controller(Model&&) = delete;
  Controller(Controller const&) = delete;
  Controller& operator=(Controller&&) = delete;
  Controller& operator=(Controller const&) = delete;

  explicit Controller(Model* model) : model_(model) {}

  void AddObserver(Observer* observer) { model_->AddObserver(observer); }

  void CustomFilter(QImage const& img, Matrix<double> const& matrix) {
    model_->CustomFilter(img, matrix);
  }

  void Brightness(QImage const& img, int brightness) {
    model_->Brightness(img, brightness);
  }

  void Contrast(QImage const& img, int contrast) {
    model_->Contrast(img, contrast);
  }

  void Toning(QImage const& img, QColor const& color) {
    model_->Toning(img, color);
  }

  void HSV(QImage const& img, int hue, int saturation, int value) {
    model_->HSV(img, hue, saturation, value);
  }

  void HSL(QImage const& img, int hue, int saturation, int light) {
    model_->HSL(img, hue, saturation, light);
  }

  void Emboss(QImage const& img) { model_->Filter(img, FilterName::Emboss); }

  void Prewitt(QImage const& img) { model_->Filter(img, FilterName::Prewitt); }

  void Sharpen(QImage const& img) { model_->Filter(img, FilterName::Sharpen); }

  void BoxBlur(QImage const& img) { model_->Filter(img, FilterName::BoxBlur); }

  void Negative(QImage const& img) {
    model_->Filter(img, FilterName::Negative);
  }

  void Grayscale(QImage const& img) {
    model_->Filter(img, FilterName::Grayscale);
  }

  void Laplacian(QImage const& img) {
    model_->Filter(img, FilterName::Laplacian);
  }

  void SobelLeft(QImage const& img) {
    model_->Filter(img, FilterName::SobelLeft);
  }

  void SobelFull(QImage const& img) {
    model_->Filter(img, FilterName::SobelFull);
  }

  void SobelRight(QImage const& img) {
    model_->Filter(img, FilterName::SobelRight);
  }

  void GaussianBlur(QImage const& img) {
    model_->Filter(img, FilterName::GaussianBlur);
  }

 private:
  Model* model_;
};

}  // namespace s21

#endif  // CPP8_SRC_CONTROLLER_H_
