#include "Filter.h"

#include <cmath>

namespace s21 {

QImage Filter::Negative(QImage const &img) {
  QImage res(img.size(), img.format());

  for (int x = 0; x < img.width(); ++x)
    for (int y = 0; y < img.height(); ++y) {
      QRgb color = img.pixel(x, y);

      res.setPixel(x, y,
                   qRgb(255 - qRed(color),    //
                        255 - qGreen(color),  //
                        255 - qBlue(color)));
    }
  return res;
}

QImage Filter::Grayscale(const QImage &img) {
  QImage res(img);
  int pixelCount = img.width() * img.height();

  QRgb *pixel = reinterpret_cast<QRgb *>(res.bits());
  for (int i = 0; i < pixelCount; ++i) {
    int gray = (qRed(pixel[i]) + qGreen(pixel[i]) + qBlue(pixel[i])) / 3;
    pixel[i] = qRgb(gray, gray, gray);
  }

  return res;
}

QImage Filter::Toning(const QImage &img, const QColor &color) {
  QImage res(img);
  int pixelCount = img.width() * img.height();

  QRgb *pixel = reinterpret_cast<QRgb *>(res.bits());

  for (int i = 0; i < pixelCount; ++i) {
    pixel[i] = qRgb(qMin(qRed(pixel[i]) + color.red(), 255),
                    qMin(qGreen(pixel[i]) + color.green(), 255),
                    qMin(qBlue(pixel[i]) + color.blue(), 255));
  }

  return res;
}

QImage Filter::Emboss(QImage const &img) {
  static const Matrix<double> emboss_kernel = {{-2, -1, 0},  //
                                               {-1, 1, 1},   //
                                               {0, 1, 2}};
  return Convolve(img, emboss_kernel);
}

QImage Filter::Sharpen(QImage const &img) {
  static const Matrix<double> sharpen_kernel = {{0, -1, 0},   //
                                                {-1, 5, -1},  //
                                                {0, -1, 0}};
  return Convolve(img, sharpen_kernel);
}

QImage Filter::BoxBlur(QImage const &img) {
  static const Matrix<double> box_blur_kernel = {
      {1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0},
      {1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0},
      {1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0}};

  return Convolve(img, box_blur_kernel);
}

QImage Filter::GaussianBlur(QImage const &img) {
  static const Matrix<double> gaussianblur = {{0.0625, 0.125, 0.0625},  //
                                              {0.125, 0.25, 0.125},     //
                                              {0.0625, 0.125, 0.0625}};
  return Convolve(img, gaussianblur);
}

QImage Filter::Laplacian(QImage const &img) {
  static const Matrix<double> Laplacian = {{-1, -1, -1},  //
                                           {-1, 8, -1},   //
                                           {-1, -1, -1}};
  return Convolve(img, Laplacian);
}

QImage Filter::Prewitt(QImage const &img) {
  static const Matrix<double> horizontal = {{-1, -1, -1},  //
                                            {0, 0, 0},     //
                                            {1, 1, 1}};
  static const Matrix<double> vertical = {{-1, 0, 1},  //
                                          {-1, 0, 1},  //
                                          {-1, 0, 1}};

  return CombineEdges(Convolve(img, horizontal), Convolve(img, vertical));
}

QImage Filter::SobelLeft(QImage const &img) {
  static const Matrix<double> SobelLeft = {{1, 0, -1},  //
                                           {2, 0, -2},  //
                                           {1, 0, -1}};
  return Convolve(img, SobelLeft);
}

QImage Filter::SobelRight(QImage const &img) {
  static const Matrix<double> SobelRight = {{-1, 0, 1},  //
                                            {-2, 0, 2},  //
                                            {-1, 0, 1}};
  return Convolve(img, SobelRight);
}

QImage Filter::SobelFull(QImage const &img) {
  return CombineEdges(SobelLeft(img), SobelRight(img));
}

QImage Filter::CustomFilter(QImage const &img, Matrix<double> const &matrix) {
  return Convolve(img, matrix);
}

QImage Filter::Convolve(const QImage &img, const Matrix<double> &kernel) {
  QImage res(img.size(), img.format());

  const int kernel_half_rows = kernel.Rows() / 2;
  const int kernel_half_cols = kernel.Cols() / 2;

  for (int y = 0; y < img.height(); y++) {
    for (int x = 0; x < img.width(); x++) {
      res.setPixel(x, y,                             //
                   ApplyKernelAt(x, y, img, kernel,  //
                                 kernel_half_rows,   //
                                 kernel_half_cols));
    }
  }

  return res;
}

QRgb Filter::ApplyKernelAt(int x, int y,                  //
                           const QImage &img,             //
                           const Matrix<double> &kernel,  //
                           int kernel_half_rows,          //
                           int kernel_half_cols) {
  double red = 0, green = 0, blue = 0;

  for (int ky = -kernel_half_rows; ky <= kernel_half_rows; ky++) {
    for (int kx = -kernel_half_cols; kx <= kernel_half_cols; kx++) {
      int px = std::clamp(x + kx, 0, img.width() - 1);
      int py = std::clamp(y + ky, 0, img.height() - 1);

      QRgb color = img.pixel(px, py);

      double kernel_value =
          kernel(ky + kernel_half_rows, kx + kernel_half_cols);

      red += qRed(color) * kernel_value;
      green += qGreen(color) * kernel_value;
      blue += qBlue(color) * kernel_value;
    }
  }

  return qRgb(std::clamp<int>(red, 0, 255),    //
              std::clamp<int>(green, 0, 255),  //
              std::clamp<int>(blue, 0, 255));
}

QImage Filter::CombineEdges(const QImage &img_1, const QImage &img_2) {
  if (img_1.format() != img_2.format() ||  //
      img_1.width() != img_2.width() ||    //
      img_1.height() != img_2.height())
    return {};

  QImage res(img_1.size(), img_1.format());

  for (int x = 0; x < img_1.width(); x++)
    for (int y = 0; y < img_1.height(); y++)
      res.setPixel(x, y,
                   CalcColorMagnitude(img_1.pixel(x, y),  //
                                      img_2.pixel(x, y)));

  return res;
}

// Combine Edges additional Function
QRgb Filter::CalcColorMagnitude(const QRgb &col_1, const QRgb &col_2) {
  int red = std::sqrt(pow(qRed(col_1), 2) + pow(qRed(col_2), 2));
  int green = std::sqrt(pow(qGreen(col_1), 2) + pow(qGreen(col_2), 2));
  int blue = std::sqrt(pow(qBlue(col_1), 2) + pow(qBlue(col_2), 2));

  return qRgb(std::clamp(red, 0, 255),    //
              std::clamp(green, 0, 255),  //
              std::clamp(blue, 0, 255));
}

QImage Filter::Brightness(QImage const &img, int brightness) {
  QImage res(img.size(), img.format());

  for (int x = 0; x < img.width(); x++) {
    for (int y = 0; y < img.height(); y++) {
      QRgb color = img.pixel(x, y);
      res.setPixel(x, y,
                   qRgb(std::clamp(qRed(color) + brightness, 0, 255),
                        std::clamp(qGreen(color) + brightness, 0, 255),
                        std::clamp(qBlue(color) + brightness, 0, 255)));
    }
  }

  return res;
}

QImage Filter::Contrast(const QImage &img, int contrast) {
  QImage res(img.size(), img.format());
  const double factor = (259.0 * (contrast + 255)) / (255.0 * (259 - contrast));

  for (int x = 0; x < img.width(); x++) {
    for (int y = 0; y < img.height(); y++) {
      QRgb color = img.pixel(x, y);
      res.setPixel(
          x, y,
          qRgb(std::clamp<int>(factor * (qRed(color) - 128) + 128, 0, 255),
               std::clamp<int>(factor * (qGreen(color) - 128) + 128, 0, 255),
               std::clamp<int>(factor * (qBlue(color) - 128) + 128, 0, 255)));
    }
  }
  return res;
}

QImage Filter::HSL(const QImage &img, int hue, int saturation, int light) {
  QImage res(img.size(), img.format());

  for (int y = 0; y < img.height(); y++) {
    for (int x = 0; x < img.width(); x++) {
      QRgb color = img.pixel(x, y);
      res.setPixel(x, y, RgbToHsl(color, hue, saturation, light));
    }
  }

  return res;
}

QImage Filter::HSV(const QImage &img, int hue, int saturation, int value) {
  QImage res(img.size(), img.format());

  for (int y = 0; y < img.height(); ++y) {
    for (int x = 0; x < img.width(); ++x) {
      QRgb color = img.pixel(x, y);
      res.setPixel(x, y, RgbToHsv(color, hue, saturation, value));
    }
  }

  return res;
}

QRgb Filter::RgbToHsv(QRgb const &color, int hue, int saturation, int value) {
  double cmax, cmin, delta;

  int h = CalcHue(color, cmax, cmin, delta);
  int s = (cmax == 0) ? 0 : (delta / cmax * 255);
  int v = cmax * 255;

  return QColor::fromHsv(std::clamp((h + hue) % 360, 0, 359),
                         std::clamp(s + saturation, 0, 255),
                         std::clamp(v + value, 0, 255))
      .rgb();
}

QRgb Filter::RgbToHsl(QRgb const &color, int hue, int saturation, int light) {
  double cmax, cmin, delta;

  int h = CalcHue(color, cmax, cmin, delta);
  int l = qRound((cmax + cmin) / 2.0 * 255.0);
  int s = (delta == 0)
              ? 0
              : qRound(delta / (1.0 - fabs(2.0 * l / 255.0 - 1.0)) * 255.0);

  return QColor::fromHsl(std::clamp((h + hue) % 360, 0, 359),
                         std::clamp(s + saturation, 0, 255),
                         std::clamp(l + light, 0, 255))
      .rgb();
}

int Filter::CalcHue(QRgb const &color,  //
                    double &cmax, double &cmin, double &delta) {
  double r = qRed(color) / 255.0;
  double g = qGreen(color) / 255.0;
  double b = qBlue(color) / 255.0;

  cmax = std::max({r, g, b});
  cmin = std::min({r, g, b});
  delta = cmax - cmin;

  if (delta == 0) return 0;
  if (cmax == r) return qRound(60 * fmod((g - b) / delta, 6));
  if (cmax == g) return qRound(60 * ((b - r) / delta + 2));
  return qRound(60 * ((r - g) / delta + 4));
}

}  // namespace s21
