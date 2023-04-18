#ifndef SRC_MODEL_FILTER_H_
#define SRC_MODEL_FILTER_H_
#include <QImage>
#include <QPainter>
#include <memory>

#include "Matrix.h"

enum class FilterName {
  Emboss,
  Sharpen,
  BoxBlur,
  Prewitt,
  Negative,
  Grayscale,
  Laplacian,
  SobelLeft,
  SobelFull,
  SobelRight,
  GaussianBlur
};

class Filter {
 public:
  Filter() = default;
  ~Filter() = default;

  static QImage Emboss(QImage const &img);
  static QImage Sharpen(QImage const &img);
  static QImage BoxBlur(QImage const &img);
  static QImage Prewitt(QImage const &img);
  static QImage Negative(QImage const &img);
  static QImage Grayscale(QImage const &img);
  static QImage Laplacian(QImage const &img);
  static QImage SobelFull(QImage const &img);
  static QImage SobelLeft(QImage const &img);
  static QImage SobelRight(QImage const &img);
  static QImage GaussianBlur(QImage const &img);
  static QImage Contrast(QImage const &img, int contrast);
  static QImage Brightness(QImage const &img, int brightness);
  static QImage Toning(QImage const &img, QColor const &color);
  static QImage HSL(QImage const &img, int hue, int saturation, int light);
  static QImage HSV(QImage const &img, int hue, int saturation, int value);
  static QImage CustomFilter(QImage const &img, Matrix<double> const &matrix);

 private:
  static QRgb CalcColorMagnitude(const QRgb &col_1, const QRgb &col_2);
  static QImage CombineEdges(const QImage &img_1, const QImage &img_2);
  static QImage Convolve(const QImage &data, const Matrix<double> &kernel);
  static QRgb RgbToHsl(QRgb const &color, int hue, int saturation, int light);
  static QRgb RgbToHsv(QRgb const &color, int hue, int saturation, int value);

  static QRgb ApplyKernelAt(int x, int y,  //
                            const QImage &data, const Matrix<double> &kernel,
                            int kernel_half_rows, int kernel_half_cols);

  static int CalcHue(const QRgb &color,  //
                     double &cmax, double &cmin, double &delta);
};

#endif  // SRC_MODEL_FILTER_H_
