#include "HistoryWidget.h"

#include <QGraphicsBlurEffect>
#include <cassert>

HistoryWidget::HistoryWidget(QWidget *parent) : QScrollArea(parent) {
  setWidgetResizable(true);

  auto widget = new QWidget();
  layout_ = new QHBoxLayout();

  widget->setLayout(layout_);
  setWidget(widget);
  layout_->addStretch();
}

void HistoryWidget::Clear() {
  while (Count()) RemoveLast();
}

void HistoryWidget::Add(QLabel *label) {
  if (!label) return;

  if (Count()) layout_->insertWidget(Count(), new QLabel("➤"));
  layout_->insertWidget(Count(), label);
}

void HistoryWidget::RemoveWidget(size_t index) {
  if (index >= Count()) return;

  auto w_item = layout_->takeAt(index);
  delete w_item->widget();
  delete w_item;
}

void HistoryWidget::RemoveLast() {
  if (Count() == 0) return;

  RemoveWidget(Count() - 1);
  if (Count()) RemoveWidget(Count() - 1);
}

void HistoryWidget::ClearEffects() {
  for (size_t i = 0; i < Count(); ++i) {
    auto label = layout_->itemAt(i)->widget();
    label->setGraphicsEffect(nullptr);
  }
}

size_t HistoryWidget::GetIndexOfItem(QLabel *label) {
  for (size_t i = 0; i < Count(); ++i)
    if (layout_->itemAt(i)->widget() == label) return i / 2;

  assert(false && "Should not be here\n");
  return -1;
}

QLabel *HistoryWidget::GetItemFromIndex(size_t index) {
  index *= 2;
  if (index > Count()) return {};

  return static_cast<QLabel *>(layout_->itemAt(index)->widget());
}

size_t HistoryWidget::Count() {
  if (layout_) return layout_->count() - 1;
  return {};
}

void HistoryWidget::HighlightLabel(QLabel *label) {
  if (!label) return;

  auto graphic_effect = new QGraphicsDropShadowEffect();

  graphic_effect->setOffset(0);
  graphic_effect->setBlurRadius(30);
  graphic_effect->setColor(Qt::blue);

  label->setGraphicsEffect(graphic_effect);
}

void HistoryWidget::HighlightLabel(size_t index) {
  HighlightLabel(GetItemFromIndex(index));
}

void HistoryWidget::RemoveItemsAfter(QLabel *label) {
  if (!label) return;

  while (Count() && layout_->itemAt(Count() - 1)->widget() != label)
    RemoveLast();
}
