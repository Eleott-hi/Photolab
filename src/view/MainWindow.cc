#include "MainWindow.h"

#include <QColorDialog>
#include <QFileDialog>
#include <QMouseEvent>
#include <QPushButton>
#include <QSlider>
#include <functional>
#include <map>

#include "CustomLabel.h"
#include "CustomMatrixDialog.h"
#include "ui_MainWindow.h"

namespace s21 {

void SetLabelPixmap(QLabel *label, QImage const &img) {
  if (!label) return;

  label->setPixmap(QPixmap::fromImage(img).scaled(
      label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void MainWindow::SetSlidersToZero() {
  static std::vector<QSlider *> sliders = {ui_->hs_Brightness,  //
                                           ui_->hs_Contrast,    //
                                           ui_->hs_Hue,         //
                                           ui_->hs_Saturation,  //
                                           ui_->hs_Light_Value};

  for (auto &slider : sliders)
    if (slider) slider->setValue(0);
}

MainWindow::MainWindow(Controller *controller, QWidget *parent)
    : QMainWindow(parent), controller_(controller), ui_(new Ui::MainWindow) {
  ui_->setupUi(this);

  ConnectSignals();
  controller_->AddObserver(this);
  ui_->labelImage->setScaledContents(false);
}

MainWindow::~MainWindow() { delete ui_; }

void MainWindow::NotifyPhotoFiltered(QImage const &img) {
  if (img.isNull()) return;

  AddToHistory(img);

  SetLabelPixmap(ui_->labelImage, img);
  preview_ = imgs_.back();

  SetSlidersToZero();
}

void MainWindow::NotifyPhotoPreview(QImage const &img) {
  if (img.isNull()) return;
  preview_ = img;

  ui_->sa_History->ClearEffects();
  ui_->sa_History->HighlightLabel(imgs_.size() - 1);

  SetLabelPixmap(ui_->labelImage, preview_);
}

void MainWindow::on_actionOpen_triggered() {
  QImage img(QFileDialog::getOpenFileName(this, "Open File", "~/",
                                          "Images (*.bmp *.png *.jpg)"));

  if (img.isNull()) return;

  SetSlidersToZero();

  imgs_.clear();
  ui_->sa_History->Clear();

  AddToHistory(img);
  preview_ = imgs_.back();

  SetLabelPixmap(ui_->labelImage, preview_);
}

void MainWindow::on_actionSave_triggered() {
  if (imgs_.empty()) return;

  QString file = QFileDialog::getSaveFileName(this, "Save File", "~/",
                                              "Image files (*.bmp)");

  if (!file.isEmpty()) imgs_.back().save(file, "BMP");
}

void MainWindow::on_actionReverse_triggered() {
  if (imgs_.size() < 2) return;

  imgs_.pop_back();

  ui_->sa_History->RemoveLast();
  ui_->sa_History->ClearEffects();
  ui_->sa_History->HighlightLabel(imgs_.size() - 1);

  preview_ = imgs_.back();

  SetLabelPixmap(ui_->labelImage, preview_);
}

void MainWindow::resizeEvent(QResizeEvent *event) {
  if (imgs_.empty()) return;

  SetLabelPixmap(ui_->labelImage, preview_);
}

void MainWindow::AddToHistory(QImage const &img) {
  auto label = new CustomLabel(ui_->sa_History);
  connect(label, &CustomLabel::mousePressEvent, this,
          &MainWindow::LabelSelected);

  imgs_.push_back(img);

  ui_->sa_History->Add(label);
  ui_->sa_History->ClearEffects();
  ui_->sa_History->HighlightLabel(label);

  SetLabelPixmap(label, img);
}

void MainWindow::LabelSelected(QMouseEvent *event) {
  auto label = static_cast<CustomLabel *>(sender());
  if (label == ui_->labelImage) return;

  SetSlidersToZero();
  ui_->sa_History->ClearEffects();
  ui_->sa_History->HighlightLabel(label);

  auto index = ui_->sa_History->GetIndexOfItem(label);
  SetLabelPixmap(ui_->labelImage, imgs_.at(index));

  if (event->button() == Qt::RightButton) ShowContextMenu(label, event->pos());
}

void MainWindow::ShowContextMenu(QLabel *label, QPoint const &pos) {
  QMenu contextMenu(tr("Context menu"), label);
  QAction action("Remove history after this label", label);

  connect(&action, &QAction::triggered, this, [&, label]() {
    auto index = ui_->sa_History->GetIndexOfItem(label);
    imgs_.erase(imgs_.begin() + index + 1, imgs_.end());
    ui_->sa_History->RemoveItemsAfter(label);
    preview_ = imgs_.back();
  });

  contextMenu.addAction(&action);
  contextMenu.exec(label->mapToGlobal(pos));
}

void MainWindow::PreviewChanging() {
  int hue = ui_->hs_Hue->value();
  int saturation = ui_->hs_Saturation->value();
  int light_value = ui_->hs_Light_Value->value();

  preview_ = imgs_.back();

  ui_->rb_HSL->isChecked()
      ? controller_->HSL(preview_, hue, saturation, light_value)
      : controller_->HSV(preview_, hue, saturation, light_value);

  controller_->Brightness(preview_, ui_->hs_Brightness->value());
  controller_->Contrast(preview_, ui_->hs_Contrast->value());
}

void MainWindow::ConnectSignals() {
  std::vector<QSlider *> sliders = {ui_->hs_Hue, ui_->hs_Saturation,
                                    ui_->hs_Light_Value, ui_->hs_Contrast,
                                    ui_->hs_Brightness};

  std::map<QPushButton *, std::function<void()>> buttons_funcs = {
      {ui_->b_Apply, [&]() { NotifyPhotoFiltered(preview_); }},
      {ui_->b_Emboss, [&]() { controller_->Emboss(imgs_.back()); }},
      {ui_->b_Prewitt, [&]() { controller_->Prewitt(imgs_.back()); }},
      {ui_->b_Sharpen, [&]() { controller_->Sharpen(imgs_.back()); }},
      {ui_->b_BoxBlur, [&]() { controller_->BoxBlur(imgs_.back()); }},
      {ui_->b_Negative, [&]() { controller_->Negative(imgs_.back()); }},
      {ui_->b_Grayscale, [&]() { controller_->Grayscale(imgs_.back()); }},
      {ui_->b_Laplacian, [&]() { controller_->Laplacian(imgs_.back()); }},
      {ui_->b_SobelFull, [&]() { controller_->SobelFull(imgs_.back()); }},
      {ui_->b_SobelLeft, [&]() { controller_->SobelLeft(imgs_.back()); }},
      {ui_->b_SobelRight, [&]() { controller_->SobelRight(imgs_.back()); }},
      {ui_->b_GaussianBlur, [&]() { controller_->GaussianBlur(imgs_.back()); }},
      {ui_->b_Toning,
       [&]() {
         QColor color = QColorDialog::getColor();
         if (color.isValid()) controller_->Toning(imgs_.back(), color);
       }},
      {ui_->b_CustomFilter, [&]() {
         auto matrix = CustomMatrixDialog::GetMatrix();
         if (matrix.IsValid()) controller_->CustomFilter(imgs_.back(), matrix);
       }}};

  for (auto &[button, func] : buttons_funcs)
    connect(button, &QPushButton::clicked, this, [&, func = func]() {
      if (!imgs_.empty()) func();
    });

  for (auto &slider : sliders)
    connect(slider, &QSlider::valueChanged, this, [&]() {
      if (!imgs_.empty()) PreviewChanging();
    });

  connect(ui_->rb_HSL, &QRadioButton::toggled, this, [&](bool toggle) {
    ui_->l_Light_Value->setText(toggle ? "Light" : "Value");
    emit ui_->hs_Brightness->valueChanged(ui_->hs_Brightness->value());
  });

  connect(ui_->labelImage, &CustomLabel::mousePressEvent, this,
          &MainWindow::LabelSelected);
}

}  // namespace s21
