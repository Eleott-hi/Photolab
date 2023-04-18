#include <gtest/gtest.h>

#include "Filter.h"

constexpr double error = 1e-1;

TEST(Grayscale, test_1) {
  QImage img_1(":/sample.png");
  QImage img_2(":/sample-bw-average.png");
  QImage result(Filter::Grayscale(img_1));

  for (int i = 0; i < result.width(); ++i) {
    for (int j = 0; j < result.height(); ++j) {
      ASSERT_NEAR(img_2.pixelColor(i, j).redF(), result.pixelColor(i, j).redF(),
                  error);
      ASSERT_NEAR(img_2.pixelColor(i, j).greenF(),
                  result.pixelColor(i, j).greenF(), error);
      ASSERT_NEAR(img_2.pixelColor(i, j).blueF(),
                  result.pixelColor(i, j).blueF(), error);
    }
  }
}

TEST(Negative, test_1) {
  QImage img_1(":/sample.png");
  QImage img_2(":/sample-negative.png");
  QImage result(Filter::Negative(img_1));

  for (int i = 0; i < result.width(); ++i) {
    for (int j = 0; j < result.height(); ++j) {
      ASSERT_NEAR(img_2.pixelColor(i, j).redF(), result.pixelColor(i, j).redF(),
                  error);
      ASSERT_NEAR(img_2.pixelColor(i, j).greenF(),
                  result.pixelColor(i, j).greenF(), error);
      ASSERT_NEAR(img_2.pixelColor(i, j).blueF(),
                  result.pixelColor(i, j).blueF(), error);
    }
  }
}

TEST(Emboss, test_1) {
  QImage img_1(":/sample.png");
  QImage img_2(":/sample-ebmoss.png");
  QImage result(Filter::Emboss(Filter::Grayscale(img_1)));

  ASSERT_NEAR(img_2.pixelColor(3, 10).redF(), result.pixelColor(3, 10).redF(),
              error);
  ASSERT_NEAR(img_2.pixelColor(41, 57).greenF(),
              result.pixelColor(41, 57).greenF(), error);
  ASSERT_NEAR(img_2.pixelColor(98, 206).blueF(),
              result.pixelColor(98, 206).blueF(), error);
}

TEST(Sharpen, test_1) {
  QImage img_1(":/sample.png");
  QImage img_2(":/sample-sharpen.png");
  QImage result(Filter::Sharpen(Filter::Grayscale(img_1)));

  ASSERT_NEAR(img_2.pixelColor(3, 10).redF(), result.pixelColor(3, 10).redF(),
              error);
  ASSERT_NEAR(img_2.pixelColor(41, 57).greenF(),
              result.pixelColor(41, 57).greenF(), error);
  ASSERT_NEAR(img_2.pixelColor(98, 206).blueF(),
              result.pixelColor(98, 206).blueF(), error);
}

TEST(BoxBlur, test_1) {
  QImage img_1(":/sample.png");
  QImage img_2(":/sample-box-blur.png");
  QImage result(Filter::BoxBlur(Filter::Grayscale(img_1)));

  ASSERT_NEAR(img_2.pixelColor(3, 10).redF(), result.pixelColor(3, 10).redF(),
              error);
  ASSERT_NEAR(img_2.pixelColor(41, 57).greenF(),
              result.pixelColor(41, 57).greenF(), error);
  ASSERT_NEAR(img_2.pixelColor(98, 13).blueF(),
              result.pixelColor(98, 13).blueF(), error);
}

TEST(Gaussian, test_1) {
  QImage img_1(":/sample.png");
  QImage img_2(":/sample-gaussian-blur.png");
  QImage result(Filter::BoxBlur(Filter::Grayscale(img_1)));

  ASSERT_NEAR(img_2.pixelColor(3, 10).redF(), result.pixelColor(3, 10).redF(),
              error);
  ASSERT_NEAR(img_2.pixelColor(41, 57).greenF(),
              result.pixelColor(41, 57).greenF(), error);
  ASSERT_NEAR(img_2.pixelColor(98, 13).blueF(),
              result.pixelColor(98, 13).blueF(), error);
}

TEST(Laplacian, test_1) {
  QImage img_1(":/sample.png");
  QImage img_2(":/sample-outline.png");
  QImage result(Filter::Laplacian(Filter::Grayscale(img_1)));

  ASSERT_NEAR(img_2.pixelColor(3, 10).redF(), result.pixelColor(3, 10).redF(),
              error);
  ASSERT_NEAR(img_2.pixelColor(41, 57).greenF(),
              result.pixelColor(41, 57).greenF(), error);
  ASSERT_NEAR(img_2.pixelColor(98, 13).blueF(),
              result.pixelColor(98, 13).blueF(), error);
}

