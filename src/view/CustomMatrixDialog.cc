#include "CustomMatrixDialog.h"

#include "ui_CustomMatrixDialog.h"

namespace s21 {

Matrix<double> CustomMatrixDialog::GetMatrix() {
  CustomMatrixDialog dialog;

  return dialog.exec() ? dialog.ToMatrix() : Matrix<double>();
}

CustomMatrixDialog::CustomMatrixDialog(QWidget *parent)
    : QDialog(parent), ui_(new Ui::CustomMatrixDialog) {
  ui_->setupUi(this);

  ui_->t_matrix->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui_->t_matrix->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  SetTable();
}

CustomMatrixDialog::~CustomMatrixDialog() { delete ui_; }

void CustomMatrixDialog::on_sb_rows_valueChanged(int value) {
  ui_->t_matrix->setRowCount(value);
  SetTable();
}

void CustomMatrixDialog::on_sb_cols_valueChanged(int value) {
  ui_->t_matrix->setColumnCount(value);
  SetTable();
}

void CustomMatrixDialog::SetTable() {
  auto w_table = ui_->t_matrix;

  for (int i = 0; i < w_table->rowCount(); ++i)
    for (int j = 0; j < w_table->columnCount(); ++j) {
      auto spin_w = new QDoubleSpinBox();
      spin_w->setRange(-255, +255);

      w_table->setCellWidget(i, j, spin_w);
    }

  w_table->resize(size());
}

Matrix<double> CustomMatrixDialog::ToMatrix() {
  auto w_table = ui_->t_matrix;

  Matrix<double> matrix(w_table->rowCount(), w_table->columnCount());

  for (int i = 0; i < w_table->rowCount(); ++i)
    for (int j = 0; j < w_table->columnCount(); ++j) {
      auto spin_box = static_cast<QDoubleSpinBox *>(w_table->cellWidget(i, j));
      matrix(i, j) = spin_box->value();
    }

  return matrix;
}

}  // namespace s21
