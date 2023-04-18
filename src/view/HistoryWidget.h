#ifndef SRC_VIEW_HISTORY_WIDGET_H_
#define SRC_VIEW_HISTORY_WIDGET_H_

#include <QHBoxLayout>
#include <QLabel>
#include <QScrollArea>

class HistoryWidget : public QScrollArea {
  Q_OBJECT
 public:
  HistoryWidget(QWidget *parent = nullptr);
  HistoryWidget(HistoryWidget &&) = delete;
  HistoryWidget(HistoryWidget const &) = delete;
  HistoryWidget &operator=(HistoryWidget &&) = delete;
  HistoryWidget &operator=(HistoryWidget const &) = delete;
  ~HistoryWidget() = default;

  void Clear();
  size_t Count();
  void RemoveLast();
  void ClearEffects();
  void Add(QLabel *label);
  void HighlightLabel(size_t index);
  void HighlightLabel(QLabel *label);
  void RemoveItemsAfter(QLabel *label);
  QLabel *GetItemFromIndex(size_t index);
  size_t GetIndexOfItem(QLabel *label_ptr);

 private:
  QHBoxLayout *layout_ = nullptr;

  void RemoveWidget(size_t index);
};

#endif  // SRC_VIEW_HISTORY_WIDGET_H_