TEST(SobelLeft, test_1) {
  QImage img_1(":/sample.png");
  QImage img_2(":/sample-sobel-left.png");
  QImage result(Filter::SobelLeft(Filter::Grayscale(img_1)));

  ASSERT_NEAR(img_2.pixelColor(3, 10).redF(), result.pixelColor(3, 10).redF(),
              error);
  ASSERT_NEAR(img_2.pixelColor(41, 57).greenF(),
              result.pixelColor(41, 57).greenF(), error);
  ASSERT_NEAR(img_2.pixelColor(98, 13).blueF(),
              result.pixelColor(98, 13).blueF(), error);
}

TEST(SobelRight, test_1) {
  QImage img_1(":/sample.png");
  QImage img_2(":/sample-sobel-right.png");
  QImage result(Filter::SobelRight(Filter::Grayscale(img_1)));

  ASSERT_NEAR(img_2.pixelColor(3, 10).redF(), result.pixelColor(3, 10).redF(),
              error);
  ASSERT_NEAR(img_2.pixelColor(41, 57).greenF(),
              result.pixelColor(41, 57).greenF(), error);
  ASSERT_NEAR(img_2.pixelColor(98, 39).blueF(),
              result.pixelColor(98, 39).blueF(), error);
}

TEST(SobelFull, test_1) {
  QImage img_1(":/sample.png");
  QImage img_2(":/sample-sobel-left-and-right.png");
  QImage result(Filter::SobelFull(Filter::Grayscale(img_1)));

  ASSERT_NEAR(img_2.pixelColor(3, 10).redF(), result.pixelColor(3, 10).redF(),
              error);
  ASSERT_NEAR(img_2.pixelColor(41, 57).greenF(),
              result.pixelColor(41, 57).greenF(), error);
  ASSERT_NEAR(img_2.pixelColor(98, 39).blueF(),
              result.pixelColor(98, 39).blueF(), error);
}

TEST(GausBlur, test) {
  QImage img_1(":/sample.png");
  QImage result(Filter::GaussianBlur(img_1));
  ASSERT_EQ(img_1 != result, true);
}

TEST(Prewitt, test_1) {
  QImage img_1(":/sample.png");
  QImage result(Filter::Prewitt(img_1));
  ASSERT_EQ(img_1 != result, true);
}

TEST(Toning, test_1) {
  QImage img_1(":/sample.png");
  QColor temp(Qt::blue);
  QImage result(Filter::Toning(img_1, temp));
  ASSERT_EQ(img_1.pixel(1, 1) != result.pixel(1, 1), true);
}
TEST(Brightness, test_1) {
  QImage img_1(":/sample.png");
  QImage img_2(":/sample-outline.png");
  QImage result_1(Filter::Brightness(img_1, -100));
  QImage result_2(Filter::Brightness(img_2, 100));

  ASSERT_GE(img_1.pixelColor(0, 0).lightness(),
            result_1.pixelColor(0, 0).lightness());
  ASSERT_LE(img_2.pixelColor(0, 0).lightness(),
            result_2.pixelColor(0, 0).lightness());
}

TEST(Contrast, test_1) {
  QImage img_1(":/sample.png");
  QImage result_1(Filter::Contrast(img_1, -100));

  int img1_min = 255;
  int img1_max = 0;
  int res1_min = 255;
  int res1_max = 0;

  for (int i = 0; i < result_1.width(); ++i) {
    for (int j = 0; j < result_1.height(); ++j) {
      img1_min = std::min(img1_min, img_1.pixelColor(i, j).lightness());
      img1_max = std::max(img1_max, img_1.pixelColor(i, j).lightness());
      res1_min = std::min(res1_min, result_1.pixelColor(i, j).lightness());
      res1_max = std::max(res1_max, result_1.pixelColor(i, j).lightness());
    }
  }

  ASSERT_LE(img1_min, res1_min);
  ASSERT_GE(img1_max, res1_max);
}

TEST(HSL, test_1) {
  QImage img_1(":/sample.png");
  QImage result_1(Filter::HSL(img_1, 60, 10, 90));
  ASSERT_EQ(result_1.pixelColor(0, 0) != img_1.pixelColor(0, 0), true);
}

TEST(HSV, test_1) {
  QImage img_1(":/sample.png");
  QImage result_1(Filter::HSV(img_1, 120, 10, 90));

  ASSERT_EQ(result_1.pixelColor(0, 0) != img_1.pixelColor(0, 0), true);
}