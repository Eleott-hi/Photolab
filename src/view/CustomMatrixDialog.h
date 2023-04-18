#ifndef SRC_VIEW_CUSTOM_MATRIX_DIALOG_H_
#define SRC_VIEW_CUSTOM_MATRIX_DIALOG_H_

#include <QDialog>

#include "Matrix.h"

namespace Ui {
class CustomMatrixDialog;
}

class CustomMatrixDialog : public QDialog {
  Q_OBJECT

 public:
  CustomMatrixDialog(QWidget* parent = nullptr);
  ~CustomMatrixDialog();

  static Matrix<double> GetMatrix();

 private slots:
  void on_sb_rows_valueChanged(int value);
  void on_sb_cols_valueChanged(int value);

 private:
  Ui::CustomMatrixDialog* ui_;

  Matrix<double> ToMatrix();
  void SetTable();
};

#endif  // SRC_VIEW_CUSTOM_MATRIX_DIALOG_H_
