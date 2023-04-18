#include "Model.h"

void Model::Filter(QImage const &img, FilterName filter) {
  if (auto itr = filters_.find(filter); itr != filters_.end())
    NotifyPhotoFiltered(itr->second(img));
}

void Model::CustomFilter(QImage const &img, Matrix<double> const &matrix) {
  NotifyPhotoFiltered(Filter::CustomFilter(img, matrix));
}

void Model::Toning(QImage const &img, QColor const &color) {
  NotifyPhotoFiltered(Filter::Toning(img, color));
}

void Model::Brightness(QImage const &img, int brightness) {
  NotifyPhotoPreview(Filter::Brightness(img, brightness));
}

void Model::Contrast(QImage const &img, int contrast) {
  NotifyPhotoPreview(Filter::Contrast(img, contrast));
}

void Model::HSV(QImage const &img, int hue, int saturation, int value) {
  NotifyPhotoPreview(Filter::HSV(img, hue, saturation, value));
}

void Model::HSL(QImage const &img, int hue, int saturation, int light) {
  NotifyPhotoPreview(Filter::HSL(img, hue, saturation, light));
}
